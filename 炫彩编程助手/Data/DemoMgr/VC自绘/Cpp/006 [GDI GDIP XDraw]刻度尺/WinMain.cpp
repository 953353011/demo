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

		TestStaff(&XDrawDc,&XGdiDC,&GdiplusDC);
		
		return 0;
	}

	void TestStaff(XDCDraw* pXDrawDC,XDCGDI* pXGdiDC,XDCGDIPlus* pGdiPlusDC)
	{
		{
			XTDCStaffHorizon<XDCDraw> staff;
			staff.Create(10,10,200,10);
			staff.SetGraduationCount(3);
			staff.SetAlign(Staff_Align_Left);
			staff.Draw(pXDrawDC);
		}

		{
			XTDCStaffHorizon<XDCGDI> staff;
			staff.Create(10,50,200,10);
			staff.SetGraduationCount(3);
			staff.SetAlign(Staff_Align_Left);
			staff.Draw(pXGdiDC);
		}
		{
			XTDCStaffHorizon<XDCGDIPlus> staff;
			staff.Create(10,100,200,10);
			staff.SetGraduationCount(3);
			staff.SetAlign(Staff_Align_Left);
			staff.Draw(pGdiPlusDC);
		}

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




