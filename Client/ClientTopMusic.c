#include "Functii_Client.h"
// #include "Manual.h"

int main (int argc, char *argv[])
{
  int sd;	

  struct sockaddr_in server;

  if(argc != 3){
    printf("Argumete incorecte.\nIntroduceti <adresa unde asteapta serverul> <portul serverului>\n");
    return 0;
  }
  port=atoi(argv[2]);

  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
  {
    perror ("Eroare la socket().\n");
    return errno;
  }
  server.sin_family = AF_INET;

  server.sin_addr.s_addr = inet_addr(argv[1]);
  
  server.sin_port = htons (port);
  
  if (connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1)
    {
      perror ("[client]Eroare la connect().\n");
      return errno;
    }
  
  printf("%s", "\n\tPentru a continua solicitati o conexiune la server prin comanda login. ");
  
  printf("%s", "\n\tPentru mai multe informatii despre comenzi consultati comanda manual. \n\n");
  
  printf("\tREGULI\n");
  printf("1. Fiecare top trebuie scris cu prima litera mare si restul mici.\n");
  printf("2. In timpul citiri veti primi cateva intructiuni pe care trebuie sa le respectati.\n");
  printf("3. Initial tastati comanda \"manual\"\n");
  printf("ORICE NERESPECTARE A REGULILOR POATE DUCE LA REZULTATE GRESITE, DELOGARE SAU CHIAR BLOCAREA CONTULUI DUMNEAVOASTRA.\n");
  printf("\n\tVa rugam sa tastati initial comanda manual daca nu sunteti falmiliari cu aplicatia.\n");
  while(exit2==0){

    char ms[D_MAX]="\t->Ati fost logat cu succes. \n";

    bzero(msg,D_MAX);
    bzero(tastatura,D_MAX);

    if(is_login==1){
      printf("\t\t%s\n\n",usernames);
    }

    printf("%s","Introduceti comanda:  " );
    fflush(stdout);

    read(0,tastatura,D_MAX);

    colectare_date(tastatura);
 
    if (write (sd, argumente, D_MAX) <= 0)
    {
      perror ("[client]Eroare la write() spre server.\n");
      return errno;
    }

    //TREBUIE GOLITE BUFFERELE OBLIGATORIU

    bzero(argumente,D_MAX);

    bzero(msg,D_MAX);

    if (read (sd, msg, D_MAX) < 0)
    {
      perror ("[client]Eroare la read() de la server.\n");
      return errno;
    }

    if(strcmp(msg,ms)==0){
      is_login=1;
    }
    if(strncmp(msg,"Inchidere realizata cu succes.",30) == 0){
      exit2=1;
      printf("Inchidere realizata in siguranta.\n");
    }
    if(strcmp(msg,"Ati fost delogat.\n")==0 || strcmp(msg,"Ati fost delogat.\nContul dumneavoastra a fost blocat.\n")==0){
      is_login=0;
      bzero(usernames,15);
    }
    printf ("%s", msg);
    fflush(stdout);
    printf("\n\n");
    fflush(stdout);

    if(strncmp(tastatura,"quit",4)==0){
      bzero(tastatura,D_MAX);
      bzero (argumente, D_MAX);
      bzero(msg,D_MAX);
      printf("Delogare in siguranta.\n");
      printf("Inchidere realizata cu succes.\n");
      fflush(stdout);      
      break;
    }

    bzero(tastatura,D_MAX);
    bzero (argumente, D_MAX);
    bzero(msg,D_MAX);
  }

  close (sd);
  exit(0);
  
}
