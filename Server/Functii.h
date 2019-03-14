
#include "Manual.h"
void analiza_comanda(char mesaj[D_MAX]){
    bzero(comanda,D_MAX);
    bzero(msgrasp,D_MAX);
    int lungime=strlen(mesaj);
    int i=0,j=0;
    // printf("MSG: [%s]\n", mesaj);
    if(strncmp(mesaj,"login",5) == 0){
        bzero(username1,15);
        bzero(password1,15);
        while(mesaj[i]!=' ' && i<lungime){
            comanda[i]=mesaj[i];
            i++;
        }
        i++;
        while(mesaj[i]!=':' && i<lungime){
            username1[j]=mesaj[i];
            i++;
            j++;
        }
        i++;
        j=0;
        while(i<lungime){
            password1[j]=mesaj[i];  
            i++;
            j++;
        }
    }
    if(strncmp(mesaj,"register",8) == 0){
        bzero(user_type1,5);
        bzero(username1,15);
        bzero(password1,15);
        while(mesaj[i]!=' ' && i<lungime && i<lungime){
            comanda[i]=mesaj[i];
            i++;
        }
        i++;
        while(mesaj[i]!=':' && i<lungime && i<lungime){
            username1[j]=mesaj[i];
            i++;
            j++;
        }
        i++;
        j=0;
        while(mesaj[i]!=':' && i<lungime){
            password1[j]=mesaj[i];
            i++;
            j++;
        }
        i++;
        j=0;
        while(i<lungime){
            user_type1[j]=mesaj[i];
            i++;
            j++;
        }
    }
    if(strncmp(mesaj,"add",3) == 0){
        bzero(nume_melodie,30);
        bzero(descriere_melodie,100);
        bzero(gen_melodie,20);
        bzero(URL_melodie,40);
        bzero(comanda,D_MAX);
        while(mesaj[i]!=' ' && i<lungime){
            comanda[i]=mesaj[i];
            i++;
        }
        i++;
        while(mesaj[i]!=':' && i<lungime){
            nume_melodie[j]=mesaj[i];
            i++;
            j++;
        }
        i++;
        j=0;
        while(mesaj[i]!=':' && i<lungime){
            descriere_melodie[j]=mesaj[i];
            i++;
            j++;
        }
        i++;
        j=0;
        while(mesaj[i]!=':' && i<lungime){
            gen_melodie[j]=mesaj[i];
            i++;
            j++;
        }
        i++;
        j=0;
        while(i<lungime){
            URL_melodie[j]=mesaj[i];
            i++;
            j++;
        }
    }
    if(strncmp(mesaj,"list",4) == 0 ){
        bzero(top,20);
        while(mesaj[i]!=' ' && i<lungime)
        {
            comanda[i]=mesaj[i];
            i++;
        }
        i++;
        while(i<lungime-1){
            top[j]=mesaj[i];
            i++;
            j++;
        }
        // printf("TOP: %s\n", top);
        // printf("LNG: %d\n", strlen(top));
    }
    if(strncmp(mesaj,"remove",6) == 0){
        bzero(nume_melodie,30);
        bzero(gen_melodie,20);
        bzero(comanda,D_MAX);
        while(mesaj[i]!=' ' && i<lungime){
            comanda[i]=mesaj[i];
            i++;
        }
        i++;
        j=0;
        while(mesaj[i]!=':' && i<lungime){
            nume_melodie[j]=mesaj[i];
            i++; j++;
        }
        j=0; i++;
        while(i<lungime){
            gen_melodie[j]=mesaj[i];
            i++; j++;
        }
    }
    if(strncmp(mesaj,"vote",4) == 0){
        bzero(nume_melodie,30);
        bzero(gen_melodie,20);
        while(mesaj[i]!=' ' && i<lungime){
            comanda[i]=mesaj[i];
            i++;
        }
        i++;
        while(mesaj[i]!=':' && i<lungime){
            nume_melodie[j]=mesaj[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(i<lungime-1){
            gen_melodie[j]=mesaj[i];
            i++;
            j++;
        }
    }
    if(strncmp(mesaj,"blockvote",9)==0 || strncmp(mesaj,"unblockvote",11)==0){
        bzero(username2,15);
        bzero(comanda,D_MAX);

        while(mesaj[i]!=' ' && i<lungime){
            comanda[i]=mesaj[i];
            i++;
        }
        i++;
        j=0;
        while(i<lungime){
            username2[j]=mesaj[i];
            i++;
            j++;
        }
    }
    if(strncmp(mesaj,"manual",6)==0){
        bzero(comanda,D_MAX);
        strcat(comanda,"manual");
    }
    if(strncmp(mesaj,"comment",7)==0){
        bzero(comanda,D_MAX);
        bzero(comentariu,150);
        bzero(nume_melodie,30);
        bzero(gen_melodie,20);
        while(mesaj[i] != ' ' && i<lungime){
            comanda[i]=mesaj[i];
            i++;
        }
        i++;
        while(mesaj[i] != ':' && i<lungime){
            nume_melodie[j]=mesaj[i];
            i++;
            j++;
        }
        // printf("NUME %s\n", nume_melodie);
        i++;
        j=0;
        while(mesaj[i] != ':' && i<lungime){
            gen_melodie[j]=mesaj[i];
            i++;
            j++;
        }
        i++;
        j=0;
        while(i<lungime){
            comentariu[j]=mesaj[i];
            i++;
            j++;
        }
    }
    if(strcmp(mesaj,"quit")==0 || strcmp(mesaj,"quit\n")==0 || strcmp(mesaj,"quit ")==0){
        bzero(comanda,D_MAX);
        strcat(comanda,"quit");
    }
    if(strncmp(mesaj,"bann",4)==0){
        bzero(username2,15);
        bzero(user_type2,5);
        while(mesaj[i]!=' ' && i<lungime){
            comanda[i]=mesaj[i];
            i++;
        }
        i++;
        j=0;
        while(i<lungime-1){
            username2[j]=mesaj[i];
            i++;
            j++;
        }
        // printf("[%s]\n", username2);
    }
    if(strncmp(mesaj,"unbann",6)==0){
        bzero(username2,15);
        bzero(user_type2,5);
        while(mesaj[i]!=' ' && i<lungime){
            comanda[i]=mesaj[i];
            i++;
        }
        i++;
        j=0;
        while(i<lungime-1){
            username2[j]=mesaj[i];
            i++;
            j++;
        }
    }
    if(strcmp(mesaj,"logout")==0 || strcmp(mesaj,"logout ")==0 || strcmp(mesaj,"logout\n")==0) {
        bzero(comanda,D_MAX);
        strcat(comanda,"logout");
    }
    if(strcmp(mesaj,"istoric")==0){
        bzero(comanda,D_MAX);
        strcat(comanda,"istoric");
    }
    if(strncmp(mesaj,"report",6)==0){
        bzero(username2,15);
        bzero(motiv,100);

        while(mesaj[i] != ' ' && i<lungime){
            comanda[i]=mesaj[i];
            i++;
        }
        i++;
        j=0;
        while(mesaj[i] != ':' && i<lungime){
            username2[j]=mesaj[i];
            i++;
            j++;
        }
        i++; j=0;
        while(i<lungime-1){
            motiv[j]=mesaj[i];
            i++;
            j++;
        }
    }
    if(strncmp(mesaj,"seereport",9)==0){
        bzero(username2,15);
        while(mesaj[i] != ' ' && i<lungime){
            comanda[i]=mesaj[i];
            i++;
        }
        i++; j=0;
        while(i<lungime-1){
            username2[j]=mesaj[i];
            i++;
        }
    }
    printf("COMM: [%s]\n", comentariu);
    printf("[%s]\n", nume_melodie);
    printf("[%s]\n", gen_melodie);
    printf("[%s]\n", URL_melodie);
    printf("[%s]\n", descriere_melodie);
    printf("[%s]\n", top);
    printf("[%s]\n", comentariu);
    printf("[%s]\n", username1);
    printf("[%s]\n", password1);
    printf("[%s]\n", user_type1);
    printf("[%s]\n", username2);
    printf("[%s]\n", motiv);
}

void executie_comenzi(){
    if(strcmp(comanda,"login")==0){
        MyLogin();
    } else if(strcmp(comanda,"register")==0){
        MyRegister();
    } else if(strcmp(comanda,"add")==0){
        MyAdd();
    } else if(strcmp(comanda,"manual")==0){
        bzero(msgrasp,D_MAX);
        MyManual();
    } else if(strcmp(comanda,"list")==0){
        MyList();
    } else if(strcmp(comanda,"vote")==0){
        MyVote();
    } else if(strncmp(comanda,"quit",4)==0){
        if(login==1) {   
            MyLogout();
            exit1=1;
            printf("Clientul s-a inchis!\n");
            fflush(stdout);
            strcat(msgrasp,"Inchidere realizata cu succes.\n");
            exit(0);
        } else {
            exit1=1;
            printf("Clientul s-a inchis!\n");
            fflush(stdout);
            strcat(msgrasp,"Inchidere realizata cu succes.\n");
            exit(0);
        }
    } else if(strcmp(comanda,"comment")==0) {
        MyComment();
    } else if(strcmp(comanda,"blockvote")==0) {
            MyBlockvote();
    } else if(strcmp(comanda,"remove")==0) {
            MyRemove();
    } else if(strcmp(comanda,"bann")==0) {
            MyBann();
    } else if(strcmp(comanda,"unbann")==0) {
            MyUnbann();
    } else if(strcmp(comanda,"logout")==0) {
            MyLogout();
    } else if(strcmp(comanda,"istoric")==0) {
            MyHistoric();
    } else if(strcmp(comanda,"unblockvote")==0) {
            MyUnblockvote();
    } else if(strcmp(comanda,"report")==0) {
            MyReport();
    } else if(strcmp(comanda,"seereport")==0) {
            MySeereport();
    } else {
        bzero(msgrasp,D_MAX);
        strcat(msgrasp,"Incercati alta comanda sau consultati manualul!\n");
    }
}
