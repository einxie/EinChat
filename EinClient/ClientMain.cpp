#include <QApplication>
#include "MainWindow.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    //创建主窗口，并显示
    MainWindow* p_main_window = new MainWindow;
    p_main_window->show();

    return app.exec();
}

