#include "CCodec.h"
#include <assert.h>



std::wstring bm_utf8_to_utf16(std::string str)
{
	std::wstring re;
	int textlen = MultiByteToWideChar( CP_UTF8, 0, str.c_str(),-1,    NULL,0 );
	re.resize(textlen);
	MultiByteToWideChar(CP_UTF8, 0,str.c_str(),-1,re.begin(),re.size());  
	return    re;  
}
std::string bm_utf16_to_utf8(std::wstring str)
{
	std::string data;
	// wide char to multi char
	int textlen = WideCharToMultiByte( CP_UTF8, 0, str.c_str(),-1,NULL,0,NULL,NULL);
	data.resize(textlen);
	WideCharToMultiByte( CP_UTF8, 0, str.c_str(), -1, data.begin(),data.size(), NULL, NULL );
	return    data;  
}

//UTF8תANSI
std::string bm_utf8_to_ascii(std::string strUTF8)
{
	//��ȡת��Ϊ���ֽں���Ҫ�Ļ�������С���������ֽڻ�����
	UINT nLen = MultiByteToWideChar(CP_UTF8,NULL,strUTF8.c_str(),-1,NULL,NULL);
	WCHAR *wszBuffer = new WCHAR[nLen+1];
	nLen = MultiByteToWideChar(CP_UTF8,NULL,strUTF8.c_str(),-1,wszBuffer,nLen);
	wszBuffer[nLen] = 0;
	
	nLen = WideCharToMultiByte(936,NULL,wszBuffer,-1,NULL,NULL,NULL,NULL);
	CHAR *szBuffer = new CHAR[nLen+1];
	nLen = WideCharToMultiByte(936,NULL,wszBuffer,-1,szBuffer,nLen,NULL,NULL);
	szBuffer[nLen] = 0;
	
	std::string ret;
	ret=szBuffer;
	//�����ڴ�
	delete []szBuffer;
	delete []wszBuffer;
	return    ret;  
}
std::string bm_ascii_to_utf8(std::string str)
{
	std::wstring wstr = bm_ascii_to_utf16(str.c_str());
	std::string t = bm_utf16_to_utf8(wstr);
	return t;
}

std::string bm_utf16_to_ascii(std::wstring wsz)
{
	std::string re;
	int nMinSize = WideCharToMultiByte(CP_OEMCP,NULL,wsz.c_str(),-1,NULL,0,NULL,FALSE);
	re.resize(nMinSize-1); //��ΪnMinSize ���ַ����ĳ���+1���ܿӵ�
	WideCharToMultiByte(CP_OEMCP,NULL,wsz.c_str(),-1,re.begin(),nMinSize,NULL,FALSE);
	return re;
}
std::wstring bm_ascii_to_utf16(std::string sz)
{
	std::wstring re;
	int nLen = MultiByteToWideChar (CP_ACP, 0, sz.c_str(), -1, NULL, 0);
	re.resize(nLen-1);
	MultiByteToWideChar (CP_ACP, 0, sz.c_str(), -1, re.begin(), nLen+1); 
	return re;
}

unsigned char ToHex(unsigned char x) 
{ 
    return  x > 9 ? x + 55 : x + 48; 
}

unsigned char FromHex(unsigned char x) 
{ 
    unsigned char y;
    if (x >= 'A' && x <= 'Z') y = x - 'A' + 10;
    else if (x >= 'a' && x <= 'z') y = x - 'a' + 10;
    else if (x >= '0' && x <= '9') y = x - '0';
    else assert(0);
    return y;
}

std::string UrlEncode(const std::string& str)
{
	std::string strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++)
    {
        if (isalnum((unsigned char)str[i]) || 
            (str[i] == '-') ||
            (str[i] == '_') || 
            (str[i] == '.') || 
            (str[i] == '~'))
            strTemp += str[i];
        else if (str[i] == ' ')
            strTemp += "+";
        else
        {
            strTemp += '%';
            strTemp += ToHex((unsigned char)str[i] >> 4);
            strTemp += ToHex((unsigned char)str[i] % 16);
        }
    }
    return strTemp;
}

std::string UrlDecode(const std::string& str)
{
	std::string strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++)
    {
        if (str[i] == '+') strTemp += ' ';
        else if (str[i] == '%')
        {
            assert(i + 2 < length);
            unsigned char high = FromHex((unsigned char)str[++i]);
            unsigned char low = FromHex((unsigned char)str[++i]);
            strTemp += high*16 + low;
        }
        else strTemp += str[i];
    }
    return strTemp;
}


//////////////////////////////////////////////////////////////////////////
//�ַ�����16����ת��

// 16 ���� ת �ַ�
CHAR pHexToDecTable[] ={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
CHAR pDecToHexTable[] =
{
	//      0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F   
	/*  0*/	0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,\
	/*	1*/ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,\
	/*	2*/ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,\
	/*	3*/ 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 0 , 0 , 0 , 0 , 0 , 0 ,\
	/*	4*/ 0 , 10, 11, 12, 13, 14, 15, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,\
	/*	5*/ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,\
	/*	6*/ 0 , 10, 11, 12, 12, 14, 15, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,\
	/*	7*/ 0 , 10, 11, 12, 13, 14, 15, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,\
	/*	8*/ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,\
	/*	9*/ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,\
	/*	A*/ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,\
	/*	B*/ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,\
	/*	C*/ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,\
	/*	D*/ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,\
	/*	E*/ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,\
	/*	F*/ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
};
DWORD HexString2Bits(PBYTE lpSrc,DWORD dwSrcLenth,PBYTE lpDes)
{

	DWORD dwIndexSrc = 0; //������
	DWORD dwIndexDes = 0; //Ŀ�껺��������
	while(dwIndexSrc < dwSrcLenth)
	{

		for (int nMove = 7; nMove >= 0; nMove--)
		{
			lpDes[dwIndexDes] = (lpSrc[dwIndexSrc] >> nMove)&1;
			dwIndexDes++;
		}
		dwIndexSrc++;
		
	}
	return NO_ERROR;
}
DWORD Bits2HexString(PBYTE lpSrc,DWORD dwSrcLenth,PBYTE lpDes)
{

	DWORD dwIndexSrc = 0; //����
	DWORD dwIndexDes = 0; //Ŀ�껺��������

	while(dwIndexSrc < dwSrcLenth)
	{
		for (int i = 7; i >= 0; i--)
		{
			lpDes[dwIndexDes] =  lpDes[dwIndexDes] | ( lpSrc[dwIndexSrc]  << i);
			dwIndexSrc++;
		}
		dwIndexDes++;
	}
	return NO_ERROR;
}




DWORD HexString2Hex(PBYTE lpSrc,DWORD dwSrcLenth,PBYTE lpDes)
{
	//�ұ�
	DWORD dwIndexDes = 0;
	for (DWORD dwSrcIndex = 0; dwSrcIndex < dwSrcLenth; dwSrcIndex+=2)
	{
		lpDes[dwIndexDes] = ( (pDecToHexTable[lpSrc[dwSrcIndex]] << 4) & 0xF0 ) | pDecToHexTable[lpSrc[dwSrcIndex+1]];
		dwIndexDes++;
	}
	return NO_ERROR;
}

DWORD Hex2HexString(PBYTE lpSrc,DWORD dwSrcLenth,PBYTE lpDes)
{
	//�ұ�
	DWORD dwOutIndex = 0;
	for (DWORD dwSrcIndex = 0; dwSrcIndex < dwSrcLenth; dwSrcIndex++)
	{
		lpDes[dwOutIndex] = pHexToDecTable[ (lpSrc[dwSrcIndex] >> 4)&0xF ]; //ʮ�����Ƶ� ��4λ ���
		lpDes[dwOutIndex + 1] = pHexToDecTable[ lpSrc[dwSrcIndex] & 0xF ];  //ʮ�����Ƶ� ��4λ ���
		dwOutIndex+=2;
	}
	return NO_ERROR;
}


std::string Hex2HexString(PBYTE lpSrc,DWORD dwSrcLenth)
{
	std::string szRet;
	PBYTE pRes = new BYTE[dwSrcLenth*2+1];
	ZeroMemory(pRes,dwSrcLenth*2+1);
	Hex2HexString(lpSrc,dwSrcLenth,pRes);
	szRet = (char*)pRes;
	delete pRes;
	pRes = NULL;
	return szRet;
}

std::string Bits2HexString(PBYTE lpSrc,DWORD dwSrcLenth)
{

	std::string szRet;
	PBYTE pRes = new BYTE[dwSrcLenth/8+1];

	if (pRes == NULL){	return szRet;	}

	ZeroMemory(pRes,dwSrcLenth/8+1);
	Bits2HexString(lpSrc,dwSrcLenth,pRes);

	szRet = (char*)pRes;
	delete pRes;
	pRes = NULL;
	return szRet;
}