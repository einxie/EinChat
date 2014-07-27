#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "LoginGUI.h"
#include "DisplayGUI.h"

//主窗口类
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();

private:
    //主窗口上的对话框
    LoginGUI* p_login_gui;
    DisplayGUI* p_display_gui;
};

#endif
