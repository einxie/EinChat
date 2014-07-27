#include "DisplayGUI.h"
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
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

    //文本框
	p_te_config = new QTextEdit;
	p_te_history = new QTextEdit;
    p_te_config->setReadOnly(TRUE);
    p_te_history->setReadOnly(TRUE);
    p_te_config->setText("");
    p_te_history->setText("");

    //布局右侧切分窗口(垂直)：第一行->配置 第二行：历史
    QSplitter* p_right_splitter = new QSplitter(Qt::Vertical);
    p_right_splitter->addWidget(p_te_config);
    p_right_splitter->addWidget(p_te_history);
    p_right_splitter->setStretchFactor(0, 1);

    //布局主切分窗口(两列控件，水平布局)
    this->setOrientation(Qt::Horizontal);
    this->addWidget(p_name_tree);
    this->addWidget(p_right_splitter);
    this->setStretchFactor(1, 1);
}

//设定显示消息
void DisplayGUI::SetDispMesg(QTextEdit* p_te, const std::string& m_mesg)
{
    if (NULL == p_te)
    {
        return;
    }
    p_te->setText(m_mesg.c_str());
//    p_te->append(m_mesg.c_str());
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
