#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create(0, 0, "480", "300", "���ڲ���", 47)

$hBtn1 = XBtn_Create(30, 30, 114, 31, "btn1", $create)
$hBtn2 = XBtn_Create(145, 30, 114, 31, "btn2", $create)
$hBtn3 = XBtn_Create(256, 30, 114, 31, "btn3", $create)

SetCheckImage($hBtn1)
SetCheckImage($hBtn2)
SetCheckImage($hBtn3)

XEle_EnableBkTransparent($hBtn1, True)
XEle_EnableBkTransparent($hBtn2, True)
XEle_EnableBkTransparent($hBtn3, True)

XEle_EnableDrawFocus($hBtn1, False)
XEle_EnableDrawFocus($hBtn2, False)
XEle_EnableDrawFocus($hBtn3, False)

; ���ð�ťΪ ��ѡ��ť �мɣ��󶨷�ҳһ��Ҫ�� radio��ť
XBtn_SetType($hBtn1, $button_type_radio)
XBtn_SetType($hBtn2, $button_type_radio)
XBtn_SetType($hBtn3, $button_type_radio)
; ���Ҫ�ѵ�ѡ��ť����۸�Ϊ��ͨ��ť����ۿ��������º���
XBtn_SetStyle($hBtn1, $button_style_default)
XBtn_SetStyle($hBtn2, $button_style_default)
XBtn_SetStyle($hBtn3, $button_style_default)

; һ��Ҫ���÷���id
XBtn_SetGroupID($hBtn1, 1)
XBtn_SetGroupID($hBtn2, 1)
XBtn_SetGroupID($hBtn3, 1)

$hEle1 = XEle_Create(40, 100, 100, 100, $create)
$hEle2 = XEle_Create(40, 100, 100, 100, $create)
$hEle3 = XEle_Create(40, 100, 100, 100, $create)

XEle_ShowEle($hEle2, False)
XEle_ShowEle($hEle3, False)

XEle_AddBkFill($hEle1, 0xff0000, 254)
XEle_AddBkFill($hEle2, 0x00ff00, 254)
XEle_AddBkFill($hEle3, 0x0000ff, 254)

; ����ť�ͷ�ҳ�󶨣������ڵ����ť��ʱ�򣬾Ϳ�����ʾ��Ӧ�ķ�ҳ
XBtn_SetBindEle($hBtn1, $hEle1)
XBtn_SetBindEle($hBtn2, $hEle2)
XBtn_SetBindEle($hBtn3, $hEle3)

XBtn_SetCheck($hBtn1, True)

$btn2 = XBtn_Create("400", "4", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func SetCheckImage($hEle)
	$hBkInfoM = XEle_GetBkInfoManager($hEle)   ;��ȡԪ�ر������ݹ�����
	;��ӱ�������ͼƬ
	XBkInfoM_AddImage($hBkInfoM, BitOR($button_state_flag_check, $button_state_flag_stay), XImage_LoadFile("res\tab_check.png", False))
	XBkInfoM_AddImage($hBkInfoM, BitOR($button_state_flag_check, $button_state_flag_leave), XImage_LoadFile("res\tab_check.png", False))
	XBkInfoM_AddImage($hBkInfoM, BitOR($button_state_flag_check, $button_state_flag_down), XImage_LoadFile("res\tab_check.png", False))
	
	XBkInfoM_AddImage($hBkInfoM, BitOR($button_state_flag_check_no, $button_state_flag_stay), XImage_LoadFile("res\tab_stay.png", False))
	XBkInfoM_AddImage($hBkInfoM, BitOR($button_state_flag_check_no, $button_state_flag_leave), XImage_LoadFile("res\tab_leave.png", False))
	XBkInfoM_AddImage($hBkInfoM, BitOR($button_state_flag_check_no, $button_state_flag_down), XImage_LoadFile("res\tab_stay.png", False))
EndFunc   ;==>SetCheckImage

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
