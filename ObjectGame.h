#pragma once
#include <string>
using namespace std;

namespace const_hex
{
	//BACKGROUND_
	const wstring BG_BLACK = L"0x0";
	const wstring BG_DARKBLUE = L"0x1";
	const wstring BG_DARKGREEN = L"0x2";
	const wstring BG_DARKCYAN = L"0x3";
	const wstring BG_DARKRED = L"0x4";
	const wstring BG_DARKMAGENTA = L"0x5";
	const wstring BG_DARKYELLOW = L"0x6";
	const wstring BG_LIGHTGRAY = L"0x7";
	const wstring BG_DARKGRAY = L"0x8";
	const wstring BG_BLUE = L"0x9";
	const wstring BG_GREEN = L"0xa";
	const wstring BG_CYAN = L"0xb";
	const wstring BG_RED = L"0xc";
	const wstring BG_MAGENTA = L"0xd";
	const wstring BG_YELLOW = L"0xe";
	const wstring BG_WHITE = L"0xf";
	//_FOREGROUND
	const wstring FG_BLACK = L"0";
	const wstring FG_DARKBLUE = L"1";
	const wstring FG_DARKGREEN = L"2";
	const wstring FG_DARKCYAN = L"3";
	const wstring FG_DARKRED = L"4";
	const wstring FG_DARKMAGENTA = L"5";
	const wstring FG_DARKYELLOW = L"6";
	const wstring FG_LIGHTGRAY = L"7";
	const wstring FG_DARKGRAY = L"8";
	const wstring FG_BLUE = L"9";
	const wstring FG_GREEN = L"a";
	const wstring FG_CYAN = L"b";
	const wstring FG_RED = L"c";
	const wstring FG_MAGENTA = L"d";
	const wstring FG_YELLOW = L"e";
	const wstring FG_WHITE = L"f";
	const wstring szDEFULT = L"0x70";
	const short sDEFULT = 7;
}
class ObjectGame
{
	wchar_t m_object_chr;
	int m_color;
	bool HitBox;
public:
	ObjectGame(const wchar_t& object_chr = L' ', const wstring& color_in_hex = L"0x00", bool HitBox = false);
	int GetColor();
	wchar_t GetWChar_t_of_Object();
	bool GetHitBox();
	bool operator==(ObjectGame& ObjGame);
};