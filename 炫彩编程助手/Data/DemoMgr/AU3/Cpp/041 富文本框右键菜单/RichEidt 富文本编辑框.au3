#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "380", "240", "���ڲ���", 47)
$XRichEdit = XRichEdit_Create("20", "40", "120", "25", $create)
$btn2 = XBtn_Create("180", "40", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XEle_RegEventC($XRichEdit, "XRichEdit_menu", $XE_RBUTTONUP, "int;int") ;ע������Ҽ������¼�
XWnd_RegEventC($create, "_menuevent", $XWM_MENU_SELECT) ;ע��˵�ѡ���¼�
XWnd_ShowWindow($create)
XRunXCGUI()
While 1
	Sleep(50)
WEnd
Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
Func XRichEdit_menu($nFlags, $pPt)
	Local $n, $m
	$a = _POINT()
	CopyMemory($a, $pPt)
	$hMenu = XMenu_Create() ;�����˵�.Ĭ�ϵ����˵����ڹرպ��Զ�����
	XMenu_AddItem($hMenu, 980201, "����(U)", $XC_ID_ROOT, 0) ;��Ӳ˵���
	XMenu_SetItemFlags($hMenu, 980201, $menu_item_flags_disable)
	XMenu_AddItem($hMenu, 0, "", $XC_ID_ROOT, $menu_item_flags_separator)
	XMenu_AddItem($hMenu, $IDM_CLIP, "����(T)", $XC_ID_ROOT, 0)
	XMenu_AddItem($hMenu, $IDM_COPY, "����(C)", $XC_ID_ROOT, 0)
	XMenu_AddItem($hMenu, $IDM_PASTE, "ճ��(V)", $XC_ID_ROOT, 0)
	XMenu_AddItem($hMenu, $IDM_DELETE, "ɾ��(D)", $XC_ID_ROOT, 0)
	XMenu_AddItem($hMenu, 0, "", $XC_ID_ROOT, $menu_item_flags_separator)
	XMenu_AddItem($hMenu, $IDM_SELECTALL, "ȫѡ(A)", $XC_ID_ROOT, 0)
	XEle_PointClientToWndClient($XRichEdit, DllStructGetPtr($a)) ;Ԫ�ؿͻ�������ת�������ڿͻ�������
	ClientToScreen($create, $a) ;�жϴ������Կͻ��������ʾ��һ�������Ļ����  �����ʾ�ɹ������ʾʧ��
	;�����˵�
	XMenu_Popup($hMenu, XWnd_GetHWND($create), DllStructGetData($a, "x"), DllStructGetData($a, "y"), 0, $menu_popup_position_left_top)
EndFunc   ;==>XRichEdit_menu

Func _menuevent($nID)
	Switch $nID
		Case 980201
			;���������ô�����,����ûд
		Case $IDM_SELECTALL ;ȫѡ
			XRichEdit_SelectAll($XRichEdit)
			XWnd_RedrawWnd($create, True)
		Case $IDM_CLIP ;����
			XRichEdit_ClipboardCut($XRichEdit)
			XWnd_RedrawWnd($create, True)
		Case $IDM_COPY ;����
			XRichEdit_ClipboardCopy($XRichEdit)
		Case $IDM_PASTE ;ճ��
			XRichEdit_ClipboardPaste($XRichEdit)
			XWnd_RedrawWnd($create, True)
		Case $IDM_DELETE ;ɾ��
			XRichEdit_DeleteSelect($XRichEdit)
			XWnd_RedrawWnd($create, True)
	EndSwitch
EndFunc   ;==>_menuevent
