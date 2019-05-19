#include "Common.h"



class CMyWnd
{
public:
    HWINDOW hWindow; //���ھ��
    HELE    m_hButton; //��ť���
	
    BOOL Create() //�������ںͰ�ť
    {
			hWindow=XWnd_Create(0,0,400,300,L"�Ųʽ����-����"); //��������
			if(hWindow)
			{
			HXCGUI hShapePic  =XShapePic_Create(0,0,24,24,hWindow);
			HXCGUI hShapeText =XShapeText_Create(0,0,100,20,L"��׼ϵͳ������");
			HELE   hBtnMin    =XBtn_Create(20,60,65,20,L"��С��",hWindow);
			HELE   hBtnMax    =XBtn_Create(20,60,90,20,L"���/��ԭ",hWindow);//������ť
			HELE   hBtnClose  =XBtn_Create(20,60,60,20,L"�ر�",hWindow);
			
			XShapePic_SetImage(hShapePic,XImage_LoadFile(L"Logo.png")); //��ʾlogoͼ��
			XBtn_SetType(hBtnMin,button_type_min);
			XBtn_SetType(hBtnMax,button_type_max);
			XBtn_SetType(hBtnClose,button_type_close);
			XEle_RegEventCPP(hBtnClose,XE_BNCLICK,&CMyWnd::OnEventBtnClick);//ע�ᰴť����¼�
			
			HXCGUI  hLayout =XLayout_Create(); //�������ֶ���
			XWnd_BindLayoutObject(hWindow,window_position_top,hLayout);
			XLayout_SetLayoutWidth(hLayout,layout_size_type_fill,0);
			XLayout_SetLayoutHeight(hLayout,layout_size_type_fill,0);
			XLayout_SetAlignV(hLayout,layout_align_center);
			XLayout_SetPadding(hLayout,8,0,8,0);
			{
				//��ӵ�������,��ʾ�����
				XLayout_AddShape(hLayout,hShapePic);
				XLayout_AddShape(hLayout,hShapeText);
			}
			{
				//�����Ҳ಼�ֶ���
				HXCGUI  hLayoutRight =XLayout_Create(); 
				XLayout_AddLayoutObject(hLayout,hLayoutRight);
				XLayout_SetLayoutWidth(hLayoutRight,layout_size_type_weight,1);
				XLayout_SetLayoutHeight(hLayoutRight,layout_size_type_fill,0);
				XLayout_SetAlignV(hLayoutRight,layout_align_center);
				XLayout_SetAlignH(hLayoutRight,layout_align_right);
        
				XLayout_AddEle(hLayoutRight,hBtnMin);  //��ӵ�������
				XLayout_AddEle(hLayoutRight,hBtnMax);
				XLayout_AddEle(hLayoutRight,hBtnClose);
			}
		
        
			XWnd_AdjustLayout(hWindow); //��������
			XWnd_ShowWindow(hWindow,SW_SHOW);

            return TRUE;
        }
        return FALSE;
    }
    int OnEventBtnClick(BOOL *pBool) //��ť����¼���Ӧ
    {
    //������Ϣ��
		::MessageBoxW(XWnd_GetHWND(hWindow),L"�����˹رհ�ť,�����رմ���",L"��ʾ",MB_OK);
    //*pbHandled=TRUE; //�Ը��¼���������,�������Ҫ���ؿ���ȥ�����д���
    return 0;    //�¼��ķ���ֵ

    }
};

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
	XC_ShowLayoutFrame(TRUE);  //��ʾ���ֱ߽�,�����õ�
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}




