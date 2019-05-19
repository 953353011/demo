#include "Common.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //���ھ��
    HELE    m_hButton; //��ť���

	POINT   m_ptDown;
	
	int OnLButtonDown(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		m_ptDown = *pPt;		
		return 0;
	}
	int OnMouseMove(UINT nFlags, POINT *pPt, BOOL *pbHandled)
	{
		if (nFlags & MK_LBUTTON)
		{
			//˵�����϶�����
			int cx = pPt->x - m_ptDown.x;
			int cy = pPt->y - m_ptDown.y;

			RECT rt;
			
			GetWindowRect(XWnd_GetHWND(m_hWindow),&rt);

			rt.left += cx;
			rt.top  += cy;
			rt.right+= cx;
			rt.bottom+=cy;

			MoveWindow(XWnd_GetHWND(m_hWindow),rt.left,rt.top,rt.right-rt.left,rt.bottom-rt.top,TRUE);

		}
		return 0;
	}
    BOOL Create() //�������ںͰ�ť
    {
        XC_LoadResource(L".\\kugou\\resource.xml",L".\\kugou");
		m_hWindow =(HWINDOW)XC_LoadLayout(L".\\kugou\\layout.xml");
        if(m_hWindow)
        {
			m_hButton =XBtn_Create(10,10,40,25,L"�ر�",m_hWindow); //������ť
			XBtn_SetType(m_hButton,button_type_close);

			m_hBtnMid    = (HELE) XC_GetObjectByID(m_hWindow,1);
			m_hBtnLeft   = (HELE) XC_GetObjectByID(m_hWindow,2);
			m_hBtnTop    = (HELE) XC_GetObjectByID(m_hWindow,3);
			m_hBtnRight  = (HELE) XC_GetObjectByID(m_hWindow,4);
			m_hBtnBottom = (HELE) XC_GetObjectByID(m_hWindow,5);

			XEle_RegEventCPP(m_hBtnMid,XE_MOUSESTAY,&CMyWnd::OnMouseStay);
			XEle_RegEventCPP(m_hBtnMid,XE_MOUSELEAVE,&CMyWnd::OnMouseLeave);

			XEle_RegEventCPP(m_hBtnMid,XE_MOUSEMOVE,&CMyWnd::OnMouseMove);
			XEle_RegEventCPP(m_hBtnMid,XE_LBUTTONDOWN,&CMyWnd::OnLButtonDown);

			XEle_RegEventCPP(m_hBtnLeft,XE_MOUSESTAY,&CMyWnd::OnMouseStay);
			XEle_RegEventCPP(m_hBtnLeft,XE_MOUSELEAVE,&CMyWnd::OnMouseLeave);

			XEle_RegEventCPP(m_hBtnTop,XE_MOUSESTAY,&CMyWnd::OnMouseStay);
			XEle_RegEventCPP(m_hBtnTop,XE_MOUSELEAVE,&CMyWnd::OnMouseLeave);

			XEle_RegEventCPP(m_hBtnRight,XE_MOUSESTAY,&CMyWnd::OnMouseStay);
			XEle_RegEventCPP(m_hBtnRight,XE_MOUSELEAVE,&CMyWnd::OnMouseLeave);


			XEle_RegEventCPP(m_hBtnBottom,XE_MOUSESTAY,&CMyWnd::OnMouseStay);
			XEle_RegEventCPP(m_hBtnBottom,XE_MOUSELEAVE,&CMyWnd::OnMouseLeave);

			XWnd_RegEventCPP(m_hWindow,WM_TIMER,&CMyWnd::OnShowBtnTimer);

            XWnd_ShowWindow(m_hWindow,SW_SHOW); //��ʾ����
            return TRUE;
        }
        return FALSE;
    }
	int OnShowBtnTimer(UINT nIDEvent,BOOL *pbHandled)
	{
		switch (nIDEvent)
		{
		case 10:
			{
				switch (m_showIndex)
				{
				case 0:
					XEle_ShowEle(m_hBtnLeft,TRUE);
					break;
				case 1:
					XEle_ShowEle(m_hBtnTop,TRUE);
					break;
				case 2:
					XEle_ShowEle(m_hBtnRight,TRUE);
					break;
				case 3:
					XEle_ShowEle(m_hBtnBottom,TRUE);
					XWnd_KillTimer(m_hWindow,10);
					break;
				}
				XWnd_RedrawWnd(m_hWindow);
				m_showIndex++;
			}
			break;
		case 11:
			{
				switch (m_hideIndex)
				{
				case 0:
					XEle_ShowEle(m_hBtnLeft,FALSE);
					break;
				case 1:
					XEle_ShowEle(m_hBtnTop,FALSE);
					break;
				case 2:
					XEle_ShowEle(m_hBtnRight,FALSE);
					break;
				case 3:
					XEle_ShowEle(m_hBtnBottom,FALSE);
					XWnd_KillTimer(m_hWindow,11);
					break;
				}
				XWnd_RedrawWnd(m_hWindow);
				m_hideIndex++;
			}
			break;
		}
		return 0;
	}
	int OnMouseStay(BOOL *pbHandled)
	{
		m_showIndex = 0;
		XWnd_SetTimer(m_hWindow,10,150);
		return 0;
	}
	int OnMouseLeave(HELE hEleStay,BOOL *pbHandled)
	{
		if (hEleStay == NULL)
		{
			XWnd_KillTimer(m_hWindow,10); //ȷ��ǰ�治��ִ��
			m_hideIndex = 0;
			XWnd_SetTimer(m_hWindow,11,150);
		}
		return 0;
	}
	HELE m_hBtnMid;
	HELE m_hBtnLeft;
	HELE m_hBtnTop;
	HELE m_hBtnRight;
	HELE m_hBtnBottom;

	int m_showIndex;
	int m_hideIndex;
};

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}




