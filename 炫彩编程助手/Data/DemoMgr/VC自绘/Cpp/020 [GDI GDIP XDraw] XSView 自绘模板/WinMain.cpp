#define  USE_GDIPACK
#define USE_GDIPLUS
#include "Common.h"
#include "DrawPack.h"


typedef struct _chColor 
{
	int left;
	int top;
	int right;
	int bottom;
	int rowIndex;
	int colIndex;
	int cor;
}CHCOLOR;

class CTableEdit
{
public:
	HELE Create(int x,int y,int cx,int cy,HXCGUI hParent)
	{
		m_hView = XSView_Create(x,y,cx,cy,hParent);
		XSView_SetTotalSize(m_hView,cx+500,cy+500);


		XEle_RegEventCPP(m_hView,XE_LBUTTONDOWN,&CTableEdit::OnLButtonDown);
		XEle_RegEventCPP(m_hView,XE_SIZE,&CTableEdit::OnSize);
		XEle_RegEventCPP(m_hView,XE_PAINT_SCROLLVIEW,&CTableEdit::OnDrawScrollView);
		return m_hView;
	}

//Events
public:
	int OnSize(BOOL *pbHandled)
	{
		return 0;
	}
	int OnLButtonDown(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		xtrace("x:%d y:%d \r\n",pPt->x,pPt->y);
		return 0;
	}
	int OnDrawScrollView(HDRAW hDraw,BOOL *pbHandled)
	{
		XDraw_TextOut(hDraw,0,0,L"����",2);
		return 0;
	}
private:

	std::wstring m_String;
	std::vector<CHCOLOR> m_VChColor;
	XGDIMEMDC m_MemDC;

	HELE m_hView;
};


class CMyWnd
{
public:
    HWINDOW m_hWindow; //���ھ��
	HELE    m_hEle;
	CTableEdit m_TableEdit;

    BOOL Create() //�������ںͰ�ť
    {
        m_hWindow=XWnd_Create(0,0,350,350,L"�Ųʽ����-����"); //��������
        if(m_hWindow)
        {
			m_TableEdit.Create(8,30,300,300,m_hWindow);
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




