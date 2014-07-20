#include "MainWindow.h"

//构造主窗口
MainWindow::MainWindow() {
    //让对话框占用主窗口中央区域部分
    p_display_gui = new DisplayGUI;
    setCentralWidget(p_display_gui);
    //设定主窗口标题与初始大小
    setWindowTitle(tr("Ein Client"));
    resize(QSize(800, 400));
}
