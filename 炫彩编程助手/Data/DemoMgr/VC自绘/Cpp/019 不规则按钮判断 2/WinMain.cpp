#define  USE_GDIPACK
#define USE_GDIPLUS
#include "Common.h"
#include "DrawPack.h"



class CVirtualButton
{
public:
	CVirtualButton()
	{
		m_State = button_state_leave;
	}
	//����״̬ͼƬ����һ����С
	void Load(const wchar_t* lpszImageLeave,const wchar_t* lpszImageStay,const wchar_t* lpszImageDown)
	{
		m_pBitMap = new Gdiplus::Bitmap(lpszImageLeave);
		if (lpszImageLeave)
			m_hImageLeave = XImage_LoadFile(lpszImageLeave);
		if (lpszImageStay)
			m_hImageStay = XImage_LoadFile(lpszImageStay);
		if (lpszImageDown)
			m_hImageDown = XImage_LoadFile(lpszImageDown);
	}

	int OnLButtonDown(UINT nFlags, POINT *pPt,BOOL* pbHandled)
	{

		if (IsPtTransparent(pPt))
		{
			if (m_State != button_state_leave)
			{
				m_State = button_state_leave;
				return 1;
			}

		}else
		{
			if (m_State != button_state_down)
			{
				*pbHandled = TRUE;
				m_State = button_state_down;
				return 1;
			}

		}

		return 0;
	}
	int OnMouseMove(UINT nFlags, POINT *pPt,BOOL* pbHandled)
	{
		if (IsPtTransparent(pPt))
		{
			if (m_State != button_state_leave)
			{
				m_State = button_state_leave;
				return 1;
			}	
		}
		else
		{
			if (m_State != button_state_stay)
			{
				m_State = button_state_stay;
				return 1;
			}
			
		}

		return 0;
	}
	int OnLButtonUp(UINT nFlags,POINT *pPt,BOOL* pbHandled)
	{
		if (IsPtTransparent(pPt))
		{
			if ( m_State != button_state_leave)
			{
				*pbHandled = TRUE;
				m_State = button_state_leave;
				return 1;
			}
		}
 		else
		{
			if (m_State != button_state_stay)
			{
				m_State = button_state_stay;
				return 1;
			}

		}
		return 0;
	}
	VOID OnMouseLeave()
	{
		m_State = button_state_leave;
	}
	VOID OnDraw(HDRAW hDraw)
	{
		switch (m_State)
		{
		case button_state_leave:
			XDraw_Image(hDraw,m_hImageLeave,0,0);
			break;
		case button_state_stay:
			XDraw_Image(hDraw,m_hImageStay,0,0);
			break;
		case button_state_down:
			XDraw_Image(hDraw,m_hImageDown,0,0);
			break;
		}
//		xtracew(L"%d ",m_State);
	}
	button_state_ GetState()
	{
		return m_State;
	}
private:
	//������Ƿ�͸��
	BOOL IsPtTransparent(POINT* pPt)
	{
		m_pBitMap->GetPixel(pPt->x,pPt->y,&cor);
		return (cor.GetAlpha() == 0)?TRUE:FALSE;
	}

private:
	Gdiplus::Bitmap* m_pBitMap;
	Gdiplus::Color cor;

	HIMAGE m_hImageLeave;
	HIMAGE m_hImageStay;
	HIMAGE m_hImageDown;

	button_state_ m_State;
};

class CAutoReDraw
{
public:
	CAutoReDraw(HELE hEle)
	{
		m_hEle = hEle;
	}
	~CAutoReDraw()
	{
		if (m_nStat == 1)
			XEle_RedrawEle(m_hEle);	
	}
	VOID SetState(int nStat)
	{
		m_nStat = nStat;
	}
private:
	HELE m_hEle;
	int  m_nStat;
};


class CMyWnd
{
public:
    HWINDOW m_hWindow; //���ھ��
	HELE    m_hEle;
	XMathTool m_MathTool;
	CVirtualButton m_Image;
	CVirtualButton m_Image2;

	int OnLButtonDown(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		CAutoReDraw AutoReDraw(m_hEle);
		BOOL bHandled = FALSE;
		AutoReDraw.SetState(m_Image.OnLButtonDown(nFlags,pPt,&bHandled));
		if (bHandled == TRUE)
		{
			MessageBoxW(NULL,L"��ť1�����",L"��ʾ",MB_OK);
			return 0;
		}

		AutoReDraw.SetState(m_Image2.OnLButtonDown(nFlags,pPt,&bHandled));
		if (bHandled == TRUE)
		{
			MessageBoxW(NULL,L"��ť2�����",L"��ʾ",MB_OK);
			return 0;
		}

		return 0;
	}
	int OnLButtonUp(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		CAutoReDraw AutoReDraw(m_hEle);
		BOOL bHandled = FALSE;

		AutoReDraw.SetState(m_Image.OnLButtonUp(nFlags,pPt,&bHandled));
		if (bHandled == TRUE)
			return 0;
		AutoReDraw.SetState(m_Image2.OnLButtonUp(nFlags,pPt,&bHandled));
		if (bHandled == TRUE)
			return 0;

		return 0;
	}
	int OnMouseMove(UINT nFlags, POINT *pPt, BOOL *pbHandled)
	{
		CAutoReDraw AutoReDraw(m_hEle);
		BOOL bHandled = FALSE;
		int nState = m_Image.OnMouseMove(nFlags,pPt,&bHandled);
		int nState2 = m_Image2.OnMouseMove(nFlags,pPt,&bHandled);

		AutoReDraw.SetState(nState|nState2);
		return 0;
	}
	int OnMouseLeave(HELE hEleStay,BOOL *pbHandled)
	{
		m_Image.OnMouseLeave();
		m_Image2.OnMouseLeave();
		XEle_RedrawEle(m_hEle);
		return 0;
	}
	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		DWORD dwT = GetTickCount();
		m_Image.OnDraw(hDraw);
		m_Image2.OnDraw(hDraw);
//		xtracew(L"��ʱ--%d \r\n  ",GetTickCount()-dwT);
		return 0;
	}
    BOOL Create() //�������ںͰ�ť
    {
        m_hWindow=XWnd_Create(0,0,500,500,L"�Ųʽ����-����"); //��������
        if(m_hWindow)
        {
			//���������Ե���ͼƬ��С��һ�£���������ͼ��ͨ���ж�ͼƬ
			//͸���ȣ��ﵽ͸����͸

			m_hEle = XBtn_Create(100,100,255,255,NULL,m_hWindow);
			XEle_EnableBkTransparent(m_hEle,TRUE);
			XEle_EnableDrawFocus(m_hEle,FALSE);
			XEle_RegEventCPP(m_hEle,XE_PAINT,&CMyWnd::OnDraw);
			XEle_RegEventCPP(m_hEle,XE_MOUSEMOVE,&CMyWnd::OnMouseMove);
			XEle_RegEventCPP(m_hEle,XE_LBUTTONDOWN,&CMyWnd::OnLButtonDown);
			XEle_RegEventCPP(m_hEle,XE_MOUSELEAVE,&CMyWnd::OnMouseLeave);
			XEle_RegEventCPP(m_hEle,XE_LBUTTONUP,&CMyWnd::OnLButtonUp);

			m_Image.Load(L"1.png",L"1.2.png",L"1.3.png");
			m_Image2.Load(L"2.png",L"2.2.png",L"2.3.png");

            XWnd_ShowWindow(m_hWindow,SW_SHOW); //��ʾ����
            return TRUE;
        }
        return FALSE;
    }

};


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{

    XInitXCGUI(); //��ʼ��
    CMyWnd  MyWnd;
    if(MyWnd.Create())
        XRunXCGUI(); //����
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}




