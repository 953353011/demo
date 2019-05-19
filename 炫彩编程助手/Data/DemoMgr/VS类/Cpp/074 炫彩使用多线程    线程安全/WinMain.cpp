#include "Common.h"


xcgui::XWnd g_Wnd;
xcgui::XEle g_Ele;
xcgui::XShapeText g_ShapeText;

#define XE_USER_SETTEXT WM_USER+999




int CALLBACK OnEventProc(HELE hEventEle, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)
{
	switch(nEvent)
	{
	case XE_USER_SETTEXT:
		{
			g_ShapeText.SetText((wchar_t*)wParam);
			XEle_RedrawEle(hEventEle);
		}
		break;
	}
	return 0;
}

int CALLBACK OnSetText(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
{
	g_Ele.SendEvent(g_Ele,XE_USER_SETTEXT,wParam,lParam);
	return 0;
}

DWORD WINAPI ThreadPro(LPVOID lpVoid)
{
	SYSTEMTIME tm;
	for (int i = 0; i < 10; i++)
	{
		wchar_t buffer[MAX_PATH] ={0};
		GetSystemTime(&tm);
		wsprintfW(buffer,L"%d:%d",tm.wMinute,tm.wSecond);
		SendMessageW(g_Wnd.GetHWND(),XE_USER_SETTEXT,(WPARAM)buffer,wcslen(buffer));
		Sleep(1000);
	}
	return 0;
}

//��Ϣ·�ɷ�ʽ �߳�->�����Զ�����Ϣ����->Ԫ�ع���
//


//�¼���Ӧ
int CALLBACK My_EventBtnClick(BOOL *pBool)
{
    CloseHandle(CreateThread(NULL,0,ThreadPro,NULL,0,NULL));
    *pBool=TRUE; //�Ը��¼���������
    return 0;    //�¼��ķ���ֵ
}

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
    g_Wnd.Create(0,0,300,200,L"�Ųʽ����-����");//��������
    if(g_Wnd)
    {
		g_Ele.Create(8,30,100,50,g_Wnd);
		//��Ϊ��״����û���¼������Դ���һ�� ele��Ϊ����Ȼ����ܸ�����Ϣ
		g_ShapeText.Create(0,0,100,20,L"��ʼ��",g_Ele);
		g_Ele.RegEventC1(XE_ELEPROCE,OnEventProc);


		xcgui::XBtn test(10,5,80,20,L"�����߳�",g_Wnd); //������ť
		test.RegEventC(XE_BNCLICK,My_EventBtnClick);    //ע�ᰴť����¼�

		g_Wnd.RegEventC(XE_USER_SETTEXT,OnSetText);
		g_Wnd.ShowWindow(SW_SHOW);
		
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}


