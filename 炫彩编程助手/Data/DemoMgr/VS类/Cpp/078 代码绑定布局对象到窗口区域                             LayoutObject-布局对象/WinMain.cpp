#include "Common.h"



class CMyWnd
{
public:
	xcgui::XWnd m_Wnd;
	
    BOOL Create() //�������ںͰ�ť
    {
		//�е�ʱ����Ҫ�鿴һ�²����Ƿ���ȷ���������ò��ֵ���ɫ��Ȼ����ʾ
		//��Ϊ������Ҫ�����������滮Ԫ�ص�����λ�ã�һ���ǲ�����ʾ��
		//������������룬���Է��ڴ��ڴ���֮ǰ
		XC_SetLayoutFrameColor(RGB(255,0,0));
		XC_ShowLayoutFrame(TRUE);

        m_Wnd.Create(0,0,400,300,L"�Ųʽ����-����"); //��������
        if(m_Wnd)
        {
			xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
			m_btn.SetType(button_type_close);			

			//�������֣�Ȼ��󶨲��ֵ����ڶ�������
			xcgui::XLayout layoutBody;
			m_Wnd.BindLayoutObject(window_position_body,layoutBody);

			//�ڶ������� ���ò��ִ�СΪ��丸��������������ʱû����
			//����������ֻ���� �ڶ�������Ϊ layout_size_type_fixed layout_size_type_weight
			//ʱ������
			layoutBody.SetLayoutHeight(layout_size_type_fill,1);
			layoutBody.SetLayoutWidth(layout_size_type_fill,1);

			//��������
			m_Wnd.AdjustLayout();
            m_Wnd.ShowWindow(SW_SHOW); //��ʾ����

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




