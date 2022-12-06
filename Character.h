#pragma once

#include "ObjectGame.h"

class Character : public ObjectGame
{
	wstring m_Name;
	int m_HealthPoint;
	int m_Speed;
public:
	Character(const wstring& Name = L"",
			const int& HealthPoint = 1,
			const int& speed = 1,
			const wchar_t& object_chr = L' ',
			const wstring& color_in_hex = L"0x00",
			bool HitBox = false);
	friend bool operator==(const wchar_t& wchar, Character& charac);
	int GetSpeed();
	wstring GetName();
	int GetHealtPoint();
	void Damage(int minus_HP);
};