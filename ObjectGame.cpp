#include "ObjectGame.h"
#include <sstream>

ObjectGame::ObjectGame(const wchar_t& object_chr, const wstring& color_in_hex, const bool HitBox) : m_object_chr(object_chr), HitBox(HitBox)
{
	wstringstream wss;
	wss << std::hex << color_in_hex;
	wss >> m_color;
}

inline int ObjectGame::GetColor()
{
	return m_color;
}

inline wchar_t ObjectGame::GetWChar_t_of_Object()
{
	return m_object_chr;
}

bool ObjectGame::GetHitBox()
{
	return HitBox;
}

bool ObjectGame::operator==(ObjectGame& ObjGame)
{
	return (m_color == ObjGame.GetColor()) && (m_object_chr == ObjGame.GetWChar_t_of_Object());
}