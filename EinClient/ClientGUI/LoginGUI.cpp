#include "LoginGUI.h"
#include <QLabel>
#include <QLineEdit>

LoginGUI::LoginGUI()
{
    p_label_user = new QLabel(tr("&User"));
    p_label_pass = new QLabel(tr("&Pass"));
    p_le_user = new QLineEdit;
    p_le_pass = new QLineEdit;
    //布局第一行控件(显示标签-显示框，发送标签-发送框)
    QGridLayout* p_center_layout = new QGridLayout;;
    p_center_layout->addWidget(p_label_user, 0, 0);
    p_center_layout->addWidget(p_le_user, 0, 1);
    p_center_layout->addWidget(p_label_pass, 1, 0);
    p_center_layout->addWidget(p_le_pass, 1, 1);

    this->addChildLayout(p_center_layout);
}
