#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
XC_EnableDebugFile(False)  ;�ر���������ļ�
$create = XWnd_Create("500", "500", "480", "300", "���ڲ���", 47)
$btn2 = XBtn_Create("400", "4", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
