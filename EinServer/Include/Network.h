#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstdlib>
#include <cstdio>
#include <cstring>

#define SERV_PORT        9877           /* TCP and UDP */
#define SA  struct sockaddr
#define MAXLINE     4096    /* max text line length */
#define	LISTENQ		1024	/* 2nd argument to listen() */

extern const char* local_ip;

