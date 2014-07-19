#include <QApplication>
#include "DisplayGUI.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    //创建主窗口，并显示
    DisplayGUI* p_main_window = new DisplayGUI;
    p_main_window->show();

    return app.exec();
}
