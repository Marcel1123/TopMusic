#include "Declarari.h"

void rusr1(char users[15]){

  printf("Intruduceti username: ");
  scanf("%s",users);

  if(strlen(users)>15){

    printf("Usename prea lung.\nIntroduceti maxim 15 caractere.\n");
    bzero(users,15);
    rusr1(users);
  }
  if(strlen(users)==0){
    printf("Usernameul nu poate fi gol.\n");
    bzero(users,15);
    rusr1(users);
  }
  int i=0;
  while(i<strlen(users)){
    if (users[i]==':' || users[i]=='.' || users[i]==';' || users[i]==',')
    {
      printf("Usernameul contine caractere nepermise.\n");
      bzero(users,15);
      rusr1(users);
      break;
    }
    i++;
  }
}

void rusr(char users[15]){

  printf("Intruduceti noul username: ");
  scanf("%s",users);

  if(strlen(users)>15){

    printf("Usename prea lung.\nIntroduceti maxim 15 caractere.\n");
    bzero(users,15);
    rusr(users);
  }
  if(strlen(users)==0){
    printf("Usernameul nu poate fi gol.\n");
    bzero(users,15);
    rusr(users);
  }
  int i=0;
  while(i<strlen(users)){
    if (users[i]==':' || users[i]=='.' || users[i]==';' || users[i]==',')
    {
      printf("Usernameul contine caractere nepermise.\n");
      bzero(users,15);
      rusr(users);
      break;
    }
    i++;
  }
}

void rpass1(char pass[15]){

  printf("Introduceti parola: ");
  scanf("%s",pass);

  if(strlen(pass)>15){
    printf("Parola prea lunga.\nIntroduceti maxim 15 caractere.\n");
    bzero(pass,15);
    rpass1(pass);
  }
  if(strlen(pass)==0){
    printf("Parola nu poate fi gol.\n");
    bzero(pass,15);
    rpass1(pass);
  }
  int i=0;
  while(i<strlen(pass)){
    if (pass[i]==':' || pass[i]=='.' || pass[i]==';' || pass[i]==',')
    {
      printf("Parola contine caractere nepermise.\n");
      bzero(pass,15);
      rpass1(pass);
      break;
    }
    i++;
  }
}

void rpass(char pass[15]){

  printf("Introduceti noua parola: ");
  scanf("%s",pass);

  if(strlen(pass)>15){
    printf("Parola prea lunga.\nIntroduceti maxim 15 caractere.\n");
    bzero(pass,15);
    rpass(pass);
  }
  if(strlen(pass)==0){
    printf("Parola nu poate fi gol.\n");
    bzero(pass,15);
    rpass(pass);
  }
  int i=0;
  while(i<strlen(pass)){
    if (pass[i]==':' || pass[i]=='.' || pass[i]==';' || pass[i]==',')
    {
      printf("Parola contine caractere nepermise.\n");
      bzero(pass,15);
      rpass(pass);
      break;
    }
    i++;
  }
}

void rtype(char type[5]){

  printf("Introduceti tipul de utilizator: ");
  scanf("%s",type);

  int usr=0;
  int adm=0;

  if(strcmp(type,"admin") == 0){
    adm=1;
  } else if(strcmp(type,"user") == 0){
    usr=1;
  }

  if(usr==0 && adm==0){

    printf("Puteti introduce doar \" user \" sau \"admin\".\n");
    bzero(type,5);
    rtype(type);
  }
}

void rname(char nume1[30]){

	printf("Introduceti numele: ");
    fflush(stdout);
    read(0,nume1,30);

	if(strlen(nume1)>30){
  	printf("Numele este prea lung.\nIntroduceti maxim 30 caractere.\n");
    bzero(nume1,30);
  	rname(nume1);
  }
  if(strlen(nume1)==0){
    printf("Numele nu poate fi gol.\n");
    bzero(nume1,30);
    rname(nume1);
  }
  int i=0;
  while(i<strlen(nume1)){
    if (nume1[i]==':' || nume1[i]=='.' || nume1[i]==';' || nume1[i]==',')
    {
      printf("Numele contine caractere nepermise.\n");
      bzero(nume1,30);
      rname(nume1);
      break;
    }
    i++;
  }
}

void rdescr(char descriere1[100]){

  printf("Introduceti descrierea: ");
  fflush(stdout);
  read(0,descriere1,100);

  if(strlen(descriere1)>100){
    printf("Descrierea este prea lunga.\nIntroduceti maxim 100 caractere.\n");
  	bzero(descriere1,100);
  	rdescr(descriere1);
  }
  if(strlen(descriere1)==0){
    printf("Parola nu poate fi gol.\n");
    bzero(descriere1,100);
    rdescr(descriere1);
  }
  int i=0;
  while(i<strlen(descriere1)){
    if (descriere1[i]==':')
    {
      printf("Parola contine caractere nepermise.\n");
      bzero(descriere1,100);
      rdescr(descriere1);
      break;
    }
    i++;
  }
}

void rgen(char gen1[20]){

    printf("Introduceti genul: ");
    fflush(stdout);
    read(0,gen1,20);

  	if(strlen(gen1)>20){
    	printf("Genul este prea lung.\nIntroduceti maxim 20 caractere.\n");
    	bzero(gen1,20);
    	rgen(gen1);
  	}
    if(strlen(gen1)==0){
      printf("Genul nu poate fi gol.\n");
      bzero(gen1,20);
      rgen(gen1);
    }
    int i=0;
    while(i<strlen(gen1)){
      if (gen1[i]==':' || gen1[i]=='.' || gen1[i]==';' || gen1[i]==',')
      {
        printf("Genul contine caractere nepermise.\n");
        bzero(gen1,20);
        rgen(gen1);
        break;
      }
      i++;
    }
}

void rURL(char URL1[40]){

    printf("Introduceti URL-ul: ");
    fflush(stdout);
    read(0,URL1,40);

  	if(strlen(URL1)>40){
    	printf("URL-ul este prea lung.\nIntroduceti maxim 40 caractere.\n");
    	bzero(URL1,40);
    	rURL(URL1);
  	}
    if(strlen(URL1)==0){
      printf("URL-ul nu poate fi gol.\n");
      bzero(URL1,40);
      rURL(URL1);
    }
    
}

void rComment(char Comment1[150]){

  printf("Introduceti comentariul: ");
  fflush(stdout);
  read(0,Comment1,150);

  if(strlen(Comment1)>150){
    printf("comentariu prea lung.\nIntroduceti maxim 150 caractere.\n");
    bzero(Comment1,150);
    rComment(Comment1);
  }
  if(strlen(Comment1)==0){
    printf("comentariul nu poate fi gol.\n");
    bzero(Comment1,150);
    rComment(Comment1);
  }
}

void rrep(char motiv1[100]){
  bzero(motiv1,100);
  printf("Introduceti motivul: ");
  fflush(stdout);
  read(0,motiv1,100);

  if(strlen(motiv1)>100){
    printf("Motivul prea lung.\nIntroduceti maxim 150 caractere.\n");
    bzero(motiv1,100);
    rComment(motiv1);
  }
  if(strlen(motiv1)==0){
    printf("Motivul nu poate fi gol.\n");
    bzero(motiv1,100);
    rComment(motiv1);
  }
}