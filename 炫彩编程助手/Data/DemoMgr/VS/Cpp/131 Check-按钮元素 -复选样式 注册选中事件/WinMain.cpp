#include "Common.h"


class CMyWindowCheck
{
public:
    HWINDOW m_hWindow;
    HELE    m_hCheck1;
    CMyWindowCheck()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"�Ųʽ���ⴰ��",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hCheck1 = XBtn_Create(20, 40, 100, 20, L"Check1", m_hWindow);
		//���ù���Ϊѡ�к�δѡ��
        XBtn_SetType(m_hCheck1, button_type_check);  
		//���������Ϊͨ���и�С�������ʽ����ҿ���ע�Ϳ���Ч��
		XBtn_SetStyle(m_hCheck1,button_style_check); 


		XEle_RegEventCPP(m_hCheck1,XE_BUTTON_CHECK,&CMyWindowCheck::OnButtonCheck);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnButtonCheck(BOOL bCheck,BOOL *pbHandled)
	{
		xtrace("��ť�Ƿ�ѡ�� %s \r\n",bCheck?"��":"δѡ��");
		return 0;
	}
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowCheck  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}




