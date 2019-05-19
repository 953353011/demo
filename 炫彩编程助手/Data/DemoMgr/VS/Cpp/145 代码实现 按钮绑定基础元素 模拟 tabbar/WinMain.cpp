#include "Common.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //���ھ��
    HELE    m_hButton; //��ť���
	
    BOOL Create() //�������ںͰ�ť
    {
        m_hWindow=XWnd_Create(0,0,400,300,L"�Ųʽ����-����"); //��������
		if (!m_hWindow)
			return FALSE;

		HELE hBtn1 = XBtn_Create(5,5,100,20,L"��1ҳ",m_hWindow);
		HELE hBtn2 = XBtn_Create(105,5,100,20,L"��2ҳ",m_hWindow);

		HELE hPage1 = XEle_Create(8,30,100,100,m_hWindow);
		HELE hPage2 = XEle_Create(8,30,100,100,m_hWindow);

		XBtn_SetType(hBtn1,button_type_radio);
		XBtn_SetType(hBtn2,button_type_radio);

		XBtn_SetBindEle(hBtn1,hPage1);
		XBtn_SetBindEle(hBtn2,hPage2);

		XBtn_SetGroupID(hBtn1,10);
		XBtn_SetGroupID(hBtn2,10);

		XEle_ShowEle(hPage1,TRUE);
		XEle_ShowEle(hPage2,FALSE);

		XBtn_SetCheck(hBtn1,TRUE);
		XBtn_SetCheck(hBtn2,FALSE);

		//Ϊ�����ֵ�һҳ�͵ڶ�ҳ���ҷֱ𴴽�һ�� ��״�ı�
		
		XShapeText_Create(0,10,100,20,L"��1ҳ",hPage1);
		XShapeText_Create(0,10,100,20,L"��2ҳ",hPage2);


        XWnd_ShowWindow(m_hWindow,SW_SHOW); //��ʾ����
        return TRUE;
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




