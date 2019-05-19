#include "Common.h"


class CMyWindowButton
{
public:
    HWINDOW m_hWindow;
    HELE    m_hButton_close;
    HELE    m_hButton;
    CMyWindowButton(){
        Init();
    }
    void Init()
    {
		HWINDOW hWindow = XWnd_Create(0, 0, 300, 200, L"�Ųʽ����-����");//��������
		if (hWindow)
		{
			HELE hButton = XBtn_Create(100, 50, 80, 25, L"Button", hWindow); //������ť
	
			XBtn_AddBkImage(hButton, button_state_leave, XImage_LoadFile(L"image\\Sys\\msg_icon_info.png")); //��������뿪״̬��ͼ
			XBtn_AddBkImage(hButton, button_state_stay, XImage_LoadFile(L"image\\Sys\\msg_icon_error.png")); //�������ͣ��״̬��ͼ
			XBtn_AddBkImage(hButton, button_state_down, XImage_LoadFile(L"image\\Sys\\msg_icon_check.png")); //������갴��״̬��ͼ
			
		}
		XWnd_ShowWindow(hWindow, SW_SHOW);//��ʾ

    }
    int OnBtnClick(BOOL *pbHandled)
    {
        MessageBoxW(XWnd_GetHWND(m_hWindow),L"�����˰�ť",L"��ʾ",MB_OK);
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowButton  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}




