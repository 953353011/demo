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
		XDrawDc.SetBrushColor(0);
		XDCGDI XGdiDC(hDraw);
		XGdiDC.SetBrushColor(0,0);
		XDCGDIPlus GdiplusDC(hDraw);

		TestTriangle(&XDrawDc,&XGdiDC,&GdiplusDC);
		
		return 0;
	}

	void TestTriangle(XDCDraw* pXDrawDC,XDCGDI* pXGdiDC,XDCGDIPlus* pGdiPlusDC)
	{

		

		XTDCTriangle<XDCDraw> DrawTriangle;
		DrawTriangle.Create(100,100,30,30);
		DrawTriangle.SetDirection(Triangle_Direction_Bottom);
		DrawTriangle.SetDrawLine(FALSE);
		DrawTriangle.Draw(pXDrawDC);


		XTDCTriangle<XDCGDI> GDITriangle;
		GDITriangle.Create(140,100,30,30);
		GDITriangle.SetDirection(Triangle_Direction_Bottom);
		GDITriangle.SetDrawLine(FALSE);
		GDITriangle.Draw(pXGdiDC);
		
		XTDCTriangle<XDCGDIPlus> GdiPlusTriangle;
		GdiPlusTriangle.Create(170,100,30,30);
		GdiPlusTriangle.SetDirection(Triangle_Direction_Bottom);
		GdiPlusTriangle.SetDrawLine(FALSE);
		GdiPlusTriangle.Draw(pGdiPlusDC);


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




