#include <QApplication>
#include "EinClient.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    //创建主窗口，并显示
    EinClient* p_main_window = new EinClient;
    p_main_window->show();

    return app.exec();
}

