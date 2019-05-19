#include "Common.h"
#include "wkeBrowser.h"
#pragma comment(lib,"wkeBrowser.lib")


#ifndef WKE_CALL
#define WKE_CALL _cdecl
#endif


__int64 __fastcall js_msgbox(void* es)
{
	wchar_t buffer[1024] = {0};
	wcscat(buffer,L"����1: ");
	wcscat(buffer,XWeb_JsToTempStringW(es,XWeb_JsArg(es,0)));
	wcscat(buffer,L",����2: ");
	wcscat(buffer,XWeb_JsToTempStringW(es,XWeb_JsArg(es,1)));
	MessageBoxW(NULL,buffer,L"���óɹ�",MB_OK);
	return XWeb_JsUndefined();
}

void WKE_CALL onURLChanged(void* webView, void* param, void* url);
void WKE_CALL onTitleChanged(void* webView, void* param, void* title);
void WKE_CALL onDocumentReadyCallback(wkeWebView webView, void* param, const wkeDocumentReadyInfo* info);
void WKE_CALL onLoadingFinishCallback(wkeWebView webView, void* param, const wkeString url, wkeLoadingResult result, const wkeString failedReason);
wkeWebView WKE_CALL onCreateViewCallback(wkeWebView webView, void* param, const wkeNewViewInfo* info);






class CMyWnd
{
public:
	HWINDOW m_hWindow; //���ھ��
	HELE    m_hButton; //��ť���
	HELE m_hWeb;
	HELE  m_hEditUrl;
	HELE  m_hMenuBar;
	HXCGUI m_hShapText;

	int OnEventChar(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		if (wParam == VK_RETURN)
		{
			wchar_t url[1024] ={0};
			XRichEdit_GetText(m_hEditUrl,url,1024);
			XWeb_LoadUrl(m_hWeb,url);
		}
		return 0;
	}
	int OnLButtonDown(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
	//	SetFocus(XWnd_GetHWND(m_hWindow));
		//		SendMessage(XWnd_GetHWND(m_hWindow),WM_KILLFOCUS,0,0);
		//		XWnd_SetFocusEle(m_hWindow,m_hEditUrl);
		return 0;
	}
	int OnWndDrawWindow(HDRAW hDraw,BOOL *pbHandled)
	{
		XEle_RedrawEle(m_hWeb);
		return 0;
	}
	BOOL Create() //�������ںͰ�ť
	{
		m_hWindow = (HWINDOW) XC_LoadLayout(L"xml\\Layout.xml");
		if (!m_hWindow)
		{
			return FALSE;
		}
		XWnd_RegEventCPP(m_hWindow,WM_PAINT,&CMyWnd::OnWndDrawWindow);

		m_hEditUrl = (HELE)XC_GetObjectByID(m_hWindow,10);
		XEle_RegEventCPP(m_hEditUrl,XE_CHAR,&CMyWnd::OnEventChar);

		XEle_RegEventCPP(m_hEditUrl,XE_LBUTTONDOWN,&CMyWnd::OnLButtonDown);

		m_hShapText = XC_GetObjectByID(m_hWindow,21);


		m_hMenuBar = (HELE)XC_GetObjectByID(m_hWindow,11);
		XMenuBar_AddButton(m_hMenuBar,L"����");
		HMENUX hMenu=XMenuBar_GetMenu(m_hMenuBar,0);
		if (hMenu)
		{
			XMenu_AddItem(hMenu,100,L"ǰ��");
			XMenu_AddItem(hMenu,101,L"����");
			XMenu_AddItem(hMenu,102,L"��ҳ");
			XMenu_AddItem(hMenu,103,L"��������");
			XMenu_AddItem(hMenu,104,L"ֹͣ����");
			XMenu_AddItem(hMenu,105,L"������عȸ�");
			XMenu_AddItem(hMenu,106,L"�Ŵ�");
			XMenu_AddItem(hMenu,107,L"��С");
			XMenu_AddItem(hMenu,108,L"�ָ�����");
			XMenu_AddItem(hMenu,109,L"��ȡCookie");
			XMenu_AddItem(hMenu,110,L"js����vc����");
			XMenu_AddItem(hMenu,111,L"������ҳ�ɱ༭");
			XMenu_AddItem(hMenu,112,L"������ҳ���ɱ༭");
			XMenu_AddItem(hMenu,113,L"ִ��js�ű�");
			XMenu_AddItem(hMenu,114,L"ȡ�����״̬");
			XMenu_AddItem(hMenu,115,L"ȡ������汾");
			XMenu_AddItem(hMenu,116,L"������ҳ����ȡ�ı�");
			XMenu_AddItem(hMenu,117,L"jsģ�����");
			XMenu_AddItem(hMenu,118,L"��ʾ/���������");

		}

		RECT rtBody;
		XWnd_GetBodyRect(m_hWindow,&rtBody);
		m_hWeb = (HELE)XWeb_Create(rtBody.left,rtBody.top,rtBody.right-rtBody.left,rtBody.bottom - rtBody.top,m_hWindow);
		XWeb_LoadUrl(m_hWeb,L"http://www.xcgui.com");


 //		XWnd_EnableDrawBk(m_hWindow,FALSE);
 		XWnd_SetTransparentAlpha(m_hWindow,200);
 		XWnd_SetTransparentType(m_hWindow,window_transparent_shaped);


		XWeb_JsBindFuction("msgbox",js_msgbox,2);

		XWeb_OnURLChanged(m_hWeb,(void*)&onURLChanged,this);
		XWeb_OnTitleChanged(m_hWeb,(void*)&onTitleChanged,this);

		XWeb_OnDocumentReady(m_hWeb,onDocumentReadyCallback,NULL);
		XWeb_OnLoadingFinish(m_hWeb,onLoadingFinishCallback,NULL);
		XWeb_OnCreateView(m_hWeb,onCreateViewCallback,m_hWindow);


		XEle_RegEventCPP(m_hMenuBar,XE_MENU_SELECT,&CMyWnd::OnWndMenuSelect);

		XWnd_RegEventCPP(m_hWindow,WM_SIZE,&CMyWnd::OnWndSize);
		XWnd_AdjustLayout(m_hWindow);
		XWnd_ShowWindow(m_hWindow,SW_SHOW);
		return TRUE;
	}
	int OnWndSize(UINT nFlags,SIZE *pSize,BOOL *pbHandled)
	{
		RECT rtBody;
		XWnd_GetBodyRect(m_hWindow,&rtBody);
		XEle_SetRectEx(m_hWeb,
			rtBody.left,
			rtBody.top,
			rtBody.right - rtBody.left,
			rtBody.bottom - rtBody.top);
//		XEle_RedrawEle(m_hWeb);
		return 0;
	}
	int OnWndMenuSelect(int nID,BOOL *pbHandled)
	{
		switch (nID)
		{
		case 100:
			{
				if (XWeb_CanGoBack(m_hWeb))
				{
					XWeb_GoForward(m_hWeb);
				}
			}
			break;
		case 101:
			{
				if (XWeb_CanGoForward(m_hWeb))
				{
					XWeb_GoBack(m_hWeb);
				}
			}
			break;
		case 102:
			XWeb_LoadUrl(m_hWeb,L"http://www.xcgui.com");
			break;
		case 103:
			XWeb_Reload(m_hWeb);
			break;
		case 104:
			XWeb_StopLoading(m_hWeb);
			break;
		case 105:
			XWeb_SetProxy(m_hWeb); //ǰ������Ҫ�б��ص�socket 5 �Ĵ���������Ȼû��
			XWeb_LoadUrl(m_hWeb,L"http://www.google.com");
			break;
		case 106:
			{
				float zom = XWeb_GetZoom(m_hWeb);
				zom+=0.3f;
				XWeb_Zoom(m_hWeb,zom);
			}
			break;
		case 107:
			{
				float zom = XWeb_GetZoom(m_hWeb);
				zom-=0.3f;
				XWeb_Zoom(m_hWeb,zom);
			}
			break;
		case 108:
			XWeb_ZoomReset(m_hWeb);
			break;
		case 109:
			{
				const wchar_t* pCookie = XWeb_GetCookie(m_hWeb);
				MessageBoxW(NULL,pCookie,L"�����cookie",MB_OK);
			}
			break;
		case 110:
			XWeb_LoadUrl(m_hWeb,L"file://./jsCallFunction.html");
			break;
		case 111:
			XWeb_SetEditable(m_hWeb,true);
			break;
		case 112:
			XWeb_SetEditable(m_hWeb,false);
			break;
		case 113:
			XWeb_RunJs(m_hWeb,L"javascript: alert('�Ųʽ����');");
			break;
		case 114:
			{
				if (XWeb_IsDocumentReady(m_hWeb))
				{
					SetStat(L"��ҳ׼�����!");
				}else if (XWeb_IsLoadingCompleted(m_hWeb))
				{
					SetStat(L"��ҳ�������!");
				}else if (XWeb_IsLoadingFailed(m_hWeb))
				{
					SetStat(L"������ҳʧ��!");
				}
			}

			break;
		case 115:
			MessageBoxA(NULL,XWeb_GetVersionString(),"�汾",MB_OK);
			break;
		case 116:
			{
				void* es = XWeb_GlobalExec(m_hWeb);
				__int64 document = XWeb_JsGet(es,XWeb_JsGlobalObject(es),"document");
				__int64 body = XWeb_JsGet(es,document,"body");

				__int64 jsvalue = XWeb_JsGet(es,body,"innerText");

				MessageBoxW(NULL,XWeb_JsToTempStringW(es,jsvalue),L"��ҳԴ��",MB_OK);

			}
			break;
		case 117:
			{
				XWeb_RunJs(m_hWeb,L"javascript: \
								   document.getElementById('kw').value='�Ųʽ����';\
								   document.getElementById('su').click(); ");
			}
			break;
		case 118:
			{
				XEle_ShowEle(m_hWeb,!XEle_IsShow(m_hWeb));
				XWnd_RedrawWnd(m_hWindow,TRUE);
			}
			break;
		}

		return 0;
	}
	int OnEventBtnClick(BOOL *pBool) //��ť����¼���Ӧ
	{
		//������Ϣ��
		MessageBoxW(XWnd_GetHWND(m_hWindow),L"�����˰�ť",L"��ʾ",MB_OK);
		*pBool=TRUE; //�Ը��¼���������
		return 0;    //�¼��ķ���ֵ
	}
public:

	void SetUrl(const wchar_t* pURL)
	{
		XRichEdit_SetText(m_hEditUrl,pURL);
	}

	void SetStat(const wchar_t* pStat)
	{
		XShapeText_SetText(m_hShapText,pStat);
		XWnd_RedrawWnd(m_hWindow);
	}

};

void WKE_CALL onDocumentReadyCallback(wkeWebView webView, void* param, const wkeDocumentReadyInfo* info)
{
	OutputDebugStringW(XWeb_GetStringW(info->url) );
}
void WKE_CALL onLoadingFinishCallback(wkeWebView webView, void* param, const wkeString url, wkeLoadingResult result, const wkeString failedReason)
{
OutputDebugStringW(XWeb_GetStringW(url) );
}
wkeWebView WKE_CALL onCreateViewCallback(wkeWebView webView, void* param, const wkeNewViewInfo* info)
{
//	return 0;
// 	�����Ŀ��
// 		�� 4 ��������Ŀ����������������ĵ��ض��������
// 		_blank
// 		���������һ���´򿪡�δ�����Ĵ���������Ŀ���ĵ���
// 		_self
// 		���Ŀ���ֵ������û��ָ��Ŀ��� <a> ��ǩ��Ĭ��Ŀ�꣬��ʹ��Ŀ���ĵ����벢��ʾ����ͬ�Ŀ�ܻ��ߴ�������ΪԴ�ĵ������Ŀ���Ƕ����Ҳ���Ҫ�ģ����Ǻ��ĵ����� <base> ��ǩ�е� target ����һ��ʹ�á�
	// 		_parent
	// 		���Ŀ��ʹ���ĵ����븸���ڻ��߰��������������õĿ�ܵĿ�ܼ����������������ڴ��ڻ����ڶ�������У���ô����Ŀ�� _self ��Ч��
	// 		_top
	// 		���Ŀ��ʹ���ĵ����������������ӵĴ��ڣ��� _top Ŀ�꽫��������б������Ŀ�ܲ����ĵ�����������������ڡ�
	const wchar_t* target = XWeb_GetStringW(info->target);
	OutputDebugStringW(target);
	OutputDebugStringW(L"\r\n");
	if (wcscmp(target,L"_self") == 0)
	{
		return webView;
	}else if (wcscmp(target, L"") == 0 || wcscmp(target, L"_blank") == 0)
	{
		HWINDOW hPopWindow = XWnd_Create(0,0,300,500,NULL,XWnd_GetHWND((HWINDOW)param));
 		void* hWeb = XWeb_Create(0,0,300,500,hPopWindow);
 		XWeb_LoadUrl(hWeb,XWeb_GetStringW(info->url));
//		XWeb_LoadUrl(hWeb,L"about:blank");
		
		//	const wchar_t* url = XWeb_GetStringW(info->url);
		//	OutputDebugStringW(L"\r\n");
		//	OutputDebugStringW(target);
		//	OutputDebugStringW(url);
		//	OutputDebugStringW(L"\r\n");
		XWnd_ShowWindow(hPopWindow,SW_SHOW);
//		return 0;
		return (wkeWebView)XWeb_GetWebView(hWeb);
	}
	

	return 0;
}


void WKE_CALL onURLChanged(void* webView, void* param, void* url)
{
	CMyWnd* pWnd =(CMyWnd*)param;
	pWnd->SetUrl(XWeb_GetStringW(url));
}

void WKE_CALL onTitleChanged(void* webView, void* param, void* title)
{
	CMyWnd* pWnd =(CMyWnd*)param;
 	pWnd->SetStat(XWeb_GetStringW(title));
}


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
	XWeb_Init();
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //����
    }
	XWeb_UnInit();
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}




