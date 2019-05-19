#include "Common.h"



class CWindow_Demo
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XEle m_ele;
    CWindow_Demo()
    {
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 500, 400, L"�Ųʽ���ⴰ��");
		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);
		

		m_ele.Create(8,30,250,150,m_Wnd);
		m_ele.GetBkManager().AddFill(element_state_flag_leave,RGB(0,128,0),255);

		XEle_RegEventCPP(m_ele,XE_PAINT,&CWindow_Demo::OnDraw);
		XWnd_RegEventCPP(m_Wnd,WM_DESTROY,&CWindow_Demo::OnDestroy);

        m_Wnd.ShowWindow(SW_SHOW);
    }
	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
// 		RECT rt = {100,50,200,100};
// 		XDraw_GradientFill2(hDraw,RGB(255,0,0),255,RGB(0,255,0),255,&rt,GRADIENT_FILL_RECT_H);
// 		//���������Ĵ��룬���޷����Ƴ�������Ľ������ġ���ʱ��Ҫ
// 		*pbHandled = TRUE;
// 		//���������������Ϣ����ô��ı����޷���ʾ��������ȷ�����������������Ĵ���


//		���Ҫ���ԣ�����ע������Ĵ��룬�������ע��ȡ�������������ܿ���Ч����

		RECT rtBkInfoM = {0,0,250,150};
		m_ele.GetBkManager().Draw(element_state_flag_leave,hDraw,&rtBkInfoM);

		RECT rt = {100,50,200,100};
		XDraw_GradientFill2(hDraw,RGB(255,0,0),255,RGB(0,255,0),255,&rt,GRADIENT_FILL_RECT_H);
		*pbHandled = TRUE;

		return 0;
	}
    int OnDestroy(BOOL* pbHandled)
    {
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CWindow_Demo  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}





