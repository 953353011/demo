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

		TestCpuUseage(&XDrawDc,&XGdiDC,&GdiplusDC);
		
		return 0;
	}

	void TestCpuUseage(XDCDraw* pXDrawDC,XDCGDI* pXGdiDC,XDCGDIPlus* pGdiPlusDC)
	{
/*
		XTemplateDCCpuUsage<XDrawDC> CpuUseage;
		pXDrawDC->SetBrushColor(0);
		CpuUseage.Create(10,10,200,150);
		CpuUseage.SetGraduationCount(11,11);

		for (int i = 0; i <= 10; i++)
		{
			CpuUseage.PushPoint(i,rand()%10);
		}
		CpuUseage.Draw(pXDrawDC);
*/
/*
		XTemplateDCCpuUsage<XGDIDC> CpuUseage;
		pXDrawDC->SetBrushColor(0);
		CpuUseage.Create(10,10,200,150);
		CpuUseage.SetGraduationCount(11,11);
		
		for (int i = 0; i <= 10; i++)
		{
			CpuUseage.PushPoint(i,rand()%10);
		}
		CpuUseage.Draw(pXGdiDC);
*/
		XTDCCpuUsage<XDCGDIPlus> CpuUseage;
		CpuUseage.Create(10,10,200,150);
		CpuUseage.SetGraduationCount(11,11);
		
		for (int i = 0; i <= 10; i++)
		{
			CpuUseage.PushPoint(i,rand()%10);
		}
		CpuUseage.Draw(pGdiPlusDC);


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




