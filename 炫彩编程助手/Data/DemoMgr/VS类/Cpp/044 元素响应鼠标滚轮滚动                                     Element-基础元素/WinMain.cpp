#include "Common.h"




//�¼���Ӧ

int CALLBACK OnMouseWheel(UINT nFlags,POINT *pPt,BOOL *pbHandled)
{
	MessageBoxW(NULL,L"���յ������ֹ�����Ϣ!",L"��ʾ",MB_OK);
	return 0;
}
int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
	xcgui::XWnd m_Wnd(0, 0, 400, 300, L"�Ųʽ���ⴰ��");
    if(m_Wnd)
    {
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Wnd);
		btn.SetType(button_type_close);

		xcgui::XEle ele(0,0,100,100,m_Wnd);
		ele.EnableEvent_XE_MOUSEWHEEL(TRUE);
		ele.RegEventC(XE_MOUSEWHEEL,OnMouseWheel);

		m_Wnd.ShowWindow(SW_SHOW);//��ʾ����
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}


