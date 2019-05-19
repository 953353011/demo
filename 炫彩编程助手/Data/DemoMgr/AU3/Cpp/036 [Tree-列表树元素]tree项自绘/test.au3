#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create(0, 0, 320, 520, "���ڲ���", 47)

$m_hTree = XTree_Create(20, 40, 280, 450, $create)
XTree_SetItemHeightDefault($m_hTree, 28, 54)

;~ ����㿴������Ĵ���, ����û��xmlģ��,
;~ ��ôname����ֶ����������أ��������Ӷ�����xmlģ���, ֻ��ͨ��ģ��
;~ ���ܴ�������Ҫ��Ч�������￴����������Ϊ����� ������ģ��
;~ ���Բ������name�ֶ�, �����Ҳ���, ��ҿ��Կ�һ����������,
;~ ����ͨ���������ƺ� ��Щ�ֶ���ô��ʾ�ģ�������ȷ����ʾ���Ҫ����ʽ

;~ ����һ��, ������Ҫ�滻�������ʽ, ��ҿ���ʹ��
;~ m_pTemplate_group �� XC_LoadTemplate (#XC_TREE, L (��xml-template-test\Tree_Item_group.xml��))
;~ �����m_pTemplate_group �� OnTemplateCreate �ӳ������õ�������ҿ����Լ������滻

$hAdapter = XAdapterTree_Create()
XTree_BindAdapter($m_hTree, $hAdapter)
XAdapterTree_AddColumn($hAdapter, "name")
For $i = 1 To 5
	$nGroupID = XAdapterTree_InsertItemText($hAdapter, "���ѷ���-" & $i, $XC_ID_ROOT, $XC_ID_LAST)
	XTree_SetItemHeight($m_hTree, $nGroupID, 26, 26)
	For $o = 1 To 5
		XAdapterTree_InsertItemText($hAdapter, "�������", $nGroupID, $XC_ID_LAST)
	Next
Next
XEle_RegEventC($m_hTree, "OnTreeSelect", $XE_TREE_SELECT, "int;bool")
;~ XEle_RegEventC($m_hTree,"OnTemplateCreate",$XE_TREE_TEMP_CREATE,"int;bool")
XEle_RegEventC($m_hTree, "OnTreeDrawItem", $XE_TREE_DRAWITEM, "int;int;bool")
$btn2 = XBtn_Create("240", "4", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func OnTreeDrawItem($hDraw, $pItem, $pbHandled)
	$a = _tree_item_i()
	CopyMemory($a, $pItem)
	$nFirstChild = XTree_GetFirstChildItem($m_hTree, DllStructGetData($a, "nID"))
	If $nFirstChild > $XC_ID_ERROR Then
		If DllStructGetData($a, "nID") = XTree_GetParentItem($m_hTree, $nFirstChild) Then
			Switch DllStructGetData($a, "nState")
				Case $tree_item_state_leave
					XDraw_SetBrushColor($hDraw, 0xff0000, 255)
					XDraw_FillRect($hDraw, DllStructGetPtr($a, "rcItem"))
					pHandle($pbHandled)
				Case $tree_item_state_select
					XDraw_SetBrushColor($hDraw, 0x00ff00, 255)
					XDraw_FillRect($hDraw, DllStructGetPtr($a, "rcItem"))
					pHandle($pbHandled)
				Case $tree_item_state_stay
					XDraw_SetBrushColor($hDraw, 0x0000ff, 255)
					XDraw_FillRect($hDraw, DllStructGetPtr($a, "rcItem"))
					pHandle($pbHandled)
			EndSwitch
		EndIf
	EndIf
	pHandle($pbHandled)
EndFunc   ;==>OnTreeDrawItem

;~ Func OnTemplateCreate($pItem,$pbHandled)
;~ 	$a=_tree_item_i()
;~ 	CopyMemory($a,$pItem)
;~ 	If XTree_GetFirstChildItem($m_hTree, DllStructGetData($a,"nID")) > $XC_ID_ERROR Then
;~ 		If $m_pTemplate_group > 0 Then
;~ 			DllStructSetData($a,"Info",$m_pTemplate_group)
;~ 			CopyMemory($pItem,$a,0,1,0)
;~ 		EndIf
;~ 	EndIf
;~ 	pHandle($pbHandled)
;~ EndFunc

Func OnTreeSelect($nItemID, $pbHandled)
	MsgBox(0, "", "��Ŀ " & $nItemID & " ��ѡ��", -1, XWnd_GetHWND($create))
	pHandle($pbHandled)
EndFunc   ;==>OnTreeSelect

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
