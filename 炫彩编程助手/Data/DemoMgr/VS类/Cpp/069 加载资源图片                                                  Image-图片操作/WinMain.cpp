#include "Common.h"

#include "resource.h"

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

    g_Wnd.Create(0,0,300,200,L"�Ųʽ����-����");//��������
    if(g_Wnd)
    {

		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",g_Wnd);
		m_btn.SetType(button_type_close);
		

        XEle_RegEventC(XBtn_Create(100,5,80,25,L"��ť",g_Wnd),XE_BNCLICK,My_EventBtnClick);//ע�ᰴť����¼�
		
		XBkM_AddImage(
			XWnd_GetBkManager(g_Wnd),
			window_state_body_leave,
			XImage_LoadRes(IDR_JPG2,L"JPG",TRUE));


		g_Wnd.ShowWindow(SW_SHOW); //��ʾ����
		
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}


