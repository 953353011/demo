#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create(0, 0, "480", "300", "���ڲ���", 47)

$btn1 = XBtn_Create(200, 100, "75", "25", "���԰�ť", $create)
XEle_RegEventC($btn1, "btn1")
XEle_RegEventC($btn1, "btn3", 34, "bool") ;�������������������Ϣ,��ô�Ͳ����������ĺ�����

$btn2 = XBtn_Create("400", "4", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func btn1($bh)
	MsgBox(0, "1", "�����ǻص�����1", -1, XWnd_GetHWND($create))
EndFunc   ;==>btn1
Func btn3($pHandle)
	MsgBox(0, "2", "�����ǻص�����2", -1, XWnd_GetHWND($create))
	pHandle($pHandle) ;��Ϣ����,���԰���ע�͵�������ʲô����
	Return 0
EndFunc   ;==>btn3
Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
