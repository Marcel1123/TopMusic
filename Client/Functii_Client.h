#include "Readuri.h"


void login(){
  if(is_login==0){
    printf("In username si parola nu puteti folosi usrmatoarele caractere: \": , . ;\"\n");
    int lungime=strlen(tastatura);
    for (int i = 0; i < lungime-1; ++i)
    {
      argumente[i]=tastatura[i];
    }
    char usr[15];
    rusr1(usr);
    lungime=strlen(usr);
    bzero(usernames,15);
    strcat(usernames,usr);
    strcat(argumente," ");
    strcat(argumente,usernames);
    bzero(usr,15);
    rpass1(usr);
    strcat(argumente,":");
    strcat(argumente,usr);
  } else {
    printf("\t->Deja sunteti lojat.\n\t->Nu va puteti loga inca o data.\n");
  }
}

void MyRegister(){
  if(is_login==0)
    {  
      printf("In username, parola, user_type nu puteti folosi usrmatoarele caractere: \": , . ;\"\n");
      int lungime=strlen(tastatura);
      for(int i = 0; i < lungime-1;++i){
        argumente[i]=tastatura[i];
      }
      char usr[15];
      char types[5];
      char aux[15];

      bzero(aux,15);
      bzero(usr,15);

      rusr(usr);
      lungime=strlen(usr);
      for(int i=0;i<lungime;i++){
        aux[i]=usr[i];
      }
      strcat(argumente," ");
      strcat(argumente,aux);
      bzero(usr,15);

      rpass(usr);
      lungime=strlen(usr);
      bzero(aux,15);
      for(int i=0;i<lungime;i++){
        aux[i]=usr[i];
      }

      strcat(argumente,":");
      strcat(argumente,aux);
      bzero(usr,15);
      bzero(types,5);
      char aux1[5];
      rtype(types);
      lungime=strlen(types);
      bzero(aux1,5);
      for(int i=0;i<lungime;i++){
        aux1[i]=types[i];
      }
      strcat(argumente,":");
      strcat(argumente,aux1);
      printf("ARG: %s\n", argumente);
    }
  if(is_login==1){
    printf("Cat timp sunteti logat nu va puteti inregistra un alt cont. \n");
  }
}

void MyAdd(){
  if(is_login==1){
    bzero(argumente,D_MAX);
    int lungime=strlen(tastatura);
    for(int i = 0; i < lungime-1;++i){
      argumente[i]=tastatura[i];
    }
    printf("In nume,gen nu puteti folosi usrmatoarele caractere: \" : , . ; \"\n");
    printf("In descriere nu puteti folosi urmatorul caracter: \" : \"\n");
    char nume[30];
    char descriere[100];
    char gen[20];
    char URL[50];
    char aux1[30];
    char aux2[100];
    char aux3[20];
    char aux4[40];

    bzero(aux1,30);
    bzero(aux2,100);
    bzero(aux3,20);
    bzero(aux4,50);
    bzero(nume,30);
    bzero(descriere,100);
    bzero(gen,20);
    bzero(URL,40);

    rname(nume);
    lungime=strlen(nume);
    for(int i=0;i<lungime-1;i++){
      aux1[i]=nume[i];
    }
    strcat(argumente," ");
    strcat(argumente,aux1);
    bzero(aux1,30);

    rdescr(descriere);
    lungime=strlen(descriere);
    for(int i=0;i<lungime-1;i++){
      aux2[i]=descriere[i];
    }    strcat(argumente,":");
    strcat(argumente,aux2);
    bzero(aux2,100);

    rgen(gen);
    lungime=strlen(gen);
    for(int i=0;i<lungime-1;i++){
      aux3[i]=gen[i];
    }
    strcat(argumente,":");
    strcat(argumente,aux3);
    bzero(aux3,20);

    rURL(URL);
    lungime=strlen(URL);
    for(int i=0;i<lungime-1;i++){
      aux4[i]=URL[i];
    }
    strcat(argumente,":");
    strcat(argumente,aux4);
    bzero(aux4,40);

  } else {
      printf("TREBUIE sa fiti logat pentru a folosi aceasta comanda!\n");
  }
}

void MyComment(){
  if(is_login==1){
    
    bzero(argumente,D_MAX);
    int lungime=strlen(tastatura);
    for(int i = 0; i < lungime-1;++i){
      argumente[i]=tastatura[i];
    }

    char nume[30];
    char aux1[30];
    char gen[20];
    char aux3[20];
    bzero(gen,20);
    bzero(aux3,20);
    bzero(aux1,30);
    bzero(nume,30);
    rname(nume);
    lungime=strlen(nume);
    for(int i=0;i<lungime-1;i++){
      aux1[i]=nume[i];
    }
    strcat(argumente," ");
    strcat(argumente,aux1);
    bzero(aux1,30);
    bzero(comentariu,150);
    rgen(gen);
    lungime=strlen(gen);
    for (int i = 0; i < lungime-1; ++i)
    {
      aux3[i]=gen[i];
    }
    strcat(argumente,":");
    strcat(argumente,aux3);
    bzero(aux3,20);
    char aux2[150];
    bzero(aux2,150);
    rComment(comentariu);
    lungime=strlen(comentariu);
    for (int i = 0; i < lungime-1; ++i)
    {
      aux2[i]=comentariu[i];
    }
    strcat(argumente,":");
    strcat(argumente,aux2);

  } else {
    printf("TREBUIE sa fiti logat pentru a folosi aceasta comanda!\n");
  }
}

void MyBlockvote(){
  if(is_login==1){
    int lungime;
    lungime=strlen(tastatura);
    bzero(argumente,D_MAX);
    for (int i = 0; i < lungime-1; ++i)
    {
      argumente[i]=tastatura[i];
    }
  } else {
    printf("TREBUIE sa fiti logat pentru a folosi aceasta comanda!\n");
  }
}

void MyRemove(){
    int lungime;
    bzero(argumente,D_MAX);
    strcat(argumente,"remove");

    char gen[20],nume_mel[30];
    char aux1[20],aux2[30];

    bzero(gen,20);
    bzero(nume_mel,30);
    bzero(aux1,20);
    bzero(aux2,30);
    
    rname(nume_mel);
    lungime=strlen(nume_mel);
    for (int i = 0; i < lungime-1; ++i)
    {
      aux2[i]=nume_mel[i];
    }
    strcat(argumente," ");
    strcat(argumente,aux2);

    rgen(gen);
    lungime=strlen(gen);
    for (int i = 0; i < lungime-1; ++i)
    {
      aux1[i]=gen[i];
    }
    strcat(argumente,":");
    strcat(argumente,aux1);

    // printf("ARG: %s\n",argumente);
}

void Myrep(){
  int lungime;
  strcat(argumente,"report ");
  char usr[15];
  char aux1[15];
  char motiv[100];
  char aux2[100];
  rusr1(usr);
  lungime=strlen(usr);
  for (int i = 0; i < lungime - 1; ++i)
  {
    aux1[i]=usr[i];
  }
  strcat(argumente,usr);
  strcat(argumente,":");
  rrep(motiv);
  lungime=strlen(motiv);
  for (int i = 0; i < lungime-1; ++i)
  {
    aux2[i]=motiv[i];
  }
  strcat(argumente,motiv);
}

void colectare_date(char input[D_MAX]){

  if(strcmp(input,"login\n")==0){
      bzero(argumente,D_MAX);
      login();
  } else if( strncmp(input,"manual",6)==0 ){
      bzero(argumente,D_MAX);
      strcat(argumente,input);
  } else if(strcmp(input,"register\n")==0){
      bzero(argumente,D_MAX);
      MyRegister();
  } else if(strcmp(input,"add\n")==0){
      MyAdd();
  } else if(strncmp(input,"list ",5)==0){
      if(strlen(input)<6){
        printf("Argumente insuficiente.\n");
      } else {
            bzero(argumente,D_MAX);
            strcat(argumente,tastatura);
          }
  } else if(strncmp(input,"vote ",5)==0) {
      bzero(argumente,D_MAX);
      strcat(argumente,input);
  } else if(strncmp(input,"quit\n",5)==0){
      bzero(argumente,D_MAX);
      strcat(argumente,input);
      // exit2=1;
  } else if(strncmp(input,"comment\n",8)==0) {
      MyComment();
  } else if(strncmp(input,"blockvote ",10)==0 || strncmp(input,"unblockvote ",12)==0) {
      MyBlockvote();
  } else if(strncmp(input,"remove\n",7)==0){
      MyRemove();
  } else if(strncmp(input,"bann ",5)==0){
        bzero(argumente,D_MAX);
        strcat(argumente,input);
  } else if(strncmp(input,"unbann ",7)==0) {
        bzero(argumente,D_MAX);
        strcat(argumente,input);
  } else if(strcmp(input,"logout\n")==0) {
        bzero(argumente,D_MAX);
        strcat(argumente,input);
  } else if(strcmp(input,"istoric\n")==0) {
        bzero(argumente,D_MAX);
        strcat(argumente,"istoric");
  } else if(strcmp(input,"report\n")==0) {
        bzero(argumente,D_MAX);
        Myrep();
  } else if(strncmp(input,"seereport ",10)==0) {
        bzero(argumente,D_MAX);
        strcat(argumente,input);
  } else {
    printf("Comanda introdusa este incorecta!\n");
  }
}
