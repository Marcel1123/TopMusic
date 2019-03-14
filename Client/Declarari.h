#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <errno.h>

#include <unistd.h>

#include <stdio.h>

#include <stdlib.h>

#include <netdb.h>

#include <string.h>

#define D_MAX 5000

#define MY_IP "127.0.0.1"

#define MY_PORT 3012

extern int errno;

char tastatura[D_MAX];

char argumente[D_MAX];

int is_login=0;

char msg[D_MAX];

char usernames[15];

int exit2=0;

char comentariu[150];

int port;
