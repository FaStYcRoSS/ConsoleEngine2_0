#include "Character.h"
#include "ObjectGame.h"
using namespace std;

Character::Character(const wstring& Name,
					const int& HealthPoint,
					const int& speed,
					const wchar_t& object_chr,
					const wstring& color_in_hex,
					bool HitBox) : 
	
					ObjectGame(object_chr, color_in_hex, HitBox), 
					m_HealthPoint(HealthPoint), 
					m_Name(Name), 
					m_Speed(speed)
{}

inline void Character::Damage(int minus_HP)
{
	m_HealthPoint -= minus_HP;
}

inline int Character::GetHealtPoint()
{
	return m_HealthPoint;
}

wstring Character::GetName()
{
	return m_Name;
}

bool operator==(const wchar_t& wchar, Character& charac)
{
	return wchar == charac.GetWChar_t_of_Object();
}

int Character::GetSpeed()
{
	return m_Speed;
}