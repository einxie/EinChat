#include "MainWindow.h"
#include "../Include/Network.h"

//构造主窗口
MainWindow::MainWindow() {
    //让对话框占用主窗口中央区域部分
    p_login_gui = new LoginGUI;
    setCentralWidget(p_login_gui);

    //设定主窗口标题与初始大小
    setWindowTitle(tr("Ein Client"));
    resize(QSize(800, 400));
}

void MainWindow::ReceiveMessage(const std::string& m_mesg)
{
	size_t pos_1 = m_mesg.find_first_of(',');
	const char* c_mesg_num = m_mesg.substr(0, pos_1).c_str();
	int mesg_num = atoi(c_mesg_num);
	switch (mesg_num)
	{
	case SERVER_MESSAGE_LOGIN_RES:
		{
		const char* c_result = m_mesg.substr(pos_1 + 1).c_str();
		int result = atoi(c_result);
		OperateLoginRes(result);
		break;
		}
	case SERVER_MESSAGE_SHOW_RES:
		{
		const char* c_result = m_mesg.substr(pos_1 + 1).c_str();
		int result = atoi(c_result);
		OperateShowRes(result);
		break;
		}
	default:
		break;
	}

}

void MainWindow::OperateLoginRes(int result)
{
	if (RES_SUCCESS == result)
	{
	    p_display_gui = new DisplayGUI;
	    setCentralWidget(p_display_gui);
	    if (p_login_gui != NULL)
	    {
	    	delete p_login_gui;
	    }
	}
	else if (RES_FAIL == result)
	{
		printf("UI: login failed\n");
	}
}

void MainWindow::OperateShowRes(int result)
{
	if (RES_SUCCESS == result)
	{
		p_message_gui = new MessageGUI;
		setCentralWidget(p_message_gui);
	    if (p_display_gui != NULL)
	    {
	    	delete p_display_gui;
	    }
	}
	else if (RES_FAIL == result)
	{
		printf("UI: show failed\n");
	}
}
