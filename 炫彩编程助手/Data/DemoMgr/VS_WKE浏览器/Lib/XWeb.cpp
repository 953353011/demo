#include "Common.h"
#include "XWeb.h"



//���������
BOOL ERROR_IsXCGUI_DASEMIMI(HXCGUI hXCGUI, XC_OBJECT_TYPE nType,char* pFunName)
{
	if (XC_IsHXCGUI(hXCGUI, nType))
		return TRUE;
	_XC_DebugPrintf(2, "��API:%s()��, ������������Ч[%d].", pFunName, hXCGUI);
	return FALSE;
}



///////////����ӿ�/////////////////////////////////////////////////
/// @defgroup web web-�����
/// @ingroup  groupElements
/// ��ť�ӿ��б�
/// @{

/// @brief    ���������
/// @param x  x����.
/// @param y  y����.
/// @param cx ���.
/// @param cy �߶�.
/// @param hParent ��Ϊ���ھ����Ԫ�ؾ��.
/// @return   ���ھ��.
XC_API HELE WINAPI XWeb_Create(int x,int y,int cx,int cy,HXCGUI hParent)
{
	return XWeb::Create(x,y,cx,cy,hParent);
}
XC_API wkeWebView* WINAPI XWeb_GetWebView(HELE hEle)
{
	ERROR_IsXCGUI_DASEMIMI(hEle,XC_WEB,"XWeb_GetWebView");
	XWeb* pWeb = (XWeb*)_XC_GetBindData(hEle);
	return pWeb->GetWebView();
}