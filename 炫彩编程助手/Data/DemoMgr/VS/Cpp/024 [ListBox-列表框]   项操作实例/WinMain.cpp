#include "Common.h"

class CMyWindowListBox
{
public:
    HWINDOW m_hWindow;
    HELE    m_hListBox;
    int     m_iIndex_prev; //先前选中项索引
    CMyWindowListBox()
    {
        m_iIndex_prev=-1;
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 400, 400, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hListBox=XListBox_Create(20,40,300,310,m_hWindow);
        XListBox_SetItemTemplateXML(m_hListBox,L"ListBox_Item.xml");
        XSView_SetLineSize(m_hListBox,20,20);
        XListBox_EnableMultiSel(m_hListBox,FALSE);
		
        HXCGUI hAdapter=XAdTable_Create();
        XListBox_BindAdapter(m_hListBox,hAdapter);
        XAdTable_AddColumn(hAdapter,L"name1");
		
        wchar_t  buf[256]={0};
        int  index=0;
        for (int i=0;i<20;i++)
        {
            wsprintfW(buf,L"item-%d",i);
            index=XAdTable_AddItemTextEx(hAdapter,L"name1",buf);
        }
        //项选择事件
        XEle_RegEventCPP(m_hListBox,XE_LISTBOX_SELECT,&CMyWindowListBox::OnListBoxSelect);
        //项模板实例化完成事件
        XEle_RegEventCPP(m_hListBox,XE_LISTBOX_TEMP_CREATE_END,&CMyWindowListBox::OnListBoxTemplateCreateEnd);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
    int  OnListBoxTemplateCreateEnd(listBox_item_i* pItem,BOOL *pbHandled)
    {
        //获取模板中(itemID=2)按钮
        HELE  hButton=(HELE)XListBox_GetTemplateObject(m_hListBox,pItem->index,2);
        if(XC_IsHXCGUI(hButton,XC_BUTTON))
        {
            XBtn_SetText(hButton,L"初始化");
            //注册按钮点击事件
            XEle_RegEventCPP1(hButton,XE_BNCLICK,&CMyWindowListBox::OnBtnClick);
        }
        *pbHandled=TRUE;
        return 0;
    }
    int  OnListBoxSelect(int iItem,BOOL *pbHandled)
    {
        if(m_iIndex_prev>=0)
        {
            //获取模板中(itemID=2)按钮
            HELE  hButton=(HELE)XListBox_GetTemplateObject(m_hListBox,m_iIndex_prev,2);
            if(XC_IsHXCGUI(hButton,XC_BUTTON))
                XBtn_SetText(hButton,L"-未选择-");
        }
        m_iIndex_prev=iItem;
        if(iItem>=0)
        {
            //获取模板中(itemID=2)按钮
            HELE  hButton=(HELE)XListBox_GetTemplateObject(m_hListBox,iItem,2);
            if(XC_IsHXCGUI(hButton,XC_BUTTON))
                XBtn_SetText(hButton,L"-被选择-");
        }
        *pbHandled=TRUE;
        return 0;
    }
    int OnBtnClick(HELE hEventEle,BOOL *pbHandled)
    {
        //获取按钮在ListBox中的项索引
		int nItem = XListBox_GetItemIndexFromHXCGUI(m_hListBox,hEventEle);
        if(nItem<0) return 0;

        //获取模板中(itemID=1)文本块
        HXCGUI  hTextBlock=XListBox_GetTemplateObject(m_hListBox,nItem,1);
        if(XC_IsHXCGUI(hTextBlock,XC_SHAPE_TEXT))
        {
            wchar_t  buf[MAX_PATH]={0};
            XShapeText_GetText(hTextBlock,buf,MAX_PATH); //此函数 1.8.4.1版本新增
            MessageBox(XEle_GetHWND(hEventEle),buf,L"您点击了按钮!",MB_OK);
        }

        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowListBox  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
