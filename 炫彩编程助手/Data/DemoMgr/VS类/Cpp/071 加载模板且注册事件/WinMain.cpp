#include "Common.h"



class CMyWnd
{
public:

	xcgui::XWnd m_Wnd;
	
    BOOL Create() //�������ںͰ�ť
    {
		m_Wnd.CreateFromLayout(L"����ģ��\\resource.xml",L"����ģ��",L"����ģ��\\layout.xml");

        if(m_Wnd)
        {
			xcgui::XBtn btnClose(10, 5, 60, 20,L"close",m_Wnd);
			btnClose.SetType(button_type_close);

			xcgui::XBtn btn;
			btn.CreateFromLayoutID(m_Wnd,10); //��Ӧģ������ ID = 10;
            XEle_RegEventCPP(btn,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //ע�ᰴť����¼�
			
			m_Wnd.AdjustLayout();
			m_Wnd.ShowWindow(SW_SHOW); //��ʾ����
            return TRUE;
        }
        return FALSE;
    }
    int OnEventBtnClick(BOOL *pBool) //��ť����¼���Ӧ
    {
        //������Ϣ��
        MessageBoxW(m_Wnd.GetHWND(),L"�����˰�ť",L"��ʾ",MB_OK);
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




