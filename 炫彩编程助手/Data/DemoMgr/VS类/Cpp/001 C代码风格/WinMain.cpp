#include "Common.h"



xcgui::XWnd g_Wnd;
//�¼���Ӧ
int CALLBACK My_EventBtnClick(BOOL *pBool)
{
    //������Ϣ��
    MessageBoxW(g_Wnd.GetHWND(),L"�����˰�ť",L"��ʾ",MB_OK);
    *pBool=TRUE; //�Ը��¼���������
    return 0;    //�¼��ķ���ֵ
}

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
    if(g_Wnd.Create(0,0,300,200,L"�Ųʽ����-����"))//��������
    {
		xcgui::XBtn btn;
		btn.Create(10,10,80,25,L"��ť",g_Wnd);
		btn.RegEventC(XE_BNCLICK,My_EventBtnClick);

		
        g_Wnd.ShowWindow(SW_SHOW);//��ʾ����
		
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}


