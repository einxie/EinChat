#ifndef SERVER_SOCK_H
#define SERVER_SOCK_H
#include "../Include/Network.h"
#include <iostream>

class ServerSock {
public:
    ServerSock();
    ~ServerSock();

    void OperateMesg();
private:
    ssize_t writen(int fd, const void* vptr, size_t n);
    void str_echo(int sockfd);
};

#endif
