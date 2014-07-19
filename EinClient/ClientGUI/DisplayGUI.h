#ifndef EINCLIENT_H
#define EINCLIENT_H
#include <QMainWindow>
#include <string>
using std::string;

//对应控件的前置声明类
class QLabel;
class QTextEdit;
class QLineEdit;
class QPushButton;
class QTreeWidget;
//对话框类，在其中实现绝大部分逻辑功能
class DisplayGUI : public QMainWindow {
    Q_OBJECT
public:
    DisplayGUI();

public:
    //设定显示消息
    void SetDispMesg(const string m_mesg);
private:
    //警告信息
    void ErrorMessage(int num);

private slots:
    //各按钮对应的槽
    void SendClicked();
    void EnableSendButton();

private:
    //对话框中各控件
    QTextEdit* p_mesg_disp;
    QTextEdit* p_mesg_send;
    QPushButton* p_send_button;
    QTreeWidget* p_name_tree;
    //存储用户要发送与要显示的消息
    QString m_mesg_disp;
    QString m_mesg_send;
    string m_mesg_change;
};

#endif
