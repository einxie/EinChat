#include "DisplayGUI.h"
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeWidget>
#include <QMessageBox>

#include <iostream>

//对话框的构造函数
DisplayGUI::DisplayGUI()
{
	//生成用户姓名树
	p_name_tree = new QTreeWidget;
	QString tree_label("name");
	p_name_tree->setHeaderLabel(tree_label);

    //生成标签与文本框
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

    //布局右侧切分窗口(垂直)：第一行->显示 第二行：编辑 第三行：发送按钮
    QSplitter* p_right_splitter = new QSplitter(Qt::Vertical);
    p_right_splitter->addWidget(p_mesg_disp);
    p_right_splitter->addWidget(p_mesg_send);
    p_right_splitter->addWidget(p_send_button);
    p_right_splitter->setStretchFactor(0, 1);

    //布局主切分窗口(两列控件，水平布局)
    this->setOrientation(Qt::Horizontal);
    this->addWidget(p_name_tree);
    this->addWidget(p_right_splitter);
    this->setStretchFactor(1, 1);
}

//点击消息按钮，读取要发送的消息
void DisplayGUI::SendClicked()
{
    //读取要发送的消息
    QString t_mesg_send = p_mesg_send->toPlainText();
    p_mesg_send->setText("");
    std::cout<<"UI Send Mesg:"<<t_mesg_send.toStdString()<<std::endl;
    SetDispMesg(t_mesg_send.toStdString());
}

//根据消息文本框的内容，更新进程按钮状态
void DisplayGUI::EnableSendButton()
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
void DisplayGUI::SetDispMesg(const std::string m_mesg)
{
	p_mesg_disp->append(m_mesg.c_str());
}

//根据错误种类弹出错误提示框
//其他错误
void DisplayGUI::ErrorMessage(int num)
{
    QString error_info;
    switch(num)
    {
    default:
        error_info = "Other errors!";
        break;
    }

    QMessageBox::critical(NULL, "Error",  
        error_info, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes); 
}
