#include "Common.h"



int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��

	xcgui::XModalWnd modal(300,200,L"��¼ϵͳ",NULL);
	xcgui::XBtn btn(10, 5, 200, 20,L"�ر�ģ̬����",modal);
	btn.SetType(button_type_close);
	modal.DoModal();

	xcgui::XWnd m_Wnd(0,0,300,200,L"�Ųʽ����-����");
    if(m_Wnd)
    {
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Wnd);
		btn.SetType(button_type_close);
	
		SetFocus(m_Wnd.GetHWND());
		m_Wnd.ShowWindow(SW_SHOW);
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}


