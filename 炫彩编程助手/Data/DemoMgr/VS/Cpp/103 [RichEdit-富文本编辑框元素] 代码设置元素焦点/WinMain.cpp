#include "Common.h"

class CMyWindowRichEdit
{
public:
    HWINDOW m_hWindow;
    HELE    m_hRichEdit;
    HELE    m_hRichEdit2;
	HELE    m_hRichEdit3;
    CMyWindowRichEdit()
    {
        Init();
    }
    void Init()
    {
		//��������Ҫ��ʾ��δ������ý���
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"�Ųʽ���ⴰ��", NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);

        m_hRichEdit=XRichEdit_Create(20, 40, 150, 20, m_hWindow);
        XRichEdit_InsertString(m_hRichEdit, L"1");

        m_hRichEdit2=XRichEdit_Create(20, 80, 150, 20, m_hWindow);
        XRichEdit_InsertString(m_hRichEdit, L"2");

		m_hRichEdit3=XRichEdit_Create(20, 120, 150, 20, m_hWindow);
        XRichEdit_InsertString(m_hRichEdit, L"3");


		//���ý���
		XWnd_SetFocusEle(m_hWindow,m_hRichEdit2);

		//���б����Ӻ󣬴�ҿ��԰�tab�����л�����

        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowRichEdit  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}

