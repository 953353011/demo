#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****

;��������chzj589��д,2016-03-31

#include "XCGUI_Fun.au3"
$_width = 800
$_height = 600
$_title = "���ڲ���"
$_style = 1
Global $XList, $XListBox, $XListView1
XInitXCGUI()
$create = XWnd_Create("500", "500", $_width, $_height, $_title, 47)
$str = XShapeText_Create("8", "6", "100", "20", "   �Ųʽ����-�б������б���ͼ�����", $create)
$font = XFont_Create2("����", "12", True, False, False, False) ;��������
XShapeText_SetFont($str, $font) ;����XShapeTextԪ������
XShapeText_SetTextColor($str, 0x00ff66, 255) ;����XShapeTextԪ����ɫ
$XTree = XTree_Create("20", "40", "200", "400", $create)
XEle_RegEventC($XTree, "_Tree", $XE_LBUTTONUP) ;ע���б��¼�,$XE_LBUTTONUP(���̧��)....û�ҵ��������¼�
$XA = XAdapterTree_Create()
XTree_BindAdapter($XTree, $XA)
XAdapterTree_AddColumn($XA, "name")
XAdapterTree_InsertItemText($XA, "��ҳ", 0, -3)
$XAbtn1 = XAdapterTree_InsertItemText($XA, "�б���ͼ", 1, -3)
XAdapterTree_InsertItemText($XA, "List-�б�", 1, -3)
$it = XAdapterTree_InsertItemText($XA, "�ļ�B", 0, -3)
XAdapterTree_InsertItemText($XA, "�б��", 1, -3)
XAdapterTree_InsertItemText($XA, "�޸�����", $it, -3)
XAdapterTree_InsertItemText($XA, "������ť", $it, -3)
XAdapterTree_InsertItemText($XA, "�༭��", $it, -3)
$XListView = XListView_Create("225", "40", "560", "400", $create)
XEle_RegEventC($XListView, "_XListView", $XE_LBUTTONUP) ;ע���б��¼�
$XA = XAdapterListView_Create()
$gr = XAdapterListView_Group_AddColumn($XA, "name3")
XAdapterListView_Item_AddColumn($XA, "name")
XAdapterListView_Item_AddColumn($XA, "name2")
XListView_BindAdapter($XListView, $XA)
$group = XAdapterListView_Group_AddItemText($XA, "����1")
$hImage = XImage_LoadFile("image\�Ų�1.jpg", False)
For $i = 0 To 10
	$index = XAdapterListView_Item_AddItemImage($XA, $group, $hImage)
	$ttt = XAdapterListView_Item_SetText($XA, $group, $index, 1, "ListView-00" & $i)
Next
$stra = XShapeText_Create("8", "446", "700", "20", "   �Ųʽ����-�б�����������", $create)
$stra1 = XShapeText_Create("8", "491", "700", "20", "   �б���ͼ��������б��List-�б�", $create)
$stra2 = XShapeText_Create("8", "536", "700", "20", "   ������ť�����ı��༭��", $create)
$fonta = XFont_Create2("����", "28", True, False, False, False) ;��������
XShapeText_SetFont($stra, $fonta) ;����XShapeTextԪ������
XShapeText_SetTextColor($stra, 0x0000ff, 255) ;����XShapeTextԪ����ɫ
XShapeText_SetFont($stra1, $fonta) ;����XShapeTextԪ������
XShapeText_SetTextColor($stra1, 0x009900, 255) ;����XShapeTextԪ����ɫ
XShapeText_SetFont($stra2, $fonta) ;����XShapeTextԪ������
XShapeText_SetTextColor($stra2, 0xff0000, 255) ;����XShapeTextԪ����ɫ
$btnt = XBtn_Create("4", "4", "27", "23", "", $create)
$xbkt = XEle_GetBkInfoManager($btnt) ;��ȡԪ�ر������ݹ�����
$imgt = XImage_LoadFile("image\�Ų�1.jpg", True) ;����ͼƬ���ļ�
XBkInfoM_AddImage($xbkt, $button_state_flag_check_no, $imgt) ;��ӱ�������ͼƬ
XBtn_SetType($btnt, $button_type_check) ;���ð�ť����
XEle_EnableDrawFocus($btnt, False)
XBtn_SetStyle($btnt, 0) ;���ð�ť��ʽ
$btna2 = XBtn_Create("738", "-2", "27", "27", "", $create)
$xbka2 = XEle_GetBkInfoManager($btna2) ;��ȡԪ�ر������ݹ�����
$img3 = XImage_LoadFile("image\close_03.jpg", True) ;����ͼƬ���ļ�
XBkInfoM_AddImage($xbka2, $button_state_flag_check_no, $img3) ;��ӱ�������ͼƬ
XBtn_SetType($btna2, $button_type_check) ;���ð�ť����
XEle_EnableDrawFocus($btna2, False)
XBtn_SetStyle($btna2, 0) ;���ð�ť��ʽ
XBtn_SetType($btna2, $button_type_min) ;���ð�ť��������Ϊ��С����ť
$btn2 = XBtn_Create("768", "-2", "27", "27", "", $create)
$xbka = XEle_GetBkInfoManager($btn2) ;��ȡԪ�ر������ݹ�����
$img3 = XImage_LoadFile("image\close_02.jpg", True) ;����ͼƬ���ļ�
XBkInfoM_AddImage($xbka, $button_state_flag_check_no, $img3) ;��ӱ�������ͼƬ
XBtn_SetType($btn2, $button_type_check) ;���ð�ť����
XEle_EnableDrawFocus($btn2, False)
XBtn_SetStyle($btn2, 0) ;���ð�ť��ʽ
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()
TrayTip("", "", 1, 0)

Func _Tree($bh)
	$io = XTree_GetSelectItem($XTree) ;����ѡ����Ŀ
	If $io = 1 Then btna2($bh);ListView-�б���ͼ
	If $io = 2 Then btna3($bh);ListView1-�б���ͼ
	If $io = 3 Then btna5($bh);ListBox-�б��
	If $io = 5 Then btna4($bh);List-�б�
	If $io = 6 Then btnaa($bh);���Ӵ���
	If $io = 7 Then btnaa1($bh);���Ӵ���
	If $io = 8 Then btnab1($bh);���Ӵ���
EndFunc   ;==>_Tree
Func btna2($bh)
	$XListView = XListView_Create("225", "40", "560", "400", $create)
	XEle_RegEventC($XListView, "_XListView", $XE_LBUTTONUP) ;ע���б��¼�
	$XA = XAdapterListView_Create()
	$gr = XAdapterListView_Group_AddColumn($XA, "name3")
	XAdapterListView_Item_AddColumn($XA, "name")
	XAdapterListView_Item_AddColumn($XA, "name2")
	XListView_BindAdapter($XListView, $XA)
	$group = XAdapterListView_Group_AddItemText($XA, "����1")
	$hImage = XImage_LoadFile("image\�Ų�1.jpg", False)
	For $i = 0 To 10
		$index = XAdapterListView_Item_AddItemImage($XA, $group, $hImage)
		$ttt = XAdapterListView_Item_SetText($XA, $group, $index, 1, "ListView-00" & $i)
	Next
	XWnd_RedrawWnd($create, True)
	TrayTip("", "", 1, 0)
EndFunc   ;==>btna2
Func _XListView($bh)
	TrayTip("Сƻ����ʾ", "����ListView-�б���ͼ��Ŀ�ɵ����޸�����...", 100, 1)
	$ioXListView = XListView_GetSelectItem($XListView)
	MsgBox(48, '��ʾ', $ioXListView[3])
EndFunc   ;==>_XListView

Func btna4($bh)
	$XList = XList_Create("225", "40", "560", "400", $create)
	XEle_RegEventC($XList, "_list", $XE_LBUTTONUP) ;ע���б��¼�,$XE_LBUTTONUP(���̧��)....û�ҵ��������¼�
	$ggg = XList_SetItemTemplateXML($XList, @ScriptDir & "\List_Item.xml")
	XList_AddColumn($XList, 100)
	XList_AddColumn($XList, 100)
	XList_AddColumn($XList, 100)
	XList_AddColumn($XList, 100)
	XList_AddColumn($XList, 100)
	$XAm = XAdapterMap_Create()
	XList_BindAdapterHeader($XList, $XAm)
	XAdapterMap_AddItemText($XAm, "name", "A001")
	XAdapterMap_AddItemText($XAm, "name2", "A002")
	XAdapterMap_AddItemText($XAm, "name3", "A003")
	XAdapterMap_AddItemText($XAm, "name4", "A004")
	XAdapterMap_AddItemText($XAm, "name5", "A005")
	$XA = XAdapterTable_Create()
	XList_BindAdapter($XList, $XA)
	XAdapterTable_AddColumn($XA, "name")
	XAdapterTable_AddColumn($XA, "name2")
	XAdapterTable_AddColumn($XA, "name3")
	XAdapterTable_AddColumn($XA, "name4")
	XAdapterTable_AddColumn($XA, "name5")
	For $i = 0 To 10
		XAdapterTable_AddItemTextEx($XA, "name", "ListBox")
		XAdapterTable_SetItemText($XA, $i, 1, "ListBox-" & $i & "-1")
		XAdapterTable_SetItemText($XA, $i, 2, "ListBox-" & $i & "-2")
		XAdapterTable_SetItemText($XA, $i, 3, "ListBox-" & $i & "-3")
		XAdapterTable_SetItemText($XA, $i, 4, "ListBox-" & $i & "-4")
		XAdapterTable_SetItemText($XA, $i, 5, "ListBox-" & $i & "-5")
	Next
	XWnd_RedrawWnd($create, True)
EndFunc   ;==>btna4
Func _list($bh)
	TrayTip("Сƻ����ʾ", "����List-�б���Ŀ�ɵ����޸�����...", 100, 1)
	$ioa = XAdapterTable_GetItemALLText($XList) ;����ѡ����Ŀ�������ı�
	MsgBox(48, '��ʾ', $ioa)

EndFunc   ;==>_list
Func btna5($bh)
	$XListBox = XListBox_Create("225", "40", "560", "400", $create)
	XEle_RegEventC($XListBox, "_XListb", $XE_LBUTTONUP) ;ע���б��¼�,
	$XA = XAdapterTable_Create()
	XListBox_BindAdapter($XListBox, $XA)
	XAdapterTable_AddColumn($XA, "name")
	For $i = 1 To 10
		XAdapterTable_AddItemTextEx($XA, "name", "ListBox-" & $i)
	Next
	XWnd_RedrawWnd($create, True)
EndFunc   ;==>btna5
Func _XListb($bh)
	TrayTip("Сƻ����ʾ", "����List-�б���ͼ��Ŀ�ɵ����޸�����...", 100, 1)
	$ioXListBox = XListBox_GetSelectItem($XListBox)
	MsgBox(48, '��ʾ', $ioXListBox)
EndFunc   ;==>_XListb
Func btna3($bh)
	$XListView1 = XListView_Create("225", "40", "560", "400", $create)
	XEle_RegEventC($XListView1, "_XListView1", $XE_LBUTTONUP) ;ע���б��¼�
	$XA = XAdapterListView_Create()
	$gr = XAdapterListView_Group_AddColumn($XA, "name3")
	XAdapterListView_Item_AddColumn($XA, "name")
	XAdapterListView_Item_AddColumn($XA, "name2")
	XListView_BindAdapter($XListView1, $XA)
	$group = XAdapterListView_Group_AddItemText($XA, "����2")
	$hImage = XImage_LoadFile("image\line.ico", False)
	For $i = 0 To 10
		$index = XAdapterListView_Item_AddItemImage($XA, $group, $hImage)
		$ttt = XAdapterListView_Item_SetText($XA, $group, $index, 1, "ListView-00" & $i)
	Next
	XWnd_RedrawWnd($create, True)
EndFunc   ;==>btna3
Func _XListView1($bh)
	TrayTip("Сƻ����ʾ", "����ListView-�б���ͼ��Ŀ�ɵ����޸�����...", 100, 1)
	$ioXListView1 = XListView_GetSelectItem($XListView1)
	MsgBox(48, '��ʾ', $ioXListView1[3])
EndFunc   ;==>_XListView1

Func btnaa($bh)
	TrayTip("Сƻ����ʾ", "�޸�����...", 100, 1)
	$hModal = XModalWnd_Create(400, 280, "dase", XWnd_GetHWND($create), $xc_window_style_modal)
	$str = XShapeText_Create("8", "6", "100", "20", "   �޸�����", $hModal)
	$font = XFont_Create2("����", "12", True, False, False, False) ;��������
	XShapeText_SetFont($str, $font) ;����XShapeTextԪ������
	XShapeText_SetTextColor($str, 0x00ff66, 255) ;����XShapeTextԪ����ɫ
	$text1 = XShapeText_Create("135", "82", "40", "20", "�û���", $hModal)
	$ComboBox1 = XComboBox_Create("175", "80", "135", "20", $hModal)
	$XAA = XAdapterTable_Create()
	XComboBox_BindApapter($ComboBox1, $XAA)
	XAdapterTable_AddColumn($XAA, "name")
	XRichEdit_SetText($ComboBox1, "admin")
	XAdapterTable_AddItemText($XAA, "aaaa")
	XAdapterTable_AddItemText($XAA, "bbbb")
	XAdapterTable_AddItemText($XAA, "cccc")
	$text2 = XShapeText_Create("135", "107", "40", "20", "����:", $hModal)
	$XRichEdit = XRichEdit_Create("175", "105", "135", "20", $hModal)
	XEle_SetTextColor($XRichEdit, 0x0000ff, 255)
	XRichEdit_SetText($XRichEdit, "123456");
	$btn3 = XBtn_Create("310", "245", "75", "20", "�ر�", $hModal)
	XBtn_SetType($btn3, $button_type_close)
	XModalWnd_DoModal($hModal)
EndFunc   ;==>btnaa
Func btnab1($bh)
	TrayTip("Сƻ����ʾ", "���ı��༭��...", 100, 1)
	$hModabl = XModalWnd_Create(400, 280, "dase", XWnd_GetHWND($create), $xc_window_style_modal)
	$str = XShapeText_Create("8", "6", "100", "20", "   ���ı��༭��", $hModabl)
	$font = XFont_Create2("����", "12", True, False, False, False) ;��������
	XShapeText_SetFont($str, $font) ;����XShapeTextԪ������
	XShapeText_SetTextColor($str, 0x00ff66, 255) ;����XShapeTextԪ����ɫ
	$XRichEditx = XRichEdit_Create("10", "40", "380", "90", $hModabl)
	$font = XFont_Create2("����", "12", True, False, False, False) ;��������
	XEle_SetFont($XRichEditx, $font) ;����XShapeTextԪ������
	XEle_SetTextColor($XRichEditx, 0xff0000, 255);����XShapeTextԪ����ɫ
	XRichEdit_SetText($XRichEditx, "�����ı�")
	$XRichEditx1 = XRichEdit_Create("10", "140", "380", "90", $hModabl)
	$font = XFont_Create2("����", "12", True, False, False, False) ;��������
	XEle_SetFont($XRichEditx1, $font) ;����XShapeTextԪ������
	XEle_SetTextColor($XRichEditx1, 0xff0000, 255)
	$read1 = XRichEdit_GetText($XRichEditx, 10, 0)
	XRichEdit_SetText($XRichEditx1, $read1[2])
	$btn3 = XBtn_Create("310", "245", "75", "20", "�ر�", $hModabl)
	XBtn_SetType($btn3, $button_type_close)
	XModalWnd_DoModal($hModabl)
EndFunc   ;==>btnab1
Func btnaa1($bh)
	TrayTip("Сƻ����ʾ", "������ť...", 100, 1)
	$hModa2 = XModalWnd_Create(250, 280, "������ť", XWnd_GetHWND($create), $xc_window_style_modal)
	$str = XShapeText_Create("8", "6", "100", "20", "   ������ť", $hModa2)
	$font = XFont_Create2("����", "12", True, False, False, False) ;��������
	XShapeText_SetFont($str, $font) ;����XShapeTextԪ������
	XShapeText_SetTextColor($str, 0x00ff66, 255) ;����XShapeTextԪ����ɫ
	$hbtn3 = XBtn_Create("40", "50", "170", "170", "", $hModa2)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s1.png", True), 150) ;��Ӷ���֡
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s2.png", True), 150)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s3.png", True), 150)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s4.png", True), 150)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s5.png", True), 150)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s6.png", True), 150)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s7.png", True), 150)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s8.png", True), 150)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s9.png", True), 150)
	XBtn_EnableAnimation($hbtn3, True, True) ;��ʼ��ر�ͼƬ�����Ĳ���
	$hbtn2 = XBtn_Create("150", "245", "75", "20", "�˳�����", $hModa2)
	XBtn_SetType($hbtn2, $button_type_close)
	XEle_RegEventC($hbtn3, "_hbtn3")
	XModalWnd_DoModal($hModa2)
EndFunc   ;==>btnaa1
Func _hbtn3($bh)
	MsgBox(0, "", "��������Ŷ")
EndFunc   ;==>_hbtn3
Func btn2($bh)
	$exit = MsgBox(4, "   �˳�����", "�Ƿ��˳�������?")
	If $exit = 6 Then xquit_acn($create)
EndFunc   ;==>btn2
