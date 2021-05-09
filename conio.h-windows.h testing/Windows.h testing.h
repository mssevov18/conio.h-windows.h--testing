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

	int pos = 0;
	double size = 4.0;
	double iSeed = 0;
	int height = 25;
	int xPos = 0;
	char a = 1;
	bool aa = true, bb = false, cc = false, dd = false;

	//Choose any color
	COLORREF COLOR = RGB(255, 255, 255);

	while (!(a == 27))
	{
		srand(400 * (int)a);
		COLOR = RGB(rand() % 256, rand() % 256, rand() % 256);
		xPos = pos;

		//Draw xPos
		for (double i = iSeed; i < PI * size; i += 0.05)
		{
			if(aa)
				SetPixel(mydc, xPos, (int)(75 + height + height * sin(i)), COLOR);
			if(bb)
				SetPixel(mydc, xPos, (int)(75 + height + height * sin(i + PI)), COLOR);
			if (dd)
			{
				if (xPos % 6 == 0)
				{
					for (double j = (height * sin(i) > height * sin(i + PI) ? height * sin(i + PI) : height * sin(i));
								j < (height * sin(i) > height * sin(i + PI) ? height * sin(i) : height * sin(i + PI));
								j += 0.5)
						SetPixel(mydc, xPos, (int)(75 + height + j), COLOR);
				}
			}
			if(cc)
				SetPixel(mydc, xPos, (int)(275 + height + height * sin(i)), COLOR);
			if (!(xPos % (rand()% 30 + 15)))
				COLOR = RGB(rand() % 256, rand() % 256, rand() % 256);
			xPos += 1;
		}

		a = _getch();

		COLOR = GetPixel(mydc, 0, 0);
		xPos = pos;
		for (double i = iSeed; i < PI * size; i += 0.05)
		{
			if (aa)
				SetPixel(mydc, xPos, (int)(75 + height + height * sin(i)), COLOR);
			if (bb)
				SetPixel(mydc, xPos, (int)(75 + height + height * sin(i + PI)), COLOR);
			if (dd)
			{
				if (xPos % 6 == 0)
				{
					for (double j = (height * sin(i) > height * sin(i + PI) ? height * sin(i + PI) : height * sin(i));
						j < (height * sin(i) > height * sin(i + PI) ? height * sin(i) : height * sin(i + PI));
						j += 0.5)
						SetPixel(mydc, xPos, (int)(75 + height + j), COLOR);
				}
			}
			if (cc)
				SetPixel(mydc, xPos, (int)(275 + height + height * sin(i)), COLOR);
			xPos += 1;
		}

		switch (a)
		{
		case 'a':
			pos--;
			break;
		case 'd':
			pos++;
			break;
		case 'w':
			size += 0.05 / PI;
			break;
		case 's':
			size -= 0.05 / PI;
			break;
		case 'W':
			size += 0.5 / PI;
			break;
		case 'S':
			size -= 0.5 / PI;
			break;
		case 'e':
			size += 0.05 / PI;
			iSeed += 0.05;
			break;
		case 'q':
			size -= 0.05 / PI;
			iSeed -= 0.05;
			break;
		case 'E':
			size += 0.5 / PI;
			iSeed += 0.5;
			break;
		case 'Q':
			size -= 0.5 / PI;
			iSeed -= 0.5;
			break;
		case 'r':
			iSeed += 0.05;
			break;
		case 'f':
			iSeed -= 0.05;
			break;
		case 't':
			height++;
			break;
		case 'g':
			height--;
			break;
		case 'z':
			aa = !aa;
			break;
		case 'x':
			bb = !bb;
			break;
		case 'c':
			dd = !dd;
			break;
		case 'v':
			cc = !cc;
			break;
		default:
			break;
		}

	}

	ReleaseDC(myconsole, mydc);

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
	COLORREF bgclr = GetPixel(hdc, 10, 10);
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