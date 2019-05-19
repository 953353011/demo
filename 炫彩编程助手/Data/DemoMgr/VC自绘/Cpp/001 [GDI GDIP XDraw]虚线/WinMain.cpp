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

            XWnd_ShowWindow(m_hWindow,SW_SHOW); //��ʾ����
            return TRUE;
        }
        return FALSE;
    }

	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		XDCDraw XDrawDc(hDraw);
		XDraw_EnableSmoothingMode(hDraw,FALSE);
		XDCGDI XGdiDC(hDraw);
		XGdiDC.SetBrushColor(0,0);
		XDCGDIPlus GdiplusDC(hDraw);

		testDottedline(&XDrawDc,&XGdiDC,&GdiplusDC);
		
		return 0;
	}

	VOID testDottedline(XDCDraw* pXDrawDC,XDCGDI* pXGdiDC,XDCGDIPlus* pGdiPlusDC)
	{
		pXDrawDC->SetBrushColor(0);
		XTDCDottedline<XDCDraw> DrawLine;
		DrawLine.Create(10,10,100,0);
		DrawLine.Draw(pXDrawDC);

		XTDCDottedline<XDCGDI> GDILine;
		GDILine.Create(10,20,100,0);
		GDILine.Draw(pXGdiDC);

		XTDCDottedline<XDCGDIPlus> GDIPlusLine;
		GDIPlusLine.Create(10,30,100,0);
		GDIPlusLine.Draw(pGdiPlusDC);
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




