#include "sxcgui.h"
#include "sxcgui.cpp"








HWINDOW  g_hWindow=NULL;
DWORD WINAPI Thread(LPVOID lpParam)
{
	HELE hButton=SXBtn_Create(g_hWindow,10,50,80,25,L"��ť",g_hWindow);
	SXEle_RedrawEle(g_hWindow,hButton,TRUE);
	return 0;
}
//�¼���Ӧ
int CALLBACK My_EventBtnClick(BOOL *pBool)
{
    //������Ϣ��
	CreateThread(NULL,0,Thread,g_hWindow,0,NULL);
    *pBool=TRUE; //�Ը��¼���������
    return 0;    //�¼��ķ���ֵ
}
int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
    g_hWindow=XWnd_Create(0,0,300,200,L"�Ųʽ����-����");//��������
    if(g_hWindow)
    {
		SXWnd_EnableSafeFunction(g_hWindow);
		HELE hButton=XBtn_Create(10,10,80,25,L"��ť",g_hWindow);
        XEle_RegEventC(hButton,XE_BNCLICK,My_EventBtnClick);//ע�ᰴť����¼�
        XWnd_ShowWindow(g_hWindow,SW_SHOW);//��ʾ����
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ�?
	return 0;
}