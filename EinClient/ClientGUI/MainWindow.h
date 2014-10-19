#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "LoginGUI.h"
#include "DisplayGUI.h"
#include "MessageGUI.h"

//主窗口类
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
    void ReceiveMessage(const std::string& m_mesg);
    void OperateLoginRes(int result);
    void OperateShowRes(int result);

private:
    //主窗口上的对话框
    LoginGUI* p_login_gui;
    DisplayGUI* p_display_gui;
    MessageGUI* p_message_gui;
};

#endif
