#include "MessageGUI.h"
#include <QLayout>
#include <QTextEdit>
#include <QPushButton>

#include <iostream>

MessageGUI::MessageGUI(QWidget* parent)
    : QDialog(parent)
{
    //生成文本框
    p_mesg_disp = new QTextEdit;
    p_mesg_send = new QTextEdit;
    p_mesg_disp->setReadOnly(TRUE);
    p_mesg_disp->setText("");
    p_mesg_send->setText("");

    //生成发送按钮
    p_send_button = new QPushButton(tr("&Send"));
    //将发送按钮设定为无效并设定鼠标停留时的提示信息
    p_send_button->setEnabled(false);
    p_send_button->setToolTip(tr("Unavailable Now!"));

    //文本框内容变化时更新进程按钮状态
    connect(p_mesg_send, SIGNAL(textChanged()),
            this, SLOT(EnableSendButton()));

    //点击进程按钮时执行对应的操作
    connect(p_send_button, SIGNAL(clicked()),
            this, SLOT(SendClicked()));

    //布局整体界面
    QVBoxLayout* p_main_layout = new QVBoxLayout;
    p_main_layout->addWidget(p_mesg_disp);
    p_main_layout->addWidget(p_mesg_send);
    p_main_layout->addWidget(p_send_button);

    setLayout(p_main_layout);
}

//点击消息按钮，读取要发送的消息
void MessageGUI::SendClicked()
{
    //读取要发送的消息
    QString t_mesg_send = p_mesg_send->toPlainText();
    p_mesg_send->setText("");
    std::cout<<"UI Send Mesg:"<<t_mesg_send.toStdString()<<std::endl;
    SetDispMesg(t_mesg_send.toStdString());
}

//根据消息文本框的内容，更新登录按钮状态
void MessageGUI::EnableSendButton()
{
    //消息文本框不为空
    if(!p_mesg_send->toPlainText().isEmpty())
    {
        //进程按钮有效，关闭提示信息
        p_send_button->setEnabled(true);
        p_send_button->setToolTip(tr(""));
    }
    //消息文本框为空
    else
    {
        //进程按钮无效，能够显示提示信息
        p_send_button->setEnabled(false);
        p_send_button->setToolTip(tr("Please input message!"));
    }
}

//设定显示消息
void MessageGUI::SetDispMesg(const std::string m_mesg)
{
    p_mesg_disp->append(m_mesg.c_str());
}
