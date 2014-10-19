#include "ClientSock.h"

using std::cout;
using std::endl;
using std::string;

const char* local_ip = "127.0.0.1";

ClientSock::ClientSock() : m_disp_set_callback(0) {
}

ClientSock::~ClientSock() {
}

//向服务端发送消息
void ClientSock::SendMesg(string s_mesg_send, SET_CALLBACK m_set_callback) {
	m_disp_set_callback = m_set_callback;
    cout<<"Mesg to Server:"<<endl;
    cout<<s_mesg_send<<endl;

    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, local_ip, &servaddr.sin_addr);
    connect(sockfd, (SA*)&servaddr, sizeof(servaddr));

    if("" == s_mesg_send) {
    	close(sockfd);
    	return;
    }

	const char* send_mesg = s_mesg_send.c_str();
	writen(sockfd, send_mesg, strlen(send_mesg));

    char recv_mesg[MAXLINE];
    RecvMesg(sockfd, recv_mesg);

    close(sockfd);
    return;
}

void ClientSock::RecvMesg(int fd, char* m_mesg) {
	string s_mesg_receive = "";
	if(readline(fd, m_mesg, MAXLINE) == 0) {
		cout<<"Receive Error"<<endl;
		m_disp_set_callback(s_mesg_receive);
		return;
	}
	cout<<"Now Receive Mesg:"<<m_mesg<<endl;
	s_mesg_receive = m_mesg;
	m_disp_set_callback(s_mesg_receive);

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

