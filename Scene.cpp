#include "Scene.h"
#include "Screen.h"
#include <conio.h>
#include <algorithm>
#include <thread>

using namespace std;

inline void Scene::Stop()
{
	m_run = false;
}

void Scene::ChangeScene(Scene& scene)
{
	this->Stop();
	scene.play();
}

void Scene::play()
{
	invisibleCursor();
	while (m_run)
	{
		this->Draw();
		this->MoveMainCharacter();
		gotoXYCursor(0,0);
	}
}

void print_with_delay(const wstring& ws, int Delay)
{
	for (wchar_t i : ws)
	{
		wcout << i;
		Sleep(Delay);
	}
}

Scene::Scene(const wstring& Name_of_Scene, int Size_X, int Size_Y, const Character& main_character, const ObjectGame& Piece) :
	m_Name_of_Scene(Name_of_Scene),
	m_SizeScene_X(Size_X), 
	m_SizeScene_Y(Size_Y), 
	m_Main_Character(main_character),
	m_Piece(Piece)
{
	for (int i = 0; i < m_SizeScene_X * m_SizeScene_Y; i++)
	{
		m_Scene.push_back(m_Piece.GetWChar_t_of_Object());
	}
}

void Scene::Draw()
{
	wcout << m_Name_of_Scene;
	int color = m_Piece.GetColor();
	for (int i = 0; i < m_Scene.size(); i++)
	{
		if (i % m_SizeScene_X == 0)
		{
			cout << endl;
		}
		else
		{
			colorScreen(color);
			for (Character charac : m_characters)
			{
				if (color == charac.GetColor() || i == this->GetPositionCharacter(charac))
				{
					colorScreen(charac.GetColor());
				}
			}
			wcout << m_Scene[i];
		}
	}
	this->ToWrite();
}

void Scene::MoveMainCharacter()
{
	wchar_t Key = _getch();
	int speed = m_Main_Character.GetSpeed();
	if (Key == toupper(Key)) speed *= 2;
	int Coord_MainCharacter = this->GetPositionCharacter(m_Main_Character);
	int next_step = Coord_MainCharacter;
	Key = tolower(Key);

	switch (Key)
	{
		case L'w':
			next_step -= speed * m_SizeScene_X;
			break;
		case L's':
			next_step += speed * m_SizeScene_X;
			break;
		case L'a':
			next_step -= speed;
			if (next_step % m_SizeScene_X == 0) next_step -= speed;
			break;
		case L'd':
			next_step += speed;
			if (next_step % m_SizeScene_X == 0) next_step += speed;
			break;
		case L'ö':
			next_step -= speed * m_SizeScene_X;
			break;
		case L'û':
			next_step += speed * m_SizeScene_X;
			break;
		case L'ô':
			next_step -= speed;
			if (next_step % m_SizeScene_X == 0) next_step -= speed;
			break;
		case L'â':
			next_step += speed;
			if (next_step % m_SizeScene_X == 0) next_step += speed;
			break;
	}
	m_next_step_main_character = next_step;
	func();
	if (
		next_step <= 0 ||
		next_step >= m_SizeScene_X * m_SizeScene_Y ||
		count_if(m_characters.begin(), m_characters.end(), [next_step, this](Character character) {
			return (m_Scene[next_step] == character) && (character.GetHitBox());
			})
		)
	{
		next_step = Coord_MainCharacter;
	}
	this->move(Coord_MainCharacter, next_step);
}

inline void Scene::move(int Position_before, int Position_after)
{
	swap(m_Scene[Position_before], m_Scene[Position_after]);
}

void Scene::SetPositionCharacter(int coord, Character& character)
{
	m_Scene[coord] = character.GetWChar_t_of_Object();
}

void Scene::AddCharacterOnScene(Character& character)
{
	m_characters.push_back(character);
}

int Scene::GetNextStepMainCharacter() 
{ 
	return m_next_step_main_character; 
}

inline size_t Scene::GetPositionCharacter(Character& To_Find)
{
	return distance(m_Scene.begin(), find(m_Scene.begin(), m_Scene.end(), To_Find.GetWChar_t_of_Object()));
}