


#ifndef _CODEC_H_
#define _CODEC_H_

#pragma warning(disable:4786)
#include <comutil.h>
#include <string>
#pragma comment(lib, "comsupp.lib")

//�������


	std::wstring bm_utf8_to_utf16( const char* str );
	std::string  bm_utf16_to_utf8( const wchar_t *str );

	// 	std::string src = "a?@��ɫ";
	// 	std::string utf8 = bm_ascii_to_utf8(src);
	// 	std::string des  = bm_utf8_to_ascii(utf8);
	// 	if (src != des)
	// 	{
	// 		return 0;
	// 	}
	std::string  bm_utf8_to_ascii(std::string strUTF8);
	std::string  bm_ascii_to_utf8(std::string str);

	std::string  bm_utf16_to_ascii(std::wstring wsz);
	std::wstring bm_ascii_to_utf16(std::string sz);

	std::string UrlEncode(const std::string& str);
	std::string UrlDecode(const std::string& str);

	//16�����ַ���ת������
	DWORD HexString2Bits(PBYTE lpSrc,DWORD dwSrcLenth,PBYTE lpDes);
	//������ת16����
	DWORD Bits2HexString(PBYTE lpSrc,DWORD dwSrcLenth,PBYTE lpDes);
	//�ɹ����� NO_ERROR
	DWORD HexString2Hex(PBYTE lpSrc,DWORD dwSrcLenth,PBYTE lpDes);
	DWORD Hex2HexString(PBYTE lpSrc,DWORD dwSrcLenth,PBYTE lpDes);

	//�����������Ƕ����� �Ľ��з�װ
	std::string Hex2HexString(PBYTE lpSrc,DWORD dwSrcLenth);
	std::string Bits2HexString(PBYTE lpSrc,DWORD dwSrcLenth);


#endif