#include "Common.h"



class CMyWnd
{
public:
	xcgui::XWnd m_Wnd;
	
    BOOL Create() //�������ںͰ�ť
    {
        m_Wnd.Create(0,0,400,300,L"�Ųʽ����-����"); //��������
        if(m_Wnd)
        {
 			xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
			m_btn.SetType(button_type_close);
		

			xcgui::XBtn sendmsg(100, 5, 60, 20,L"����",m_Wnd);
			XEle_RegEventCPP(sendmsg,XE_BNCLICK,&CMyWnd::OnEventBtnClick);

			XWnd_RegEventCPP(m_Wnd,WM_USER+1000,&CMyWnd::OnWndOther);
			m_Wnd.ShowWindow(SW_SHOW); //��ʾ����
            return TRUE;
        }
        return FALSE;
    }
	int OnWndOther(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		MessageBoxW(NULL,L"�յ���Ϣ",NULL,MB_OK);
		return 0;
	}
    int OnEventBtnClick(BOOL *pBool) //��ť����¼���Ӧ
    {
        //������Ϣ��
        SendMessage(m_Wnd.GetHWND(),WM_USER+1000,0,0);
        *pBool=TRUE; //�Ը��¼���������
        return 0;    //�¼��ķ���ֵ
    }
};

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}




