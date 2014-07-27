#ifndef LOGINGUI_H
#define LOGINGUI_H

#include <QLayout>

class QLabel;
class QLineEdit;

class LoginGUI : public QLayout
{
    Q_OBJECT
public:
    LoginGUI();

private:
    QLabel* p_label_user;
    QLabel* p_label_pass;
    QLineEdit* p_le_user;
    QLineEdit* p_le_pass;
};

#endif
