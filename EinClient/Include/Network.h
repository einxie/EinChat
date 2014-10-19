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

enum
{
	CLIENT_MESSAGE_LOGIN = 1,
};

enum
{
	SERVER_MESSAGE_LOGIN_RES = 1,
	SERVER_MESSAGE_SHOW_RES = 2,
};

#define RES_SUCCESS		1
#define RES_FAIL		2
