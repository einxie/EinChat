#include "LoginGUI.h"
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QPushButton>

#include <iostream>

LoginGUI::LoginGUI(QWidget* parent)
        : QDialog(parent)
{
    p_label_user = new QLabel(tr("Username"));
    p_label_pass = new QLabel(tr("Password"));
    p_le_user = new QLineEdit;
    p_le_pass = new QLineEdit;
    p_pb_login = new QPushButton(tr("&Login"));
    //将登录按钮设定为无效并设定鼠标停留时的提示信息
    p_pb_login->setEnabled(false);
    p_pb_login->setToolTip(tr("Unavailable Now!"));

    //文本框内容变化时更新登录按钮状态
    connect(p_le_user, SIGNAL(textChanged(const QString &)),
            this, SLOT(EnableLoginButton()));
    //文本框内容变化时更新登录进程按钮状态
    connect(p_le_pass, SIGNAL(textChanged(const QString &)),
            this, SLOT(EnableLoginButton()));

    //点击登录按钮时执行对应的操作
    connect(p_pb_login, SIGNAL(clicked()),
            this, SLOT(LoginClicked()));

    //布局第一行控件(显示标签-显示框，发送标签-发送框)
    QGridLayout* p_center_layout = new QGridLayout;
    p_center_layout->addWidget(p_label_user, 0, 0);
    p_center_layout->addWidget(p_le_user, 0, 1);
    p_center_layout->addWidget(p_label_pass, 1, 0);
    p_center_layout->addWidget(p_le_pass, 1, 1);

    //布局登录按钮
    QHBoxLayout* p_bottom_layout = new QHBoxLayout;
    p_bottom_layout->addStretch();
    p_bottom_layout->addWidget(p_pb_login);
    p_bottom_layout->addStretch();

    //布局整体界面
    QVBoxLayout* p_main_layout = new QVBoxLayout;
    p_main_layout->addStretch();
    p_main_layout->addLayout(p_center_layout);
    p_main_layout->addLayout(p_bottom_layout);
    p_main_layout->addStretch();

    setLayout(p_main_layout);
}

//根据消息文本框的内容，更新进程按钮状态
void LoginGUI::EnableLoginButton()
{
    //消息文本框不为空
    if(!p_le_user->text().isEmpty() && !p_le_pass->text().isEmpty())
    {
        //进程按钮有效，关闭提示信息
        p_pb_login->setEnabled(true);
        p_pb_login->setToolTip(tr(""));
    }
    //消息文本框为空
    else
    {
        //进程按钮无效，能够显示提示信息
        p_pb_login->setEnabled(false);
        p_pb_login->setToolTip(tr("Please input username or password!"));
    }
}

//点击消息按钮，读取要发送的消息
void LoginGUI::LoginClicked()
{
    //读取要发送的消息
    QString t_mesg_user = p_le_user->text();
    QString t_mesg_pass = p_le_pass->text();
    p_le_user->setText("");
    p_le_pass->setText("");
    std::cout<<"UI Send username:"<<t_mesg_user.toStdString()
            << " and password:"<<t_mesg_pass.toStdString()<<std::endl;
}
