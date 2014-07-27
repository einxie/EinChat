#ifndef LOGINGUI_H
#define LOGINGUI_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class LoginGUI : public QDialog
{
    Q_OBJECT
public:
    LoginGUI(QWidget* parent = 0);

private slots:
    //各按钮对应的槽
    void LoginClicked();
    void EnableLoginButton();

private:
    QLabel* p_label_user;
    QLabel* p_label_pass;
    QLineEdit* p_le_user;
    QLineEdit* p_le_pass;
    QPushButton* p_pb_login;
};

#endif
