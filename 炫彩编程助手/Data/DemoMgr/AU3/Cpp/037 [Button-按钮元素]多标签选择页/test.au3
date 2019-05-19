#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "480", "300", "���ڲ���", 47)

$hBtn1 = XBtn_Create(30, 40, 50, 50, "btn1", $create)
$hBtn2 = XBtn_Create(81, 40, 50, 50, "btn2", $create)
$hBtn3 = XBtn_Create(132, 40, 50, 50, "btn3", $create)

; ���ð�ťΪ ��ѡ��ť �мɣ��󶨷�ҳһ��Ҫ�� radio��ť����
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
XEle_RegEventC($btn2, "quit")
XWnd_ShowWindow($create)
XRunXCGUI()

Func quit($bh)
	xquit_acn($create)
EndFunc   ;==>quit
