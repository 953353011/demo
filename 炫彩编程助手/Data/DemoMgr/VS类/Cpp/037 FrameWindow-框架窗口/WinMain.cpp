#include "Common.h"



class CFrameWindow_Demo
{
public:
	xcgui::XFrameWnd m_framWnd;
    HWINDOW m_hWindow;
		xcgui::XPane pane1;
		xcgui::XPane pane2;
		xcgui::XPane pane3;
		
		CFrameWindow_Demo()
		{
        Init();
    }
    void Init()
    {
		m_framWnd.Create(0, 0, 600, 400, L"�Ųʽ���ⴰ��");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_framWnd);
		btn.SetType(button_type_close);


		xcgui::XEle view(200,10,100,100,m_framWnd);
		m_framWnd.SetView(view);  //��������ͼ

		pane1.Create(L"�������",200,200,m_framWnd);
		pane2.Create(L"����ͼ",200,200,m_framWnd);
		pane3.Create(L"���Թ���",200,200,m_framWnd);

		xcgui::XPane pane4(L"�Ŷ���Դ",200,200,m_framWnd);
		xcgui::XPane pane5(L"��ʼҳ",200,200,m_framWnd);
		xcgui::XPane pane6(L"������",200,200,m_framWnd);
		xcgui::XPane pane7(L"������",200,200,m_framWnd);
		xcgui::XPane pane8(L"���",200,200,m_framWnd);

		m_framWnd.AddPane(NULL,pane1,align_left); //��Ӵ���
		m_framWnd.AddPane(NULL,pane5,align_right);
		m_framWnd.AddPane(NULL,pane6,align_right);
		m_framWnd.AddPane(NULL,pane8,align_bottom);
		
		m_framWnd.MergePane(pane1, pane2); //�ϲ�����
		m_framWnd.MergePane(pane1, pane3);
		m_framWnd.MergePane(pane1, pane4);
		m_framWnd.MergePane(pane6, pane7);
	
        XWnd_RegEventCPP(m_framWnd,WM_RBUTTONUP,&CFrameWindow_Demo::OnWndRButtonUp);
        XWnd_RegEventCPP(m_framWnd, XWM_MENU_SELECT, &CFrameWindow_Demo::OnWndMenuSelect);
        
		m_framWnd.AdjustLayout();
		m_framWnd.ShowWindow(SW_SHOW);
    }
    int  OnWndRButtonUp(UINT nFlags,POINT *pPt,BOOL *pbHandled)
    {
        POINT pt=*pPt;
		
		//���������˵�
		xcgui::XMenu menu;
		menu.Create();
		menu.AddItem(201,L"����1");
		menu.AddItem(202,L"����2");
		menu.AddItem(203,L"����3");
        
        ClientToScreen(m_framWnd.GetHWND(),&pt);
        menu.Popup(m_framWnd.GetHWND(),pt.x,pt.y);
        return 0;
    }
    int OnWndMenuSelect(int nID,BOOL *pbHandled)
    {
        XTRACE("menu id %d \n", nID);
        switch(nID)
        {
        case 201:
            {
                if(pane1 == FALSE) return 0;
                if(pane1.IsShowPane())
                    pane1.HidePane();
                else
                    pane1.ShowPane();
            }break;
        case 202:
            {
                if(pane1 == FALSE) return 0;
                if(pane2.IsShowPane())
                    pane2.HidePane();
                else
                    pane2.ShowPane();
            }break;
        case 203:
            {
                if(pane1 == FALSE) return 0;
                if(pane3.IsShowPane())
                    pane3.HidePane();
                else
                    pane3.ShowPane();
            }break;
        }
        return 0;
    }
};



int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    //XC_ShowLayoutFrame(TRUE);
    CFrameWindow_Demo  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
	
    return 0;
}


