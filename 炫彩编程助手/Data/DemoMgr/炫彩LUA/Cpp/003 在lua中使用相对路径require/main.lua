--lua��C++��ͬ��requireʹ�����·�����ܼ򵥵�ʹ�á�./xx/����������ʽ.
--��lua��ʹ�����·�����õ�������ķ�������:

package.path = package.path .. ';./XCLIB/?.lua' --ע�ⲻҪ©��������
require("_const")  --���볣��
require("_xcgui")  --���뺯��


local m_hWindow = XWnd_Create(0, 0, 400, 200,"war3helper",0,const.xc_window_style_default);
--��ʾ����
XWnd_ShowWindow(m_hWindow,5--[[SW_SHOW]]);

