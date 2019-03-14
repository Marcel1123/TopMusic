#include "Declaratii.h"
#include "Implementare_comenzi.h"
#include "Functii.h"

int main ()
{
    struct sockaddr_in server;  // structura folosita de server
    struct sockaddr_in from;
    int sd;

    /* crearea unui socket */
    if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror ("[server]Eroare la socket().\n");
        return errno;
    }

    /* pregatirea structurilor de date */
    bzero (&server, sizeof (server));
    bzero (&from, sizeof (from));

    /* umplem structura folosita de server */
    /* stabilirea familiei de socket-uri */
    server.sin_family = AF_INET;
    /* acceptam orice adresa */
    server.sin_addr.s_addr = htonl (INADDR_ANY);
    /* utilizam un port utilizator */
    server.sin_port = htons (MY_PORT);

    /* atasam socketul */
    if (bind (sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1)
    {
        perror ("[server]Eroare la bind().\n");
        return errno;
    }

    /* punem serverul sa asculte daca vin clienti sa se conecteze */
    if (listen (sd, 5) == -1)
    {
        perror ("[server]Eroare la listen().\n");
        return errno;
    }

    /* servim in mod concurent clientii... */
    while (exit1==0)
    {

        int length = sizeof (from);

        printf ("[server]Asteptam la portul %d...\n",MY_PORT);
        fflush (stdout);

        /* acceptam un client (stare blocanta pina la realizarea conexiunii) */
        client = accept (sd, (struct sockaddr *) &from, &length);
        /* eroare la acceptarea conexiunii de la un client */
        if (client < 0)
        {
            perror ("[server]Eroare la accept().\n");
            continue;
        }

        int pid;
        if ((pid = fork()) == -1) {
            close(client);
            continue;
        } else if (pid > 0) {
            // parinte
            close(client);
            while(waitpid(-1,NULL,WNOHANG));
            continue;
        } else if (pid == 0) {
            // copil
            close(sd);

            /* s-a realizat conexiunea, se astepta mesajul */
            while(exit1 == 0) {
                bzero (msg, D_MAX);
                bzero(msgrasp,D_MAX);
                printf ("[server]Asteptam mesajul...\n");
                fflush (stdout);
                

                            /* citirea mesajului */
                if (read (client, msg, D_MAX) <= 0)
                {
                    // perror ("[server]Eroare la read() de la client.\n");
                    close (client); /* inchidem conexiunea cu clientul */
                    continue;       /* continuam sa ascultam */
                }
                
                printf ("[server]Comanda receptionata: %s\n", msg);
                
                /*pregatim mesajul de raspuns */
                actualizare_blockvote();
                actualizare_bann();
                bzero(msgrasp,D_MAX);
                analiza_comanda(msg);
                    
                executie_comenzi();
                if(banat == 1){
                    bzero(msgrasp,D_MAX);
                    printf("Blocat.\n");
                    MyLogout();

                    strcat(msgrasp,"Contul dumneavoastra a fost blocat.\n");
                    
                }
                // printf("LG: [%d]\n", login);
                AddHistoric();
                 
                /* returnam mesajul clientului */
                if (write (client, msgrasp, D_MAX) <= 0)
                {
                    perror ("[server]Eroare la write() catre client.\n");
                    continue;       /* continuam sa ascultam */
                }
                else
                    printf ("[server]Mesajul a fost trasmis cu succes.\n");

                bzero (msg, D_MAX);
                bzero(msgrasp,D_MAX);
                printf("\n");
                fflush(stdout);
            }

            break;
            /* am terminat cu acest client, inchidem conexiunea */
            close (client);
            exit(0);
        }
        if (endd==1)
        {
            return 0;
        }
    }               /* while */
}



