#include "Common.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //���ھ��
    HELE    m_hButton; //��ť���
	
    BOOL Create() //�������ںͰ�ť
    {
		
        m_hWindow=XWnd_Create(0,0,400,300,L"�Ųʽ����-����"); //��������
        if(m_hWindow)
        {

			HXCGUI hLayoutBody = XLayout_Create();
			XWnd_BindLayoutObject(m_hWindow,window_position_body,hLayoutBody);
			XLayout_SetLayoutHeight(hLayoutBody,layout_size_type_fill,1);
			XLayout_SetLayoutWidth(hLayoutBody,layout_size_type_fill,1);
			XLayout_SetPadding(hLayoutBody,5,5,5,5);


			HELE hEleBody = XEle_Create(0,0,100,100,m_hWindow);
			XEle_SetLayoutWidth(hEleBody,layout_size_type_fill,1);
			XEle_SetLayoutHeight(hEleBody,layout_size_type_fill,1);
			XLayout_AddEle(hLayoutBody,hEleBody);


			XWnd_SetTransparentType(m_hWindow,window_transparent_shadow);
			XWnd_SetTransparentAlpha(m_hWindow,255);
			XWnd_SetShadowInfo(m_hWindow,10,222,5,TRUE,10);


			XWnd_AdjustLayout(m_hWindow);
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //��ʾ����
            return TRUE;
        }
        return FALSE;
    }
};

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
	XC_SetLayoutFrameColor(255);
	XC_ShowLayoutFrame(TRUE);
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}




