#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create(0, 0, 500, 400, "���ڲ���", $xc_window_style_default)
$hListBox = XListBox_Create(8, 30, 400, 300, $create) ;����ListBox
XListBox_SetItemTemplateXML($hListBox, "ListBox_Item.xml") ;����ListBoxģ��

$hAdapter = XAdapterTable_Create() ;�����б��Ԫ������������
XListBox_BindAdapter($hListBox, $hAdapter) ;���б��Ԫ������������
XAdapterTable_AddColumn($hAdapter, "name") ;���������

XListBox_AddItemBkFill($hListBox, $list_item_state_leave, 0x800000, 100) ;�������������(����뿪״̬)
XListBox_AddItemBkFill($hListBox, $list_item_state_stay, 0x008000, 100) ;�������������(���ͣ��״̬)
XListBox_AddItemBkFill($hListBox, $list_item_state_select, 0x000080, 100) ;�������������(ѡ��״̬ )

For $i = 1 To 20
	XAdapterTable_AddItemText($hAdapter, "ID-" & $i) ;���������,Ĭ��ֵ�ŵ���һ��
Next
XEle_RedrawEle($hListBox, False) ;�ػ�Ԫ��(�������ػ�)
XEle_RegEventC1($hListBox, "OnListBoxTemplateCreateEnd", $XE_LISTBOX_TEMP_CREATE_END, "int;int") ;ע���б��¼����Զ��庯��(�б��Ԫ��,��ģ�崴������¼�)
XEle_RegEventC1($hListBox, "OnListBoxSelect", $XE_LISTBOX_SELECT)

$btn2 = XBtn_Create("420", "2", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2

Func OnListBoxTemplateCreateEnd($hEle, $pItem)
	$a = _listBox_item_i() ;����listBox_item_i���ݽṹ
	CopyMemory($a, $pItem) ;�����ڴ�����
	$btn = XListBox_GetTemplateObject($hListBox, DllStructGetData($a, "index"), 2) ;ͨ��ģ����ID,��ȡʵ����ģ����ID��Ӧ�Ķ�����
	If XC_IsHXCGUI($btn, $XC_BUTTON) Then ;�жϾ�������Ƿ�Ϊ��ť($XC_BUTTON)
		$pp = XListBox_GetItemData($hListBox, DllStructGetData($a, "index")) ;��ȡ���û�����
		If $pp = 0 Then
			XBtn_SetCheck($btn, False) ;����ѡ��״̬
		Else
			XBtn_SetCheck($btn, True)
		EndIf
		XEle_RegEventC1($btn, "OnListBoxBtnClick", $XE_BNCLICK) ;ע���б�ť����¼����Զ��庯��
	EndIf
EndFunc   ;==>OnListBoxTemplateCreateEnd

Func OnListBoxBtnClick($bh)
	$nItemID = XListBox_GetItemIndexFromHXCGUI($hListBox, $bh) ;��ȡ��ǰ��������ģ��ʵ��,�����б�����һ����
	$hShapText = XListBox_GetTemplateObject($hListBox, $nItemID, 3) ;ͨ��ģ����ID,��ȡʵ����ģ����ID��Ӧ�Ķ�����
	$GetText = XShapeText_GetText($hShapText, 0, 50) ;��ȡ�ı�����
	XListBox_SetItemData($hListBox, $nItemID, BitXOR(XBtn_IsCheck($bh), 1)) ;�������û�����,�����������Ҫ,��������ô˺����б��ᱣ�水ť��ѡ��״̬,�����׵Ŀ���ע�͵��������,���Կ���ʲô���
	MsgBox(0, "", $GetText[2], -1, XWnd_GetHWND($create))
EndFunc   ;==>OnListBoxBtnClick

Func OnListBoxSelect($hEle,$bHandle)
	$bHandle = True  ;��Ϣ����
EndFunc