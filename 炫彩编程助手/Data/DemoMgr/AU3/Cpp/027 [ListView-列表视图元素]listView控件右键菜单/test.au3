#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
XC_ShowLayoutFrame(True) ;��ʾ���ֱ߽�
$create = XWnd_Create(0, 0, 500, 300, "���ڲ���", 47)

$hListView = XListView_Create(8, 30, 400, 200, $create)
XListView_SetItemTemplateXML($hListView, "XML-template\ListView_Item.xml")

$hAdapter = XAdapterListView_Create()
XListView_BindAdapter($hListView, $hAdapter)
XAdapterListView_Group_AddColumn($hAdapter, "name3")
XAdapterListView_Item_AddColumn($hAdapter, "name")
XAdapterListView_Item_AddColumn($hAdapter, "name2")

$group1 = XAdapterListView_Group_AddItemText($hAdapter, "group1")

$hImage = XImage_LoadFile("saomiao_down.jpg", False)
$index = XAdapterListView_Item_AddItemImage($hAdapter, $group1, $hImage)
XAdapterListView_Item_SetText($hAdapter, $group1, $index, 1, "test1")

XEle_RegEventC($hListView, "OnRButtonUp", $XE_RBUTTONUP, "int;int") ;ע������Ҽ������¼�
XWnd_RegEventC($create, "OnWndMenuSelect", $XWM_MENU_SELECT) ;ע��˵�ѡ���¼�

$btn2 = XBtn_Create("400", "4", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func OnRButtonUp($nFlags, $pPt)
	Local $n, $m
	$a = _POINT()
	CopyMemory($a, $pPt)
	$hj = XListView_HitTest($hListView, DllStructGetPtr($a), $n, $m)
	If $hj = 0 Then
		$hMenu = XMenu_Create() ;�����˵�.Ĭ�ϵ����˵����ڹرպ��Զ�����

		XMenu_AddItem($hMenu, 201, "1", $XC_ID_ROOT, 0) ;��Ӳ˵���
		XMenu_AddItem($hMenu, 202, "2", $XC_ID_ROOT, 0)
		XMenu_AddItem($hMenu, 203, "3", $XC_ID_ROOT, 0)
		
		XMenu_AddItem($hMenu, 2031, "3-1", 203, 0)
		
		XEle_PointClientToWndClient($hListView, DllStructGetPtr($a)) ;Ԫ�ؿͻ�������ת�������ڿͻ�������

		ClientToScreen($create, $a) ;�жϴ������Կͻ��������ʾ��һ�������Ļ����  �����ʾ�ɹ������ʾʧ��
		;�����˵�
		XMenu_Popup($hMenu, XWnd_GetHWND($create), DllStructGetData($a, "x"), DllStructGetData($a, "y"), 0, 0)
	EndIf
EndFunc   ;==>OnRButtonUp

Func OnWndMenuSelect($nID)
	MsgBox(0, "", "ѡ��Ĳ˵�IDΪ: " & $nID, -1, XWnd_GetHWND($create))
EndFunc   ;==>OnWndMenuSelect

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
