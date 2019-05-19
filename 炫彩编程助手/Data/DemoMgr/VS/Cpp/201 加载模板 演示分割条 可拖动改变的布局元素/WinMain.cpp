#include "Common.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //���ھ��
    HELE    m_hButton; //��ť���
	
    BOOL Create() //�������ںͰ�ť
    {
		XC_LoadResource(L"�϶�����\\��Դ�ļ�\\resource.res",L"�϶�����");
		m_hWindow=(HWINDOW)XC_LoadLayout(L"�϶�����\\�����ļ�\\layout.xml");
 //       m_hWindow=XWnd_Create(0,0,400,300,L"�Ųʽ����-����"); //��������
        if(m_hWindow)
        {


			HELE m_hEleLeft = (HELE)XC_GetObjectByID(m_hWindow,10);
			HELE m_hEleRight = (HELE)XC_GetObjectByID(m_hWindow,11);
			XEle_SetBorderSize(m_hEleLeft, 5, 5, 5, 5);
			XEle_SetBorderSize(m_hEleRight, 5, 5, 5, 5);
			
			XEle_SetDragBorder(m_hEleRight, element_position_left | element_position_top | element_position_bottom | element_position_right);
			XEle_SetDragBorderBindEle(m_hEleRight, element_position_left, m_hEleLeft, 5);

			XWnd_AdjustLayout(m_hWindow);
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

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
	XC_ShowLayoutFrame(TRUE);
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}




