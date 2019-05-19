#include "Common.h"

class CMyWindowRichEdit
{
public:
    HWINDOW m_hWindow;
    HELE    m_hRichEdit;
    HELE    m_hRichEdit2;
    CMyWindowRichEdit()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 500, 500, L"�Ųʽ���ⴰ��", NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);

        m_hRichEdit=XRichEdit_Create(20, 40, 400, 400, m_hWindow);
        XRichEdit_InsertString(m_hRichEdit, L"123456");

		XRichEdit_InsertImage(m_hRichEdit,XImage_LoadFile(L"demo.png"),L"demo.png");
    
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

