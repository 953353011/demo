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

			HELE hTabbar = XTabBar_Create(8,30,384,40,m_hWindow);

			XTabBar_EnableClose(hTabbar,TRUE);

			XTabBar_AddLabel(hTabbar,L"��ť1");
			XTabBar_AddLabel(hTabbar,L"��ť2");

			
			//XTabBar_EnableTile(hTabbar,TRUE);

			SIZE sz={20,20};
			XTabBar_SetCloseSize(hTabbar,&sz);
			
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //��ʾ����
            return TRUE;
        }
        return FALSE;
    }

};

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}




