#include "Common.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //窗口句柄
    HELE    m_hButton; //按钮句柄
	
    BOOL Create() //创建窗口和按钮
    {
        m_hWindow=XWnd_Create(0,0,400,300,L"炫彩界面库-窗口"); //创建窗口
        if(m_hWindow)
        {
            m_hButton =XBtn_Create(10,10,80,25,L"按钮",m_hWindow); //创建按钮
            XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //注册按钮点击事件
			
			int nHotkeyID = 10;
			//按住ctrl+ left键就会响应了
			RegisterHotKey(XWnd_GetHWND(m_hWindow),nHotkeyID,MOD_CONTROL,VK_LEFT);

			XWnd_RegEventCPP(m_hWindow,XWM_WINDPROC,&CMyWnd::OnWndProc);
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //显示窗口
            return TRUE;
        }
        return FALSE;
    }
	int OnWndProc(UINT message, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)
	{
		if (message != WM_HOTKEY)
			return 0;

		char buffer[MAX_PATH] = {0};
		sprintf(buffer,"%d \r\n",message);
		OutputDebugStringA(buffer);
		return 0;
	}
    int OnEventBtnClick(BOOL *pBool) //按钮点击事件响应
    {
        //弹出消息框
        MessageBoxW(XWnd_GetHWND(m_hWindow),L"你点击了按钮",L"提示",MB_OK);
        *pBool=TRUE; //对该事件进行拦截
        return 0;    //事件的返回值
    }
};

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}




