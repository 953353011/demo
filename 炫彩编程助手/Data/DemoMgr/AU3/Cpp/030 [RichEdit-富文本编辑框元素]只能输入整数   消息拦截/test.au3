#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "480", "300", "���ڲ���", 47)
$XRich = XRichEdit_Create(40, 80, 200, 30, $create)
XEle_RegEventC($XRich, "OnEventChar", $XE_CHAR, "int;int;bool") ;ע��XE_CHAR�¼�(ͨ��TranslateMessage����������ַ��¼�)
$btn2 = XBtn_Create("400", "4", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func OnEventChar($wParam, $lParam, $pbHandled)
	If $wParam >= 48 And $wParam <= 57 Then ;�Ա�ASCII��,�������48-57֮����ô������Ϣ
		Return 0 ;ASCII��48-57 ��������0-9
	EndIf
	pHandle($pbHandled) ;������Ϣ
EndFunc   ;==>OnEventChar
Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
