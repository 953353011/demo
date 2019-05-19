#region ;**** ���������� ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** ���������� ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create(0, 0, 500, 400, "���ڲ���", 47)
$str = XShapeText_Create(80, 80, 20, 25, "��������", $create)
$hSliderBar = XSliderBar_Create(8, 50, 150, 20, $create) ;����������Ԫ��
XSliderBar_SetRange($hSliderBar, 100) ;���û�����Χ
XSliderBar_SetButtonHeight($hSliderBar, 12) ;�����϶���ť�߶�
XSliderBar_SetSpaceTwo($hSliderBar, 0, 0) ;�������˼����С
XEle_EnableDrawFocus($hSliderBar, False) ;�Ƿ����û��ƽ���

$hEleBkInfoM = XEle_GetBkInfoManager($hSliderBar) ;��ȡԪ�ر������ݹ�����
XBkInfoM_AddFill($hEleBkInfoM, $element_state_flag_leave, 0, 255) ;��ӱ����������(����뿪)

$hBtnSlider = XSliderBar_GetButton($hSliderBar) ;��ȡ���鰴ť
$hBtnBkInfoM = XEle_GetBkInfoManager($hBtnSlider)
XBkInfoM_AddImage($hBtnBkInfoM, $button_state_flag_leave, XImage_LoadFile("����.png", False)) ;��ӱ�������ͼƬ

XSliderBar_SetImageLoad($hSliderBar, XImage_LoadFileAdaptive("δ����-2.png", 0, 8, 0, 8)) ;���ý�����ͼ
XEle_EnableBkTransparent($hBtnSlider, True) ;���ñ���͸��

XEle_RegEventC($hSliderBar, "OnSliderBarChange", $XE_SLIDERBAR_CHANGE) ;ע�Ử��������λ�øı��¼�

$btn2 = XBtn_Create("400", "4", "75", "25", "�˳�����", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2

Func OnSliderBarChange($pos)
	XShapeText_SetText($str, $pos)
	XWnd_RedrawWnd($create, True)
EndFunc   ;==>OnSliderBarChange
