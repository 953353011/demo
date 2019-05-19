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
            m_hButton =XBtn_Create(10,10,80,25,L"�ر�",m_hWindow); //������ť
			XBtn_SetType(m_hButton,button_type_close);

			//�������֣�Ȼ��󶨲��ֵ����ڶ�������
			HXCGUI hLayoutBody = XLayout_Create();
			XWnd_BindLayoutObject(m_hWindow,window_position_body,hLayoutBody);

			//�ڶ������� ���ò��ִ�СΪ��丸��������������ʱû����
			//����������ֻ���� �ڶ�������Ϊ layout_size_type_fixed layout_size_type_weight
			//ʱ������
			XLayout_SetLayoutHeight(hLayoutBody,layout_size_type_fill,1);
			XLayout_SetLayoutWidth(hLayoutBody,layout_size_type_fill,1);



			XWnd_RegEventCPP(m_hWindow,WM_SIZE,&CMyWnd::OnWndSize);


			//��������
			XWnd_AdjustLayout(m_hWindow);
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //��ʾ����
            return TRUE;
        }
        return FALSE;
    }
	int OnWndSize(UINT nFlags,SIZE *pSize,BOOL *pbHandled)
	{
		HXCGUI hLayout = XWnd_GetLayoutObject(m_hWindow,window_position_body);

		SIZE sz;
		// ������÷������� XLayout_GetContentSize �ҵ�
		XLayout_GetContentSize(hLayout,&sz);


		//�õ����� 		XLayout_SetLayoutWidth() ¥���Լ����õ�
		layout_size_type_  tp;
		int nOutWidth;
		XLayout_GetLayoutWidth(hLayout,&tp,&nOutWidth);


		//�õ���ʵ��Ⱥ͸߶�
		xtrace("%d %d\r\n",XLayout_GetWidth(hLayout),XLayout_GetHeight(hLayout));
		return 0;
	}
};

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��

	//�е�ʱ����Ҫ�鿴һ�²����Ƿ���ȷ���������ò��ֵ���ɫ��Ȼ����ʾ
	//��Ϊ������Ҫ�����������滮Ԫ�ص�����λ�ã�һ���ǲ�����ʾ��
	//������������룬���Է��ڴ��ڴ���֮ǰ
	XC_SetLayoutFrameColor(RGB(255,0,0));
	XC_ShowLayoutFrame(TRUE);

    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}




