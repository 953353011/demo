#include "Common.h"



class CMyWnd
{
public:
    xcgui::XWnd m_Wnd;
	
    BOOL Create() //�������ںͰ�ť
    {
		m_Wnd.Create(0, 0, 350, 400, L"�Ųʽ���ⴰ��");

        if(m_Wnd)
        {
			xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Wnd);
			btn.SetType(button_type_close);

			xcgui::XBtn btnPopup(10,35,80,25,L"����ģ̬����",m_Wnd);
            XEle_RegEventCPP(btnPopup,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //ע�ᰴť����¼�
			
            m_Wnd.ShowWindow(SW_SHOW); //��ʾ����
            return TRUE;
        }
        return FALSE;
    }
    int OnEventBtnClick(BOOL *pBool) //��ť����¼���Ӧ
    {
        //������Ϣ��
		xcgui::XModalWnd modalWnd(200,200,L"����",m_Wnd.GetHWND());

		xcgui::XBtn btn(10, 5, 60, 20,L"close",modalWnd);
		btn.SetType(button_type_close);

		modalWnd.DoModal();
        
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




