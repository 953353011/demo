#include "Common.h"



DWORD WINAPI ThreadProc(LPVOID lpThreadParameter)
{
	HWINDOW m_hWindow=XWnd_Create(0,0,400,300,L"�Ųʽ����-����"); //��������
	if(m_hWindow)
	{
		HELE m_hButton =XBtn_Create(10,10,80,25,L"��ť",m_hWindow); //������ť
		XBtn_SetType(m_hButton,button_type_close);
		XWnd_ShowWindow(m_hWindow,SW_SHOW); //��ʾ����

		MSG msg;
		while(GetMessage(&msg,NULL,0,0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
    }
	return 0;
}


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
			
			XWnd_RegEventCPP(m_hWindow,XWM_WINDPROC,&CMyWnd::OnWndProc);
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //��ʾ����
            return TRUE;
        }
        return FALSE;
    }
	int OnWndProc(UINT message, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)
	{

		char buffer[MAX_PATH] = {0};
		sprintf(buffer,"%d \r\n",message);
		OutputDebugStringA(buffer);
		return 0;
	}
    int OnEventBtnClick(BOOL *pBool) //��ť����¼���Ӧ
    {

		CreateThread(NULL,0,ThreadProc,NULL,0,NULL);
        //������Ϣ��
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




