#pragma once
#include <iostream>
#include <vector>

#include "windows.h"
#include "conio.h"

#define PI 3.14

int windowsH_drawSin_main()
{
	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);

	int xPos = 0;

	//Choose any color
	COLORREF COLOR = RGB(255, 255, 255);
	srand(400);

	//Draw xPoss
	for (double i = 0; i < PI * 4; i += 0.05)
	{
		SetPixel(mydc, xPos, (int)(100 + 25 * sin(i)), COLOR);
		if (!(xPos % (int)(50 + 25 * sin(i))))
			COLOR = RGB(rand() % 256, rand() % 256, rand() % 256);
		xPos += 1;
	}

	ReleaseDC(myconsole, mydc);
	std::cin.ignore();

	return 0;
}


struct Form
{
	COORD pos;
	size_t sizeX;
	size_t sizeY;
	COLORREF clr;
};

void printForm(HDC hdc, COORD pos, size_t sizeX, size_t sizeY, COLORREF clr)
{
	for (size_t i = pos.Y; i < pos.Y + sizeY; i++)
	{
		for (size_t j = pos.X; j < pos.X + sizeX; j++)
		{
			SetPixel(hdc, j, i, clr);
		}
	}
}

void printForm(HDC hdc, Form form)
{
	printForm(hdc, form.pos, form.sizeX, form.sizeY, form.clr);
}

int windowsH_movement_main()
{
	HWND conHWND = GetConsoleWindow();
	HDC hdc = GetDC(conHWND);

	COORD pos = { 10,10 };
	COORD ppos = { 10,10 };

	bool ss = true;
	bool speed = false;
	BYTE r = 200, g = 180, b = 30;
	COLORREF mainclr = RGB(r, g, b);
	COLORREF bgclr = RGB(0,0,0);
	size_t sizeX = 5;
	size_t sizeY = 5;
	size_t psizeX = 5;
	size_t psizeY = 5;
	std::vector<Form> vec;

	while (ss)
	{
		if (pos.X != ppos.X or pos.Y != ppos.Y)
		{
			//SetPixel(hdc, ppos.X, ppos.Y, bgclr);
			printForm(hdc, ppos, psizeX, psizeY, bgclr);
		}

		if (!vec.empty())
			for (size_t i = 0; i < vec.size(); i++)
				printForm(hdc, vec[i]);

		mainclr = RGB(r, g, b);
		//SetPixel(hdc, pos.X, pos.Y, mainclr);
		printForm(hdc, pos, sizeX, sizeY, mainclr);

		ppos.X = pos.X;
		ppos.Y = pos.Y;
		psizeX = sizeX;
		psizeY = sizeY;

		switch (_getch())
		{
		case 'w':
			pos.Y -= 1 + (speed * 4) + int(sizeY / 10);
			break;
		case 's':
			pos.Y+= 1 + (speed * 4) + int(sizeY / 10);
			break;
		case 'a':
			pos.X-= 1 + (speed * 4) + int(sizeX / 10);
			break;
		case 'd':
			pos.X+= 1 + (speed * 4) + int(sizeX / 10);
			break;
		case 'p':
			vec.push_back(Form{ pos, sizeX, sizeY, mainclr });
			break;
		case ';':
			vec.pop_back();
			break;
		case 'q':
			speed = !speed;
			break;
		case 'r':
			r+= 1 + (speed * 4);
			break;
		case 'f':
			r-= 1 + (speed * 4);
			break;
		case 't':
			g+= 1 + (speed * 4);
			break;
		case 'g':
			g-= 1 + (speed * 4);
			break;
		case 'y':
			b+= 1 + (speed * 4);
			break;
		case 'h':
			b-= 1 + (speed * 4);
			break;
		case 'o':
			sizeY++;
			break;
		case 'l':
			if (sizeY > 0)
				sizeY--;
			break;
		case 'i':
			sizeX++;
			break;
		case 'k':
			if (sizeX > 0)
				sizeX--;
			break;
		case 27:
			ss = false;
			break;
		default:
			break;
		}
	}

	return 0;
}

int windowsH_main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);

	return 0;
}