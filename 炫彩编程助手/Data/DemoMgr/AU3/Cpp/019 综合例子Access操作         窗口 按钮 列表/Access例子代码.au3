#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****

;��������chzj589��д,2016-03-31

#include "XCGUI_Fun.au3"

TrayTip("Сƻ����ʾ", "����������������ȴ�...", 100, 1)
Global $adSource = 'MyDatabase.mdb'
Global $adTable = "���ݿ�"
Global $DatabasePassword = "admin"
Global $adCol = 'ID identity|��һ�� TEXT(255)|�ڶ��� TEXT(255)|������ TEXT(255)|������ TEXT(255)|������ TEXT(255)|������ TEXT(255)'
Global $XRichEdit, $XRichEdit1, $XRichEdit2, $XRichEdit3, $XRichEdit4, $XRichEdit5, $XRichEdit6
Global $Button2, $Button1, $XList, $XAA, $XA, $create, $XRichEditx, $aItemText
SHUAXIN()

GUI_S();��¼����

Func SHUAXIN()
	If Not FileExists($adSource) Then
		$msg = MsgBox(0x00000001, "��ӭʹ��", "û���ҵ����ݿ��ļ�,�Ƿ񴴽�? ")
		If $msg = 0x00000001 Then
			NEW_MDB()
		Else
			Exit
		EndIf
	EndIf
EndFunc   ;==>SHUAXIN
Func GUI_S()
	XInitXCGUI()
	$create = XWnd_Create("500", "500", "660", "500", "���ڲ���", $XC_PIER)
	$str = XShapeText_Create("8", "6", "100", "20", "   �Ųʽ����-Access����", $create)
	$font = XFont_Create2("����", "12", True, False, False, False) ;��������
	XShapeText_SetFont($str, $font) ;����XShapeTextԪ������
	XShapeText_SetTextColor($str, 0x00ff66, 255) ;����XShapeTextԪ����ɫ
	$XList = XList_Create("10", "40", "640", "370", $create)
	XEle_RegEventC($XList, "_list", $XE_LBUTTONUP) ;ע���б��¼�,$XE_LBUTTONUP(���̧��)....û�ҵ��������¼�
	$ggg = XList_SetItemTemplateXML($XList, @ScriptDir & "\List_Item.xml")
	XList_AddColumn($XList, 40)
	XList_AddColumn($XList, 120)
	XList_AddColumn($XList, 90)
	XList_AddColumn($XList, 90)
	XList_AddColumn($XList, 90)
	XList_AddColumn($XList, 90)
	XList_AddColumn($XList, 90)
	$XAm = XAdapterMap_Create()
	XList_BindAdapterHeader($XList, $XAm)
	XAdapterMap_AddItemText($XAm, "name", "ID");ID|��һ��|�ڶ���
	XAdapterMap_AddItemText($XAm, "name2", "��һ��")
	XAdapterMap_AddItemText($XAm, "name3", "�ڶ���")
	XAdapterMap_AddItemText($XAm, "name4", "������")
	XAdapterMap_AddItemText($XAm, "name5", "������")
	XAdapterMap_AddItemText($XAm, "name6", "������")
	XAdapterMap_AddItemText($XAm, "name7", "������")
	$XA = XAdapterTable_Create()
	XList_BindAdapter($XList, $XA)
	XAdapterTable_AddColumn($XA, "name")
	XAdapterTable_AddColumn($XA, "name2")
	XAdapterTable_AddColumn($XA, "name3")
	XAdapterTable_AddColumn($XA, "name4")
	XAdapterTable_AddColumn($XA, "name5")
	XAdapterTable_AddColumn($XA, "name6")
	XAdapterTable_AddColumn($XA, "name7")
	_ddu()
	$XRichEditx = XRichEdit_Create("10", "460", "135", "20", $create)
	$font = XFont_Create2("����", "8", True, False, False, False) ;��������
	XEle_SetTextColor($XRichEditx, 0xff0000, 255);����XShapeTextԪ����ɫ
	XRichEdit_SetText($XRichEditx, "")
	$XRichEdit = XRichEdit_Create("10", "420", "95", "20", $create)
	XEle_SetTextColor($XRichEdit, 0xff0000, 255)
	XRichEdit_SetText($XRichEdit, _today1());
	$XRichEdit1 = XRichEdit_Create("110", "420", "95", "20", $create)
	XEle_SetTextColor($XRichEdit1, 0xff0000, 255)
	XRichEdit_SetText($XRichEdit1, "2")
	$XRichEdit2 = XRichEdit_Create("210", "420", "95", "20", $create)
	XEle_SetTextColor($XRichEdit2, 0xff0000, 255)
	XRichEdit_SetText($XRichEdit2, "3")
	$XRichEdit3 = XRichEdit_Create("310", "420", "95", "20", $create)
	XEle_SetTextColor($XRichEdit3, 0xff0000, 255)
	XRichEdit_SetText($XRichEdit3, "4")
	$XRichEdit4 = XRichEdit_Create("410", "420", "95", "20", $create)
	XEle_SetTextColor($XRichEdit4, 0xff0000, 255)
	XRichEdit_SetText($XRichEdit4, "5")
	$XRichEdit5 = XRichEdit_Create("510", "420", "95", "20", $create)
	XEle_SetTextColor($XRichEdit5, 0xff0000, 255)
	XRichEdit_SetText($XRichEdit5, "6")
	$XRichEdit6 = XRichEdit_Create("610", "420", "25", "20", $create)
	XEle_SetTextColor($XRichEdit6, 0xff0000, 255)
	$btnt = XBtn_Create("4", "4", "27", "23", "", $create)
	$xbkt = XEle_GetBkInfoManager($btnt) ;��ȡԪ�ر������ݹ�����
	$imgt = XImage_LoadFile("image\�Ų�1.jpg", True) ;����ͼƬ���ļ�
	XBkInfoM_AddImage($xbkt, $button_state_flag_check_no, $imgt) ;��ӱ�������ͼƬ
	XBtn_SetType($btnt, $button_type_check) ;���ð�ť����
	XEle_EnableDrawFocus($btnt, False)
	XBtn_SetStyle($btnt, 0) ;���ð�ť��ʽ
	$btna2 = XBtn_Create("598", "-2", "27", "27", "", $create)
	$xbka2 = XEle_GetBkInfoManager($btna2) ;��ȡԪ�ر������ݹ�����
	$img3 = XImage_LoadFile("image\close_03.jpg", True) ;����ͼƬ���ļ�
	XBkInfoM_AddImage($xbka2, $button_state_flag_check_no, $img3) ;��ӱ�������ͼƬ
	XBtn_SetType($btna2, $button_type_check) ;���ð�ť����
	XEle_EnableDrawFocus($btna2, False)
	XBtn_SetStyle($btna2, 0) ;���ð�ť��ʽ
	XBtn_SetType($btna2, $button_type_min) ;���ð�ť��������Ϊ��С����ť
	$btn2 = XBtn_Create("628", "-2", "27", "27", "", $create)
	$xbka = XEle_GetBkInfoManager($btn2) ;��ȡԪ�ر������ݹ�����
	$img3 = XImage_LoadFile("image\close_02.jpg", True) ;����ͼƬ���ļ�
	XBkInfoM_AddImage($xbka, $button_state_flag_check_no, $img3) ;��ӱ�������ͼƬ
	XBtn_SetType($btn2, $button_type_check) ;���ð�ť����
	XEle_EnableDrawFocus($btn2, False)
	XBtn_SetStyle($btn2, 0) ;���ð�ť��ʽ
	XEle_RegEventC($btn2, "btn2")
	$Button1 = XBtn_Create("170", "460", "75", "25", "����", $create)
	XEle_RegEventC($Button1, "_Button1")
	$Button2 = XBtn_Create("270", "460", "75", "20", "��ȡ", $create)
	XEle_RegEventC($Button2, "_Button3")
	$Button3 = XBtn_Create("370", "460", "75", "20", "���", $create)
	XEle_RegEventC($Button3, "_xie")
	$Button4 = XBtn_Create("470", "460", "75", "20", "�޸�", $create)
	XEle_RegEventC($Button4, "_back")
	$text = XShapeText_Create("570", "460", "60", "20", "������", $create)
	XShapeText_SetTextColor($text, 0xff0000, 255)
	TrayTip("", "", 1, 0)
	XWnd_ShowWindow($create)
	XRunXCGUI()
EndFunc   ;==>GUI_S

Func _today1() ;���ص�ǰ����
	Return (@YEAR & "��" & @MON & "��" & @MDAY & "��")
EndFunc   ;==>_today1
Func _Button3($bh)
	MsgBox(48, '��ʾ��', 'ˢ������----', 1)
	_ddu()
EndFunc   ;==>_Button3

Func _list($bh)
	TrayTip("Сƻ����ʾ", "������Ŀ�ɵ����޸�����...", 100, 1)
	$io = XAdapterTable_GetItemALLText($XList) ;����ѡ����Ŀ�������ı�
	$io = StringRegExpReplace($io, '\|', ',')
	Local $sString = StringLeft($io, 1) ; �����ַ������� 5 ���ַ�.
	$id = XList_GetSelectItem($XList)
	$sString = $id + 1
	If $sString = 0 Then
		MsgBox(48, '��ʾ', '������б�հ״�!', 1)
	Else
		$addfld = ObjCreate("ADODB.Connection")
		$addfld.Open("Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" & $adSource & "; Jet OLEDB:Database Password=" & $DatabasePassword)
		$RS = ObjCreate("ADODB.Recordset")
		$RS.ActiveConnection = $addfld
		$RS.Open("Select * FROM " & $adTable & " WHERE id" & " = " & $sString)
		XRichEdit_SetText($XRichEdit, $RS.Fields(1).value)
		XRichEdit_SetText($XRichEdit1, $RS.Fields(2).value)
		XRichEdit_SetText($XRichEdit2, $RS.Fields(3).value)
		XRichEdit_SetText($XRichEdit3, $RS.Fields(4).value)
		XRichEdit_SetText($XRichEdit4, $RS.Fields(5).value)
		XRichEdit_SetText($XRichEdit5, $RS.Fields(6).value)
		XRichEdit_SetText($XRichEdit6, $RS.Fields(0).value)
		$RS.movenext
		$RS.close
		$addfld.Close
	EndIf
EndFunc   ;==>_list

Func _back($bh);�޸�
	$Strnspin = XRichEdit_GetText($XRichEdit6, 20, 0)
	$read1 = XRichEdit_GetText($XRichEdit, 20, 0)
	$read2 = XRichEdit_GetText($XRichEdit1, 20, 0)
	$read3 = XRichEdit_GetText($XRichEdit2, 20, 0)
	$read4 = XRichEdit_GetText($XRichEdit3, 20, 0)
	$read5 = XRichEdit_GetText($XRichEdit4, 20, 0)
	$read6 = XRichEdit_GetText($XRichEdit5, 20, 0)
	$addfld = ObjCreate("ADODB.Connection")
	$addfld.Open("Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" & $adSource & "; Jet OLEDB:Database Password=" & $DatabasePassword)
	$addfld.execute("update " & $adTable & " set  ��һ��='" & $read1[2] & "',�ڶ���='" & $read2[2] & "',������='" & $read3[2] & "',������='" & $read4[2] & "',������='" & $read5[2] & "',������='" & $read6[2] & "' WHERE id" & " = " & $Strnspin[2])
	$addfld.close
	XRichEdit_SetText($XRichEdit, "")
	XRichEdit_SetText($XRichEdit1, "")
	XRichEdit_SetText($XRichEdit2, "")
	XRichEdit_SetText($XRichEdit3, "")
	XRichEdit_SetText($XRichEdit4, "")
	XRichEdit_SetText($XRichEdit5, "")
	XRichEdit_SetText($XRichEdit6, "")
	_ddu()
EndFunc   ;==>_back
Func _ddu();��ȡ
	XAdapterTable_DeleteItemAll($XA);ˢ������--�б��Ԫ���������������
	XWnd_RedrawWnd($create, True)
	$addfld = ObjCreate("ADODB.Connection")
	$addfld.Open("Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" & $adSource & "; Jet OLEDB:Database Password=" & $DatabasePassword)
	$RS = ObjCreate("ADODB.Recordset")
	$RS.ActiveConnection = $addfld
	$RS.Open("Select * From " & $adTable)
	Dim $ss = 0
	While Not $RS.eof And Not $RS.bof
		XAdapterTable_AddItemTextEx($XA, "name", $RS.Fields(0).value)
		XAdapterTable_SetItemText($XA, $ss, 1, $RS.Fields(1).value)
		XAdapterTable_SetItemText($XA, $ss, 2, $RS.Fields(2).value)
		XAdapterTable_SetItemText($XA, $ss, 3, $RS.Fields(3).value)
		XAdapterTable_SetItemText($XA, $ss, 4, $RS.Fields(4).value)
		XAdapterTable_SetItemText($XA, $ss, 5, $RS.Fields(5).value)
		XAdapterTable_SetItemText($XA, $ss, 6, $RS.Fields(6).value)
		$aItemText = $RS.Fields(0).value
		$ss += 1
		$RS.movenext
	WEnd
	$RS.close
	$addfld.Close
	$begin = TimerInit()
	$dif = TimerDiff($begin)
	$dif = StringFormat('%.3f', $dif / 1000)
	MsgBox(0, 'ͳ��', '���ƣ�' & $aItemText & ' ������' & @CRLF & '��ʱ��' & $dif & ' ��', 1)
	XWnd_RedrawWnd($create, True)
EndFunc   ;==>_ddu
Func _xie($bh);���
	If XRichEdit_GetTextLength($XRichEdit) <> '' And XRichEdit_GetTextLength($XRichEdit5) <> '' Then
		$read1 = XRichEdit_GetText($XRichEdit, 20, 0)
		$read2 = XRichEdit_GetText($XRichEdit1, 20, 0)
		$read3 = XRichEdit_GetText($XRichEdit2, 20, 0)
		$read4 = XRichEdit_GetText($XRichEdit3, 20, 0)
		$read5 = XRichEdit_GetText($XRichEdit4, 20, 0)
		$read6 = XRichEdit_GetText($XRichEdit5, 20, 0)

		$addfld = ObjCreate("ADODB.Connection")
		$addfld.Open("Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" & $adSource & "; Jet OLEDB:Database Password=" & $DatabasePassword)
		$addfld.execute("insert into " & $adTable & " (��һ��,�ڶ���,������,������,������,������) values('" & $read1[2] & "','" & $read2[2] & "','" & $read3[2] & "','" & $read4[2] & "','" & $read5[2] & "','" & $read6[2] & "')")
		$addfld.close
		_ddu()
	Else
		MsgBox(48, '����', '���������Ƿ�����')
	EndIf
	XWnd_RedrawWnd($create, True)
EndFunc   ;==>_xie
Func _Button1($bh)
	_XRichEditx()
EndFunc   ;==>_Button1
Func _XRichEditx();������Ϣ��ѯ
	If XRichEdit_GetTextLength($XRichEditx) = '' Then
		MsgBox(48, "��ʾ", "��������������", 3)
	Else
		$readq19 = XRichEdit_GetText($XRichEditx, 20, 0)
		XAdapterTable_DeleteItemAll($XA);ˢ������--�б��Ԫ���������������
		XWnd_RedrawWnd($create, True)
		$addfld = ObjCreate("ADODB.Connection")
		$addfld.Open("Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" & $adSource & "; Jet OLEDB:Database Password=" & $DatabasePassword)
		$RS = ObjCreate("ADODB.Recordset")
		$RS = ObjCreate("ADODB.Recordset")
		$RS.ActiveConnection = $addfld
		$RS.open("SELECT * FROM " & $adTable & " WHERE ��һ��='" & $readq19[2] & "' OR �ڶ���='" & $readq19[2] & "'OR ������='" & $readq19[2] & "'OR ������='" & $readq19[2] & "'OR ������='" & $readq19[2] & "' OR ������='" & $readq19[2] & "'")
		Dim $ss = 0
		While Not $RS.eof And Not $RS.bof
			XAdapterTable_AddItemTextEx($XA, "name", $RS.Fields(0).value)
			XAdapterTable_SetItemText($XA, $ss, 1, $RS.Fields(1).value)
			XAdapterTable_SetItemText($XA, $ss, 2, $RS.Fields(2).value)
			XAdapterTable_SetItemText($XA, $ss, 3, $RS.Fields(3).value)
			XAdapterTable_SetItemText($XA, $ss, 4, $RS.Fields(4).value)
			XAdapterTable_SetItemText($XA, $ss, 5, $RS.Fields(5).value)
			XAdapterTable_SetItemText($XA, $ss, 6, $RS.Fields(6).value)
			$ss += 1
			$RS.movenext
		WEnd
		$RS.close
		$addfld.Close
	EndIf
	XWnd_RedrawWnd($create, True)
EndFunc   ;==>_XRichEditx
Func btn2($bh)
	$exit = MsgBox(4, "   �˳�����", "�Ƿ��˳�������?")
	If $exit = 6 Then XQuit_ACN($create)
EndFunc   ;==>btn2
Func NEW_MDB()
	$NEWMDB = ObjCreate("ADOX.Catalog")
	$NEWMDB.Create("Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" & $adSource & "; Jet OLEDB:Database Password=" & $DatabasePassword)
	$NEWMDB.ActiveConnection.Close
	$adCol = StringRegExpReplace($adCol, '\|', ',')
	$ADDTBL = ObjCreate("ADODB.Connection")
	$ADDTBL.Open("Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" & $adSource & "; Jet OLEDB:Database Password=" & $DatabasePassword)
	$ADDTBL.Execute("CREATE TABLE " & $adTable)
	$ADDTBL.Close;������
	$ADDTBL = ObjCreate("ADODB.Connection")
	$ADDTBL.Open("Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" & $adSource & "; Jet OLEDB:Database Password=" & $DatabasePassword)
	$ADDTBL.Execute("ALTER TABLE " & $adTable & " ADD " & $adCol)
	$ADDTBL.Close;������
	MsgBox(0, '��ʾ��', '���ݿⴴ�����,������������', 2)
EndFunc   ;==>NEW_MDB
