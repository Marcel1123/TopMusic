#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sqlite3.h>
#define MY_PORT 3032
#define D_MAX 5000
extern int errno;
/*------------GENERAL------------*/
int login=0;
char msg[D_MAX];    
char msgrasp[D_MAX]=" "; 
char comanda[D_MAX];
int logat=0;
/*------------CONTURI------------*/
char username1[15];
char password1[15];
char user_type1[5];
int drept_vot=0;
int drept_sterge=0;
int banat=0;
/*------------MELODII------------*/
char nume_melodie[30];
char descriere_melodie[100];
char gen_melodie[20];
char URL_melodie[40];
int voturi=0;
int ID=0;
/*------------TOPUTI------------*/
char top[20];
/*------------EXIT------------*/
int exit1 = 0;
int client;
int endd=0;
/*------------COMENTARIU------------*/
char comentariu[150];
/*------------BLOCKOTE--------------*/
char username2[15];
char user_type2[5];
char motiv[100];