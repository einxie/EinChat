#ifndef CLIENTSOCK_H
#define CLIENTSOCK_H

#include "../Include/Network.h"
#include <iostream>
#include <string>
using std::string;

class ClientSock {
private:
	typedef void (*SET_CALLBACK)(const string m_str);
public:
    ClientSock();
    ~ClientSock();
    void SendMesg(string send_mesg, SET_CALLBACK m_set_callback);
    void RecvMesg(int fd, char* m_mesg);
private:
    ssize_t writen(int fd, const void* vptr, size_t n);
    ssize_t my_read(int fd, char* ptr);
    ssize_t readline(int fd, void* vptr, size_t maxlen);

private:
    SET_CALLBACK m_disp_set_callback;
};

#endif

