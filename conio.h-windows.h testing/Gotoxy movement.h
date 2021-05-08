#pragma once

// Works in Turbo C compiler only
#include <iostream>
#include <conio.h>
#include <windows.h>

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD  result;
	result.X = 0;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return result.X;
}

int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD  result;
	result.Y = 0;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return result.Y;
}

int Gotoxy_main()
{
	int x, y;

	x = 10;
	y = 10;

	int X = x, Y = y;
	bool ss = true;

	while (ss)
	{
		gotoxy(x, y);
		std::cout << "#";
		if (x != X or y != Y)
		{
			gotoxy(X, Y);
			std::cout << " ";
		}
		gotoxy(x, y);
		X = x;
		Y = y;
		switch (_getch())
		{
		case 'w':
			y--;
			break;
		case 's':
			y++;
			break;
		case 'a':
			x--;
			break;
		case 'd':
			x++;
			break;
		case 27:
			ss = false;
			break;
		default:
			break;
		}
	}

	_getch();
	return 0;
}