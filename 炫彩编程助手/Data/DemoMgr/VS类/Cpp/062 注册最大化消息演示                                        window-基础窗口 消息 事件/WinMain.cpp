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

int CALLBACK OnWndOther(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
{
	MINMAXINFO* pMiniMaxInfo = (MINMAXINFO*)lParam;

	//pMiniMaxInfo->ptMaxPosition
	MessageBoxW(g_Wnd.GetHWND(),L"���ڿ�ʼ���",L"����",MB_OK);
	return 0;
}

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
    g_Wnd.Create(0,0,300,200,L"�Ųʽ����-����");//��������
    if(g_Wnd)
    {
		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",g_Wnd);
		m_btn.SetType(button_type_close);

		xcgui::XBtn btnMax(100, 5, 60, 20,L"���",g_Wnd);
		btnMax.SetType(button_type_max);
		
		g_Wnd.RegEventC(WM_GETMINMAXINFO,OnWndOther);
		g_Wnd.ShowWindow(SW_SHOW);
		
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}


