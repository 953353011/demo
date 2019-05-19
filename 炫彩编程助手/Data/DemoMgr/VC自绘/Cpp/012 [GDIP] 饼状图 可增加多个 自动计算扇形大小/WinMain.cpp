#define  USE_GDIPACK
#define USE_GDIPLUS
#include "Common.h"
#include "DrawPack.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //���ھ��
	HELE    m_hEle;

    BOOL Create() //�������ںͰ�ť
    {
        m_hWindow=XWnd_Create(0,0,350,350,L"�Ųʽ����-����"); //��������
        if(m_hWindow)
        {
 			m_hEle = XEle_Create(8,30,300,300,m_hWindow);
 			XEle_RegEventCPP(m_hEle,XE_PAINT, &CMyWnd::OnDraw);

			srand(GetTickCount());
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //��ʾ����
            return TRUE;
        }
        return FALSE;
    }

	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		XDCDraw XDrawDc(hDraw);
		XDrawDc.SetBrushColor(0);
		XDCGDI XGdiDC(hDraw);
		XGdiDC.SetBrushColor(0,0);
		XDCGDIPlus GdiplusDC(hDraw);

		TestPie(&XDrawDc,&XGdiDC,&GdiplusDC);
		
		return 0;
	}

	void TestPie(XDCDraw* pXDrawDC,XDCGDI* pXGdiDC,XDCGDIPlus* pGdiPlusDC)
	{
		pGdiPlusDC->SetSmoothingMode(SmoothingModeHighQuality);
		{
			XGDIPlusPieSix pie;
			pie.Create(0,100,100,100);
			pie.AddPieInfo(1,RGB(255,255,0));
			pie.AddPieInfo(2,RGB(255,0,255));
			pie.AddPieInfo(3,RGB(0,255,255));
			pie.AddPieInfo(4,RGB(128,128,128));
			pie.AutoCalc();
			pie.Draw(pGdiPlusDC);
		}
		pGdiPlusDC->SetSmoothingMode(SmoothingModeHighSpeed);
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




