#include "Common.h"


HELE XC_GetEleByStr(HWINDOW hWindow,const wchar_t* res)
{
	return (HELE) XC_GetObjectByID(hWindow, XRes_GetIDValue(res) );
}

HXCGUI XC_GetLayoutByStr(HWINDOW hWindow,const wchar_t* res)
{
	return XC_GetObjectByID(hWindow, XRes_GetIDValue(res) );
}

class CMyWnd
{
public:
    HWINDOW m_hWindow; //���ھ��
    HELE    m_hButton1; //��ť���
	HELE    m_hButton2; //��ť���

	HXCGUI  m_hLayoutObjectBody;

	HELE    m_hEleCurrentBody;

	
    BOOL Create() //�������ںͰ�ť
    {
		m_hEleCurrentBody = NULL;

		XC_LoadResource(L"���ز������\\resource.xml",L"���ز������");
        m_hWindow =(HWINDOW)XC_LoadLayout(L"���ز������\\layout.xml");
        if(m_hWindow)
        {

			int nId = XRes_GetIDValue(L"ID_btn1");
			//��ģ���ļ��л�ȡ��ť���
			m_hButton1 = XC_GetEleByStr(m_hWindow,L"ID_btn1");
			m_hButton2 = XC_GetEleByStr(m_hWindow,L"ID_btn2");

            XEle_RegEventCPP(m_hButton1,XE_BNCLICK,&CMyWnd::OnEventBtn1Click); //ע�ᰴť����¼�
            XEle_RegEventCPP(m_hButton2,XE_BNCLICK,&CMyWnd::OnEventBtn2Click); //ע�ᰴť����¼�

			m_hLayoutObjectBody = XC_GetLayoutByStr(m_hWindow,L"ID_LayoutBody");
			

			XWnd_AdjustLayout(m_hWindow);
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //��ʾ����
            return TRUE;
        }
        return FALSE;
    }
    int OnEventBtn1Click(BOOL *pBool) //��ť����¼���Ӧ
    {
		DestoryBodyPane();

		HELE hLayoutPane1 = (HELE)XC_LoadLayout(L"���ز������\\���1.xml",m_hWindow);
		XLayout_AddEle(m_hLayoutObjectBody,hLayoutPane1);
		
		XEle_SetLayoutHeight(hLayoutPane1,layout_size_type_fill,1);
		XEle_SetLayoutWidth(hLayoutPane1,layout_size_type_fill,1);	

		XWnd_AdjustLayout(m_hWindow);
		XWnd_RedrawWnd(m_hWindow);

		m_hEleCurrentBody = hLayoutPane1;
        return 0;    //�¼��ķ���ֵ
    }
	int OnEventBtn2Click(BOOL *pBool) //��ť����¼���Ӧ
    {
		DestoryBodyPane();

		HELE hLayoutPane2 = (HELE)XC_LoadLayout(L"���ز������\\���2.xml",m_hWindow);
		XLayout_AddEle(m_hLayoutObjectBody,hLayoutPane2);

		XEle_SetLayoutHeight(hLayoutPane2,layout_size_type_fill,1);
		XEle_SetLayoutWidth(hLayoutPane2,layout_size_type_fill,1);


		XWnd_AdjustLayout(m_hWindow);
		XWnd_RedrawWnd(m_hWindow);

		m_hEleCurrentBody = hLayoutPane2;
        return 0;    //�¼��ķ���ֵ
    }

	void DestoryBodyPane()
	{
		if (m_hEleCurrentBody)
		{
			XEle_Destroy(m_hEleCurrentBody);
		}
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




