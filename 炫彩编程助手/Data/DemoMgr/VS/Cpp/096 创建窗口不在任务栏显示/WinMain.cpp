#include "Common.h"



HWINDOW  hWindow=NULL;


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
	hWindow=XWnd_CreateEx(WS_EX_TOOLWINDOW,NULL,L"������������ʾ",WS_VISIBLE,0,0,500,400);
//    hWindow=XWnd_Create(0,0,300,200,L"�Ųʽ����-����");//��������
    if(hWindow)
    {
        HELE hButton=XBtn_Create(10,10,80,25,L"�ر�",hWindow);//������ť
		XBtn_SetType(hButton,button_type_close);
		
        XWnd_ShowWindow(hWindow,SW_SHOW);//��ʾ����
		
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}


