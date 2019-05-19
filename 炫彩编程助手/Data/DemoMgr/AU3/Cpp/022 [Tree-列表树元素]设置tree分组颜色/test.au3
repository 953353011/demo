#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("0", "0", "320", "520", "���ڲ���", 47)
$m_hTree = XTree_Create(20, 40, 280, 450, $create)  ;������Ԫ��
XTree_SetItemHeightDefault($m_hTree, 28, 54)  ;������Ĭ�ϸ߶ȣ�δѡ��,ѡ��
XTree_SetItemTemplateXML($m_hTree, "xml-template-test\Tree_Item_friend.xml")  ;������ģ���ļ�
XTree_SetItemTemplateXMLSel($m_hTree, "xml-template-test\Tree_Item_friend_sel.xml")  ;������ģ���ļ�,��ѡ��״̬
$m_pTemplate_group = XC_LoadTemplate($XC_TREE, "xml-template-test\Tree_Item_group.xml")  ;��ģ���ļ�����
$m_hVip = XImage_LoadFile("QQImage\vip.png", False)  ;����ͼƬ������ͼƬ���
$m_hQZone = XImage_LoadFile("QQImage\QZone.png", False)
$m_hAvatar = XImage_LoadFile("QQImage\avatar.png", False)
$m_hAvatarLarge = XImage_LoadFile("QQImage\avatar_large.png", False)
$hAdapter = XAdapterTree_Create()  ;������Ԫ������������
XTree_BindAdapter($m_hTree, $hAdapter)  ;������������
XAdapterTree_AddColumn($hAdapter, "name") ;����� �ǳ� ������
XAdapterTree_AddColumn($hAdapter, "name2") ; ǩ��
XAdapterTree_AddColumn($hAdapter, "name3") ; Сͷ��
XAdapterTree_AddColumn($hAdapter, "name4") ; ��ͷ��
XAdapterTree_AddColumn($hAdapter, "name5") ; VIP ͼ��
XAdapterTree_AddColumn($hAdapter, "name6") ; �ռ�ͼ��
For $i = 1 To 5  ;ѭ������Ԫ�����������
	$nGroupID = XAdapterTree_InsertItemText($hAdapter, "���ѷ���-" & $i, $XC_ID_ROOT, $XC_ID_LAST)  ;������,������䵽��һ��
	XTree_SetItemHeight($m_hTree, $nGroupID, 26, 26)
	For $x = 1 To 3
		$nItemID = XAdapterTree_InsertItemText($hAdapter, "��1�ѷ���-" & $x, $nGroupID, $XC_ID_LAST)
		XAdapterTree_SetItemTextEx($hAdapter, $nItemID, "name2", "�ҵĸ���ǩ��!")  ;�������ļ�����
		XAdapterTree_SetItemImageEx($hAdapter, $nItemID, "name5", $m_hVip)
		XAdapterTree_SetItemImageEx($hAdapter, $nItemID, "name6", $m_hQZone)
		XAdapterTree_SetItemImageEx($hAdapter, $nItemID, "name3", $m_hAvatar)
		XAdapterTree_SetItemImageEx($hAdapter, $nItemID, "name4", $m_hAvatarLarge)
	Next
Next
XEle_RegEventC($m_hTree, "OnTemplateCreate", $XE_TREE_TEMP_CREATE)  ;ע�� ��Ԫ��,��ģ�崴�� �¼����Զ��庯�� OnTemplateCreate
XEle_RegEventC($m_hTree, "OnTreeTemplateCreateEnd", $XE_TREE_TEMP_CREATE_END)  ;ע�� ��Ԫ��,��ģ�崴����� �¼����Զ��庯�� OnTreeTemplateCreateEnd
$btn2 = XBtn_Create("235", "2", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_AdjustLayout($create)
XWnd_ShowWindow($create)
XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2

Func OnTreeTemplateCreateEnd($pItem)
	$a = _tree_item_i()  ;����tree_item_i���ݽṹ
	CopyMemory($a, $pItem)  ;�����ڴ�����
	$btn = XTree_GetTemplateObject($m_hTree, DllStructGetData($a, "nID"), 1)  ;ͨ��ģ����ID,��ȡʵ����ģ����ID��Ӧ�Ķ�����
	$pd = XC_IsHXCGUI($btn, $XC_BUTTON)  ;�жϾ�������Ƿ�Ϊ��ť($XC_BUTTON)
	If $pd = True Then
		$unCheck = XImage_LoadFile("��.png", False)
		$check = XImage_LoadFile("��.png", False)
		XBtn_SetStyle($btn, $button_style_default)  ;���ð�ť��ʽΪĬ��
		$hBkInfoM = XEle_GetBkInfoManager($btn)  ;��ȡԪ�ر������ݹ�����
		XBkInfoM_AddImage($hBkInfoM, $button_state_flag_check_no, $unCheck)  ;��ӱ�������ͼƬ(δѡ��)
		XBkInfoM_AddImage($hBkInfoM, $button_state_flag_check, $check)  ;;��ӱ�������ͼƬ(ѡ��)
	EndIf
	$hEle = XTree_GetTemplateObject($m_hTree, DllStructGetData($a, 1), 5)
	If XC_IsHXCGUI($hEle, $XC_ELE) Then
		$hBkInfoM = XEle_GetBkInfoManager($hEle)  
		XBkInfoM_AddFill($hBkInfoM, $element_state_flag_leave, 255, 255)  ;��ӱ����������(����뿪,��ɫ:255,͸����:255) 
	EndIf
EndFunc   ;==>OnTreeTemplateCreateEnd

Func OnTemplateCreate($pItem)
	$a = _tree_item_i()
	CopyMemory($a, $pItem)
	$GetFirst = XTree_GetFirstChildItem($m_hTree, DllStructGetData($a, 1))  ;��ȡ��һ������
	If $XC_ID_ERROR < $GetFirst Then
		If DllStructGetData($a, "info") > 0 Then  ;�����ǽ����ģ����Ϣд���ڴ�
			$tm = DllStructSetData($a, "info", $m_pTemplate_group) 
			CopyMemory($pItem,$a,0,1,0)
		EndIf
	EndIf
EndFunc   ;==>OnTemplateCreate
