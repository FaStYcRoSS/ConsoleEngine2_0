#include "Screen.h"

void gotoXYCursor(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void invisibleCursor()
{
	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void colorScreen(short number_color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), number_color);
}