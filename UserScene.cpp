#include "UserScene.h"
#include <conio.h>

void TeleportScene::ToWrite()
{
	switch (Number_of_string)
	{
	case if_blue_teleport:
		wcout << endl;
		print_with_delay(L"Ты был телепортирован в синий телепорт", 10);
		break;
	case if_yellow_teleport:
		wcout << endl;
		print_with_delay(L"Ты был телепортирован в жёлтый телепорт", 10);
		break;
	default:
		break;
	}
	Number_of_string = -1;
}

TeleportScene::TeleportScene(const wstring& a_Name_of_Scene, int a_Size_X, int a_Size_Y, const Character& a_main_character, const ObjectGame& a_Piece) :
Scene(a_Name_of_Scene, a_Size_X, a_Size_Y, a_main_character, a_Piece) 
{}


void TeleportScene::func()
{
	if ((this->GetNextStepMainCharacter() == this->GetPositionCharacter(m_characters[1])) && 
		(this->GetPositionCharacter(m_characters[0]) == (this->GetPositionCharacter(m_characters[1]) - 1)))
	{
		this->move(this->GetPositionCharacter(m_characters[0]), this->GetPositionCharacter(m_characters[2]) + 2);
		Number_of_string = if_blue_teleport;
	}
	else if ((this->GetNextStepMainCharacter() == this->GetPositionCharacter(m_characters[2])) && 
		(this->GetPositionCharacter(m_characters[0]) == (this->GetPositionCharacter(m_characters[2]) + 1)))
	{
		this->move(this->GetPositionCharacter(m_characters[0]), this->GetPositionCharacter(m_characters[1]) - 2);
		Number_of_string = if_yellow_teleport;
	}
}