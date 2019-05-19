#include "Common.h"

class CMyWindowRichEdit
{
public:
    HWINDOW m_hWindow;
    HELE    m_hRichEdit;
    CMyWindowRichEdit()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"�Ųʽ���ⴰ��", NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);

        m_hRichEdit=XRichEdit_Create(20, 40, 150, 20, m_hWindow);
        XRichEdit_InsertString(m_hRichEdit, L"123456");
    
		XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE(m_hRichEdit,TRUE);

		//�ֶ����� XE_RICHEDIT_CHANGE �¼�
		XEle_PostEvent(m_hRichEdit,m_hRichEdit,XE_RICHEDIT_CHANGE,NULL,NULL);

		XEle_RegEventCPP(m_hRichEdit,XE_RICHEDIT_CHANGE, &CMyWindowRichEdit::OnRichEditChange);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }

	
	///�û��޸������¼�,ֻ�е��û�����ʱ�Żᴥ��,��Ҫ��������Ч, XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE()��
	/// XRichEdit_SetText()��XRichEdit_InsertString()���ᴥ�����¼�
	
	int OnRichEditChange(BOOL *pbHandled)
	{
		return 0;
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

