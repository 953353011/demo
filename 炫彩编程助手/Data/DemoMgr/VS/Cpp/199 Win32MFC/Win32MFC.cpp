// Win32MFC.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "resource.h"
#include "MFCDlg.h"
#define nullptr NULL
#include "Common.h"

CDialog Dlg;



class CMyWnd
{
public:
    HWINDOW m_hWindow; //���ھ��
    HELE    m_hButton; //��ť���
	
	HWND GetSafeWnd()
	{
		return XWnd_GetHWND(m_hWindow);
	}

    BOOL Create() //�������ںͰ�ť
    {
        m_hWindow=XWnd_Create(0,0,400,300,L"�Ųʽ����-����"); //��������
        if(m_hWindow)
        {
            m_hButton =XBtn_Create(10,10,80,25,L"��ť",m_hWindow); //������ť
            XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //ע�ᰴť����¼�
			
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //��ʾ����
            return TRUE;
        }
        return FALSE;
    }
    int OnEventBtnClick(BOOL *pBool) //��ť����¼���Ӧ
    {
        //������Ϣ��
        MessageBoxW(XWnd_GetHWND(m_hWindow),L"�����˰�ť",L"��ʾ",MB_OK);
        *pBool=TRUE; //�Ը��¼���������
        return 0;    //�¼��ķ���ֵ
    }
};



int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

	if(!AfxWinInit(::GetModuleHandle(NULL),NULL,::GetCommandLine(),0))
	{
		//??_Module.LogEvent(_T("MFC��ʼ������"), EVENTLOG_ERROR_TYPE );
		return 1;
	}
 	// TODO: Place code here.
	AfxEnableControlContainer();
	XInitXCGUI(); //��ʼ��
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
		Dlg.Create(IDD_DIALOG1);
		Dlg.ShowWindow(SW_SHOW);
		SetParent(Dlg.GetSafeHwnd(),MyWnd.GetSafeWnd());
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
	
// #ifdef _AFXDLL
// 	Enable3dControls();			// Call this when using MFC in a shared DLL
// #else
// 	Enable3dControlsStatic();	// Call this when linking to MFC statically
// #endif
// 

	
	return 0;
}



