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
XWnd_ShowWindow($create)
XRunXCGUI()
While 1
	Sleep(50)
WEnd
Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
