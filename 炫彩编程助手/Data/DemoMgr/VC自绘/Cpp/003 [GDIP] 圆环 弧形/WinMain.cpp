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

		TestArc(&XDrawDc,&XGdiDC,&GdiplusDC);
		
		return 0;
	}

	void TestArc(XDCDraw* pXDrawDC,XDCGDI* pXGdiDC,XDCGDIPlus* pGdiPlusDC)
	{
		pGdiPlusDC->SetSmoothingMode(SmoothingModeHighQuality);
		XGDIPlusRing Ring;
		Ring.Create(10,10,100,100);
		Ring.SetSize(15);
		Ring.SetColor(RGB(190,90,90),255);
		Ring.Draw(pGdiPlusDC);

		XGDIPlusArc  Arc;
		Arc.Create(10,10,100,100);
		Arc.SetColor(RGB(77,74,207),255);
		Arc.SetAngle(0,90);
		Arc.SetSize(25);
		Arc.Draw(pGdiPlusDC);
		pGdiPlusDC->SetSmoothingMode(SmoothingModeHighSpeed);
		
		const wchar_t* pStr = L"�����˵ĵ�һ�������";
		RECT rt = {0,0,200,20};
		pXDrawDC->SetBrushColor(RGB(255,128,0),255);
		pXDrawDC->DrawText(pStr,wcslen(pStr),&rt);
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




