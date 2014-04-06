#ifndef EINCLIENT_H
#define EINCLIENT_H
#include <QDialog>
#include <string>
#include "ClientSock.h"
using std::string;

//对应控件的前置声明类
class QLabel;
class QTextEdit;
class QLineEdit;
class QPushButton;
//对话框类，在其中实现绝大部分逻辑功能
class EinClient : public QDialog {
    Q_OBJECT
public:
    EinClient(QWidget* p_parent = 0);

private:
    //警告信息
    void ErrorMessage(int num);

private slots:
    //各按钮对应的槽
    void SendClicked();
    void EnableSendButton();

private:
    //对话框中各控件
    QLabel* p_label_disp;
    QLabel* p_label_send;
    QTextEdit* p_mesg_disp;
    QTextEdit* p_mesg_send;
    QPushButton* p_send_button;
    //存储用户要发送与要显示的消息
    QString m_mesg_disp;
    QString m_mesg_send;

public:
    string m_mesg_change;
    ClientSock m_client_sock;
};

#endif
