#include "Common.h"



xcgui::XWnd g_Wnd;
LONG_PTR g_oldProc = NULL;
//�¼���Ӧ
int CALLBACK My_EventBtnClick(BOOL *pBool)
{
    //������Ϣ��
    MessageBoxW(g_Wnd.GetHWND(),L"�����˰�ť",L"��ʾ",MB_OK);
    *pBool=TRUE; //�Ը��¼���������
    return 0;    //�¼��ķ���ֵ
}

LRESULT CALLBACK WindowProc(  HWND hwnd,      // handle to window
							UINT uMsg,      // message identifier
							WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
 )
{
	OutputDebugStringW(L"�յ���Ϣ?\r\n");
	return CallWindowProc((WNDPROC)g_oldProc,hwnd,uMsg,wParam,lParam);
}

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
	g_Wnd.Create(0,0,300,200,L"�Ųʽ����-����"); //��������
    if(g_Wnd)
    {
		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",g_Wnd);
		m_btn.SetType(button_type_close);


        XEle_RegEventC(XBtn_Create(100,5,80,25,L"����",g_Wnd),XE_BNCLICK,My_EventBtnClick);//ע�ᰴť����¼�
		

		g_oldProc = SetWindowLongPtr(g_Wnd.GetHWND(),GWLP_WNDPROC,(LONG_PTR)&WindowProc);

		g_Wnd.ShowWindow(SW_SHOW); //��ʾ����
		
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}


