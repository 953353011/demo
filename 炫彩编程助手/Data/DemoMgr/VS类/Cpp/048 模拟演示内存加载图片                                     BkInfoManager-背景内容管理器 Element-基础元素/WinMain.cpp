#include "Common.h"


#include <iostream>
#include <fstream>


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��
	xcgui::XWnd m_Wnd(0,0,300,200,L"�Ųʽ����-����");//��������
    if(m_Wnd)
    {
		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);


		

 		std::ifstream ifsm("1.jpg",std::ios::binary|std::ios::in);
		ifsm.seekg(0,std::ios::end);
		int fileSize =ifsm.tellg();
//		char buffer[1574] = {0};
		char* buffer = new char[fileSize];
 
 		ifsm.seekg(0,std::ios::beg);
 		ifsm.read(buffer,fileSize);
 		ifsm.close();

		HIMAGE hImage = XImage_LoadMemory((void*)buffer,fileSize,TRUE);

		xcgui::XEle ele(0,0,100,100,m_Wnd);
		ele.GetBkManager().AddImage(element_state_flag_leave,hImage);

		//�ϰ汾ʹ�õķ�������Ҫ������
//		XEle_AddBkImage(hEle,hImage);


        m_Wnd.ShowWindow(SW_SHOW);//��ʾ����
        XRunXCGUI(); //����
    }
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}


