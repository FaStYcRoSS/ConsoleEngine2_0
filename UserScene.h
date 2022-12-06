#pragma once
#include "Scene.h"

#define if_yellow_teleport 0
#define if_blue_teleport 1

class TeleportScene : public Scene
{
	wstring empty;
	void ToWrite();
	void func();
public:
	TeleportScene(const wstring& a_Name_of_Scene, int a_Size_X, int a_Size_Y, const Character& a_main_character, const ObjectGame& a_Piece);
};