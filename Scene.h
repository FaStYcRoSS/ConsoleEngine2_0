#pragma once

#include "Character.h"
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

void print_with_delay(const wstring& ws, int Delay);
class Scene
{
	wstring m_Name_of_Scene;
	bool m_run = true;
	int m_SizeScene_X;
	int m_SizeScene_Y;
	vector<wchar_t> m_Scene;
	void Draw();
	void MoveMainCharacter();
	int m_next_step_main_character = NULL;
public:
	int Number_of_string = -1;
	vector<Character> m_characters;
	Character m_Main_Character;
	ObjectGame m_Piece;
	virtual void ToWrite() {}
	Scene(const wstring& Name_of_Scene = L"", int Size_X = 0, int Size_Y = 0, const Character& main_character = Character(), const ObjectGame& Piece = ObjectGame());
	virtual void func() {}
	void move(int Position_before, int Position_after);
	void AddCharacterOnScene(Character& character);
	size_t GetPositionCharacter(Character& To_Find);
	void SetPositionCharacter(int coord, Character& character);
	void play();
	void Stop();
	void ChangeScene(Scene& scene);
	int GetNextStepMainCharacter();
};