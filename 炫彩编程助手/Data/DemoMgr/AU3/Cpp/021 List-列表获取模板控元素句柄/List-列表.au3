#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "500", "500", "���ڲ���", 47)
$XList = XList_Create("20", "40", "440", "400", $create)
XList_SetItemHeightDefault($XList, 35, 40)  ;������δѡ�и߶�,ѡ�и߶�
$ggg=XList_SetItemTemplateXML($XList,@ScriptDir&"\List_Item.xml")  ;�����б�ģ��
XList_AddColumn($XList, 100)  ;�����п��
XList_AddColumn($XList, 100)
XList_AddColumn($XList, 100)
$XAm = XAdapterMap_Create()
XList_BindAdapterHeader($XList, $XAm)
$XA = XAdapterTable_Create()
XList_BindAdapter($XList, $XA)
XAdapterTable_AddColumn($XA, "name")
XAdapterTable_AddColumn($XA, "name2")
XAdapterTable_AddColumn($XA, "name3")
For $i = 0 To 10
	XAdapterTable_AddItemTextEx($XA, "name", "ListBox")
	XAdapterTable_SetItemText($XA, $i, 1, "ListBox-" & $i & "-1")
	XAdapterTable_SetItemText($XA, $i, 2, "ListBox-" & $i & "-2")
Next
XEle_RegEventC1($XList, "_OnListTemplateCreateEnd", $XE_LIST_TEMP_CREATE_END, "int;int")  ;ע���б��¼�
$btn2 = XBtn_Create("400", "460", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)

XRunXCGUI()
Func _OnListTemplateCreateEnd($hEle, $pItem)
	$a = _list_item_i()  ;��� list_item_i ���ݽṹ
	CopyMemory($a, $pItem)
	$but = XList_GetTemplateObject($XList, DllStructGetData($a, 1), 20)  ;��ȡ���
	$pd = XC_IsHXCGUI($but, $XC_BUTTON)  ;�жϻ�ȡ�ľ���Ƿ�Ϊ��ť
	If $pd = True Then
		XEle_RegEventC1($but, "_but_list", 34)  ;���ð�ť����¼�
	EndIf
EndFunc
Func _but_list($bh)
	$ghgh = XList_GetItemIndexFromHXCGUI($XList, $bh)  ;��ȡ��ǰ��������ģ��ʵ��,�����б�����һ����
	$yu = XAdapterTable_GetItemText($XA, $ghgh, 1, 50)  ;��ȡ���ı�����
	MsgBox(0,"",$yu[4])
EndFunc
Func btn2($bh)
	xquit_acn($create)
EndFunc 
