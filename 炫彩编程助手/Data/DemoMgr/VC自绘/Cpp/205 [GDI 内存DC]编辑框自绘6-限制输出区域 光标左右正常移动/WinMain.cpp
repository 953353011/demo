#define  USE_GDIPACK
#define USE_GDIPLUS
#include "Common.h"
#include "DrawPack.h"


//��Ϊ��ͨ�ı༭���������볬������ʾ������ô���Ǿ�Ҫ����
//������ʾ�ķ�Χ ����������΢�Ľ�һ����һ�����̵Ĵ���

class CMyWnd
{
public:
    HWINDOW m_hWindow; //���ھ��
	HELE    m_hEle;

	XGDIMEMDC m_memDC;
	XCaret    m_Caret;

	std::wstring m_Text;
	RECT         m_RectText;

	int			 m_CaretInTextIndex;

	//������ʾ����
	int			 m_nTextShowOffset;
	
    BOOL Create()
    {
        m_hWindow=XWnd_Create(0,0,350,350,L"�Ųʽ����-����"); //��������
        if(m_hWindow)
        {
 			m_hEle = XEle_Create(8,35,100,20,m_hWindow);

					



			m_memDC.Create(XEle_GetHWND(m_hEle));
			m_memDC.Resize(300,300);


			//��ʼ���ַ������ַ�����ռ�ľ���
			m_Text = L"�Ųʽ����-www.xcgui.com";
			SIZE sz;
			m_memDC.GetTextSize(m_Text.c_str(),m_Text.length(),&sz);
			m_RectText.left  = 0;
			m_RectText.top   = 0;
			m_RectText.right = 100;
			m_RectText.bottom = 20;

			m_nTextShowOffset = 2;


			//������Ի�ɱ༭�ؼ�����ȱ�ٵĶ���
			m_Caret.Create(m_hEle);
			m_Caret.SetHeight(sz.cy);



			XEle_RegEventCPP(m_hEle,XE_LBUTTONDOWN,&CMyWnd::OnLButtonDown);
			XEle_RegEventCPP(m_hEle,XE_LBUTTONUP,&CMyWnd::OnLButtonUp);
			XEle_RegEventCPP(m_hEle,XE_CHAR,&CMyWnd::OnEventChar);
			XEle_RegEventCPP(m_hEle,XE_KEYDOWN,&CMyWnd::OnEventKeyDown);
			XEle_RegEventCPP(m_hEle,XE_MOUSEMOVE,&CMyWnd::OnMouseMove);
			XEle_RegEventCPP(m_hEle,XE_PAINT, &CMyWnd::OnDraw);

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


//�����ı�
		m_memDC.SelectObject(m_memDC.GetStockObject(DC_PEN));
		m_memDC.SetDCPenColor(RGB(0,128,0));
		m_memDC.TextOutW(
			m_RectText.left,
			m_RectText.top,
			m_Text.c_str()+m_nTextShowOffset,m_Text.length()-m_nTextShowOffset);


		m_memDC.BitBlt1(hDraw);
		return 0;
	}

	int OnLButtonDown(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		//����������Ҫ�жϵ��λ���Ƿ������־�����
		if (IsPtInRect2(pPt,&m_RectText) == FALSE)
		{
			//������� ���ع�꣬����
			m_Caret.Show(FALSE);
			return 0;
		}
		
		//����ڣ����жϳ������ַ���λ������
		int nLeftWidth = 0;
		int nCharLen   = 0;
		for (int i = 0; i < m_Text.length(); i++)
		{
			nCharLen = m_memDC.GetTextWidth(m_Text.c_str()+i+m_nTextShowOffset,1);
			if (m_RectText.left + nLeftWidth + nCharLen > pPt->x)
			{
				m_CaretInTextIndex = i;
				break;
			}
			nLeftWidth+=nCharLen;
		}

		m_Caret.SetPos(m_RectText.left + nLeftWidth,m_RectText.top);
		m_Caret.Show(TRUE);
		//ˢ��һ��
		XEle_RedrawEle(m_hEle);

		return 0;
	}
	int OnLButtonUp(UINT nFlags, POINT *pPt,BOOL *pbHandled)	{		return 0;	}
	int OnMouseMove(UINT nFlags, POINT *pPt, BOOL *pbHandled)	{		return 0;	}


	int GetShowCount()
	{
		int nLeftWidth = 0;
		int nCharWidth = 0;
		int nEdithWidth = m_RectText.right-m_RectText.left;
		int i = m_nTextShowOffset;
		for (; i < m_Text.length(); i++)
		{
			nCharWidth = m_memDC.GetTextWidth(m_Text.c_str()+i,1);
			if (nLeftWidth+nCharWidth > nEdithWidth)
			{
				break;
			}
			nLeftWidth+=nCharWidth;
		}
		return i-m_nTextShowOffset;
	}

	int OnEventKeyDown(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		switch (wParam)
		{
		case VK_LEFT:
			{

				if (m_CaretInTextIndex == 0)
				{
					if (m_nTextShowOffset>0)
					{
						m_nTextShowOffset--;
					}else
					{
						return 0;
					}
				}else
				{
					m_CaretInTextIndex--;
				}

				int x = m_RectText.left+m_memDC.GetTextWidth(m_Text.c_str()+m_nTextShowOffset,m_CaretInTextIndex);
				int y = m_RectText.top;

				m_Caret.SetPos(x,y);
				XEle_RedrawEle(m_hEle);
			}
			break;
		case VK_RIGHT:
			{
				//������Ҫ����һ�£���Ϊ�༭���е�ʱ��ֻ��ʾ�ı��еļ�������
				//����ʾ�����ֺ������û��ʾ��ϵġ���������Ҫ�ж�һ��
				int nMaxEditShowCharCount = GetShowCount();
				if (m_CaretInTextIndex+1 > nMaxEditShowCharCount)
				{
					if (m_CaretInTextIndex+m_nTextShowOffset+1 > m_Text.length())
						return 0;
					else
					{
						m_nTextShowOffset++;
					}
				}
				else
				{
					m_CaretInTextIndex++;
				}
		
				int x = m_RectText.left+m_memDC.GetTextWidth(m_Text.c_str()+m_nTextShowOffset,m_CaretInTextIndex);
				int y = m_RectText.top;
				
				m_Caret.SetPos(x,y);
				XEle_RedrawEle(m_hEle);

			}
			break;
		case VK_BACK:
			{
				if (m_CaretInTextIndex == 0)
					return 0;
				m_Text.erase(m_Text.begin()+--m_CaretInTextIndex);

				//���¶�λ�����λ��
				int x = m_RectText.left+m_memDC.GetTextWidth(m_Text.c_str(),m_CaretInTextIndex);
				int y = m_RectText.top;
				m_Caret.SetPos(x,y);
				XEle_RedrawEle(m_hEle);
				*pbHandled = TRUE;
			}
			break;
		}
		return 0;	
	}
	int OnEventChar(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		//��궼û��ʾ���ͱ�༭��
		if (wParam == VK_BACK)
			return 0;
		if (m_Caret.IsCaretShow() == FALSE)
			return 0;

		//���λ�ò����ַ�
		m_Text.insert(m_Text.begin()+m_CaretInTextIndex+m_nTextShowOffset,(wchar_t)wParam);
		m_CaretInTextIndex++;

		int x = m_RectText.left+m_memDC.GetTextWidth(m_Text.c_str(),m_CaretInTextIndex);
		int y = m_RectText.top;
		
		m_Caret.SetPos(x,y);
		XEle_RedrawEle(m_hEle);


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




