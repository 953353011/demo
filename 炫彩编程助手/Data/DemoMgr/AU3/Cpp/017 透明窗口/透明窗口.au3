#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "480", "300", "���ڲ���", 47)
$XSliderBar = XSliderBar_Create("20", "60", "440", "40", $create)
XEle_RegEventC1($XSliderBar, $XE_SLIDERBAR_CHANGE, "XSliderBar")
XSliderBar_SetButtonWidth($XSliderBar, 20)
XSliderBar_SetButtonHeight($XSliderBar, 30)
XSliderBar_SetRange($XSliderBar, 255)
XSliderBar_SetPos($XSliderBar, 255)
$str = XShapeText_Create(200, 120, 20, 25, "��������", $create)
$btn2 = XBtn_Create("180", "260", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_SetTransparentType($create, $window_transparent_shaped)
XWnd_SetTransparentAlpha($create, 255)
XWnd_ShowWindow($create)
XRunXCGUI()
Func XSliderBar($bh)
	XWnd_SetTransparentAlpha($create, XSliderBar_GetPos($XSliderBar))
	XWnd_RedrawWnd($create, True)
EndFunc   ;==>XSliderBar

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
