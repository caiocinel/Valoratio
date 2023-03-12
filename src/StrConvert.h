#pragma once
#include <string>
#include <Windows.h>

namespace StrConvert {
	std::string string_To_UTF8(const std::string& str);
	std::wstring MBytesToWString(const char* lpcszString);
	std::string WStringToUTF8(const wchar_t* lpwcszWString);
	char* wchar_to_char(const wchar_t* pwchar);	
}