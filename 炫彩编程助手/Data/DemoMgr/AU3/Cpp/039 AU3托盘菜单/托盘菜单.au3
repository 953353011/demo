#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****

Opt("TrayMenuMode", 1) ;���ò���ʾĬ�ϲ˵���Ŀ (�ű���ͣ��/�˳�)
#include "XCGUI_Fun.au3"
#include <Constants.au3>

XInitXCGUI()
$create = XWnd_Create(0, 0, 600, 500, "���ڲ���", 47)
XWnd_RegEventC($create, "OnWndMenuSelect", $XWM_MENU_SELECT)
$btn2 = XBtn_Create("400", "4", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)

While 1
	Switch TrayGetMsg()
		Case $TRAY_EVENT_SECONDARYDOWN ;����Ҽ������
			_tray()
	EndSwitch
WEnd

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
Func _tray()
	$traypos = MouseGetPos()
	$hMenu = XMenu_Create() ;�����˵�.Ĭ�ϵ����˵����ڹرպ��Զ�����
	XMenu_AddItem($hMenu, 201, "1", $XC_ID_ROOT, 0) ;��Ӳ˵���
	XMenu_AddItem($hMenu, 202, "2", $XC_ID_ROOT, 0)
	XMenu_AddItem($hMenu, 203, "3", $XC_ID_ROOT, 0)
	XMenu_AddItem($hMenu, 2031, "3-1", 203, 0)
	;�����˵�
	XMenu_Popup($hMenu, XWnd_GetHWND($create), $traypos[0], $traypos[1], 0, 0)
EndFunc   ;==>_tray
Func OnWndMenuSelect($nID)
	MsgBox(0, "", "ѡ��Ĳ˵�IDΪ: " & $nID, -1, XWnd_GetHWND($create))
EndFunc   ;==>OnWndMenuSelect
