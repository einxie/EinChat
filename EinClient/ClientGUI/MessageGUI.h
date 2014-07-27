#ifndef MESSAGEGUI_H
#define MESSAGEGUI_H
#include <QDialog>
#include <string>

class QTextEdit;
class QPushButton;
//对话框类，在其中实现绝大部分逻辑功能
class MessageGUI : public QDialog
{
    Q_OBJECT
public:
    MessageGUI(QWidget* parent = 0);

public:
    //设定显示消息
    void SetDispMesg(const std::string m_mesg);

private slots:
    //各按钮对应的槽
    void SendClicked();
    void EnableSendButton();

private:
    //对话框中各控件
    QTextEdit* p_mesg_disp;
    QTextEdit* p_mesg_send;
    QPushButton* p_send_button;
};

#endif
