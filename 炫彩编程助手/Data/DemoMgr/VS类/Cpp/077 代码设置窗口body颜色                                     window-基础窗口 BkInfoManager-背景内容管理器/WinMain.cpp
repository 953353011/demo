#include "Common.h"



class CMyWnd
{
public:
	xcgui::XWnd m_Wnd;
	
    BOOL Create() //�������ںͰ�ť
    {
		m_Wnd.Create(0,0,400,300,L"�Ųʽ����-����");
        if(m_Wnd)
        {
			xcgui::XBtn btnClose(10, 5, 60, 20,L"close",m_Wnd);
			btnClose.SetType(button_type_close);

			xcgui::XBtn btn(100,5,80,25,L"��ť",m_Wnd);
            XEle_RegEventCPP(btn,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //ע�ᰴť����¼�
			

			//���ȣ���ȡ�����������ľ����Ȼ��ͨ����������������������ɫ
			//��Ȼ����Կ�����ӱ�����ͼ���������������
			//���Ҫ�������棬��ߣ��ұߣ�������ɫ�������ɫ�����������window_state_ 
			//��ͷ�ģ�������
			m_Wnd.GetBkManager().AddFill(window_state_body_leave,RGB(128,15,50),255);
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




