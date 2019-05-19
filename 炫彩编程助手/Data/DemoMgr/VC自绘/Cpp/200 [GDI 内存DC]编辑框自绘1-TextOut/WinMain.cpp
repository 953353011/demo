#define  USE_GDIPACK
#define USE_GDIPLUS
#include "Common.h"
#include "DrawPack.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //���ھ��
	HELE    m_hEle;

	XGDIMEMDC m_memDC;

    BOOL Create() //�������ںͰ�ť
    {
        m_hWindow=XWnd_Create(0,0,350,350,L"�Ųʽ����-����"); //��������
        if(m_hWindow)
        {
 			m_hEle = XEle_Create(8,30,300,300,m_hWindow);
 			XEle_RegEventCPP(m_hEle,XE_PAINT, &CMyWnd::OnDraw);

			m_memDC.Create(XEle_GetHWND(m_hEle));
			m_memDC.Resize(300,300);


            XWnd_ShowWindow(m_hWindow,SW_SHOW); //��ʾ����
            return TRUE;
        }
        return FALSE;
    }

	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		m_memDC.SelectObject(m_memDC.GetStockObject(DC_BRUSH));
		m_memDC.SetDCBrushColor(RGB(128,128,128));
		m_memDC.FillRect(0,0,300,300);

		m_memDC.SetBkMode(TRANSPARENT); //�����ֱ���͸��
		const wchar_t* lpText = L"�Ųʽ����-www.xcgui.com";
		RECT rt = {0};
		m_memDC.GetTextSize(lpText,wcslen(lpText),(SIZE*)((int*)(&rt)+2));
		rt.left += 10;
		rt.top  += 10;
		rt.right += 10;
		rt.bottom += 10;
		m_memDC.SelectObject(m_memDC.GetStockObject(DC_PEN));
		m_memDC.SetDCPenColor(RGB(0,128,0));
		m_memDC.TextOutW(rt.left,rt.top,lpText,wcslen(lpText));
		m_memDC.DrawRect1(&rt);

		m_memDC.BitBlt1(hDraw);
		return 0;
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




