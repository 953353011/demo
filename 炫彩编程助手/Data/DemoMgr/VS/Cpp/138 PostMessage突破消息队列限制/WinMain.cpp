#include "Common.h"

#include "LY_MainDlg.h"


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //��ʼ��

	CLYMainDlgClass dlg;
	dlg.Init();
    XRunXCGUI(); //����
    XExitXCGUI(); //�ͷ���Դ
    return 0;
}


