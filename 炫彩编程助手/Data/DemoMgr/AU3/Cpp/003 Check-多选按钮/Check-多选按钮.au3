#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI() ;��ʼ��
$create = XWnd_Create("500", "500", "300", "200", "���ڲ���", 47) ;����GUI����
$Check1 = XBtn_Create("160", "100", "75", "25", "Test", $create) ;������ť
$Check2 = XBtn_Create("60", "100", "75", "25", "Test", $create)
XBtn_SetGroupID($radio1, 1) ;���ð�ť����ID
XBtn_SetGroupID($radio2, 1)
XBtn_SetType($radio1, 1) ;���ð�ť����
XBtn_SetType($radio2, 1)
XBtn_SetStyle($radio1, 1) ;���ð�ť��ʽ
XBtn_SetStyle($radio2, 1)
XBtn_SetCheck($radio1, True) ;���ð�ť��ѡ״̬
$btn2 = XBtn_Create("100", "140", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2") ;ע�ᰴť�¼�
XWnd_ShowWindow($create) ;��ʾ����
XRunXCGUI()
Func btn2($bh) ;��ť�¼�
	xquit_acn($create)
EndFunc
