#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****

#include "XCGUI_Fun.au3"

XInitXCGUI()

$create = XWnd_Create(0, 0, 600, 500, "���ڲ���", 47)
$Layout = XLayout_Create() ;�������ֶ���
XWnd_BindLayoutObject($create, $window_position_body, $Layout);�󶨲��ֶ��󵽴���body����
$btn = XBtn_Create("400", "360", "75", "25", "test", $create)
XLayout_AddEle($Layout, $btn) ;���Ԫ�ص����ֶ���,�Զ���Ԫ����ӵ���UI��
XLayout_SetAlignH($Layout, $layout_align_center) ;����ˮƽ���뷽ʽΪ����
XLayout_SetAlignV($Layout, $layout_align_center) ;���ô�ֱ���뷽ʽΪ����
XLayout_SetLayoutWidth($Layout, $layout_size_type_fill, 0) ;���ÿ��Ϊ��丸
XLayout_SetLayoutHeight($Layout, $layout_size_type_fill, 0) ;���ø߶�Ϊ��丸
;XLayout_ShowLayout($Layout,True)  ;��ʾ���ֶ���,�ڵ��Ե�ʱ�����ʹ�ô�����,������ʾ���ֵı߽�

$btn2 = XBtn_Create("400", "4", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_AdjustLayout($create)
XWnd_ShowWindow($create)

XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2

