#include "Common.h"



int CALLBACK OnTabBarSelectC(int iItem, BOOL *pbHandled)
{

	return 0;
}
class CMyWnd
{
public:
    HWINDOW m_hWindow; //���ھ��
    HELE    m_hButton; //��ť���
	
	int OnTabBarSelect(int iItem, BOOL *pbHandled)
	{
		return 0;
	}
    BOOL Create() //�������ںͰ�ť
    {
        m_hWindow=XWnd_Create(0,0,400,300,L"�Ųʽ����-����"); //��������
        if(m_hWindow)
        {

			HELE hTabbar = XTabBar_Create(8,30,384,20,m_hWindow);

			XTabBar_AddLabel(hTabbar,L"��ť1");
			XTabBar_AddLabel(hTabbar,L"��ť2");

			XEle_RegEventCPP(hTabbar,XE_TABBAR_SELECT,&CMyWnd::OnTabBarSelect);
			
			XEle_RegEventC(hTabbar,XE_TABBAR_SELECT,OnTabBarSelectC);

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




