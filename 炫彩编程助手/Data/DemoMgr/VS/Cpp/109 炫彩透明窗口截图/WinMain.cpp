#define  USE_GDIPLUS
#include "Common.h"

//��ȡEncoder��CLSID�ķ���
BOOL GetEncoderClsid(const WCHAR* format, CLSID* pCLSID)
{
	UINT num = 0;
	UINT size = 0;
	ImageCodecInfo* pImageCodecInfo = NULL;
	GetImageEncodersSize(&num, &size);
	if(size == 0)
		return FALSE;
	pImageCodecInfo = (ImageCodecInfo *)(malloc(size));
	if(pImageCodecInfo == NULL)
		return FALSE;
	GetImageEncoders(num, size, pImageCodecInfo);
	// Find for the support of format for image in the windows
	for(UINT i = 0; i < num; ++i)
	{
		//MimeType: Depiction for the program image 
		if( wcscmp(pImageCodecInfo[i].MimeType, format) == 0)
		{ 
			*pCLSID = pImageCodecInfo[i].Clsid;
			free(pImageCodecInfo);
			return TRUE; 
		} 
	} 
	free(pImageCodecInfo); 
	return FALSE;
}


HRESULT GetScreenSnap(HWND hWnd,int x,int y)
{
	///////////////////////////////////////////
	LPCWSTR     pszFileName = L"1.jpg";

	int     quality = 80;
	///////////////////////////

	HDC hdc = GetDC(hWnd);
	HDC hmemdc = ::CreateCompatibleDC(hdc);
	
	//�������λͼ,��λͼ���ڴ�����HDC��
	HBITMAP hbmp = ::CreateCompatibleBitmap(hdc,x,y),hold;      
	hold  = (HBITMAP)::SelectObject(hmemdc,hbmp);   
	//����Ļ�豸�����ڴ�����λͼ����
	BitBlt(hmemdc, 0, 0, x, y,hdc,0,0,SRCCOPY|CAPTUREBLT); 
	//��ԭ�ڴ�����
	SelectObject(hmemdc,hold);
	{      
		
		//ʹ��GDI+����λͼ
		Bitmap bit(hbmp,NULL);
		CLSID encoderClsid;      
		EncoderParameters encoderParameters;      
		
		encoderParameters.Count = 1;      
		encoderParameters.Parameter[0].Guid = EncoderQuality;      
		encoderParameters.Parameter[0].Type = EncoderParameterValueTypeLong;      
		encoderParameters.Parameter[0].NumberOfValues = 1;      
		encoderParameters.Parameter[0].Value = &quality;      
		
		GetEncoderClsid(L"image/jpeg",&encoderClsid);      
		bit.Save(pszFileName,&encoderClsid,&encoderParameters);
	}      
	::DeleteObject(hbmp);      
	::DeleteObject(hmemdc);
// 	::DeleteObject(hmemdc1);
// 	::DeleteObject(hdc1);
//	::DeleteObject(hdc);
	::ReleaseDC(hWnd,hdc);
	return 0;   
} 


class CMyWindowButton
{
public:
    HWINDOW m_hWindow;
    HELE    m_hButton_close;
    HELE    m_hButton;
    CMyWindowButton(){
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"�Ųʽ���ⴰ��",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
		XWnd_SetTransparentType(m_hWindow,window_transparent_shaped);
		XWnd_SetTransparentAlpha(m_hWindow,128);

        m_hButton = XBtn_Create(100, 50, 60, 25,L"��ͼ", m_hWindow);
        XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWindowButton::OnBtnClick);

        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
    int OnBtnClick(BOOL *pbHandled)
    {
		GetScreenSnap(XWnd_GetHWND(m_hWindow),300,200);
        MessageBoxW(XWnd_GetHWND(m_hWindow),L"�����˰�ť",L"��ʾ",MB_OK);
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{

    XInitXCGUI();
    CMyWindowButton  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}




