-- the first program in every language
require("_const")  --���볣��
require("_xcgui")  --���뺯��

local m_hWindow = XWnd_Create(0, 0, 400, 200,"abc�Ų�",0,const.xc_window_style_default);

function OnBtnClick( pbHandled )
	hWnd = XWnd_GetHWND(m_hWindow);
	m_hWindowModal = XModalWnd_Create(200, 200, "�Ųʽ���ⴰ��",hWnd,const.xc_window_style_modal);
	hBtnClose = XBtn_Create(5, 3, 60, 20, "Close", m_hWindowModal)
	XBtn_SetType(hBtnClose,const.button_type_close);
	nResult=XModalWnd_DoModal(m_hWindowModal);
	return 0;
end
--��������


hBtnClose = XBtn_Create(10, 5, 100, 20,"����ģ̬����",m_hWindow);
XEle_RegEventC(hBtnClose,const.XE_BNCLICK,OnBtnClick);

--��ʾ����
XWnd_ShowWindow(m_hWindow,5--[[SW_SHOW]]);

