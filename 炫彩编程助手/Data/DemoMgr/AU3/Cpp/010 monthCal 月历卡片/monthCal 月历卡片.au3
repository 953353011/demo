#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "380", "500", "���ڲ���", 47)
$XMonthCal = XMonthCal_Create("20", "40", "300", "300", $create)
$btn2 = XBtn_Create("180", "460", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)

XRunXCGUI()
Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
