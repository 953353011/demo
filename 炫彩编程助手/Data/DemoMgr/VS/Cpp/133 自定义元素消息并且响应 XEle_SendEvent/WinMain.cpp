#include "Common.h"


#define XE_USER 999

class CMyWindowElement
{
public:
    HWINDOW m_hWindow;
	HELE    m_hEle;
	HELE    m_hBtn;
    CMyWindowElement(){
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"�Ųʽ���ⴰ��",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);
		

		m_hBtn = XBtn_Create(10,30,100,25,L"������Ϣ",m_hWindow);
		XEle_RegEventCPP(m_hBtn,XE_BNCLICK,&CMyWindowElement::OnBtnClick);

		

        m_hEle=XEle_Create(20,50,100,100,m_hWindow);
		XEle_RegEventCPP(m_hEle,XE_ELEPROCE, &CMyWindowElement::OnEventProc);
		
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnBtnClick(BOOL *pbHandled)
	{

		
// 		int WINAPI XEle_SendEvent  ( HELE  hEle,  
// 			HELE  hEventEle,  
// 			int  nEvent,  
// 			WPARAM  wParam,  
// 			LPARAM  lParam  
// 			)   
// 			
// 			
// 			�����¼�. 
// 			����:
// 			hEle Ŀ��Ԫ�ؾ��.  
// 			hEventEle �����¼�Ԫ�ؾ��.  
// 			nEvent �¼�����.  
// 			wParam ����.  
// 			lParam ����.  
// 			����:�¼�����ֵ. 

		XEle_SendEvent(m_hEle,m_hBtn,XE_USER,0,0);
		return 0;
	}
	int OnEventProc(UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)
	{
		switch (nEvent)
		{
		case XE_USER:
			{
				MessageBoxA(NULL,NULL,NULL,MB_OK);
				*pbHandled = TRUE;
			}
			break;
		}
		return 0;
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




