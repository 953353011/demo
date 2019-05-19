#include "Common.h"

class CMyWindowElement
{
public:
    HWINDOW m_hWindow;
    CMyWindowElement(){
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"�Ųʽ���ⴰ��",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);
		
        HELE hEle=XEle_Create(20,50,100,100,m_hWindow);

		HBKM hBkM = XEle_GetBkManager(hEle);
		XBkM_AddFill(hBkM,element_state_flag_leave,RGB(0,128,0),255);
		//���������һ��ͼƬ����䱳������ô���������������
		//XBkM_AddImage(hBkM,element_state_flag_leave,)
		

		//�������˵һ��element_state_flag_leave ��������״̬���������
		//���İ����ĵ������״̬

		//���״̬����һ�����Ե���������  _state_flag_ �мɣ�

        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowElement  MyWindowt;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}




