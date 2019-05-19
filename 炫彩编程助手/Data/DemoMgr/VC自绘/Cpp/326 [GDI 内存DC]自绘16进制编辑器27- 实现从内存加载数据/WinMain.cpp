#define  USE_GDIPACK
#define USE_GDIPLUS
#pragma warning(disable:4786)


	


#include "Common.h"
#include "DrawPack.h"


#include <map>


class XFileMem
{
public:
	BOOL Open(void *lpBuffer,DWORD dwBufferSize)
	{
		m_Data.resize(dwBufferSize);
		CopyMemory(m_Data.begin(),lpBuffer,dwBufferSize);
		//		m_Data.assign((char*)lpBuffer,(char*)lpBuffer+dwBufferSize);
		return TRUE;
	}
	VOID Close()
	{
	}
	BOOL SetPoint(int nPos)
	{
		m_nPos = nPos;
		return nPos > m_Data.size();
	}
	
	BOOL Read(VOID* pBuffer,DWORD dwBufferSize,DWORD* pdwRealReadSize)
	{
		DWORD nLeftSize = m_Data.size() - m_nPos;
		
		if ( nLeftSize < dwBufferSize  )
			*pdwRealReadSize = nLeftSize;
		else
			*pdwRealReadSize  = dwBufferSize;
		
		
		CopyMemory(pBuffer,m_Data.begin()+m_nPos,*pdwRealReadSize);
		return TRUE;
	}
	BOOL WriteChar(char ch)
	{
		m_Data[m_nPos]=ch;
		return TRUE;
	}
	
	BOOL GetSizeMoreThan4GB(PLARGE_INTEGER fileSize)
	{
		return m_Data.size();
	}
	BOOL GetSizeLessThan4GB(DWORD* pdwSize)
	{
		*pdwSize = m_Data.size();
		return TRUE;
	}
private:
	int    m_nPos;
	std::vector<char> m_Data;
};

typedef enum
{
	XFile_Open_File=0,
	XFile_Open_Mem,
}XFile_Open_;

class XFile
{
public:
	//�ڶ�������û�á�����
	BOOL Open(const wchar_t* lpFileName)
	{
		m_OpenType = XFile_Open_File;

		m_hFile = CreateFileW(
			lpFileName,
			GENERIC_READ|GENERIC_WRITE,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL);
		if (m_hFile == INVALID_HANDLE_VALUE)
			return FALSE;

		return TRUE;
	}
	BOOL OpenBuffer(void* lpBuffer,DWORD dwBufferSize)
	{
		m_OpenType = XFile_Open_Mem;
		m_MemFile.Open(lpBuffer,dwBufferSize);
	}
	VOID Close()
	{
		if (m_OpenType == XFile_Open_File)
			CloseHandle(m_hFile);
	}
	BOOL SetPoint(int nPos)
	{
		if (m_OpenType == XFile_Open_File)
			return SetFilePointer(m_hFile,nPos,NULL,FILE_BEGIN) == INVALID_SET_FILE_POINTER ? FALSE:FALSE;
		if (m_OpenType == XFile_Open_Mem)
			return m_MemFile.SetPoint(nPos);
		return TRUE;
	}

	BOOL Read(VOID* pBuffer,DWORD dwBufferSize,DWORD* pdwRealReadSize)
	{
		if (m_OpenType == XFile_Open_File)
			return ReadFile(m_hFile,pBuffer,dwBufferSize,pdwRealReadSize,NULL);
		if (m_OpenType == XFile_Open_Mem)
			return m_MemFile.Read(pBuffer,dwBufferSize,pdwRealReadSize);
		return TRUE;
	}
	BOOL WriteChar(char ch)
	{
		DWORD dwWriteByts = 0;
		if (m_OpenType == XFile_Open_File)
			return ::WriteFile(m_hFile,&ch,1,&dwWriteByts,NULL);

		if (m_OpenType == XFile_Open_Mem)
			return m_MemFile.WriteChar(ch);

		return TRUE;
	}

	BOOL GetSizeMoreThan4GB(PLARGE_INTEGER fileSize)
	{
		if (m_OpenType == XFile_Open_File)
			return GetFileSizeEx(m_hFile,fileSize);
		if (m_OpenType == XFile_Open_Mem)
			return m_MemFile.GetSizeMoreThan4GB(fileSize);
		return TRUE;

	}
	BOOL GetSizeLessThan4GB(DWORD* pdwSize)
	{
		if (m_OpenType == XFile_Open_File)
		{
			LARGE_INTEGER fullSize;
			BOOL bOk = GetSizeMoreThan4GB(&fullSize);
			*pdwSize = fullSize.LowPart;
			return bOk;
		}
		if (m_OpenType == XFile_Open_Mem)
			return m_MemFile.GetSizeLessThan4GB(pdwSize);

		return TRUE;
	}

private:
	XFile_Open_  m_OpenType;   
	HANDLE m_hFile;
	XFileMem m_MemFile;
};






class XBuffer
{
public:
	XBuffer()
	{
		m_pBuffer = NULL;
	}
	~XBuffer()
	{
		if (m_pBuffer)
			delete [] m_pBuffer;
	}

	void ReSize(int size)
	{
		
		if (size < m_MaxShowCount)
		{
			m_MaxShowCount = size;
			return ;
		}

		if (m_pBuffer)
			delete [] m_pBuffer;

		m_pBuffer = new char[size];
		m_MaxShowCount = size;
	}
public:
	char* m_pBuffer;
	int m_MaxShowCount;
};


//����������
class XHightLight
{
public:
	void Add(int pos,COLORREF cor)
	{
		std::map<int,COLORREF>::iterator it = m_data.find(pos);
		
		if ( it != m_data.end())
		{
			it->second = cor;
		}else
		{
			m_data.insert(std::pair<int,COLORREF>(pos,cor));
		}
	}
	void Del(int pos)
	{
		std::map<int,COLORREF>::iterator it = m_data.find(pos);
		if (it != m_data.end())
			m_data.erase(it);
	}

	BOOL IsHighLight(int pos,COLORREF* pCor)
	{
		if (IsEmpty())
			return FALSE;
		
		std::map<int,COLORREF>::iterator it = m_data.find(pos);
		
		if (it == m_data.end())
			return FALSE;
		
		*pCor = it->second;
		return TRUE;
	}

	BOOL IsEmpty()
	{
		return m_data.empty();
	}
	VOID Clear()
	{
		m_data.clear();
	}

private:
	std::map<int,COLORREF> m_data;
};


//�޸ĵ����ݱ�����
class XModiyData
{
public:
	//ch ���޸ĵĲ���
	//pos ���޸����ݵľ���λ��
	void push(int pos,char ch)
	{
		std::map<int,char>::iterator it = m_data.find(pos);

		if ( it != m_data.end())
		{
			it->second = ch;
		}else
		{
			m_data.insert(std::pair<int,char>(pos,ch));
		}
	}
	BOOL pop(char* pCh,int * pPos)
	{
		if (IsEmpty())
			return FALSE;
		std::map<int,char>::iterator it = m_data.end();
		it--;
		if (pCh != NULL && pPos != NULL)
		{
			*pCh = it->second;
			*pPos = it->first;
		}
		m_data.erase(it);
		return TRUE;
	}
	BOOL IsEmpty()
	{
		return m_data.empty();
	}
	VOID Clear()
	{
		m_data.clear();
	}
	BOOL IsDataModify(int pos,char* pCh)
	{
		if (IsEmpty())
			return FALSE;
		
		std::map<int,char>::iterator it = m_data.find(pos);

		if (it == m_data.end())
			return FALSE;

		*pCh = it->second;
		return TRUE;
	}
	std::map<int,char>::iterator GetBegin()
	{
		return m_data.begin();
	}
	std::map<int,char>::iterator GetEnd()
	{
		return m_data.end();
	}
private:
	std::map<int,char> m_data;
};


class XHexFilter
{
public:
	XHexFilter()
	{
		memset(m_TableArray,'.',256);
		unsigned char ch = 33;
		for (; ch < 128; ch++)
		{
			m_TableArray[ch] = ch;
		}
		m_TableArray[127] = '.';
	}
	void SetFilter(unsigned char index,char showedChar)
	{
		m_TableArray[index]= showedChar;
	}
	char* Filter(char* lpChar)
	{
		return m_TableArray + (unsigned char)*lpChar;
	}
private:
	char m_TableArray[256];
};



class DataFormat
{
public:
    DataFormat()
    {
        ZeroMemory(pDicTable, 256);
        pDicTable['0'] = 0;
        pDicTable['1'] = 1;
        pDicTable['2'] = 2;
        pDicTable['3'] = 3;
        pDicTable['4'] = 4;
        pDicTable['5'] = 5;
        pDicTable['6'] = 6;
        pDicTable['7'] = 7;
        pDicTable['8'] = 8;
        pDicTable['9'] = 9;
        pDicTable['A'] = 10;
        pDicTable['B'] = 11;
        pDicTable['C'] = 12;
        pDicTable['D'] = 13;
        pDicTable['E'] = 14;
        pDicTable['F'] = 15;
		pDicTable['a'] = 10;
        pDicTable['b'] = 11;
        pDicTable['c'] = 12;
        pDicTable['d'] = 13;
        pDicTable['e'] = 14;
        pDicTable['f'] = 15;
    }
    wchar_t HexStrToChar(const wchar_t* pBuf)
    {
        wchar_t result = 0;
        result |= ((pDicTable[pBuf[0]] << 4) & 0xF0);
        result |= pDicTable[pBuf[1]];
        return result;
    }
	// ����a ��16�����ַ����� 61 ��ʱ�����޸� 6���� 1
	char CharModiy(char chSrc,int nIndex,wchar_t md)
	{
		char result = '\0';
		if (nIndex == 0)
		{//�޸ĸ�λ
			result |= pDicTable[md];
			result <<= 4;
			result |= (chSrc&0x0f);
		} 
		else // == 1 �޸ĵ�λ
		{
			result = chSrc&0xf0;
			result |= pDicTable[md];
		}
		return result;
	}

    wchar_t* CharToHexStr(wchar_t ch)
    {
        wchar_t pHexToDecTable[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
        buffer[0] = pHexToDecTable[(ch & 0xf000) >> 12];
        buffer[1] = pHexToDecTable[(ch & 0xf00) >> 8];
        buffer[2] = pHexToDecTable[(ch & 0xf0) >> 4];
        buffer[3] = pHexToDecTable[(ch & 0xf)];
        buffer[4] = 0;
        return buffer;
    }
	wchar_t* CharToHexWstring(char ch)
	{
        wchar_t pHexToDecTable[] = { L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'A', L'B', L'C', L'D', L'E', L'F' };
        m_WString[0] = pHexToDecTable[(ch & 0xf0) >> 4];
        m_WString[1] = pHexToDecTable[(ch & 0xf)];
		m_WString[2] = 0;
		return m_WString;
	}
private:
    wchar_t pDicTable[256];
	wchar_t m_WString[5];
    wchar_t buffer[5];
};



class XPartRect
{
public:
	VOID SetRect(int x,int y,int cx,int cy)
	{
		m_rt.left = x;
		m_rt.top  = y;
		m_rt.right = x+cx;
		m_rt.bottom = y+cy;
	}
	VOID GetRect(RECT* pRect)
	{
		*pRect = m_rt;
	}
protected:
	RECT m_rt;
};


class XPart1 : public XPartRect
{
public:
	XPart1()
	{
		ZeroMemory(m_lpText,256);
		wcscat(m_lpText,L"offset");
	}
	VOID SetText(const wchar_t* lpText)
	{
		wcscpy(m_lpText,lpText);
	}
	void Draw(XGDIMEMDC* pMemDC)
	{
		pMemDC->DrawText(m_lpText,wcslen(m_lpText),&m_rt,DT_CENTER|DT_VCENTER);
	}
private:
	wchar_t m_lpText[128];
};


class XPart2 : public XPartRect
{
public:
	XPart2()
	{
		//m_lpText = L"000102030405060708090A0B0C0D0E0F";
		m_lpText = L"0123456789ABCDEF";
	}
	int GetChCount()
	{
		return 16;
	}
	VOID SetChRect(int nIndex,int x,int y,int cx,int cy)
	{
		m_rtArray[nIndex].left = x;
		m_rtArray[nIndex].top  = y;
		m_rtArray[nIndex].right = x+cx;
		m_rtArray[nIndex].bottom = y+cy;
	}

	VOID Draw(XGDIMEMDC* pMemDC,int nHightLigtColIndex)
	{
		for (int i = 0; i < 16; i++)
		{
			if (i == nHightLigtColIndex)
			{
				COLORREF cor = pMemDC->SetBkColor(RGB(224,224,255));
				pMemDC->DrawRect1(m_rtArray+i);
				pMemDC->DrawText(m_lpText+i,1,m_rtArray+i,DT_LEFT|DT_VCENTER);
				pMemDC->SetBkColor(cor);
			} 
			else
			{
				pMemDC->DrawRect1(m_rtArray+i);
				pMemDC->DrawText(m_lpText+i,1,m_rtArray+i,DT_LEFT|DT_VCENTER);
			}
		}
	}
private:
	RECT m_rtArray[16];
	wchar_t* m_lpText;
};


class XPart3 : public XPartRect
{
public:
	XPart3()
	{
		m_lpText = L"0123456789ABCDEF";
	}
	int GetChCount()
	{
		return 16;
	}
	VOID SetChRect(int nIndex,int x,int y,int cx,int cy)
	{
		m_rtArray[nIndex].left = x;
		m_rtArray[nIndex].top  = y;
		m_rtArray[nIndex].right = x+cx;
		m_rtArray[nIndex].bottom = y+cy;
	}
	
	VOID Draw(XGDIMEMDC* pMemDC,int nHighLightColIndex)
	{
		for (int i = 0; i < 16; i++)
		{
			if (i == nHighLightColIndex)
			{
				COLORREF cor = pMemDC->SetBkColor(RGB(224,224,255));
//				pMemDC->DrawRect1(m_rtArray+i);
				pMemDC->DrawText(m_lpText+i,1,m_rtArray+i,DT_LEFT|DT_VCENTER);
				pMemDC->SetBkColor(cor);
			} 
			else
			{
//				pMemDC->DrawRect1(m_rtArray+i);
				pMemDC->DrawText(m_lpText+i,1,m_rtArray+i,DT_LEFT|DT_VCENTER);
			}

		}
	}
private:
	RECT m_rtArray[16];
	wchar_t* m_lpText;
};


class XPart4 : public XPartRect
{
public:
	XPart4()
	{
		m_buffer[8]=L'\0';
	}

	VOID SetChRect(int nIndex,int x,int y,int cx,int cy)
	{
		m_rtArray[nIndex].left = x;
		m_rtArray[nIndex].top  = y;
		m_rtArray[nIndex].right = x+cx;
		m_rtArray[nIndex].bottom = y+cy;
	}
	int GetRowCount()
	{
		return m_nMaxShowRowCount;
	}
	VOID SetRowCount(int nRowCount)
	{
		m_nMaxShowRowCount = nRowCount;
	}

	VOID Draw(XGDIMEMDC* pMemDC,int nHightLightRowIndex,int m_nScorbarPos)
	{
		for (int i = 0; i < m_nMaxShowRowCount; i++)
		{
			if (nHightLightRowIndex == i+m_nScorbarPos)
			{
				COLORREF cor = pMemDC->SetBkColor(RGB(224,224,255));
				wsprintfW(m_buffer,L"%08X",i+m_nScorbarPos);
				pMemDC->TextOutW(m_rtArray[i].left,m_rtArray[i].top,m_buffer,8);
				pMemDC->SetBkColor(cor);
			} 
			else
			{
				wsprintfW(m_buffer,L"%08X",i+m_nScorbarPos);
				pMemDC->TextOutW(m_rtArray[i].left,m_rtArray[i].top,m_buffer,8);

			}
		}
	}

private:
	wchar_t m_buffer[9];
	RECT    m_rtArray[1000];
	int     m_nMaxShowRowCount;
};


class XPart5 : public XPartRect
{
public:
	XPart5()
	{
		m_pRtArray = NULL;
		m_ArraySize = 0;
	}

	VOID ReSize(int nSize)
	{
		if (nSize < m_ArraySize)
		{
			m_ArraySize = nSize;
			return ;
		}
		if (m_ArraySize != NULL)
		{
			delete [] m_pRtArray;
			m_pRtArray = new RECT[nSize];
		}else
		{
			m_pRtArray = new RECT[nSize];
		}
		m_ArraySize = nSize;
	}
	int GetArrayCount()
	{
		return m_ArraySize;
	}
	void SetHexsRect(int nIndex,int x,int y,int cx,int cy)
	{
		m_pRtArray[nIndex].left = x;
		m_pRtArray[nIndex].top  = y;
		m_pRtArray[nIndex].right = x+cx;
		m_pRtArray[nIndex].bottom = y+cy;
	}
	void GetHexsRect(int nIndex,RECT *pRect)
	{
		*pRect = m_pRtArray[nIndex];
	}
private:
	RECT* m_pRtArray;
	int   m_ArraySize;
};

class XPart6 : public XPart5
{
public:
	XPart6()
	{

	}
};


#define HEX_TEXT_HEIGHT 14
#define SPLIT1_WIDTH  10
#define SPLIT2_WIDTH  10

enum CARET_IN_
{
	CARET_IN_PART1 = 1,
	CARET_IN_PART2,
	CARET_IN_PART3,
	CARET_IN_PART4,
	CARET_IN_PART5,
	CARET_IN_PART6,
};

class XHexEdit
{
public:
	typedef struct _tagSelect 
	{
		CARET_IN_ m_CaretInWichPart;
		int       m_TextIndex; // ���� FF ����� 0,1 |FF ���� F|F ����� part6 ֻ�� 0
		int       m_DataIndex; //�������� buffer ƫ�� + ������pos
	}SELECT,*PSELECT;

	XHexEdit()
	{
		m_PaddingLeft = 5;
		m_PaddingTop  = 0;
		m_nPart2BlockWidth = 20;
		m_nPart2BlockSpace = 6;
		m_nPart3BlockWidth = 15;
		m_nRowHeight = HEX_TEXT_HEIGHT;
		m_nScorBarVPos = 0;
		m_nScorBarHPos = 0;
		ZeroMemory(&m_SelectStart,sizeof(m_SelectStart));
		m_SelectStart.m_DataIndex = -1;
		ZeroMemory(&m_SelectEnd,sizeof(m_SelectEnd));
		m_SelectEnd.m_DataIndex = -1;
	}
	HELE Init(int x,int y,int cx,int cy,HXCGUI hParent)
	{
		m_x = x, m_y = y,m_cx = cx, m_cy = cy;
        m_hScrollView=XSView_Create(m_x,m_y,m_cx,m_cy,hParent);
		XEle_RegEventCPP(m_hScrollView,XE_SCROLLVIEW_SCROLL_H,&XHexEdit::OnScrollViewScrollH);
		XEle_RegEventCPP(m_hScrollView,XE_SCROLLVIEW_SCROLL_V,&XHexEdit::OnScrollViewScrollV);
		XEle_RegEventCPP(m_hScrollView,XE_SIZE,&XHexEdit::OnSize);
		XEle_RegEventCPP(m_hScrollView,XE_PAINT_SCROLLVIEW,&XHexEdit::OnDrawScrollView);
		XEle_RegEventCPP(m_hScrollView,XE_MOUSEMOVE,&XHexEdit::OnMouseMove);
		XEle_RegEventCPP(m_hScrollView,XE_LBUTTONDOWN,&XHexEdit::OnLButtonDown);
		XEle_RegEventCPP(m_hScrollView,XE_KEYDOWN,&XHexEdit::OnEventKeyDown);
		XEle_RegEventCPP(m_hScrollView,XE_CHAR,&XHexEdit::OnEventChar);
//		XEle_RegEventCPP(m_hScrollView,XE_SETFONT,&XHexEdit::OnSetFont);

		XEle_RegEventCPP(m_hScrollView,XE_DESTROY,&XHexEdit::OnDestroy);
		XSView_SetBorderSize(m_hScrollView,0,0,0,0);

		m_Caret.Create(m_hScrollView,1,m_nRowHeight);
		m_Caret.SetColor(RGB(128,0,0));
		m_MemDC.Create(XEle_GetHWND(m_hScrollView));

		XEle_PostEvent(m_hScrollView,m_hScrollView,XE_SIZE,NULL,NULL);

		return m_hScrollView;
	}

	static HELE Create(int x,int y,int cx,int cy,HXCGUI hParent)
	{
		
		XHexEdit* pEdit = new XHexEdit;
		HELE hEle = pEdit->Init(x,y,cx,cy,hParent);
		if (pEdit == NULL)
		{
			delete pEdit;
			pEdit = NULL;
			return NULL;
		}
		_XC_SetType(hEle,(XC_OBJECT_TYPE)XC_HEXEDIT); //��������
		_XC_AddType(hEle,(XC_OBJECT_TYPE)XC_HEXEDIT); //��������
		_XC_BindData(hEle, (int)pEdit); //�󶨹���
		return hEle;
	}


	BOOL LoadFile(const wchar_t* lpFileName)
	{
		if (!m_FileReadWrite.Open(lpFileName))
			return FALSE;

		//Ԫ�ؿؼ���С�仯 ���¼�����ͼ�ܴ�С
// 		LARGE_INTEGER fileSize;
// 		m_File.GetSizeMoreThan4GB(&fileSize);

		LONGLONG fileSize = 0;
		if (!GetFileSize(&fileSize))
			return FALSE;
		
		DWORD nRowCount = fileSize / 16 + ( fileSize % 16?1:0) ;
		int nRowHeight = m_PaddingTop+m_nRowHeight+nRowCount*m_nRowHeight+100;
		XSView_SetTotalSize(m_hScrollView,800,nRowHeight);
		XSView_SetLineSize(m_hScrollView,m_nRowHeight,m_nRowHeight);

		XEle_PostEvent(m_hScrollView,m_hScrollView,XE_SIZE,NULL,NULL);

		m_nScorBarVPos = 0;
		return TRUE;
	}

	BOOL LoadBuffer(void* lpBuffer,DWORD dwBufferSize)
	{
		if (!m_FileReadWrite.OpenBuffer(lpBuffer,dwBufferSize))
			return FALSE;
		
		//Ԫ�ؿؼ���С�仯 ���¼�����ͼ�ܴ�С
		// 		LARGE_INTEGER fileSize;
		// 		m_File.GetSizeMoreThan4GB(&fileSize);
		
		LONGLONG fileSize = 0;
		if (!GetFileSize(&fileSize))
			return FALSE;
		
		DWORD nRowCount = fileSize / 16 + ( fileSize % 16?1:0) ;
		int nRowHeight = m_PaddingTop+m_nRowHeight+nRowCount*m_nRowHeight+100;
		XSView_SetTotalSize(m_hScrollView,800,nRowHeight);
		XSView_SetLineSize(m_hScrollView,m_nRowHeight,m_nRowHeight);
		
		XEle_PostEvent(m_hScrollView,m_hScrollView,XE_SIZE,NULL,NULL);
		
		m_nScorBarVPos = 0;
		return TRUE;
	}

	BOOL GetFileSize(LONGLONG* pFileSize)
	{
		LARGE_INTEGER fileSize;
		BOOL bOk = m_FileReadWrite.GetSizeMoreThan4GB(&fileSize);
		*pFileSize = fileSize.QuadPart;
		return bOk;
	}
	VOID SetFont(wchar_t* lpFontFile,const wchar_t* lpFontName,int nFontSize)
	{
		m_FileFont.CreateFromFile(lpFontFile,lpFontName,nFontSize);
		m_nRowHeight = nFontSize;
		m_nPart3BlockWidth = nFontSize;
		m_nPart2BlockWidth = nFontSize;
		m_MemDC.SelectObject(m_FileFont.GetHFont());
	}

	VOID SetHighLight(int nStart,int nEnd,COLORREF cor)
	{
		for (int i = nStart; i <= nEnd; i++)
			m_HighLight.Add(i,cor);
	}

	BOOL GetSelect(int* pSelectStart,int* pSelectEnd)
	{
		if (m_SelectStart.m_DataIndex == m_SelectEnd.m_DataIndex)
			return FALSE;
		if (m_SelectStart.m_DataIndex > m_SelectEnd.m_DataIndex)
		{
			*pSelectStart = m_SelectEnd.m_DataIndex;
			*pSelectEnd   = m_SelectStart.m_DataIndex;
		} 
		else
		{
			*pSelectStart = m_SelectStart.m_DataIndex;
			*pSelectEnd   = m_SelectEnd.m_DataIndex;
		}
		return TRUE;
	}
	VOID SetSelect(int nStart,int nEnd)
	{
		m_SelectStart.m_CaretInWichPart = CARET_IN_PART5;
		m_SelectStart.m_DataIndex = nStart;
		
		m_SelectEnd.m_CaretInWichPart = CARET_IN_PART5;
		m_SelectEnd.m_DataIndex  = nEnd;
	}
	VOID SetSelectAll()
	{
		LONGLONG fileSize;
		GetFileSize(&fileSize);
		SetSelect(0,fileSize-1);
	}


	BOOL SaveModiy()
	{
		std::map<int,char>::iterator it = m_ModData.GetBegin();

		while (it != m_ModData.GetEnd())
		{
			int nIndex = it->first;
			char  ch   = it->second;
			m_FileReadWrite.SetPoint(nIndex);
			m_FileReadWrite.WriteChar(ch);
			it++;
		}
		m_ModData.Clear();
		return TRUE;
	}


//�¼��ӿ�
public:
	int OnEventChar(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		//����
		if (wParam == 8)
			return 0;

		//��ʱ����λ�õ��ж�����part5 ������part6
		SELECT CaretInfo = m_SelectEnd;

		if (CaretInfo.m_CaretInWichPart == CARET_IN_PART5)
		{
			BOOL bFilter = TRUE;
			if ( wParam >= '0' && wParam <= '9')
			{
				bFilter = FALSE;
			} 
			else if ( wParam >= 'a' && wParam <= 'f')
			{
				bFilter = FALSE;
			} 
			else if( wParam >= 'A' && wParam <= 'F')
			{
				bFilter = FALSE;
			}

			SELECT CaretInfo = m_SelectEnd;

			//�����Ҫ���˾�ֱ�ӹ�����
			if ( bFilter == TRUE)
				return 0;

			//��������Ϣ

			//�����ж��Ƿ��Ѿ��޸Ĺ��ˡ�������
			char oldChar='0';
			int nScorllHideSize = m_nScorBarVPos*16;
			int nBufferIndex = CaretInfo.m_DataIndex - nScorllHideSize;

			if (m_ModData.IsDataModify(CaretInfo.m_DataIndex,&oldChar))
			{
				//����޸Ĺ��������޸Ĺ�������
				char newCh = m_Format.CharModiy(oldChar,CaretInfo.m_TextIndex,(wchar_t)wParam);
				m_ModData.push(nBufferIndex+nScorllHideSize,newCh);
			} 
			else
			{
				char newCh = m_Format.CharModiy(m_Buffer.m_pBuffer[nBufferIndex],CaretInfo.m_TextIndex,(wchar_t)wParam);
				m_ModData.push(nBufferIndex+nScorllHideSize,newCh);
			}
			CaretMoveRight_Part5(&CaretInfo);

			m_SelectStart = CaretInfo;
			m_SelectEnd   = CaretInfo;

			AutoAdjustCaretPosition();
			XEle_RedrawEle(m_hScrollView,TRUE);
			return 0;
		}
		if (CaretInfo.m_CaretInWichPart == CARET_IN_PART6)
		{
			int nBufferIndex = CaretInfo.m_DataIndex;
			//���滹Ҫ�޸�
			m_ModData.push(nBufferIndex,(char)wParam);
			CaretMoveRight_Part6(&CaretInfo);
			m_SelectStart = CaretInfo;
			m_SelectEnd   = CaretInfo;
			AutoAdjustCaretPosition();
			XEle_RedrawEle(m_hScrollView,TRUE);
			return 0;
		}
		return 0;
	}
	int OnEventKeyDown(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
#ifdef _DEBUG
		xtrace("keydown %d \r\n",wParam);
#endif
		if (wParam == VK_RIGHT)
		{
			SELECT CaretInfo = m_SelectEnd;
			//���������
			//��part5 ������part6
			if (CaretInfo.m_CaretInWichPart == CARET_IN_PART5)
			{
				CaretMoveRight_Part5(&CaretInfo);
				//��Ҫ���Ƿ�ס�� ctrl��
				if(GetAsyncKeyState(VK_SHIFT)&0x8000)
				{
					//��ѡ
					m_SelectEnd = CaretInfo;
					XEle_RedrawEle(m_hScrollView);
				}else
				{
					//���õ�ǰ���λ��
					m_SelectEnd = CaretInfo;
					m_SelectStart = CaretInfo;
				}
				AutoAdjustCaretPosition();
				XEle_RedrawEle(m_hScrollView);
			}
			if (CaretInfo.m_CaretInWichPart == CARET_IN_PART6)
			{
				CaretMoveRight_Part6(&CaretInfo);
				//��Ҫ���Ƿ�ס�� ctrl��
				if(GetAsyncKeyState(VK_SHIFT)&0x8000)
				{
					//��ѡ
					m_SelectEnd = CaretInfo;
					XEle_RedrawEle(m_hScrollView);
				}else
				{
					//���õ�ǰ���λ��
					m_SelectEnd = CaretInfo;
					m_SelectStart = CaretInfo;
				}
				//�Զ��������λ��
				AutoAdjustCaretPosition();
				XEle_RedrawEle(m_hScrollView);
			}
			return 0;
		}

		if (wParam == VK_LEFT)
		{
			SELECT CaretInfo = m_SelectEnd;
			//���������
			if (CaretInfo.m_CaretInWichPart == CARET_IN_PART5)
			{
				CaretMoveLeft_Part5(&CaretInfo);
				//��Ҫ���Ƿ�ס�� ctrl��
				if(GetAsyncKeyState(VK_SHIFT)&0x8000)
				{
					//��ѡ
					m_SelectEnd = CaretInfo;
					XEle_RedrawEle(m_hScrollView);
				}else
				{
					//���õ�ǰ���λ��
					m_SelectEnd = CaretInfo;
					m_SelectStart = CaretInfo;
				}
				//�Զ��������λ��
				AutoAdjustCaretPosition();
				XEle_RedrawEle(m_hScrollView);
				return 0;
			}
			if (CaretInfo.m_CaretInWichPart == CARET_IN_PART6)
			{
				CaretMoveLeft_Part6(&CaretInfo);
				//��Ҫ���Ƿ�ס�� ctrl��
				if(GetAsyncKeyState(VK_SHIFT)&0x8000)
				{
					//��ѡ
					m_SelectEnd = CaretInfo;
					XEle_RedrawEle(m_hScrollView);
				}else
				{
					//���õ�ǰ���λ��
					m_SelectEnd = CaretInfo;
					m_SelectStart = CaretInfo;
				}
				//�Զ��������λ��
				AutoAdjustCaretPosition();
				XEle_RedrawEle(m_hScrollView);
				return 0;
			}
			return 0;
		}

		// 90 == z
		if (wParam == 90 && GetAsyncKeyState(VK_CONTROL)&0x8000)
		{
			//�����޸�
			m_ModData.pop(NULL,NULL);
			XEle_RedrawEle(m_hScrollView);
			*pbHandled = TRUE;
			return 0;
		}
		// 83 == s
		if (wParam == 83 && GetAsyncKeyState(VK_CONTROL)&0x8000)
		{
			//�����޸�
			SaveModiy();
			//�޸���Ӳ���е����ݣ�Ҫ���¶�ȡ�����еĶ�ȡ����ͨ��������������ȡ��
			XEle_SendEvent(m_hScrollView,m_hScrollView,XE_SCROLLVIEW_SCROLL_V,(WPARAM)m_nScorBarVPos,NULL);
			XEle_RedrawEle(m_hScrollView);
			*pbHandled = TRUE;
			return 0;
		}
		

		return 0;
	}
	int OnLButtonDown(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		SIZE LineSize;
		XSView_GetLineSize(m_hScrollView,&LineSize);
//		pPt->x += LineSize.cx*m_nScorBarHPos; //���λ�������λ��Ҫת���ɾ���λ��
		pPt->x += XSView_GetViewPosH(m_hScrollView);


		RECT rt;
		m_Part5.GetRect(&rt);
		if (IsPtInRect2(pPt,&rt))
		{
			int nColIndex = (pPt->x - m_PaddingLeft - m_Part1Width)/(m_nPart2BlockWidth+m_nPart2BlockSpace);
			int nRowIndex = (pPt->y - m_PaddingTop - m_nRowHeight)/m_nRowHeight;
			//�����ǰ������������������ڿ���ʾ���������
			if (nRowIndex *16 + nColIndex >= m_nRealShowSize)
				return 0;

			int nOffsetIndex = nRowIndex *16 + nColIndex + m_nScorBarVPos*16;
			wchar_t txtBuffer[9] = {0};
			wsprintfW(txtBuffer,L"%08X",nOffsetIndex);
			m_part1.SetText(txtBuffer);

			m_SelectStart.m_CaretInWichPart = CARET_IN_PART5;
			m_SelectStart.m_DataIndex = nOffsetIndex;
			

			RECT rtCh;
			m_Part5.GetHexsRect(nRowIndex *16 + nColIndex,&rtCh);

			char ch = m_Buffer.m_pBuffer[nRowIndex *16 + nColIndex];
			wchar_t* pHexChar = m_Format.CharToHexWstring(ch);
			int chWidth = m_MemDC.GetTextWidth(pHexChar,1);
//			wchar_t* pHexChar = m_Format.CharToHexStr((wchar_t)ch);
//			int chWidth = m_MemDC.GetTextWidth(pHexChar+2,1);




			int nCaretPosX = rtCh.left;
			int nCaretPosY = rtCh.top;
			if (pPt->x > rtCh.left+chWidth)
			{
				nCaretPosX = rtCh.left+chWidth;
				m_SelectStart.m_TextIndex = 1;
			}else
			{
				nCaretPosX = rtCh.left;
				m_SelectStart.m_TextIndex = 0;
			}

			//������λ��
			m_SelectEnd = m_SelectStart;

			//�������ת���ɾ��Ե�����

			int nViewOffsetY = XSView_GetViewPosV(m_hScrollView);
//			nCaretPosY += m_nScorBarVPos*LineSize.cy;
			nCaretPosY += nViewOffsetY;

			//�����ʾ���
			m_Caret.SetPos(nCaretPosX,nCaretPosY);
			m_Caret.Show(TRUE);

			
			xtrace("caret in part5  Col=%d row=%d \r\n",nColIndex,nRowIndex);
			XEle_RedrawEle(m_hScrollView);
			return 0;
		}
		m_Part6.GetRect(&rt);
		if (IsPtInRect2(pPt,&rt))
		{
			int nColIndex = (pPt->x - m_PaddingLeft - m_Part1Width - SPLIT1_WIDTH - m_Part2Width - SPLIT2_WIDTH )/(m_nPart3BlockWidth);
			int nRowIndex = (pPt->y - m_nRowHeight)/m_nRowHeight;
			//�����ǰ������������������ڿ���ʾ���������
			if (nRowIndex *16 + nColIndex >= m_nRealShowSize)
				return 0;
			
			int nOffsetIndex = nRowIndex *16 + nColIndex + m_nScorBarVPos*16;
			wchar_t txtBuffer[9] = {0};
			wsprintfW(txtBuffer,L"%08X",nOffsetIndex);
			m_part1.SetText(txtBuffer);


			m_SelectStart.m_CaretInWichPart = CARET_IN_PART6;
			m_SelectStart.m_DataIndex = nOffsetIndex;
			m_SelectStart.m_TextIndex = 0;

			m_SelectEnd = m_SelectStart;

			RECT rtCh;
			m_Part6.GetHexsRect(nRowIndex *16 + nColIndex,&rtCh);

			int nCaretPosX = rtCh.left;
			int nCaretPosY = rtCh.top;

			int nViewOffsetY = XSView_GetViewPosV(m_hScrollView);
			//			nCaretPosY += m_nScorBarVPos*LineSize.cy;
			nCaretPosY += nViewOffsetY;

			//�����ʾ���
			m_Caret.SetPos(nCaretPosX,nCaretPosY);
			m_Caret.Show(TRUE);

			

			xtrace("caret in part6  Col=%d row=%d \r\n",nColIndex,nRowIndex);
			XEle_RedrawEle(m_hScrollView);
			return 0;
		}
		return 0;
	}
	int OnMouseMove(UINT nFlags, POINT *pPt, BOOL *pbHandled)
	{

		SIZE LineSize;
		XSView_GetLineSize(m_hScrollView,&LineSize);
//		pPt->x += LineSize.cx*m_nScorBarHPos;
		pPt->x += XSView_GetViewPosH(m_hScrollView);

		m_MousePosX = pPt->x ;
		m_MousePosy = pPt->y;

		if ( (nFlags & MK_LBUTTON) == 0)
		{
			XEle_RedrawEle(m_hScrollView,FALSE);
			return 0;
		}

		RECT rt;
		m_Part5.GetRect(&rt);
		if (IsPtInRect2(pPt,&rt))
		{
			if (CARET_IN_PART6 == m_SelectStart.m_CaretInWichPart)
			{
				//��갴�µ�ʱ���� �� part6 ���ǵ�ǰΪpart5��ֱ�Ӻ���
				XEle_RedrawEle(m_hScrollView);
				return 0;
			}
			int nColIndex = (pPt->x - m_PaddingLeft - m_Part1Width)/(m_nPart2BlockWidth+m_nPart2BlockSpace);
			int nRowIndex = (pPt->y - m_PaddingTop - m_nRowHeight)/m_nRowHeight;
			//�����ǰ������������������ڿ���ʾ���������
			if (nRowIndex *16 + nColIndex >= m_nRealShowSize)
				return 0;			

			//���� Part1��ʾ��ǰ �������λ��
			int nOffsetIndex = nRowIndex *16 + nColIndex + m_nScorBarVPos*16;
			wchar_t txtBuffer[9] = {0};
			wsprintfW(txtBuffer,L"%08X",nOffsetIndex);
			m_part1.SetText(txtBuffer);
			
			m_SelectEnd.m_CaretInWichPart = CARET_IN_PART5;
			m_SelectEnd.m_DataIndex = nOffsetIndex;
			
			
			RECT rtCh;
			m_Part5.GetHexsRect(nRowIndex *16 + nColIndex,&rtCh);
			
			char ch = m_Buffer.m_pBuffer[nRowIndex *16 + nColIndex];
			wchar_t* pHexChar = m_Format.CharToHexWstring(ch);
			//wchar_t* pHexChar = m_Format.CharToHexStr((wchar_t)ch);
			int chWidth = m_MemDC.GetTextWidth(pHexChar,1);
			
			int nCaretPosX = rtCh.left;
			int nCaretPosY = rtCh.top;
			if (pPt->x > rtCh.left+chWidth)
			{
				nCaretPosX = rtCh.left+chWidth;
				m_SelectEnd.m_TextIndex = 1;
			}else
			{
				nCaretPosX = rtCh.left;
				m_SelectEnd.m_TextIndex = 0;
			}
			
			
			//�������ת���ɾ��Ե�����
			int nViewOffsetY = XSView_GetViewPosV(m_hScrollView);
//			nCaretPosY += m_nScorBarVPos*m_nRowHeight;
			nCaretPosY += nViewOffsetY;
			
			//�����ʾ���
			m_Caret.SetPos(nCaretPosX,nCaretPosY);
			m_Caret.Show(TRUE);
			
			
			xtrace("caret in part5  Col=%d row=%d \r\n",nColIndex,nRowIndex);
			XEle_RedrawEle(m_hScrollView);
			return 0;
		}
		m_Part6.GetRect(&rt);
		if (IsPtInRect2(pPt,&rt))
		{

			if (m_SelectStart.m_CaretInWichPart == CARET_IN_PART5)
			{
				//��갴�µ�ʱ���� �� part5 ���ǵ�ǰΪpart��ֱ�Ӻ���
				XEle_RedrawEle(m_hScrollView);
				return 0;
			}

			int nColIndex = (pPt->x - m_PaddingLeft - m_Part1Width - SPLIT1_WIDTH - m_Part2Width - SPLIT2_WIDTH )/(m_nPart3BlockWidth);
			int nRowIndex = (pPt->y - m_nRowHeight)/m_nRowHeight;
			
			//�����ǰ������������������ڿ���ʾ���������
			if (nRowIndex *16 + nColIndex >= m_nRealShowSize)
				return 0;

			int nOffsetIndex = nRowIndex *16 + nColIndex + m_nScorBarVPos*16;
			wchar_t txtBuffer[9] = {0};
			wsprintfW(txtBuffer,L"%08X",nOffsetIndex);
			m_part1.SetText(txtBuffer);
			
			
			m_SelectEnd.m_CaretInWichPart = CARET_IN_PART6;
			m_SelectEnd.m_DataIndex = nOffsetIndex;
			m_SelectEnd.m_TextIndex = 0;
			

			
			RECT rtCh;
			m_Part6.GetHexsRect(nRowIndex *16 + nColIndex,&rtCh);
			
			int nCaretPosX = rtCh.left;
			int nCaretPosY = rtCh.top;
			
			int nViewOffsetY = XSView_GetViewPosV(m_hScrollView);
			//			nCaretPosY += m_nScorBarVPos*LineSize.cy;
			nCaretPosY += nViewOffsetY;
			//�����ʾ���
			m_Caret.SetPos(nCaretPosX,nCaretPosY);
			m_Caret.Show(TRUE);
			
			
			
			xtrace("caret in part6  Col=%d row=%d \r\n",nColIndex,nRowIndex);
			XEle_RedrawEle(m_hScrollView);
			return 0;
		}




		XEle_RedrawEle(m_hScrollView,FALSE);




		return 0;
	}
	int OnSize(BOOL *pbHandled)
	{
		//������Ԫ�ش�С�仯�󣬵��¹�������Χ��С�仯��
		//��ʱ����������λ��


		//�ؼ���С�仯����Ҫ��������

		//Ӧ�ø�����һ����ʾ��λ�ã����¶�λS

		//1 ���¼��㻺������С
		//2 ���¶�ȡָ��λ������
		//3 ���¼������part������
		//4 ���¶�λ�����Caret����

		m_cx = XEle_GetWidth(m_hScrollView);
		m_cy = XEle_GetHeight(m_hScrollView);
		m_MemDC.Resize(1000,m_cy);

		//���㵱ǰԪ���������ʾ���ٸ��ַ�
	    int cy = m_cy - m_PaddingTop - m_nRowHeight;
		int nShowBufferSize = (cy / m_nRowHeight + ((cy % m_nRowHeight)?1:0))*16;
		m_Buffer.ReSize(nShowBufferSize);


		HELE hSBarV = XSView_GetScrollBarV(m_hScrollView);
		int nRange = XSBar_GetRange(hSBarV);

		if (m_nScorBarVPos > nRange )
		{
			m_nScorBarVPos = nRange;
		}
#ifdef _DEBUG
		xtrace(" %d %d\r\n",nRange,m_nScorBarVPos);
#endif


		XEle_SendEvent(m_hScrollView,m_hScrollView,XE_SCROLLVIEW_SCROLL_V,(WPARAM)m_nScorBarVPos,NULL);

		//���µ������λ��
		AutoAdjustCaretPosition();


#ifdef _DEBUG
// 		xtrace("ViewPosH %d ViewPosH %d  TotalSize_cx%d TotalSize_cy%d --\r\n",
// 			XSView_GetViewPosH(m_hScrollView),
// 			XSView_GetViewPosV(m_hScrollView),
// 			sz.cx,
// 			sz.cy);	
#endif
		return 0;
	}
    int  OnScrollViewScrollH(int pos,BOOL *pbHandled)
    {
		m_nScorBarHPos = pos;
        XTRACE("XE_SCROLLVIEW_SCROLL_H %d \n",pos);
        return 0;
    }
    int  OnScrollViewScrollV(int pos,BOOL *pbHandled)
    {

		//���������� ��Ҫ���ļ�����
		// ��һ����ȡ������λ�õ����ݣ�
		// �ڶ������ʵ�ʶ�ȡ������С�ڿ���ʾ�����ݣ���ô���±���һ��
		// ���� ���¼������part������
		m_nScorBarVPos = pos;

		m_FileReadWrite.SetPoint(m_nScorBarVPos*16);
		m_FileReadWrite.Read(m_Buffer.m_pBuffer,m_Buffer.m_MaxShowCount,&m_nRealShowSize);
		

		m_nRealRowCount = m_nRealShowSize / 16 + (m_nRealShowSize%16?1:0);
		m_Part4.SetRowCount(m_nRealRowCount);

		m_Part5.ReSize(m_nRealShowSize);
		m_Part6.ReSize(m_nRealShowSize);

		AutoCalcPartsRect();


        XTRACE("XE_SCROLLVIEW_SCROLL_V %d \n",pos);
        return 0;
    }
#if 0
	int OnSetFont(BOOL *pbHandled)
	{
		//��ʱ������
		HFONTX hFontx = XEle_GetFont(m_hScrollView);
		xc_font_info_i font_info;
		XFont_GetFontInfo(hFontx,&font_info);
		bool bok = m_Font.CreateFromLogFontW2(font_info.aName,font_info.nSize);
		//		bool bok = m_Font.CreateFromLogFontW2(L"΢���ź�",font_info.nSize);
		m_MemDC.SelectObject(m_Font.m_hFont);
		return 0;
	}
#endif


	
	//��Ϊ6������

	//  | part1 | part2 | part3|
	//  |----------------------|
	//  | part4 | part5 | part6|
	//  |       |       |      |

	// part1  == offset �ַ���
	// part2  == 0 - F  �б�ʾ
	// part3  == 0 - F  �ַ���ʾ
	// part4  == 00000000  - FFFFFFFF  �к�
	// part5  == ʮ��������ʾ 
	// part6  == �ַ���ʽ��ʾ


	int OnDrawScrollView(HDRAW hDraw,BOOL *pbHandled)
	{
		m_MemDC.FillRect(0,0,m_MemDC.GetBitMapWidth(),m_MemDC.GetBitMapHeight());

		SELECT CaretInfo = m_SelectEnd;
		int nRowIndex = CaretInfo.m_DataIndex / 16;
		int nColIndex = CaretInfo.m_DataIndex % 16;

		m_MemDC.SetTextColor(RGB(128,18,0));
		// draw offset 
		m_part1.Draw(&m_MemDC);	
		m_MemDC.SetTextColor(RGB(0,0,128));
		m_part2.Draw(&m_MemDC,nColIndex);
		m_Part3.Draw(&m_MemDC,nColIndex);
		m_MemDC.SetTextColor(0);
		m_Part4.Draw(&m_MemDC,nRowIndex,m_nScorBarVPos);

#ifdef _DEBUG
		xtrace("type=%d Index=%d tpye=%d Index =%d\r\n",m_SelectStart.m_CaretInWichPart,m_SelectStart.m_DataIndex,
			m_SelectEnd.m_CaretInWichPart,m_SelectEnd.m_DataIndex);
#endif
		//������Ҫ�ж��Ƿ���ѡ��
		//Ϊ�����Ч�ʣ��ŷֿ� ��ѡ�е�״̬��û��ѡ�е�״̬
		//������״̬�ϲ�һ�£�����������Ӹ����״̬���������ɶ��

		
		int nSelectStart = 0;
		int nSelectEnd   = 0;
		if(!GetSelect(&nSelectStart,&nSelectEnd))
		{
			//û��ѡ��
			RECT rtPart5,rtPart6;
			int nScrollPos = m_nScorBarVPos*16;
			for (int k = 0 ; k < m_Part5.GetArrayCount(); k++)
			{
				
				m_Part5.GetHexsRect(k,&rtPart5);
				m_Part6.GetHexsRect(k,&rtPart6);
				DrawBuffer(&CaretInfo,m_Buffer.m_pBuffer[k],k+nScrollPos,&rtPart5,&rtPart6);
			}
		}else{
			//��ѡ��

#ifdef _DEBUG
			xtrace("select start = %d  select end = %d \r\n",nSelectStart,nSelectEnd);
#endif
			int  tmpIndex = 0; //���ַ����������ת���ɾ������� �����ж�
			RECT rtPart5,rtPart6;
			int nScorPos = m_nScorBarVPos*16;
			for (int k = 0 ; k < m_Part5.GetArrayCount(); k++)
			{
				tmpIndex = k + nScorPos;
				m_Part5.GetHexsRect(k,&rtPart5);
				m_Part6.GetHexsRect(k,&rtPart6);

				DrawBufferWithSelect(nSelectStart,nSelectEnd,
					&CaretInfo,
					m_Buffer.m_pBuffer[k],
					tmpIndex,&rtPart5,&rtPart6);

			}

		}

		HGDIOBJ hOldObj = m_MemDC.SelectObject(m_MemDC.GetStockObject(DC_PEN));
		m_MemDC.SetDCPenColor(RGB(255,0,0));
		//��������,���Ʈ������ʶ��
		int x1,y1,x2,y2;
		x1 = 0;
		y1 = m_MousePosy;
		x2 = m_Part1Width;
		y2 = m_MousePosy;
		m_MemDC.DrawLine(x1,y1,x2,y2);

		int x3,y3,x4,y4;
		x3 = m_MousePosX;
		y3 = m_nRowHeight;
		x4 = m_MousePosX;
		y4 = 0;
		m_MemDC.DrawLine(x3,y3,x4,y4);
		//�ָ���ɫ�ֳ�
		m_MemDC.SelectObject(hOldObj);

		int x,y;
		XDraw_GetOffset(hDraw,&x,&y);
		m_MemDC.BitBlt3_(hDraw,0,y);



//		XDraw_SetLineWidth(hDraw,m_nRowHeight);
		
		//��������,���Ʈ������ʶ��
// 		RECT rt1;
// 		rt1.left = 0;
// 		rt1.top  = m_MousePosy;
// 		rt1.right = m_Part1Width;
// 		rt1.bottom = m_MousePosy+m_nRowHeight/2;
// 		XDraw_FillRectColor(hDraw,&rt1,RGB(0,128,0),50);
// 
// 
// 		RECT rt2;
// 		rt2.left = m_MousePosX;
// 		rt2.top  = 0;
// 		rt2.right = m_MousePosX+m_nPart2BlockWidth/2;
// 		rt2.bottom = m_nRowHeight;
// 		XDraw_FillRectColor(hDraw,&rt2,RGB(0,128,0),50);


		return 0;
	}

	//nIndex,�Ǿ���ֵ����
	VOID DrawBuffer(SELECT* pCaretInfo,char ch,int nIndex,RECT* pRtHex,RECT* pRtChar)
	{
		//�޸Ĺ�����
		char ModifyCh;
		if (m_ModData.IsDataModify(nIndex,&ModifyCh))
		{	//���޸Ĺ�������
			COLORREF oldCor = m_MemDC.SetTextColor(RGB(255,0,0));
			//����16���� �� �����ַ�
			wchar_t* pStrHex= m_Format.CharToHexWstring(ModifyCh);
			m_MemDC.TextOutW(pRtHex->left,pRtHex->top,pStrHex,2);
			m_MemDC.TextOutA(pRtChar->left,pRtChar->top,m_HexFilter.Filter(&ModifyCh),1);

			m_MemDC.SetTextColor(oldCor);
			return ;
		}
		COLORREF cor;
		if (m_HighLight.IsHighLight(nIndex,&cor))
		{
			COLORREF oldCor = m_MemDC.SetTextColor(cor);
			wchar_t* pStrHex= m_Format.CharToHexWstring(ch);
			m_MemDC.TextOutW(pRtHex->left,pRtHex->top,pStrHex,2);
			m_MemDC.TextOutA(pRtChar->left,pRtChar->top,m_HexFilter.Filter(&ch),1);
			m_MemDC.SetTextColor(oldCor);;
			return ;
		}

		//������ڸ���
		if (pCaretInfo->m_DataIndex == nIndex)
		{
			//224,224,255
			COLORREF oldBkcor   = m_MemDC.SetBkColor(RGB(224,224,255));;
			//			COLORREF oldTextCor = m_MemDC.SetTextColor(RGB(128,18,0));
			
			wchar_t* pStrHex= m_Format.CharToHexWstring(ch);
			m_MemDC.TextOutW(pRtHex->left,pRtHex->top,pStrHex,2);
			m_MemDC.TextOutA(pRtChar->left,pRtChar->top,m_HexFilter.Filter(&ch),1);
			
			//			m_MemDC.SetTextColor(oldCor);
			m_MemDC.SetBkColor(oldBkcor);;
			return ;
		}		

		wchar_t* pStrHex= m_Format.CharToHexWstring(ch);
		m_MemDC.TextOutW(pRtHex->left,pRtHex->top,pStrHex,2);
		m_MemDC.TextOutA(pRtChar->left,pRtChar->top,m_HexFilter.Filter(&ch),1);

	}
	//����ѡ��״̬��
	VOID DrawBufferWithSelect(
		int nSelectStart,
		int nSelectEnd,
		SELECT* pCaretInfo,
		char ch,int nIndex,RECT* pRtHex,RECT* pRtChar)
	{
		
		if ( (nIndex >= nSelectStart) && (nIndex <= nSelectEnd) )
		{ //ѡ��


			//�޸Ĺ�����
			char ModifyCh = ch;
			m_ModData.IsDataModify(nIndex,&ModifyCh);

			COLORREF corBk = m_MemDC.SetBkColor(RGB(0,0,128));
			COLORREF corText = m_MemDC.SetTextColor(RGB(255,255,255));

			wchar_t* pStrHex = m_Format.CharToHexWstring(ModifyCh);

			m_MemDC.TextOutW(pRtHex->left,pRtHex->top,pStrHex,2);
			m_MemDC.TextOutA(pRtChar->left,pRtChar->top,m_HexFilter.Filter(&ModifyCh),1);

			m_MemDC.SetBkColor(corBk);
			m_MemDC.SetTextColor(corText);
			
			return ;
		}
		//û��ѡ�е�
		DrawBuffer(pCaretInfo,ch,nIndex,pRtHex,pRtChar);
	}

	int OnDestroy(BOOL *pbHandled)
	{
#ifdef _DLL
		delete this; //�ͷ���չ��
#endif
		return 0;
	}
private:
//�����صĵ���
	VOID CaretMoveRight_Part5(SELECT* pCaretInfo)
	{
		DWORD dwFileSize = 0;
		m_FileReadWrite.GetSizeLessThan4GB(&dwFileSize);
		if (pCaretInfo->m_DataIndex == (dwFileSize-1) && pCaretInfo->m_TextIndex == 1)
		{
			MessageBeep(-1);
			return;  //��ĩβ
		}
		if (pCaretInfo->m_TextIndex == 0)
		{
			RECT rt;
			int nBufferIndex =pCaretInfo->m_DataIndex - m_nScorBarVPos*16;
			m_Part5.GetHexsRect(nBufferIndex,&rt);
			pCaretInfo->m_TextIndex = 1;
		}else
		{
			
			pCaretInfo->m_DataIndex++;
			pCaretInfo->m_TextIndex = 0;
		}
	}
	VOID CaretMoveRight_Part6(SELECT* pCaretInfo)
	{
		DWORD dwFileSize = 0;
		m_FileReadWrite.GetSizeLessThan4GB(&dwFileSize);
		if (pCaretInfo->m_DataIndex == (dwFileSize-1) ) 
		{
			MessageBeep(-1);
			return;  //��ĩβ
		}
		pCaretInfo->m_DataIndex++;
	}


	VOID CaretMoveLeft_Part5(SELECT* pCaretInfo)
	{
		if (pCaretInfo->m_DataIndex == 0 && pCaretInfo->m_TextIndex == 0)
		{
			MessageBeep(-1);
			return ; //���ͷ��
		}
		//
		if (pCaretInfo->m_TextIndex == 1)
		{
			pCaretInfo->m_TextIndex=0;
		}else
		{
			//����
			pCaretInfo->m_DataIndex--;
			pCaretInfo->m_TextIndex=1;
		}
	}
	VOID CaretMoveLeft_Part6(SELECT* pCaretInfo)
	{
		if (pCaretInfo->m_DataIndex == 0)
		{
			MessageBeep(-1);
			return; //���ͷ��
		}
		
		pCaretInfo->m_DataIndex--;
		pCaretInfo->m_TextIndex=0;
	}



//��ʾ��صĵ���
	VOID AutoAdjustCaretPosition()
	{
		//���ݹ����Ϣ���Զ��������λ��
		SELECT CaretInfo = m_SelectEnd;
		//���������
		//��part5 ������part6
		if (CaretInfo.m_CaretInWichPart == CARET_IN_PART5)
		{
			RECT rt;
			
			int nBufferIndex =CaretInfo.m_DataIndex - m_nScorBarVPos*16;
			m_Part5.GetHexsRect(nBufferIndex,&rt);
			
			if (CaretInfo.m_TextIndex == 1)
			{
				wchar_t* pHexText = m_Format.CharToHexWstring(m_Buffer.m_pBuffer[nBufferIndex]);
				//wchar_t* pHexText = m_Format.CharToHexStr(m_Buffer.m_pBuffer[nBufferIndex]);
				rt.left += m_MemDC.GetTextWidth(pHexText,1);
			}
			
			int nViewOffsetY = XSView_GetViewPosV(m_hScrollView);
			//�������ת���ɾ��Ե�����
			//rt.top += m_nScorBarVPos*m_nRowHeight;
			rt.top += nViewOffsetY;
			m_Caret.SetPos(rt.left,rt.top);
		}
		if (CaretInfo.m_CaretInWichPart == CARET_IN_PART6)
		{
			
			int nBufferIndex =CaretInfo.m_DataIndex - m_nScorBarVPos*16;
			
			RECT rt;
			m_Part6.GetHexsRect(nBufferIndex,&rt);
			
			int nViewOffsetY = XSView_GetViewPosV(m_hScrollView);
			//�������ת���ɾ��Ե�����
			//rt.top += m_nScorBarVPos*m_nRowHeight;
			rt.top += nViewOffsetY;
			
			m_Caret.SetPos(rt.left,rt.top);
		}
	}

	//�Զ���������part������
	VOID AutoCalcPartsRect()
	{

		m_Part1Width = m_MemDC.GetTextWidth(L"00000000",8);

		int offsetX = m_PaddingLeft;
		int offsetY = m_PaddingTop;
		int x = offsetX;
		int y = offsetY; 
		m_part1.SetRect(x,y,m_Part1Width,m_nRowHeight);

		x+= m_Part1Width;
		x+= SPLIT1_WIDTH;

		m_Part2Width = (m_nPart2BlockWidth+m_nPart2BlockSpace)*m_part2.GetChCount();
		m_part2.SetRect(x,y,m_Part2Width,m_nRowHeight);

		int i ;
		for (i = 0; i < m_part2.GetChCount(); i++)
		{
			m_part2.SetChRect(i,x,y,m_nPart2BlockWidth,m_nRowHeight);
			x+=m_nPart2BlockWidth;
			x+=m_nPart2BlockSpace;
		}

		x+= SPLIT2_WIDTH;
		m_Part3Width = m_nPart3BlockWidth*m_Part3.GetChCount();
		m_Part3.SetRect(x,y,m_Part3Width,m_nRowHeight);
		for (i = 0; i < m_Part3.GetChCount(); i++)
		{
			m_Part3.SetChRect(i,x,y,m_nPart3BlockWidth,m_nRowHeight);
			x+=m_nPart3BlockWidth;
		}
		
		x = offsetX;
		y += m_nRowHeight;

		for (i = 0; i < m_Part4.GetRowCount(); i++)
		{
			m_Part4.SetChRect(i,x,y,m_Part1Width,m_nRowHeight);
			y+=m_nRowHeight;
		}


		x = offsetX+SPLIT1_WIDTH+m_Part1Width;
		y = offsetY+m_nRowHeight;
		m_Part5.SetRect(x,y,m_Part2Width,m_cy-m_nRowHeight-offsetY);
		for (i = 0; i < m_Part5.GetArrayCount(); i++)
		{
			if ( (i % 16) == 0 && i != 0)
			{
				x = offsetX+SPLIT1_WIDTH+m_Part1Width;
				y+= m_nRowHeight;
			}
			m_Part5.SetHexsRect(i,x,y,m_nPart2BlockWidth,m_nRowHeight);
			x+=m_nPart2BlockWidth;
			x+=m_nPart2BlockSpace;
		}


		x = offsetX +m_Part1Width+SPLIT1_WIDTH+m_Part2Width+SPLIT2_WIDTH;
		y = offsetY + m_nRowHeight;
		m_Part6.SetRect(x,y,m_Part3Width,m_cy-m_nRowHeight);

		for (i = 0; i < m_Part6.GetArrayCount(); i++)
		{
			if ( (i %16) == 0 && i != 0)
			{
				x= offsetX +m_Part1Width+SPLIT1_WIDTH+m_Part2Width+SPLIT2_WIDTH;
				y+= m_nRowHeight;
			}
			m_Part6.SetHexsRect(i,x,y,m_nPart3BlockWidth,m_nRowHeight);
			x+=m_nPart3BlockWidth;
		}
	}

private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;

	HELE    m_hScrollView;
		
	XFile  m_FileReadWrite;
	XBuffer m_Buffer;
	DataFormat m_Format;
	XGDIMEMDC m_MemDC;


	int m_PaddingLeft;
	int m_PaddingTop;
	//���������ı��Ŀ��
	int m_Part1Width;
	int m_Part2Width;
	int m_Part3Width;

	int m_nPart2BlockWidth; //�м�16�����ı� �������
	int m_nPart2BlockSpace; //�м�16�����ı� ���

	int m_nPart3BlockWidth; //�м�16�����ı� �������

	int m_nRowHeight;

	int  m_nScorBarVPos;
	int  m_nScorBarHPos; //ˮƽ����λ��

	//Ϊʲô�����������Ϊ��ȡ��ʵ�����ݿ��ܴ��ڱ༭�����ʾ�����ݴ�С
	DWORD m_nRealShowSize;
	int m_nRealRowCount;

	int m_MousePosX;
	int m_MousePosy;


	XPart1 m_part1;
	XPart2 m_part2;
	XPart3 m_Part3;
	XPart4 m_Part4;
	XPart5 m_Part5;
	XPart6 m_Part6;

	XHexFilter m_HexFilter;
	XHightLight m_HighLight;

	XCaret m_Caret;
	SELECT m_SelectStart; //����������������ʱ��Ĺ����Ϣ
	SELECT m_SelectEnd;  //�����ŵ�ǰ�����Ϣ

	XModiyData m_ModData;

	XGDIFileFont m_FileFont;
	XGDIFont     m_Font;
//	BOOL         m_bSetFont;
};



BOOL ERROR_IsXCGUI_HEXEDIT(HXCGUI hXCGUI, XC_OBJECT_TYPE nType,char* pFunName)
{
	if (XC_IsHXCGUI(hXCGUI, nType))
		return TRUE;
	_XC_DebugPrintf(2, "��API:%s()��, ������������Ч[%d].", pFunName, hXCGUI);
	return FALSE;
}

XC_API BOOL WINAPI XHexEdit_GetSelect(HELE hEle,int* pSelectStart,int* pSelectEnd)
{
	ERROR_IsXCGUI_HEXEDIT(hEle,XC_HEXEDIT,"XHexEdit_LoadFile");
	XHexEdit* pEdit = (XHexEdit*)_XC_GetBindData(hEle);
	return pEdit->GetSelect(pSelectStart,pSelectEnd);
}


XC_API HELE WINAPI XHexEdit_Create(int x,int y,int cx,int cy,HXCGUI hParent)
{
	return XHexEdit::Create(x,y,cx,cy,hParent);
}

XC_API BOOL WINAPI XHexEdit_LoadFile(HELE hEle,const wchar_t* lpFile)
{
	ERROR_IsXCGUI_HEXEDIT(hEle,XC_HEXEDIT,"XHexEdit_LoadFile");
	XHexEdit* pEdit = (XHexEdit*)_XC_GetBindData(hEle);
	return pEdit->LoadFile(lpFile);
}

XC_API VOID WINAPI XHexEdit_SetFont(HELE hEle,wchar_t* lpFontFile,const wchar_t* lpFontName,int nFontSize)
{
	ERROR_IsXCGUI_HEXEDIT(hEle,XC_HEXEDIT,"XHexEdit_SetFont");
	XHexEdit* pEdit = (XHexEdit*)_XC_GetBindData(hEle);
	pEdit->SetFont(lpFontFile,lpFontName,nFontSize);
}

XC_API VOID WINAPI XHexEdit_SetHighLight(HELE hEle,int nStart,int nEnd,COLORREF cor)
{
	ERROR_IsXCGUI_HEXEDIT(hEle,XC_HEXEDIT,"XHexEdit_SetHighLight");
	XHexEdit* pEdit = (XHexEdit*)_XC_GetBindData(hEle);
	pEdit->SetHighLight(nStart,nEnd,cor);
}

XC_API VOID WINAPI XHexEdit_SetSelectAll(HELE hEle)
{
	ERROR_IsXCGUI_HEXEDIT(hEle,XC_HEXEDIT,"XHexEdit_SetHighLight");
	XHexEdit* pEdit = (XHexEdit*)_XC_GetBindData(hEle);
	pEdit->SetSelectAll();
}



#if 1

class CMyWindowScrollView
{
public:
    HWINDOW m_hWindow;
	HELE m_hHexEdit;

    CMyWindowScrollView()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 600, 300, L"�Ųʽ���ⴰ��", NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		

#if 1
#define _DLL
		m_hHexEdit = XHexEdit_Create(20,50,200,200,m_hWindow);
		//		XEle_SetFont(hEle,XFont_CreateFromFile(L"Cousine-Regular.ttf",16)); //��ʱ����
		XHexEdit_SetFont(m_hHexEdit,L"Cousine-Regular.ttf",L"Cousine",16);
		XHexEdit_LoadFile(m_hHexEdit,L"g:\\1.bak");
//		XHexEdit_SetHighLight(hEle,0,10,RGB(160,0,160));
//		XHexEdit_SetHighLight(hEle,32,42,RGB(255,204,0));
		
#endif

#if 0
		XHexEdit * pHexEdit = new XHexEdit;
		m_hHexEdit = pHexEdit->Init(20,50,200,200,m_hWindow);
		pHexEdit->SetFont(L"Cousine-Regular.ttf",L"Cousine",16);
		pHexEdit->LoadFile(L"g:\\1.bak");
//		m_HexEdit.SetHighLight(0,10,RGB(160,0,160));
//		m_HexEdit.SetHighLight(32,42,RGB(255,204,0));

#endif
		

		XEle_RegEventCPP(m_hHexEdit,XE_RBUTTONDOWN,&CMyWindowScrollView::OnRButtonDOWN);
		XWnd_RegEventCPP(m_hWindow, XWM_MENU_SELECT, &CMyWindowScrollView::OnWndMenuSelect);
        XWnd_RegEventCPP(m_hWindow, XWM_MENU_EXIT, &CMyWindowScrollView::OnWndMenuExit);

		HXCGUI hLayoutBody = XLayout_Create();
		XWnd_BindLayoutObject(m_hWindow,window_position_body,hLayoutBody);
		XLayout_SetLayoutHeight(hLayoutBody,layout_size_type_fill,1);
		XLayout_SetLayoutWidth(hLayoutBody,layout_size_type_fill,1);
		
		XLayout_AddEle(hLayoutBody,m_hHexEdit);
		XEle_SetLayoutWidth(m_hHexEdit,layout_size_type_fill,1);
		XEle_SetLayoutHeight(m_hHexEdit,layout_size_type_fill,1);

		XWnd_AdjustLayout(m_hWindow);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnRButtonDOWN(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		POINT pt = *pPt;
		XEle_PointClientToWndClient(m_hHexEdit,&pt);
		//���������˵�
		HMENUX hMenu = XMenu_Create();
		XMenu_AddItem(hMenu, 201, L"���ָ���");
		XMenu_AddItem(hMenu, 202, L"ȫѡ");
		XMenu_AddItem(hMenu, 203, L"333");



		int nStart,nEnd;
		if (XHexEdit_GetSelect(m_hHexEdit,&nStart,&nEnd))
		{
			XMenu_AddItem(hMenu, 300, L"195.195.195", 201);
			XMenu_AddItem(hMenu, 301, L"255.174.201", 201);
			XMenu_AddItem(hMenu, 302, L"185.122.87", 201);
		}


		
		XMenu_SetItemIcon(hMenu,300,XImage_LoadFile(L"1.195.195.195.png"));
		XMenu_SetItemIcon(hMenu,301,XImage_LoadFile(L"2.255.174.201.png"));
		XMenu_SetItemIcon(hMenu,302,XImage_LoadFile(L"3.185.122.87.png"));
		
		
		XMenu_AddItem(hMenu, 400, L"444", 203);
		XMenu_AddItem(hMenu, 401, L"555", 203);
		XMenu_AddItem(hMenu, 402, L"666", 203);
		

		::ClientToScreen(XWnd_GetHWND(m_hWindow), &pt);
		XMenu_Popup(hMenu, XWnd_GetHWND(m_hWindow), pt.x, pt.y);

		return 0;
	}
	int  OnWndMenuSelect(int nID,BOOL *pBool)
    {
		switch (nID)
		{
		case 300:
		case 301:
		case 302:
			{
				COLORREF cor;
				if (nID == 300)
					cor = RGB(195,195,195);
				else if (nID == 301)
					cor = RGB(255,174,201);
				else
					cor = RGB(185,122,87);
				int nStart,nEnd;
				XHexEdit_GetSelect(m_hHexEdit,&nStart,&nEnd);
				XHexEdit_SetHighLight(m_hHexEdit,nStart,nEnd,cor);
				XEle_RedrawEle(m_hHexEdit);
			}
			break;
		case 202:

			XHexEdit_SetSelectAll(m_hHexEdit);
			XEle_RedrawEle(m_hHexEdit);
			break;
		}
        XTRACE("menu-item:%d\n",nID);
        return 0;
    }
    int  OnWndMenuExit(BOOL *pbHandled)
    {
        XTRACE("menu-exit \n");
        return 0;
    }
};


int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowScrollView  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}

#endif