#include "Common.h"



class CMyWnd
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XBtn m_btn;

	xcgui::XShapeText m_ShapeText1;
	xcgui::XShapeText m_ShapeText2;
	xcgui::XShapeText m_ShapeText3;
	
    BOOL Create() //�������ںͰ�ť
    {
        m_Wnd.Create(0,0,400,300,L"�Ųʽ����-����"); //��������
        if(m_Wnd)
        {
            m_btn.Create(10,10,80,25,L"��ť",m_Wnd); //������ť
            XEle_RegEventCPP(m_btn,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //ע�ᰴť����¼�
		
			
			m_ShapeText1.Create(10,50,100,20,L"����1",m_Wnd);
			m_ShapeText2.Create(10,80,100,20,L"����2",m_Wnd);
			m_ShapeText3.Create(10,110,100,20,L"����3",m_Wnd);


			m_Wnd.ShowWindow(SW_SHOW);  //��ʾ����
            return TRUE;
        }
        return FALSE;
    }
    int OnEventBtnClick(BOOL *pBool) //��ť����¼���Ӧ
    {
        //�������ص� �Ųʲ��õ� �û�����ˢ�»���
		//�������Խ�ʡЧ�ʣ���Ϊûˢ��һ�Σ��ڲ��ͱ���
		//����һ�λ��õ����ݵ����ڣ���ҿ��Կ������ע��
		//���룬������һ���ı��͵���ˢ��һ�Σ������൱��
		//���ڴ濽�������Σ�Ч�ʼ���ĵ��£��������������
		//ֻˢ��һ�Σ���ô�����������Ч��

		m_ShapeText1.SetText(L"�Ųʽ����");
		m_ShapeText2.SetText(L"xcgui");
		m_ShapeText3.SetText(L"xcgui1");
		m_Wnd.RedrawWnd();
       

// 		m_ShapeText1.SetText(m_hRichEdit,L"�Ųʽ����");
// 		m_Wnd.RedrawWnd();
// 		m_ShapeText2.SetText(m_hShapeText,L"xcgui");
// 		m_Wnd.RedrawWnd();
// 		m_ShapeText3.SetText(m_hShapeText1,L"xcgui1");
// 		m_Wnd.RedrawWnd();


		//����֪ʶ���Ųʲ��õ�˫���壬�ֲ�ˢ�£��û�����ˢ��
		//�ȵȼ��������Ч��

		//���� �ı���һ�� ����Ԫ�� HELE ��ô��ֻ��Ҫ���� 
		//XEle_RedrawEle ��ˢ�������λ������������ʾ
		//ˢ�¾ֲ��ܴ�����߳���Ч��
		//�˽�����Щ֮�󣬴��ֻҪ���� �������ı������޸���
		//�������Բ������̸ı䣬��Ҫ�϶����ڻ��߼����
		//�Ż���Ч ��Щ�����Ҿ�֪������ô����



        *pBool=TRUE; //�Ը��¼���������
        return 0;    //�¼��ķ���ֵ
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




