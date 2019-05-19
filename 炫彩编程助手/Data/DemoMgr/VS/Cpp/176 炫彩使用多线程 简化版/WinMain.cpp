#include "Common.h"


#define XE_USER_SETTEXT WM_USER+999

class XMyWnd
{
public:

	//�¼���Ӧ
	int My_EventBtnClick(BOOL *pBool)
	{
		CloseHandle(CreateThread(NULL,0,&XMyWnd::ThreadPro,m_hWindow,0,NULL));
		*pBool=TRUE; //�Ը��¼���������
		return 0;    //�¼��ķ���ֵ
	}
	int OnSetText(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		XShapeText_SetText(m_ShapeText,(wchar_t*)wParam);
		XEle_RedrawEle(m_hEle);
		return 0;
	}
	BOOL Create()
	{

		m_hWindow=XWnd_Create(0,0,300,200,L"�Ųʽ����-����");//��������
		if (m_hWindow == NULL)
			return FALSE;
		m_hEle = XEle_Create(8,30,100,50,m_hWindow);
		//��Ϊ��״����û���¼������Դ���һ�� ele��Ϊ����Ȼ����ܸ�����Ϣ
		m_ShapeText = XShapeText_Create(0,0,100,20,L"��ʼ��",m_hEle);

	
        HELE hButton=XBtn_Create(10,5,80,20,L"�����߳�",m_hWindow);//������ť
        XWnd_RegEventCPP(hButton,XE_BNCLICK,&XMyWnd::My_EventBtnClick);//ע�ᰴť����¼�
		
		
		XWnd_RegEventCPP(m_hWindow,XE_USER_SETTEXT,&XMyWnd::OnSetText);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);//��ʾ����
		return TRUE;
	}


	
static	DWORD WINAPI ThreadPro(LPVOID lpVoid)
{
HWINDOW hWindow = (HWINDOW) lpVoid;
	SYSTEMTIME tm;
	for (int i = 0; i < 10; i++)
	{
		wchar_t buffer[MAX_PATH] ={0};
		GetSystemTime(&tm);
		wsprintfW(buffer,L"%d:%d",tm.wMinute,tm.wSecond);
		SendMessageW(XWnd_GetHWND(hWindow),XE_USER_SETTEXT,(WPARAM)buffer,wcslen(buffer));
		Sleep(1000);
	}
	return 0;
}
private:

	HWINDOW  m_hWindow;
	HELE m_hEle;
	HXCGUI m_ShapeText;
};


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
    
	XMyWnd MyWnd;
    if(MyWnd.Create())
        XRunXCGUI(); //����
 
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}


