
#include "UserScene.h"
using namespace std;

int main()
{

	setlocale(LC_ALL, "");

	Character main_character_ = Character(L"Main", 1, 1, L'%', const_hex::BG_BLACK + const_hex::FG_RED);
	Character teleport_blue = Character(L"Blue", 1, 1, L'}', const_hex::BG_BLACK + const_hex::FG_BLUE, true);
	Character teleport_yellow = Character(L"Yellow", 1, 1, L'{', const_hex::BG_BLACK + const_hex::FG_YELLOW, true);

	TeleportScene scene = TeleportScene(L"Teleport Scene", 17, 17, main_character_, ObjectGame(L'-', const_hex::BG_BLACK + const_hex::FG_GREEN, false));
	Scene aSimpleScene = Scene(L"Simple Scene", 17, 17, main_character_); 

	aSimpleScene.AddCharacterOnScene(main_character_);
	aSimpleScene.SetPositionCharacter((17 * 17) / 2, main_character_);

	aSimpleScene.play();

	if (aSimpleScene.GetPositionCharacter(main_character_) == 0)
	{
		aSimpleScene.ChangeScene(scene);
	}

	scene.AddCharacterOnScene(main_character_);
	scene.AddCharacterOnScene(teleport_blue);
	scene.AddCharacterOnScene(teleport_yellow);

	scene.SetPositionCharacter((15 * 17) / 2, teleport_blue);
	scene.SetPositionCharacter((17 * 17) /  2, main_character_);
	scene.SetPositionCharacter((16 * 17) / 2 - 14, teleport_yellow);
}