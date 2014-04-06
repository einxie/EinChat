#ifndef CLIENTSOCK_H
#define CLIENTSOCK_H

#include "../Include/Network.h"
#include <iostream>
#include <string>
using std::string;

class ClientSock {
public:
    ClientSock();
    ~ClientSock();
    string SendMesg(string& send_mesg);
private:
    ssize_t writen(int fd, const void* vptr, size_t n);
    ssize_t my_read(int fd, char* ptr);
    ssize_t readline(int fd, void* vptr, size_t maxlen);
};

#endif

