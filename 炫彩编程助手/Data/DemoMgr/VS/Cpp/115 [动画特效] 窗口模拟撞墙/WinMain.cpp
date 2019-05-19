#include "Common.h"




class Bounce
{
public:
    double In(double t, double b, double c, double d)
    {
		return c - Out(d-t, 0, c, d) + b;
    }
	double Out(double t, double b, double c, double d)
    {
		if ((t/=d) < (1/2.75)) {
			return c*(7.5625*t*t) + b;
		} else if (t < (2/2.75)) {
			return c*(7.5625*(t-=(1.5/2.75))*t + .75) + b;
		} else if (t < (2.5/2.75)) {
			return c*(7.5625*(t-=(2.25/2.75))*t + .9375) + b;
		} else {
			return c*(7.5625*(t-=(2.625/2.75))*t + .984375) + b;
		}
    }
	double InOut(double t, double b, double c, double d)
    {
        if (t < d/2) return In(t*2, 0, c, d) * .5 + b;
        else return Out(t*2-d, 0, c, d) * .5 + c*.5 + b;
    }
};

// t => time(��ʼ�ǲ�����)
// b => begin(��ʼλ��)
// c => change(�仯��)
// d => duration(��������)
class XWndAnimate
{
public:
	HWINDOW m_hWindow;
	Bounce m_bounce;


	int m_y;

	int m_startX;
	int m_endX;
	int m_index;

// 	int m_startY;
// 	int m_endY;
// 	int m_tempY;
	int m_cx;
	int m_cy;

	void Create(HWINDOW hWindow)
	{
		m_hWindow = hWindow;
		XWnd_RegEventCPP(m_hWindow,WM_TIMER,&XWndAnimate::OnWndTimer);
		XWnd_SetTimer(m_hWindow,100,10);
		RestPos();
		SetWindowRect(m_startX,m_y,m_cx,m_cy);
	}

	int OnWndTimer(UINT nIDEvent,BOOL *pbHandled)
	{
		if (nIDEvent == 100)
		{
			if (m_index <= 100)
			{
				double cx = m_bounce.Out(m_index,0,m_endX,100);
				SetWindowRect(cx,m_y,m_cx,m_cy);
				m_index++;
			}else
			{
				XWnd_KillTimer(m_hWindow,nIDEvent);
			}
			
		}
		return 0;
	}


	void RestPos()
	{
		int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
		int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
		
		RECT rect;
		GetWindowRect(XWnd_GetHWND(m_hWindow), &rect);
		int nWindowWidth = rect.right - rect.left;
		int nWindowHeight= rect.bottom- rect.top;
		

		
		//��Ļ��������
		int centery = nScreenHeight/2 - nWindowHeight / 2;
		int centerx = nScreenWidth/2-nWindowWidth/2;
		
		//��Ļ����в�����
		int x = 0;
		int y = centery;

		m_y = y;
		m_startX = x;
		m_endX   = centerx;
		m_index  = 0;

		m_cx = nWindowWidth;
		m_cy = nWindowHeight;
	}
	
private:


	void SetWindowRect(int x,int y,int cx,int cy)
	{
		SetWindowPos(
			XWnd_GetHWND(m_hWindow),
			HWND_TOP,
			x,y,cx,cy,
			SWP_SHOWWINDOW);
	}

private:
	
};

class CMyWnd
{
public:
    HWINDOW m_hWindow; //���ھ��
	XWndAnimate m_Animate;
	
    BOOL Create() //�������ںͰ�ť
    {
        m_hWindow=XWnd_Create(0,0,400,300,L"�Ųʽ����-����"); //��������
        if(m_hWindow)
        {
            HELE m_hButton =XBtn_Create(10,10,80,25,L"�ر�",m_hWindow); //������ť
			XBtn_SetType(m_hButton,button_type_close);

			m_Animate.Create(m_hWindow);

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
    {
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}




