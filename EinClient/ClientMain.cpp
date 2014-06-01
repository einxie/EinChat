#include <QApplication>
#include "EinClient.h"
#include "ClientSock.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

//网络借口类
ClientSock m_client_sock;
QApplication* app;

//回调函数
void SetDispMesgCallback(const string m_mesg) {
    cout<<"UI Receive Connect Mesg:"<<m_mesg<<endl;
    size_t pos1 = m_mesg.find_first_of('|');
    string mesg_type(m_mesg, 0, pos1 - 0);
    int type = atoi(mesg_type.c_str());
    if (type != 1)
    {
        cout << "User name connect failed\n";
        delete app;
        return;
    }
    //创建主窗口，并显示
    EinClient* p_main_window = new EinClient;
    p_main_window->show();
    app->exec();
}

int main(int argc, char** argv) {
    if (argc != 3)
    {
        std::cerr << "Usage: client <user> <host>" << std::endl;
        return 1;
    }
    app = new QApplication(argc, argv);

	string connect_mesg;
	connect_mesg = "1";
	connect_mesg += "|";
	connect_mesg += argv[1];
	connect_mesg += "|";
	connect_mesg += argv[2];
	m_client_sock.SendMesg(connect_mesg, SetDispMesgCallback);

	return 0;
}
