#include "Common.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //���ھ��
    HELE    m_hButton; //��ť���
	
	HELE m_hProgBarScan;

    BOOL Create() //�������ںͰ�ť
    {

		XC_LoadResource(L"res\\resource.xml",L"res");
		m_hWindow =(HWINDOW) XC_LoadLayout(L"res\\layout.xml");

		InitPage1();

		XWnd_AdjustLayout(m_hWindow);
		XWnd_ShowWindow(m_hWindow,SW_SHOW);
		return TRUE;
    }
	void InitPage1()
	{
		//Ӱ��Ӧ��ҳ��
		HELE hBtn = GetEleByRes(m_hWindow, L"ID_btn_hide_Pane2");
		XEle_RegEventCPP(hBtn,XE_BNCLICK,&CMyWnd::OnBtnHidePane2Click);
		
		//���ఴť
		hBtn = GetEleByRes(m_hWindow,L"ID_btn_show_pane2");
		XEle_RegEventCPP(hBtn,XE_BNCLICK,&CMyWnd::OnBtnShowPane2Click);
		

		//ɨ�������
		m_hProgBarScan = GetEleByRes(m_hWindow,L"ID_progbar_scan");
		XProgBar_SetSpaceTwo(m_hProgBarScan,0,0);
		XProgBar_SetPos(m_hProgBarScan,0);
		XEle_SetUserData(m_hProgBarScan,0);


		//ע��ʱ�ӣ���ʾ��������
		XWnd_SetTimer(m_hWindow,100,10);
		XWnd_RegEventCPP(m_hWindow,WM_TIMER,&CMyWnd::OnWndTimer);


		//��ʼ�����������
		InitTreeTiJian();
	}
	int OnWndTimer(UINT nIDEvent,BOOL *pbHandled)
	{
		if (nIDEvent == 100)
		{
			int nCurPos = XEle_GetUserData(m_hProgBarScan);
			nCurPos++;
			if (nCurPos > 100)
			{
				nCurPos = 0;
//				XWnd_KillTimer(m_hWindow,100);
			}
			XProgBar_SetPos(m_hProgBarScan,nCurPos);
			XEle_SetUserData(m_hProgBarScan,nCurPos);
			XEle_RedrawEle(m_hProgBarScan,TRUE);
		}
		return 0;
	}

	int OnBtnShowPane2Click(BOOL *pbHandled)
	{
		
		HELE hPane2 = GetEleByRes(m_hWindow,L"ID_page1_pane2");
		XEle_ShowEle(hPane2,TRUE);
		XWnd_RedrawWnd(m_hWindow);
		return 0;
	}
	int OnBtnHidePane2Click(BOOL *pbHandled)
	{

		HELE hPane2 = GetEleByRes(m_hWindow,L"ID_page1_pane2");
		XEle_ShowEle(hPane2,FALSE);
		XWnd_RedrawWnd(m_hWindow);
		return 0;
	}


	//�������
	HTEMP m_pTemplate_group;
	HELE m_hTree;
	void InitTreeTiJian()
	{
		m_hTree = GetEleByRes(m_hWindow,L"ID_Tree_tijian");
		XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_CREATE,&CMyWnd::OnTreeTemplateCreate);

		HXCGUI hAdapter = XAdTree_Create();
		XTree_BindAdapter(m_hTree,hAdapter);

		XTree_SetItemTemplateXML(m_hTree,L"res\\Treetijian\\Tree_Item_friend.xml");
		m_pTemplate_group = XTemp_Load(listItemTemp_type_tree,L"res\\Treetijian\\Tree_Item_group.xml");

		//���������ֶ��Ƕ�Ӧ���������
		XAdTree_AddColumn(hAdapter,L"name1"); //
		XAdTree_AddColumn(hAdapter,L"name2"); //
		XAdTree_AddColumn(hAdapter,L"name3"); //

		//���������ֶ��Ƕ�Ӧ��ͨ���������
		XAdTree_AddColumn(hAdapter,L"name4");
		XAdTree_AddColumn(hAdapter,L"name5");

		HIMAGE hImage = NULL;

		hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\safeitem_fine.png");
		int nGroup1 = XAdTree_InsertItemImage(hAdapter,hImage);
		XAdTree_SetItemText(hAdapter,nGroup1,1,L"��ȫ���(����Ƿ���ľ��������©��)");
		XAdTree_SetItemText(hAdapter,nGroup1,2,L"4");


		XTree_SetItemHeight(m_hTree,nGroup1,40,40);
		XTree_EnableConnectLine(m_hTree,FALSE,FALSE);


		hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\2nd_Icon.png");
		int nItem = XAdTree_InsertItemImage(hAdapter,hImage,nGroup1);
		XAdTree_SetItemTextEx(hAdapter,nItem,L"name4",L"����������");
		XTree_SetItemHeight(m_hTree,nItem,25,25);
		hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\ItemOkIcon.png");
		XAdTree_SetItemImageEx(hAdapter,nItem,L"name5",hImage);


		hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\2nd_Icon.png");
		nItem = XAdTree_InsertItemImage(hAdapter,hImage,nGroup1);
		XAdTree_SetItemTextEx(hAdapter,nItem,L"name4",L"����������2");
		XTree_SetItemHeight(m_hTree,nItem,25,25);
		hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\ItemOkIcon.png");
		XAdTree_SetItemImageEx(hAdapter,nItem,L"name5",hImage);


		hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\2nd_Tail_Icon.png");
		nItem = XAdTree_InsertItemImage(hAdapter,hImage,nGroup1);
		XAdTree_SetItemTextEx(hAdapter,nItem,L"name4",L"����������3");
		XTree_SetItemHeight(m_hTree,nItem,25,25);
		hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\ItemOkIcon.png");
		XAdTree_SetItemImageEx(hAdapter,nItem,L"name5",hImage);

		{
			hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\Fault_fine.png");
			nGroup1 = XAdTree_InsertItemImage(hAdapter,hImage);
			XAdTree_SetItemText(hAdapter,nGroup1,1,L"���ϼ��(������Ӳ��������Ƿ��й���)");
			XAdTree_SetItemText(hAdapter,nGroup1,2,L"4");
			XTree_SetItemHeight(m_hTree,nGroup1,40,40);
			
			hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\2nd_Icon.png");
			nItem = XAdTree_InsertItemImage(hAdapter,hImage,nGroup1);	
			XAdTree_SetItemTextEx(hAdapter,nItem,L"name4",L"����������");
			XTree_SetItemHeight(m_hTree,nItem,25,25);
			hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\ItemOkIcon.png");
			XAdTree_SetItemImageEx(hAdapter,nItem,L"name5",hImage);
			
			hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\2nd_Icon.png");
			nItem = XAdTree_InsertItemImage(hAdapter,hImage,nGroup1);
			XAdTree_SetItemTextEx(hAdapter,nItem,L"name4",L"����������2");
			XTree_SetItemHeight(m_hTree,nItem,25,25);			
			hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\ItemOkIcon.png");
			XAdTree_SetItemImageEx(hAdapter,nItem,L"name5",hImage);

			hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\2nd_Tail_Icon.png");
			nItem = XAdTree_InsertItemImage(hAdapter,hImage,nGroup1);			
			XAdTree_SetItemTextEx(hAdapter,nItem,L"name4",L"����������3");
			XTree_SetItemHeight(m_hTree,nItem,25,25);
			hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\ItemOkIcon.png");
			XAdTree_SetItemImageEx(hAdapter,nItem,L"name5",hImage);

		}

	}

	int OnTreeTemplateCreate(tree_item_i* pItem,BOOL *pbHandled)
	{
        if(XC_ID_ERROR!=XTree_GetFirstChildItem(m_hTree,pItem->nID))
        {
            if(m_pTemplate_group)
                pItem->hTemp=m_pTemplate_group;
        }
        *pbHandled=TRUE;
		return 0;
	}

	//��ʼ������app
	void InitListViewApp()
	{
		HELE hTree = GetEleByRes(m_hWindow,L"ID_ListView_app");
	}

private:
	HELE GetEleByRes(HWINDOW hWindow, const wchar_t* pResStr)
	{
		return (HELE) XC_GetObjectByID(hWindow, XRes_GetIDValue(pResStr));
	}

	HIMAGE GethImageByRes(HWINDOW hWindow,const wchar_t* pResStr)
	{
		return (HIMAGE) XC_GetObjectByID(hWindow, XRes_GetIDValue(pResStr));
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




