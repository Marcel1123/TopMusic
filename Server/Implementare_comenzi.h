
void MyVote(){

    if(login==1){ 

        sqlite3 *Data_base;
        char *Error_message = 0;
        int command;
        char *query;
        sqlite3_stmt* capat;
    
        command = sqlite3_open("./Server/TopMusic.db", &Data_base);
    
        if(command){
            fprintf(stderr, "Nu s-a putut deschide baza de date: %s.\n", sqlite3_errmsg(Data_base)); 
        } else {
            fprintf(stderr, "Am deschis cu succes baza de date.\n");
        }
    
        // printf("DV %d\n", drept_vot);
    
        if(drept_vot == 1){

            query = "SELECT * from Melodii where Nume=? and Gen=?;";
    
            command = sqlite3_prepare_v2(Data_base,query,-1,&capat,NULL);
    
            sqlite3_bind_text(capat, 1, nume_melodie , strlen(nume_melodie), SQLITE_STATIC);
            sqlite3_bind_text(capat, 2, gen_melodie, strlen(gen_melodie), SQLITE_STATIC);
    
            if(sqlite3_step(capat) == SQLITE_ROW){
                sqlite3_finalize(capat);
                query = "UPDATE Melodii set Voturi=Voturi+1 where Nume=? and Gen=?;";
    
                command = sqlite3_prepare_v2(Data_base,query,-1,&capat,NULL);

                sqlite3_bind_text(capat, 1, nume_melodie , strlen(nume_melodie), SQLITE_STATIC);
                sqlite3_bind_text(capat, 2, gen_melodie, strlen(gen_melodie), SQLITE_STATIC);
    
                // command=sqlite3_step(capat);

                if(sqlite3_step(capat) == SQLITE_DONE){
                    // printf("STPVT: [%d]\n", command);
                    strcat(msgrasp,"Ati votat aceasta melodie.\n");
                    sqlite3_finalize(capat);
                    sqlite3_close(Data_base);
                } else {
                    printf("UPS: \n");
                    bzero(msgrasp,D_MAX);
                    strcat(msgrasp,"Nu ai votat!\n");
                    sqlite3_finalize(capat);
                    sqlite3_close(Data_base);
                }
            } else {

                printf("Nu am gasit aceasta melodie.\n");
                strcat(msgrasp,"Nu am gasit acesta melodie.\n");
                sqlite3_finalize(capat);
                sqlite3_close(Data_base);

            }
    
        } else {
                printf("Nu aveti drept de vot.\n");
                bzero(msgrasp,D_MAX);
                strcat(msgrasp,"Nu mai aveti drept de vot.\n");
        }
    } else {
        printf("Lovativa.\n");
        strcat(msgrasp,"Mai intai logativa.\n");
    }

}

void MyLogin(){
    
    if(login==0){

        sqlite3 *Data_base;
        char *Error_message = 0;
        int command;
        char *query;
        sqlite3_stmt* capat;

        command = sqlite3_open("./Server/TopMusic.db",&Data_base);

        if(command){
            fprintf(stderr, "Nu am deschis baza de date.%s\n", sqlite3_errmsg(Data_base));
        } else {
            fprintf(stderr, "Am deschis cu succes baza de date.\n");
        }

        query = "SELECT * from Logat where Username=?;";

        sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);
        sqlite3_bind_text(capat,1,username1,strlen(username1),SQLITE_STATIC);

        if(sqlite3_step(capat) == SQLITE_ROW){

            logat = sqlite3_column_int(capat,1);
            if(logat == 0){
                sqlite3_finalize(capat);
                query = "SELECT * from Conturi where Username=? and Password=?;";

                sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);
                sqlite3_bind_text(capat,1,username1,strlen(username1),SQLITE_STATIC);
                sqlite3_bind_text(capat,2,password1,strlen(password1),SQLITE_STATIC);

                if(sqlite3_step(capat) == SQLITE_ROW){

                    bzero(user_type1,5);
                    const char *text = (const char *)sqlite3_column_text(capat,2);
                    strcat(user_type1,text);
                    int temp1 = sqlite3_column_int(capat,3);
                    drept_vot = temp1;
                    int temp2 = sqlite3_column_int(capat,4);
                    drept_sterge = temp2;
                    int temp3 = sqlite3_column_int(capat,5);
                    banat = temp3;

                    if(banat == 1){
                        printf("BLOCAT\n");
                        bzero(msgrasp,D_MAX);
                        strcat(msgrasp,"Acest cont este blocat.\n");
                        bzero(username1,15);
                        bzero(password1,15);
                        bzero(user_type1,5);
                        drept_vot=0;
                        drept_sterge=0;
                        banat = 0;
                        sqlite3_finalize(capat);
                        sqlite3_close(Data_base);
                    } else {
                        sqlite3_finalize(capat);
                        query = "UPDATE Logat set Login=1 where Username=?;";

                        sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);
                        sqlite3_bind_text(capat,1,username1,strlen(username1),SQLITE_STATIC);

                        if(sqlite3_step(capat) == SQLITE_DONE){
                            login=1;
                            printf("Cont corect: %s si %s.\n",username1,password1 );
                            fflush(stdout);
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"\t->Ati fost logat cu succes. \n");
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);

                        } else {
                            printf("Problema la BD.\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Avem o problema la baza de date.\n");
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);
                        }
                    }

                } else {
                    printf("Parola incorecta!\n");
                    bzero(msgrasp,D_MAX);
                    strcat(msgrasp,"Parola introdusa este incorecta.\n");
                    sqlite3_finalize(capat);
                    sqlite3_close(Data_base);
                }

            } else {
                printf("Cnt deja conectat.\n");
                bzero(msgrasp,D_MAX);
                strcat(msgrasp,"Acest cont este deja conectat.\n");
                sqlite3_finalize(capat);
                sqlite3_close(Data_base);
            }

        } else {
            printf("Nu am gasit USR;\n");
            bzero(msgrasp,D_MAX);
            strcat(msgrasp,"\n\tCont incorect.\n\tMai incercati sau creativa un nou cont.\n");
            sqlite3_finalize(capat);
            sqlite3_close(Data_base);
        }

    } else {
        printf("Sunteti deja logat.\n");
        bzero(msgrasp,D_MAX);
        strcat(msgrasp,"Deja sunteti logat.\n");        
    }

}

void MyRegister(){

    if(login==0){

        sqlite3 *Data_base;
        char *Error_message = 0;
        int command;
        char *query;
        sqlite3_stmt *capat;
        int vote;
        int stergere;
        int banat=0;

        command = sqlite3_open("./Server/TopMusic.db", &Data_base);

        if(command){
            fprintf(stderr, "Nu s-a putut deschide baza de date: %s.\n", sqlite3_errmsg(Data_base));
        } else {
            fprintf(stderr, "Am deschis cu succes baza de date.\n");
        }

        if(strcmp(user_type1,"user")==0){
            vote=1;
            stergere=0;
        }
        if(strcmp(user_type1,"admin")==0){
            vote=1;
            stergere=1;
        }

        query = "SELECT * from Conturi where Username=?";

        sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);

        sqlite3_bind_text(capat,1,username1,strlen(username1), SQLITE_STATIC);

        if(sqlite3_step(capat) == SQLITE_ROW){
            printf("Am gasit acest user: %s\n", username1);
            fflush(stdout);
            strcat(msgrasp,"Acest username este deja exista.\n");
            sqlite3_finalize(capat);
            sqlite3_close(Data_base);
        } else {
            sqlite3_finalize(capat);
            query="INSERT INTO Conturi (Username,Password,Tip_user,Drept_vot,Stergere,Banat) " \
                    "VALUES (?,?,?,?,?,?);";

            sqlite3_prepare_v2(Data_base,query,-1,&capat, SQLITE_OK);

            sqlite3_bind_text(capat,1,username1,strlen(username1), SQLITE_STATIC);
            sqlite3_bind_text(capat,2,password1,strlen(password1), SQLITE_STATIC);
            sqlite3_bind_text(capat,3,user_type1,strlen(user_type1), SQLITE_STATIC);

            sqlite3_bind_int(capat,4,vote);
            sqlite3_bind_int(capat,5,stergere);
            sqlite3_bind_int(capat,6,banat);

            if(sqlite3_step(capat) == SQLITE_DONE ){
                sqlite3_finalize(capat);
                query = "INSERT INTO Logat (Username,Login) " \
                        "VALUES (?,0);";

                sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);

                sqlite3_bind_text(capat,1,username1,strlen(username1),SQLITE_STATIC);

                if(sqlite3_step(capat) == SQLITE_DONE){

                    printf("Am adaugat acest user: %s\n", username1);
                    fflush(stdout);
                    bzero(msgrasp,D_MAX);
                    strcat(msgrasp,"Contul creat cu succes.\n");
                    sqlite3_finalize(capat);
                    sqlite3_close(Data_base);

                } else {
                    fprintf(stderr, "A aparut o eroare la register: %s\n", sqlite3_errmsg(Data_base));
                    bzero(msgrasp,D_MAX);
                    strcat(msgrasp,"A aparut o problema la register.\n");
                    sqlite3_finalize(capat);
                    sqlite3_close(Data_base);
                }
            } else {
                fprintf(stderr, "A aparut o eroare la register: %s.\n", sqlite3_errmsg(Data_base));
                bzero(msgrasp,D_MAX);
                strcat(msgrasp,"A aparut o eroare la register");
                strcat(msgrasp,"\n");
                sqlite3_finalize(capat);
                sqlite3_close(Data_base);
            }
        }
    } else {
        printf("Sunteti deja logat.\n");
        bzero(msgrasp,D_MAX);
        strcat(msgrasp,"Deja sunteti logat. Nu puteti sa va inregistrati alt cont.\n");
    }
    
}

void MyList(){
    if(login == 1){

        sqlite3 *Data_base;
        char *Error_message = 0;
        int command;
        char *query;
        sqlite3_stmt *capat;
        voturi=0;
        ID=0;
    
        command = sqlite3_open("./Server/TopMusic.db",&Data_base);
    
        if(command){
            fprintf(stderr, "Nu s-a putut deschide baza de date: %s.\n", sqlite3_errmsg(Data_base));
        } else {
            fprintf(stderr, "Am deschis cu succes baza de date.\n");
        }
        
        if(strlen(top)>0){

            if(strcmp(top,"all")==0){
        
                query = "SELECT * from Melodii order by Voturi desc;";
                
                command = sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);

            } else {
        
                query = "SELECT * from Melodii where Gen=? order by Voturi desc;";
                
                command = sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);
        
                sqlite3_bind_text(capat,1,top,strlen(top), SQLITE_STATIC);
            }
            
            if(command != SQLITE_OK){
                printf("A aparut o problema.\n");
                bzero(msgrasp,D_MAX);
                strcat(msgrasp,"Problema la crearea queryului\n");
                sqlite3_finalize(capat);
                sqlite3_close(Data_base);
            } else {

                if(sqlite3_step(capat) == SQLITE_ROW){
                    bzero(msgrasp,D_MAX);
                    strcat(msgrasp,"> Numele -----------> Voturi === Gen<\n");
                    // char voturi[10];
                        const char *text = (const char *)sqlite3_column_text(capat,1);
                        const char *vt = (const char*)sqlite3_column_text(capat,4);
                        const char *tops1 = (const char*)sqlite3_column_text(capat,3);
                        strcat(msgrasp,text);
                        strcat(msgrasp," -----------> ");
                        // strcat(voturi,vt);
                        strcat(msgrasp,vt);
                        strcat(msgrasp," === ");
                        strcat(msgrasp,tops1);
                        strcat(msgrasp,"\n");
                    while(sqlite3_step(capat) == SQLITE_ROW){
                        // bzero(voturi,10);
                        const char *text = (const char *)sqlite3_column_text(capat,1);
                        const char *vt = (const char*)sqlite3_column_text(capat,4);
                        const char *tops = (const char*)sqlite3_column_text(capat,3);
                        strcat(msgrasp,text);
                        strcat(msgrasp," -----------> ");
                        // strcat(voturi,vt);
                        strcat(msgrasp,vt);
                        strcat(msgrasp," === ");
                        strcat(msgrasp,tops);
                        strcat(msgrasp,"\n");
                
                    }
                    sqlite3_finalize(capat);    
                    sqlite3_close(Data_base);

                } else {

                    printf("topul nu exista!\n");
                    bzero(msgrasp,D_MAX);
                    strcat(msgrasp,"Acest top nu exista!\n");
                    sqlite3_finalize(capat);
                    sqlite3_close(Data_base);
                } 
            }
        } else {

            printf("Introduceti un gen.\n");
            bzero(msgrasp,D_MAX);
            strcat(msgrasp,"Introduceti un gen.\n");

        }

    } else {
        printf("Logativa.\n");
        strcat(msgrasp,"Mai intai logativa!\n");
    }

}

void MyAdd(){
    if(login==1){
        sqlite3 *Data_base;
        char *Error_message = 0;
        int command;
        char *query;
        sqlite3_stmt *capat;
        voturi=0;
        ID=0;

        command = sqlite3_open("./Server/TopMusic.db",&Data_base);

        if(command){
            fprintf(stderr, "Nu s-a putut deschide baza de date: %s.\n", sqlite3_errmsg(Data_base));
        } else {
            fprintf(stderr, "Am deschis cu succes baza de date.\n");
        }

        query = "SELECT * from Melodii where ID is not null order by ID asc;";
        
        command = sqlite3_prepare_v2(Data_base,query,-1,&capat,NULL );
        // printf("[%d]\n", command);
        if(command != SQLITE_OK){
            printf("Eroare!\n");
            bzero(msgrasp,D_MAX);
            strcat(msgrasp,"Eroare. Rencercati. \n");
        }

        while(command != SQLITE_DONE){
            
            command = sqlite3_step(capat);

            if(command != SQLITE_ROW)
                break;

            int temp;

            temp = sqlite3_column_int(capat,0);
            
            ID = temp;
        }

        ID++;

        // printf("ID IS: %d\n", ID);
        sqlite3_finalize(capat);

        query = "SELECT * from Melodii where Nume=? and Gen=?;";

        sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);

        sqlite3_bind_text(capat,1,nume_melodie,strlen(nume_melodie), SQLITE_STATIC);
        sqlite3_bind_text(capat,2,gen_melodie,strlen(gen_melodie), SQLITE_STATIC);

        if(sqlite3_step(capat) == SQLITE_ROW){
            printf("Am gasit acesta melodie: %s %s \n", nume_melodie,gen_melodie);
            fflush(stdout);
            strcat(msgrasp,"Aceasta melodie exista deja in acest top.\n");
            sqlite3_finalize(capat);
            sqlite3_close(Data_base);
        } else {
            sqlite3_finalize(capat);
            query="INSERT INTO Melodii (ID,Nume,Descriere,Gen,Voturi,URL) " \
                    "VALUES (?,?,?,?,?,?);";

            sqlite3_prepare_v2(Data_base,query,-1,&capat, SQLITE_OK);

            sqlite3_bind_int(capat,1,ID);
            sqlite3_bind_text(capat,2,nume_melodie,strlen(nume_melodie), SQLITE_STATIC);
            sqlite3_bind_text(capat,3,descriere_melodie,strlen(descriere_melodie), SQLITE_STATIC);
            sqlite3_bind_text(capat,4,gen_melodie,strlen(gen_melodie), SQLITE_STATIC);
            sqlite3_bind_int(capat,5,voturi);
            sqlite3_bind_text(capat,6,URL_melodie,strlen(URL_melodie), SQLITE_STATIC);


            if(sqlite3_step(capat) == SQLITE_DONE){
                printf("Am adaugat acesta melodie: %s\n", nume_melodie);
                fflush(stdout);
                strcat(msgrasp,"Am adaugat acesta melodie.\n");
                sqlite3_finalize(capat);
                sqlite3_close(Data_base);
            } else {
                fprintf(stderr, " A aparut o eroare la register:  %s\n",Error_message );
                bzero(msgrasp,D_MAX);
                strcat(msgrasp,"Eroare la adaugare.\n");
                sqlite3_finalize(capat);
                sqlite3_close(Data_base);
            }
        }
    } else {
        printf("Logati-va\n");
        bzero(msgrasp,D_MAX);
        strcat(msgrasp,"Nu sunteti logat. Logati-va!");
    }
       
}

void MyComment(){

    if(login==1){

        sqlite3 *Data_base;
        char *Error_message = 0;
        int command;
        char *query;
        sqlite3_stmt *capat;
        voturi=0;
        ID=0;

        command = sqlite3_open("./Server/TopMusic.db",&Data_base);

        if(command){
            fprintf(stderr, "Nu s-a putut deschide baza de date: %s.\n", sqlite3_errmsg(Data_base));
        } else {
            fprintf(stderr, "Am deschis cu succes baza de date.\n");
        }

        query = "SELECT * from Melodii where Nume=? and Gen=?;";

        sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);

        sqlite3_bind_text(capat,1,nume_melodie,strlen(nume_melodie),SQLITE_STATIC);
        sqlite3_bind_text(capat,2,gen_melodie,strlen(gen_melodie),SQLITE_STATIC);

        if(sqlite3_step(capat) == SQLITE_ROW){

            //TREBUIE ADAUGAT COMENTARIUL
            ID = sqlite3_column_int(capat,0);

            // printf("ID: %d\n", ID);
            sqlite3_finalize(capat);
            query = "INSERT INTO Comentarii(ID,Username,Comentariu)" \
                    "VALUES(?,?,?);";

            sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);

            sqlite3_bind_int(capat,1,ID);

            sqlite3_bind_text(capat,2,username1,strlen(username1),SQLITE_STATIC);
            sqlite3_bind_text(capat,3,comentariu,strlen(comentariu),SQLITE_STATIC);

            if(sqlite3_step(capat) == SQLITE_DONE){

                printf("Comentariu adaugat.\n");
                bzero(msgrasp,D_MAX);
                strcat(msgrasp,"Ati comentat la aceasta melodie.\n");
                sqlite3_finalize(capat);
                sqlite3_close(Data_base);

            } else {

                printf("Nu a fost adaugat acest comentariu.\n");
                bzero(msgrasp,D_MAX);
                strcat(msgrasp,"Nu a fost adaugat acest comentariu.\n");
                sqlite3_finalize(capat);
                sqlite3_close(Data_base);   
            }

        } else {

            printf("Nu am gasit aceasta melodie.\n");
            bzero(msgrasp,D_MAX);
            strcat(msgrasp,"Nu am gasit aceasta melodie.\n");
            sqlite3_finalize(capat);
            sqlite3_close(Data_base);
        }
    } else {
        printf("Logativa!\n");
        bzero(msgrasp,D_MAX);
        strcat(msgrasp,"Nu sunteti logat. Logati-va!");
    }
    
}

void MyBlockvote(){
    if(login==1){
        if(strcmp(user_type1,"admin")==0 || strcmp(user_type1,"owner")==0){
            sqlite3 *Data_base;
            char *Error_message = 0;
            int command;
            char *query;
            sqlite3_stmt *capat;
            voturi=0;
            ID=0;

            command = sqlite3_open("./Server/TopMusic.db",&Data_base);

            if(command){
                fprintf(stderr, "Nu s-a putut deschide baza de date: %s.\n", sqlite3_errmsg(Data_base));
            } else {
                fprintf(stderr, "Am deschis cu succes baza de date.\n");
            }

            query = "SELECT * from Conturi where Username=?;";

            command = sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);

            sqlite3_bind_text(capat,1,username2,strlen(username2),SQLITE_STATIC);

            if(sqlite3_step(capat) == SQLITE_ROW){

                if(strcmp(username1,username2)!=0){
                    bzero(user_type2,5);
                    const char * aux2=(const char*)sqlite3_column_text(capat,2);
                    strcat(user_type2,aux2);
                    if(strcmp(user_type1,"owner")==0){

                        sqlite3_finalize(capat);
                        query = "UPDATE Conturi set Drept_vot=0 where Username=?;";
                
                        command = sqlite3_prepare_v2(Data_base,query,-1,&capat,NULL);
                
                        sqlite3_bind_text(capat, 1, username2 , strlen(username2), SQLITE_STATIC);
                    
                        command=sqlite3_step(capat);
                    
                        if(command == SQLITE_DONE){

                            printf("Totul este ok.\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Ati blocat dreptul acestui user.\n");
                    
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);
                        
                        } else {

                            printf("Eroare MyBlockvote\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Eroare de blocare.\n");
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);                            

                        }
                    } else if(strcmp(user_type1,"admin")==0 && strcmp(user_type2,"user")==0) {
                        sqlite3_finalize(capat);
                        query = "UPDATE Conturi set Drept_vot=0 where Username=?;";
                
                        command = sqlite3_prepare_v2(Data_base,query,-1,&capat,NULL);
                
                        sqlite3_bind_text(capat, 1, username2 , strlen(username2), SQLITE_STATIC);
                    
                        command=sqlite3_step(capat);
                    
                        if(command == SQLITE_DONE){

                            printf("Totul este ok.\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Ati blocat dreptul acestui user.\n");
                    
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);
                        
                        } else {

                            printf("Eroare MyBlockvote\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Eroare de blocare.\n");
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);                            

                        }
                    } else {
                        printf("PROBLEME.\n");
                        bzero(msgrasp,D_MAX);
                        strcat(msgrasp,"Nu puteti bloca acest drept.\n");
                        sqlite3_finalize(capat);
                        sqlite3_close(Data_base);
                    }

                } else {

                    printf("Nu puteti sa va blocati drepturile.\n");
                    bzero(msgrasp,D_MAX);
                    strcat(msgrasp,"Nu puteti sa va blocati drepturile.\n");

                    sqlite3_finalize(capat);
                    sqlite3_close(Data_base);
                }

            } else {
                printf("Nu am gasit acest user.\n");
                bzero(msgrasp,D_MAX);
                strcat(msgrasp,"Nu am gasit acest user.\n");
                sqlite3_finalize(capat);
                sqlite3_close(Data_base);
            }
        } else {
            printf("ESIT USER. \n");
            bzero(msgrasp,D_MAX);
            strcat(msgrasp,"Nu aveti dreptul sa stergeti acest drept.\n");
        }
    } else {
        printf("Logativa. \n");
        bzero(msgrasp,D_MAX);
        strcat(msgrasp,"Nu sunteti logat. Lovativa va rog.\n");
    }
        
}

void MyUnblockvote(){
    if(login==1){
        if(strcmp(user_type1,"admin")==0 || strcmp(user_type1,"owner")==0){
            sqlite3 *Data_base;
            char *Error_message = 0;
            int command;
            char *query;
            sqlite3_stmt *capat;
            voturi=0;
            ID=0;

            command = sqlite3_open("./Server/TopMusic.db",&Data_base);

            if(command){
                fprintf(stderr, "Nu s-a putut deschide baza de date: %s.\n", sqlite3_errmsg(Data_base));
            } else {
                fprintf(stderr, "Am deschis cu succes baza de date.\n");
            }

            query = "SELECT * from Conturi where Username=?;";

            command = sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);

            sqlite3_bind_text(capat,1,username2,strlen(username2),SQLITE_STATIC);

            if(sqlite3_step(capat) == SQLITE_ROW){

                if(strcmp(username1,username2)!=0){
                    bzero(user_type2,5);
                    const char * aux2=(const char*)sqlite3_column_text(capat,2);
                    strcat(user_type2,aux2);
                    if(strcmp(user_type1,"owner")==0){

                        sqlite3_finalize(capat);
                        query = "UPDATE Conturi set Drept_vot=1 where Username=?;";
                
                        command = sqlite3_prepare_v2(Data_base,query,-1,&capat,NULL);
                
                        sqlite3_bind_text(capat, 1, username2 , strlen(username2), SQLITE_STATIC);
                    
                        command=sqlite3_step(capat);
                    
                        if(command == SQLITE_DONE){

                            printf("Totul este ok.\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Ati deblocat dreptul acestui user.\n");
                    
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);
                        
                        } else {

                            printf("Eroare MyBlockvote\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Eroare de blocare.\n");
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);                            

                        }
                    } else if(strcmp(user_type1,"admin")==0 && strcmp(user_type2,"user")==0) {
                        sqlite3_finalize(capat);
                        query = "UPDATE Conturi set Drept_vot=1 where Username=?;";
                
                        command = sqlite3_prepare_v2(Data_base,query,-1,&capat,NULL);
                
                        sqlite3_bind_text(capat, 1, username2 , strlen(username2), SQLITE_STATIC);
                    
                        command=sqlite3_step(capat);
                    
                        if(command == SQLITE_DONE){

                            printf("Totul este ok.\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Ati deblocat dreptul acestui user.\n");
                    
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);
                        
                        } else {

                            printf("Eroare MyBlockvote\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Eroare de deblocare.\n");
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);                            

                        }
                    } else {
                        printf("PROBLEME.\n");
                        bzero(msgrasp,D_MAX);
                        strcat(msgrasp,"Nu puteti debloca acest drept.\n");
                        sqlite3_finalize(capat);
                        sqlite3_close(Data_base);
                    }

                } else {

                    printf("Nu puteti sa va deblocati drepturile.\n");
                    bzero(msgrasp,D_MAX);
                    strcat(msgrasp,"Nu puteti sa va deblocati drepturile.\n");

                    sqlite3_finalize(capat);
                    sqlite3_close(Data_base);
                }

            } else {
                printf("Nu am gasit acest user.\n");
                bzero(msgrasp,D_MAX);
                strcat(msgrasp,"Nu am gasit acest user.\n");
                sqlite3_finalize(capat);
                sqlite3_close(Data_base);
            }
        } else {
            printf("ESIT USER. \n");
            bzero(msgrasp,D_MAX);
            strcat(msgrasp,"Nu aveti dreptul sa stergeti acest drept.\n");
        }
    } else {
        printf("Logativa. \n");
        bzero(msgrasp,D_MAX);
        strcat(msgrasp,"Nu sunteti logat. Lovativa va rog.\n");
    }
        
}

void MyRemove(){

    if(login==1){   
        // printf("[%s]\n", user_type1);
        if(strcmp(user_type1,"admin")==0 || strcmp(user_type1,"owner")==0){
            sqlite3 *Data_base;
            char *Error_message = 0;
            int command;
            char *query;
            sqlite3_stmt *capat;
            voturi=0;
            ID=0;
        
            command = sqlite3_open("./Server/TopMusic.db",&Data_base);
        
            if(command){
                fprintf(stderr, "Nu s-a putut deschide baza de date: %s.\n", sqlite3_errmsg(Data_base));
            } else {
                fprintf(stderr, "Am deschis cu succes baza de date.\n");
            }
        
            query = "SELECT * from Melodii where Nume=?;";
        
            command = sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);
        
            sqlite3_bind_text(capat,1,nume_melodie,strlen(nume_melodie),SQLITE_STATIC);
        
            if(sqlite3_step(capat) == SQLITE_ROW){
                sqlite3_finalize(capat);
                query = "SELECT * from Melodii where Gen=?;";
        
                command = sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);
                sqlite3_bind_text(capat,1,gen_melodie,strlen(gen_melodie),SQLITE_STATIC);
        
                if(sqlite3_step(capat) == SQLITE_ROW){
                    sqlite3_finalize(capat);
                    query = "DELETE from Melodii where Nume=? and Gen=?;";
        
                    command=sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);
                    sqlite3_bind_text(capat,1,nume_melodie,strlen(nume_melodie),SQLITE_STATIC);
                    sqlite3_bind_text(capat,2,gen_melodie,strlen(gen_melodie),SQLITE_STATIC);
        
                    command = sqlite3_step(capat);
                    bzero(msgrasp,D_MAX);
                    printf("melodie stersa.\n");
                    strcat(msgrasp,"melodie stersa.\n");   
                    sqlite3_finalize(capat);
                    sqlite3_close(Data_base);
        
                } else {
        
                    printf("Nu se afla in cest top.\n");
                    bzero(msgrasp,D_MAX);
                    strcat(msgrasp,"Aceasta melodie exista dar nu se afla in acest top.\n");
                    sqlite3_finalize(capat);
                    sqlite3_close(Data_base);
                }
        
            } else {

                printf("Nu exista.\n");
                bzero(msgrasp,D_MAX);
                strcat(msgrasp,"Aceasta melodie nu exista.\n");
                sqlite3_finalize(capat);
                sqlite3_close(Data_base);

            }
        } else {

            printf("ESIT USER. \n");
            bzero(msgrasp,D_MAX);
            strcat(msgrasp,"Nu aveti dreptul sa stergeti o melodie.\n");

        }
    } else {

        printf("Logativa. \n");
        bzero(msgrasp,D_MAX);
        strcat(msgrasp,"Nu sunteti logat. Lovativa va rog.\n");

    }

}

void MyBann(){

    if(login==1){

        if(strcmp(user_type1,"admin")==0 || strcmp(user_type1,"owner")==0){

            if(strcmp(username1,username2)!=0){

                sqlite3 *Data_base;
                char *Error_message = 0;
                int command;
                char *query;
                sqlite3_stmt *capat;
                voturi=0;
                ID=0;
                    
                command = sqlite3_open("./Server/TopMusic.db",&Data_base);
                    
                if(command){
                    fprintf(stderr, "Nu s-a putut deschide baza de date: %s.\n", sqlite3_errmsg(Data_base));
                } else {
                    fprintf(stderr, "Am deschis cu succes baza de date.\n");
                }
                
                query = "SELECT * from Conturi where Username=?;";
                    
                command = sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);
                    
                sqlite3_bind_text(capat,1,username2,strlen(username2),SQLITE_STATIC);
            
                    
                if(sqlite3_step(capat) == SQLITE_ROW){
                    
                    const char *temp = (const char *)sqlite3_column_text(capat,2);
                    bzero(user_type2,5);
                    strcat(user_type2,temp);
                            // printf("usr: [%s]\n", user_type2);
                    if(strcmp(user_type1,"owner")==0){
                        sqlite3_finalize(capat);
                        query = "UPDATE Conturi set Banat=1 where Username=?;";
                                
                        command = sqlite3_prepare_v2(Data_base,query,-1,&capat,NULL);
                            
                        sqlite3_bind_text(capat, 1, username2 , strlen(username2), SQLITE_STATIC);
                                
                        command=sqlite3_step(capat);
            
                        if(command == SQLITE_DONE){
                                    
                            printf("Banat!\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Ati banat acest user.\n");
                                
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);
            
                        } else {
            
                            printf("Problema Bann.\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Eroare la Bann.\n");
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);
                                    
                        }
                    } else if(strcmp(user_type2,"admin")==0 || strcmp(user_type2,"owner")==0){
                        printf("Nu puteti aplica aceasta comanda unui admin sau ownerului.\n");
                        bzero(msgrasp,D_MAX);
                        strcat(msgrasp,"Nu puteti aplica acesta comanda unui admin sau ownerului.\n");
                    } else {
                        sqlite3_finalize(capat);
                        query = "UPDATE Conturi set Banat=1 where Username=?;";
                                
                        command = sqlite3_prepare_v2(Data_base,query,-1,&capat,NULL);
                            
                        sqlite3_bind_text(capat, 1, username2 , strlen(username2), SQLITE_STATIC);
                                
                        command=sqlite3_step(capat);
            
                        if(command == SQLITE_DONE){
                                    
                            printf("Banat!\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Ati banat acest user.\n");
                                
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);
            
                        } else {
            
                            printf("Problema Bann.\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Eroare la Bann.\n");
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);
                                    
                        }
                    }
                } else {
                    printf("Nu am gasit aces user.\n");
                    bzero(msgrasp,D_MAX);
                    strcat(msgrasp,"Nu am gasit aces user.\n");
                    sqlite3_finalize(capat);
                    sqlite3_close(Data_base);
                }
            } else {

                printf("Nu puteti sa va banati propriul cont.\n");
                bzero(msgrasp,D_MAX);
                strcat(msgrasp,"Nu puteti sa va banati propriul cont.\n");

            }
        } else {
            
            printf("Nu este admin\n");
            bzero(msgrasp,D_MAX);
            strcat(msgrasp,"Nu aveti deptul sa folositi aceasta comanda.\n");
        }

    } else {
        printf("Mai intai logati-va.\n");
        bzero(msgrasp,D_MAX);
        strcat(msgrasp,"Mai intai logati-va.\n");
    }

}

void MyUnbann(){

    if(login==1){

        if(strcmp(user_type1,"admin")==0 || strcmp(user_type1,"owner")==0){

            if(strcmp(username1,username2)!=0){
                sqlite3 *Data_base;
                char *Error_message = 0;
                int command;
                char *query;
                sqlite3_stmt *capat;
                voturi=0;
                ID=0;
        
                command = sqlite3_open("./Server/TopMusic.db",&Data_base);
        
                if(command){
                    fprintf(stderr, "Nu s-a putut deschide baza de date: %s.\n", sqlite3_errmsg(Data_base));
                } else {
                    fprintf(stderr, "Am deschis cu succes baza de date.\n");
                }
        
                query = "SELECT * from Conturi where Username=?;";
        
                command = sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);
        
                sqlite3_bind_text(capat,1,username2,strlen(username2),SQLITE_STATIC);

        
                if(sqlite3_step(capat) == SQLITE_ROW){
        
                    const char *temp = (const char *)sqlite3_column_text(capat,2);
                    bzero(user_type2,5);
                    strcat(user_type2,temp);
                    if(strcmp(user_type1,"owner")==0){
                        sqlite3_finalize(capat);
                        query = "UPDATE Conturi set Banat=0 where Username=?;";
                                
                        command = sqlite3_prepare_v2(Data_base,query,-1,&capat,NULL);
                            
                        sqlite3_bind_text(capat, 1, username2 , strlen(username2), SQLITE_STATIC);
                                
                        command=sqlite3_step(capat);
            
                        if(command == SQLITE_DONE){
                                    
                            printf("Debanat!\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Ati debanat acest user.\n");
                                
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);
            
                        } else {
            
                            printf("Problema Unbann.\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Eroare la Unbann.\n");
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);
                                    
                        }
                    } else if(strcmp(user_type2,"admin")==0 || strcmp(user_type2,"owner")==0){
                        printf("Nu puteti aplica ecasta comanda unui admin sau ownerului.\n");
                        bzero(msgrasp,D_MAX);
                        strcat(msgrasp,"Nu puteti aplica ecasta comanda unui admin sau ownerului.\n");
                    } else {
                        sqlite3_finalize(capat);
                        query = "UPDATE Conturi set Banat=0 where Username=?;";
                    
                        command = sqlite3_prepare_v2(Data_base,query,-1,&capat,NULL);
                
                        sqlite3_bind_text(capat, 1, username2 , strlen(username2), SQLITE_STATIC);
                    
                        command=sqlite3_step(capat);

                        if(command == SQLITE_DONE){
                        
                            printf("Debanat!\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Ati deblocat acest user.\n");
                    
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);

                        } else {

                            printf("Problema Unbann.\n");
                            bzero(msgrasp,D_MAX);
                            strcat(msgrasp,"Eroare la Unbann.\n");
                            sqlite3_finalize(capat);
                            sqlite3_close(Data_base);
                        
                        }
                    }
                } else {
                    printf("Nu am gasit aces user.\n");
                    bzero(msgrasp,D_MAX);
                    strcat(msgrasp,"Nu am gasit aces user.\n");
                    sqlite3_finalize(capat);
                    sqlite3_close(Data_base);
                }
            } else {
                printf("Nu puteti aplica acesta comanda propriului cont.\n");
                bzero(msgrasp,D_MAX);
                strcat(msgrasp,"Nu puteti aplica acesta comanda propriului cont.\n");
            }
            
        } else {

            printf("Nu este admin\n");
            bzero(msgrasp,D_MAX);
            strcat(msgrasp,"Nu aveti deptul sa folositi aceasta comanda.\n");
        }

    } else {
        printf("Mai intai logati-va.\n");
        bzero(msgrasp,D_MAX);
        strcat(msgrasp,"Mai intai logati-va.\n");
    }

}

void MyLogout(){

    if(login==1){

        sqlite3 *Data_base;
        char *Error_message = 0;
        int command;
        char *query;
        sqlite3_stmt *capat;

        command = sqlite3_open("./Server/TopMusic.db",&Data_base);

        if(command){
            fprintf(stderr, "Nu am deschis baza de date.%s\n", sqlite3_errmsg(Data_base));
        } else {
            fprintf(stderr, "Am deschis cu succes baza de date.\n");
        }

        query = "UPDATE Logat set Login=0 where Username=?;";

        command = sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);
        sqlite3_bind_text(capat,1,username1,strlen(username1),SQLITE_STATIC);
        command = sqlite3_step(capat);
        if(sqlite3_step(capat) == SQLITE_DONE){

            bzero(username1,15);
            bzero(password1,15);
            bzero(user_type1,5);
            login=0;
            logat=0;
            drept_vot=0;
            drept_sterge=0;
            banat=0;
            printf("Ati fost delogat.\n");
            bzero(msgrasp,D_MAX);
            strcat(msgrasp,"Ati fost delogat.\n");
            sqlite3_finalize(capat);
            sqlite3_close(Data_base);

        } else {
            printf("Problema.\n");
            bzero(msgrasp,D_MAX);
            strcat(msgrasp,"problema.\n");
            sqlite3_finalize(capat);
            sqlite3_close(Data_base);
        }
    } else {
        printf("Logati-va\n");
        bzero(msgrasp,D_MAX);
        strcat(msgrasp,"Mai intai logati-va.\n");
    }

}

void AddHistoric(){
    if(login==1){

        sqlite3 *Data_base;
        char *Error_message = 0;
        int command;
        char *query;
        sqlite3_stmt *capat;

        command = sqlite3_open("./Server/TopMusic.db",&Data_base);
        if(command){
            fprintf(stderr, "Nu am deschis baza de date.%s\n", sqlite3_errmsg(Data_base));
        } else {
            fprintf(stderr, "Am deschis cu succes baza de date.\n");
        }

        query = "INSERT INTO Istoric (Username,Comanda) " \
                "VALUES(?,?);";

        sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);
        sqlite3_bind_text(capat,1,username1,strlen(username1),SQLITE_STATIC);
        sqlite3_bind_text(capat,2,comanda,strlen(comanda),SQLITE_STATIC);

        if(sqlite3_step(capat) == SQLITE_DONE){
            // int i=0;
            // while(i<1000000000){
            //     i++;
            // }
            printf("Istoric actualizat.\n");
            fflush(stdout);
            sqlite3_finalize(capat);
            sqlite3_close(Data_base);

        } else {

            printf("Probleme la adaugarea comenzii.\n");
            fflush(stdout);
            sqlite3_finalize(capat);
            sqlite3_close(Data_base);
        }

    } else {
        printf("Nu am salvat!\n");
        fflush(stdout);
    }

}

void MyHistoric(){
    if(login==1){
        // printf("[%s]\n", username1);
        sqlite3 *Data_base;
        char *Error_message = 0;
        int command;
        char *query;
        sqlite3_stmt *capat;

        command = sqlite3_open("./Server/TopMusic.db",&Data_base);
        if(command){
            fprintf(stderr, "Nu am deschis baza de date.%s\n", sqlite3_errmsg(Data_base));
        } else {
            fprintf(stderr, "Am deschis cu succes baza de date.\n");
        }
        // printf("1\n");
        query = "SELECT * from Istoric where Username=?;";

        sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);
        // printf("1\n");
        sqlite3_bind_text(capat,1,username1,strlen(username1),SQLITE_STATIC);
        // printf("1\n");
        bzero(msgrasp,D_MAX);
        // printf("1\n");
        strcat(msgrasp,"\t->");
        // printf("1\n");
        strcat(msgrasp,username1);
        // printf("1\n");
        strcat(msgrasp,"<-\n");
        // printf("1\n");
        while(1){
            command = sqlite3_step(capat);
            // printf("2\n");
            if(command == SQLITE_DONE){
                break;
            }
            // printf("3\n");
            if(command != SQLITE_ROW){
                printf("Ceva ciudat.\n");
                bzero(msgrasp,D_MAX);
                strcat(msgrasp,"Problema la cautare.\n");
                sqlite3_finalize(capat);
                sqlite3_close(Data_base);
            }
            // printf("4\n");
            const char *text=(const char*)sqlite3_column_text(capat,1);
            strcat(msgrasp,text);
            strcat(msgrasp,"\n");
            // printf("5\n");
        }
        sqlite3_finalize(capat);
        sqlite3_close(Data_base);

    } else {
        printf("Logati-va!\n");
        fflush(stdout);
        bzero(msgrasp,D_MAX);
        strcat(msgrasp,"Mai intai logati-va!\n");
    }

}

void actualizare_blockvote(){
    sqlite3 *Data_base;
    char *Error_message = 0;
    int command;
    char *query;
    sqlite3_stmt *capat;

    command = sqlite3_open("./Server/TopMusic.db",&Data_base);
    if(command){
        fprintf(stderr, "Nu am deschis baza de date.%s\n", sqlite3_errmsg(Data_base));
    } else {
        fprintf(stderr, "Am deschis cu succes baza de date.\n");
    }

    query = "SELECT * from Conturi where Username=? and Password=?;";

    sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);

    sqlite3_bind_text(capat,1,username1,strlen(username1),SQLITE_STATIC);
    sqlite3_bind_text(capat,2,password1,strlen(password1),SQLITE_STATIC);

    if(sqlite3_step(capat) == SQLITE_ROW){

        drept_vot = sqlite3_column_int(capat,3);
        printf("[%d]\n", drept_vot);
        sqlite3_finalize(capat);
        sqlite3_close(Data_base);

    } else {
        printf("Problema la actualizare.\n");
        sqlite3_finalize(capat);
        sqlite3_close(Data_base);
    }

}

void actualizare_bann(){
    sqlite3 *Data_base;
    char *Error_message = 0;
    int command;
    char *query;
    sqlite3_stmt *capat;

    command = sqlite3_open("./Server/TopMusic.db",&Data_base);
    if(command){
        fprintf(stderr, "Nu am deschis baza de date.%s\n", sqlite3_errmsg(Data_base));
    } else {
        fprintf(stderr, "Am deschis cu succes baza de date.\n");
    }

    query = "SELECT * from Conturi where Username=? and Password=?;";

    sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);

    sqlite3_bind_text(capat,1,username1,strlen(username1),SQLITE_STATIC);
    sqlite3_bind_text(capat,2,password1,strlen(password1),SQLITE_STATIC);

    if(sqlite3_step(capat) == SQLITE_ROW){
        banat = sqlite3_column_int(capat,5);
        printf("[%d]\n", banat);
        sqlite3_finalize(capat);
        sqlite3_close(Data_base);
    } else {
        printf("Problema la actualizare.\n");
        sqlite3_finalize(capat);
        sqlite3_close(Data_base);
    }

}

void MyReport(){
    if(login==1){
        // if(strcmp(user_type1,"admin")==0 || strcmp(user_type1,"owner")==0 || strcmp(user_type1,"user")==0) {
            sqlite3 *Data_base;
            char *Error_message = 0;
            int command;
            char *query;
            sqlite3_stmt *capat;

            command = sqlite3_open("./Server/TopMusic.db",&Data_base);
            if(command){
                fprintf(stderr, "Nu am deschis baza de date.%s\n", sqlite3_errmsg(Data_base));
            } else {
                fprintf(stderr, "Am deschis cu succes baza de date.\n");
            }
            // printf("1\n");
            query = "SELECT * from Conturi where Username=?;";

            command=sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);
            // printf("1\n");
            // printf("[%d]\n", command);
            sqlite3_bind_text(capat,1,username2,strlen(username2),SQLITE_STATIC);

            if(sqlite3_step(capat) == SQLITE_ROW){

                bzero(user_type2,5);
                // user_type2 = sqlite3_column_int(capat,2);
                if(strcmp(user_type2,"owner")==0){

                    printf("Este owner.\n");
                    bzero(msgrasp,D_MAX);
                    strcat(msgrasp,"Acesta este ownerul si nu poatefi raportat.\n");
                    sqlite3_finalize(capat);
                    sqlite3_close(Data_base);

                } else {

                    sqlite3_finalize(capat);
                    query = "INSERT INTO Raporturi(Sursa,Vinovat,Motiv)" \
                            "VALUES(?,?,?);";
                    command = sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);
                    
                    sqlite3_bind_text(capat,1,username1,strlen(username1),SQLITE_STATIC);
                    sqlite3_bind_text(capat,2,username2,strlen(username2),SQLITE_STATIC);
                    sqlite3_bind_text(capat,3,motiv,strlen(motiv),SQLITE_STATIC);

                    command = sqlite3_step(capat);
                    if(command = SQLITE_DONE){
                        printf("Adaugat!\n");
                        bzero(msgrasp,D_MAX);
                        strcat(msgrasp,"Ati raportat acest user.\n");
                        sqlite3_finalize(capat);
                        sqlite3_close(Data_base);
                    }
                }
            } else {
                printf("Negasit.\n");
                bzero(msgrasp,D_MAX);
                strcat(msgrasp,"Nu am gasit acest user.\n");
                sqlite3_finalize(capat);
                sqlite3_close(Data_base);
            }
        // } else {
            // printf("Nu este admin/owner.\n");
            // bzero(msgrasp,D_MAX);
            // strcat(msgrasp,"Nu aveti dreptul sa raportati.\n");
        // }
    } else {
        printf("Logati-va!\n");
        bzero(msgrasp,D_MAX);
        strcat(msgrasp,"Mai intai logati-va!\n");
    }

}

void MySeereport(){
    if(login==1){
        if(strcmp(user_type1,"owner")==0){
            // printf("OK!\n");
            sqlite3 *Data_base;
            char *Error_message = 0;
            int command;
            char *query;
            sqlite3_stmt *capat;

            command = sqlite3_open("./Server/TopMusic.db",&Data_base);
            if(command){
                fprintf(stderr, "Nu am deschis baza de date.%s\n", sqlite3_errmsg(Data_base));
            } else {
                fprintf(stderr, "Am deschis cu succes baza de date.\n");
            }
            // printf("1\n");
            query = "SELECT * from Raporturi where Vinovat=?;";

            command=sqlite3_prepare_v2(Data_base,query,-1,&capat,SQLITE_OK);
            // printf("1\n");
            // printf("[%d]\n", command);
            sqlite3_bind_text(capat,1,username2,strlen(username2),SQLITE_STATIC);

            if(command == SQLITE_OK){

                if(sqlite3_step(capat) == SQLITE_ROW){
                    bzero(msgrasp,D_MAX);
                    strcat(msgrasp,"\t\t");
                    strcat(msgrasp,username2);
                    strcat(msgrasp,"\n");
                    const char *text1 = (const char *)sqlite3_column_text(capat,2);
                    strcat(msgrasp,"\t->");
                    strcat(msgrasp,text1);
                    strcat(msgrasp,"\n");
                    while(sqlite3_step(capat)==SQLITE_ROW){

                        // command = ;

                        // if(command == SQLITE_DONE){
                        //     break;
                        // }
                        // if(command != SQLITE_ROW){
                        //     printf("Am obtinut ceva ciudat.\n");
                        //     strcat(msgrasp,"A aparut o problema in timpul cautarii.\n");
                        //     break;
                        // }
                        // if(command == SQLITE_ROW){

                            const char *text = (const char *)sqlite3_column_text(capat,2);
                            strcat(msgrasp,"\t->");
                            strcat(msgrasp,text);
                            strcat(msgrasp,"\n");
                        // }
                    }
                    sqlite3_finalize(capat);
                    sqlite3_close(Data_base);
                }

            } else {
                printf("Probleme!.\n");
                bzero(msgrasp,D_MAX);
                strcat(msgrasp,"Reincercati comanda!\n");
                sqlite3_finalize(capat);
                sqlite3_close(Data_base);
            }

        } else {
            printf("Nu este owner.\n");
            bzero(msgrasp,D_MAX);
            strcat(msgrasp,"Aceasta comanda poate fi folosita doar de catre owner.\n");
        }
    } else {
        printf("Logati-va\n");
        bzero(msgrasp,D_MAX);
        strcat(msgrasp,"Logati-va pentru a folosi acesta comanda.\n");
    }

}