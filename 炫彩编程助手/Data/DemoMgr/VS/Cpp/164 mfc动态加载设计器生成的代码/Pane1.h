//�Ųʽ����-UI������Զ������ļ�
#pragma once


#define       ID_Btn1       10 


class CPane1
{
public:
	HELE  m_hPane1;
	CPane1();
	BOOL Init(HWINDOW hWindow);

	XC_LAYOUT_FILE(L"./���ز������/p1.xml");
	int  OnBtnClick_ID_Btn1(BOOL *pbHandled);
	XC_EVENT_DECLARE_MARK;
};
