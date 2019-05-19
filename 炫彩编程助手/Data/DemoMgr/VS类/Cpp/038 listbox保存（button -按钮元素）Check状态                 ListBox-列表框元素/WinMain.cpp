#include "Common.h"

class CMyWindowListBox
{
public:
	xcgui::XWnd m_wnd;
	xcgui::XListBox m_listBox;
    int     m_iIndex_prev; //��ǰѡ��������

    CMyWindowListBox()
    {
        m_iIndex_prev=-1;
        Init();
    }
    void Init()
    {
		m_wnd.Create(0, 0, 500, 400, L"�Ųʽ���ⴰ��");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_wnd);
		btn.SetType(button_type_close);
		
        m_listBox.Create(20,40,300,310,m_wnd);
        m_listBox.SetItemTemplateXML(L"ListBox_Item.xml");
        m_listBox.SetLineSize(20,20);
        m_listBox.EnableMultiSel(FALSE);
			


		xcgui::XAdTable m_adapter;
        m_listBox.BindAdapter(m_adapter);
        m_adapter.AddColumn(L"name");
		m_adapter.AddColumn(L"name1");
		
        wchar_t  buf[256]={0};
        int  index=0;
        for (int i=0;i<20;i++)
        {
            wsprintfW(buf,L"item-%d",i);
            index=m_adapter.AddItemTextEx(L"name",buf);
			m_adapter.SetItemText(index,1,L"����");
        }
        //��ѡ���¼�
        XEle_RegEventCPP(m_listBox,XE_LISTBOX_SELECT,&CMyWindowListBox::OnListBoxSelect);
        //��ģ��ʵ��������¼�
        XEle_RegEventCPP(m_listBox,XE_LISTBOX_TEMP_CREATE_END,&CMyWindowListBox::OnListBoxTemplateCreateEnd);
        m_wnd.ShowWindow(SW_SHOW);
    }

    int  OnListBoxTemplateCreateEnd(listBox_item_i* pItem,BOOL *pbHandled)
    {
        //��ȡģ����(itemID=1)��ť
        xcgui::XBtn btn((HELE)m_listBox.GetTemplateObject(pItem->index,1));
        if(btn.IsHXCGUI(XC_BUTTON))
        {
			
			btn.SetCheck(m_listBox.GetItemData(pItem->index));
            btn.SetText(L"��ʼ��");
            //ע�ᰴť����¼�
            XEle_RegEventCPP1(btn,XE_BUTTON_CHECK,&CMyWindowListBox::OnButtonCheck);
		}

        *pbHandled=TRUE;
        return 0;
    }
	int OnButtonCheck(HELE hEventEle,BOOL bCheck,BOOL *pbHandled)
	{
		int item = m_listBox.GetItemIndexFromHXCGUI(hEventEle);
		m_listBox.SetItemData(item,bCheck);
		return 0;
	}
    int  OnListBoxSelect(int iItem,BOOL *pbHandled)
    {
        if(m_iIndex_prev>=0)
        {
            //��ȡģ����(itemID=2)��ť
			xcgui::XBtn btn((HELE)m_listBox.GetTemplateObject(m_iIndex_prev,2));
            if(btn.IsHXCGUI(XC_BUTTON))
                btn.SetText(L"-δѡ��-");
        }
        m_iIndex_prev=iItem;
        if(iItem>=0)
        {
            //��ȡģ����(itemID=2)��ť
			xcgui::XBtn btn((HELE)m_listBox.GetTemplateObject(iItem,2));
            if(btn.IsHXCGUI(XC_BUTTON))
                btn.SetText(L"-��ѡ��-");
        }
        *pbHandled=TRUE;
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
