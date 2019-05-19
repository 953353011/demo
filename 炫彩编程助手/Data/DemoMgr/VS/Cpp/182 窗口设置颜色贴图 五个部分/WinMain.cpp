#include "Common.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //���ھ��
    HELE    m_hButton; //��ť���
	
    BOOL Create() //�������ںͰ�ť
    {
        m_hWindow=XWnd_Create(0,0,400,300,L"�Ųʽ����-����"); //��������
        if(m_hWindow)
        {
            m_hButton =XBtn_Create(10,10,80,25,L"��ť",m_hWindow); //������ť
            XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //ע�ᰴť����¼�
			

			HBKM hBkM = XWnd_GetBkManager(m_hWindow);
			//�����Ҫ��ͼ����ʹ��XBkM_AddImage
			XBkM_AddFill(hBkM,window_state_flag_left_leave,RGB(128,0,0),255);
			XBkM_AddFill(hBkM,window_state_flag_top_leave,RGB(0,128,0),255);
			XBkM_AddFill(hBkM,window_state_flag_right_leave,RGB(0,0,128),255);
			XBkM_AddFill(hBkM,window_state_flag_bottom_leave,RGB(128,128,128),255);
			XBkM_AddFill(hBkM,window_state_flag_body_leave,RGB(128,128,0),255);
				

			
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //��ʾ����
            return TRUE;
        }
        return FALSE;
    }
    int OnEventBtnClick(BOOL *pBool) //��ť����¼���Ӧ
    {
        //������Ϣ��
        MessageBoxW(XWnd_GetHWND(m_hWindow),L"�����˰�ť",L"��ʾ",MB_OK);
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




