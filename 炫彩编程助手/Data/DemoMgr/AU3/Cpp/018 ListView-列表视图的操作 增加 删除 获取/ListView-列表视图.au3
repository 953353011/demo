#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "500", "500", "���ڲ���", 47)
$XListView = XListView_Create("20", "40", "460", "400", $create)
XEle_RegEventC($XListView, "_list", $XE_LBUTTONDBCLICK) ;ע���б���ͼ˫���¼�
$XA = XAdapterListView_Create()
$gr = XAdapterListView_Group_AddColumn($XA, "name3")
XAdapterListView_Item_AddColumn($XA, "name")
XAdapterListView_Item_AddColumn($XA, "name2")
XListView_BindAdapter($XListView, $XA)
$group = XAdapterListView_Group_AddItemText($XA, "����1")
$hImage = XImage_LoadFile("ly.png", False)
For $i = 0 To 10
	$index = XAdapterListView_Item_AddItemImage($XA, $group, $hImage)
	$ttt = XAdapterListView_Item_SetText($XA, $group, $index, 1, "ListView-00" & $i)
Next
$btn3 = XBtn_Create("160", "460", "75", "25", "ɾ��ѡ��", $create)
XEle_RegEventC($btn3, "_del")
$btn4 = XBtn_Create("240", "460", "75", "25", "ɾ��ȫ��", $create)
XEle_RegEventC($btn4, "_delall")
$btn1 = XBtn_Create("320", "460", "75", "25", "����һ��", $create)
XEle_RegEventC($btn1, "_add")
$btn2 = XBtn_Create("400", "460", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)

XRunXCGUI()
Func _list($bh)
	$get = XListView_GetSelectItem($XListView)
	$hModal = XModalWnd_Create(300, 210, "dase", XWnd_GetHWND($create), $xc_window_style_modal)
	XShapeText_Create(20, 40, 75, 25, "��ѡ��ͼƬ:", $hModal)
	$pic = XShapePic_Create(100, 70, 80, 80, $hModal)
	$img = XAdapterListView_Item_GetImageEx($XA, $get[2], $get[3], "name")
	XShapePic_SetImage($pic, $img)
	$io = XAdapterListView_Item_GetTextEx($XA, $get[2], $get[3], "name2", 0, 10)
	$txt = XShapeText_Create(105, 40, 75, 25, $io[5], $hModal)
	$btn6 = XBtn_Create("110", "170", "75", "25", "�ر�", $hModal)
	XBtn_SetType($btn6, $button_type_close)
	XModalWnd_DoModal($hModal)
EndFunc 
Func btn2($bh)
	xquit_acn($create)
EndFunc 
Func _add($bh)
	$hImage = XImage_LoadFile("ly.png", False)
	$index = XAdapterListView_Item_AddItemImage($XA, $group, $hImage)
	$ttt = XAdapterListView_Item_SetText($XA, $group, $index, 1, "ListView-00")
	XWnd_RedrawWnd($create, True)
EndFunc 
Func _del($bh)
	$get = XListView_GetSelectItem($XListView)
	$del = XAdapterListView_Item_DeleteItem($XA, $get[2], $get[3])
	If $del = True Then
		MsgBox(0, "", "ɾ���ɹ���")
	Else
		MsgBox(0, "", "ɾ��ʧ�ܣ�")
	EndIf
EndFunc 
Func _delall($bh)
	XAdapterListView_Group_DeleteAllChildItem($XA, $group)
	XWnd_RedrawWnd($create, True)
EndFunc 
