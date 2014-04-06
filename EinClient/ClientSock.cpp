#include "ClientSock.h"

using std::cout;
using std::endl;
using std::string;

const char* local_ip = "127.0.0.1";

ClientSock::ClientSock() {
}

ClientSock::~ClientSock() {
}

//向服务端发送消息
string ClientSock::SendMesg(string& s_mesg_send) {
    cout<<"Mesg to Server:"<<endl;
    cout<<s_mesg_send<<endl;
    string s_mesg_receive;
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, local_ip, &servaddr.sin_addr);
    connect(sockfd, (SA*)&servaddr, sizeof(servaddr));

    char recv_mesg[MAXLINE];
    while(s_mesg_send != "") {
        const char* send_mesg = s_mesg_send.c_str();
        writen(sockfd, send_mesg, strlen(send_mesg));
        if(readline(sockfd, recv_mesg, MAXLINE) == 0) {
            cout<<"Receive Error"<<endl;
            return "";
        }
        cout<<"Now Recive Mesg:"<<endl;
        cout<<recv_mesg<<endl;
        s_mesg_send = "";
        s_mesg_receive = send_mesg;
    }

    close(sockfd);
    return s_mesg_receive;
}

ssize_t ClientSock::my_read(int fd, char* ptr) {
    static int read_cnt = 0;
    static char* read_ptr;
    static char read_buf[MAXLINE];

    if(read_cnt <= 0) {
        if((read_cnt = read(fd, read_buf, sizeof(read_buf))) < 0) {
            return -1;
        } else if(read_cnt == 0) {
            return 0;
        } else {
            read_ptr = read_buf;
        }
    }
    --read_cnt;
    *ptr = *read_ptr++;
    return 1;
}

//将消息写入socket
ssize_t ClientSock::writen(int fd, const void* vptr, size_t n) {
    size_t nleft;
    ssize_t nwritten;
    const char* ptr;

    ptr = (const char*)vptr;
    nleft = n;
    while(nleft > 0) {
        nwritten = write(fd, ptr, nleft);
        nleft -= nwritten;
        ptr += nwritten;
    }
    return n;
}

//从socket读取消息
ssize_t ClientSock::readline(int fd, void* vptr, size_t maxlen) {
    ssize_t n, rc;
    char c, *ptr;
    
    ptr = (char*)vptr;
    for(n = 1; n < (ssize_t)maxlen; ++n) {
        if((rc = my_read(fd, &c)) == 1) {
            *ptr++ = c;
            if(c == '\0') {
                break;
            }
        } else if(rc == 0) {
            if(n == 1) {
                return 0;
            } else {
                break;
            }
        } else {
            return -1;
        }
    }
    *ptr = 0;
    return n;
}

