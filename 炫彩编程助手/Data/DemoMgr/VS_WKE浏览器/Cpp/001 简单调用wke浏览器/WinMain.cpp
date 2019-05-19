#include "Common.h"
#include "XWeb.h"
#include "XWeb.cpp"


const wchar_t* g_wHtml = L"<html><head></head><body style='font-size:16px;'>"
L"������ַ: &nbsp<input id=myurl style='width:400px;' value='http://www.4399.com/flash/112689_3.htm'><button onclick=\"document.location=document.getElementById('myurl').value;\">GO</button><hr />"
L"<a href='http://www.taobao.com/'>�Ա�</a><br />"
L"<a href='http://www.youku.com/'>�ſ�</a><br />"

L"<a href='http://www.youzu.com/'>����</a><br />"

L"<a href='http://www.baidu.com/'>�ٶ�</a><br />"
L"<a href='http://map.baidu.com/'>�ٶȵ�ͼ</a><br />"
L"<a href='http://www.le.com/'>����</a><br />"
L"<a href='http://download.csdn.net/'>CSDN</a><br />"


L"<a href='http://www.yvoschaap.com/chainrxn/'>2D����</a><br />"
L"<a href='https://www.benjoffe.com/code/demos/canvascape/textures'>3D����</a><br />"

L"<a href='http://www.jz5u.com/soft/softdown.asp?softid=18109'>���ز���</a><br />"


L"<a href='http://workerman.net:8383/'>���������</a><br />"
L"<a href='http://chat.workerman.net/'>Websocket������</a><br />"
L"<a href='http://www.workerman.net/demos/browserquest/'>Websocket������Ϸ</a><br />"

L"</body></html>";

void BindEleToBody(HWINDOW hWindow, HELE hEle);


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
	wkeDisableWOFF( false );
	HWINDOW hWindow = XWnd_Create(0,0,500,300,L"�Ų������");
    if(hWindow)
    {
		HELE hEle = XWeb_Create(8,30,400,300,hWindow);
		BindEleToBody(hWindow,hEle);
		wkeWebView* pWebView = XWeb_GetWebView(hEle);
		wkeLoadHTML(pWebView,g_wHtml);

		XWnd_AdjustLayout(hWindow);
        XWnd_ShowWindow(hWindow,SW_SHOW);//��ʾ����	
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}

void BindEleToBody(HWINDOW hWindow, HELE hEle)
{

	HXCGUI hLayoutBody = XLayout_Create();
	XWnd_BindLayoutObject(hWindow,window_position_body,hLayoutBody);
	XLayout_SetLayoutHeight(hLayoutBody,layout_size_type_fill,1);
	XLayout_SetLayoutWidth(hLayoutBody,layout_size_type_fill,1);

	XLayout_AddEle(hLayoutBody,hEle);
	XEle_SetLayoutHeight(hEle,layout_size_type_fill,1);
	XEle_SetLayoutWidth(hEle,layout_size_type_fill,1);
}

