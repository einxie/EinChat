#ifndef DISPLAYGUI_H
#define DISPLAYGUI_H
#include <QSplitter>
#include <string>

class QLabel;
class QTextEdit;
class QLineEdit;
class QPushButton;
class QTreeWidget;
//对话框类，在其中实现绝大部分逻辑功能
class DisplayGUI : public QSplitter
{
    Q_OBJECT
public:
    DisplayGUI();

public:
    //设定显示消息
    void SetDispMesg(QTextEdit* p_te, const std::string& m_mesg);
private:
    //警告信息
    void ErrorMessage(int num);

private:
    //对话框中各控件
    QTextEdit* p_te_config;
    QTextEdit* p_te_history;
    QTreeWidget* p_name_tree;
};

#endif
