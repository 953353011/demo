#include "Common.h"


class CMyWnd
{
public:
	xcgui::XWnd    m_wnd;
    BOOL Create() //�������ںͰ�ť
    {
		if (m_wnd.Create(0,0,300,200,L"�Ųʽ����-����"))
		{
			xcgui::XBtn m_btn(10,10,80,25,L"��ť",m_wnd);
            XEle_RegEventCPP(m_btn,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //ע�ᰴť����¼�			
			m_wnd.ShowWindow(SW_SHOW);
			return TRUE;
		}
        return FALSE;
    }
    int OnEventBtnClick(BOOL *pBool) //��ť����¼���Ӧ
    {
        //������Ϣ��
        MessageBoxW(m_wnd.GetHWND(),L"�����˰�ť",L"��ʾ",MB_OK);
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




