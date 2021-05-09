#include <iostream>
#include <vector>

#include "windows.h"
#include "conio.h"
#include "RenderTest.h"

int RenderTest_main()
{
	HWND hwndCon = GetConsoleWindow();
	HDC hdcCon = GetDC(hwndCon);

	Shape shape;
	COLOURREF bgclr = GetPixel(hdcCon, 100, 100);
	COLOURREF mainclr = RGB(205, 185, 45);

	//Generate Shape - Rectangle
	shape = makeRectange(100, 100, 30, 30, mainclr);

	char a = NULL;

	while (a!=27)
	{
		//Draw
		shape.draw(hdcCon);

		//Get input
		a = _getch();

		//Draw over
		shape.draw(hdcCon, bgclr);
		

		//Process input
		switch (a)
		{
		case 'a':
			shape.movePixels(-1, 0);
			break;
		case 'd':
			shape.movePixels(1, 0);
			break;
		case 'w':
			shape.movePixels(0, -1);
			break;
		case 's':
			shape.movePixels(0, 1);
			break;
		case 'A':
			shape.movePixels(-5, 0);
			break;
		case 'D':
			shape.movePixels(5, 0);
			break;
		case 'W':
			shape.movePixels(0, -5);
			break;
		case 'S':
			shape.movePixels(0, 5);
			break;
		default:
			break;
		}

	}

	return 0;
}

void Pixel::updatePixel(int addX, int addY)
{
	x += addX;
	y += addY;
}

bool operator==(Pixel l, Pixel r)
{
	return (l.x == r.x) * (l.y == r.y) * (l.colour == r.colour);
}

bool operator!=(Pixel l, Pixel r)
{
	return !(l==r);
}

Shape::Shape()
{
	vPixel.clear();
	layer = 0;
}

void Shape::addPixel(Pixel newPixel)
{
	vPixel.push_back(newPixel);
}

void Shape::removePixel(size_t pos)
{
	if (pos >= vPixel.size())
		return;
	vPixel.erase(vPixel.begin() + pos);
}

//if mode is 0 -> remove by Pixel
//if mode is 1 -> remove by X&Yposition
//if mode is 2 -> remove by Xposition
//if mode is 3 -> remove by Yposition
//if mode is 4 -> remove by COLOURREF
void Shape::removePixel(Pixel filter, char mode)
{
	switch (mode)
	{
	case 0:
		return;
	case 1:
		return;
	case 2:
		return;
	case 3:
		return;
	case 4:
		return;
	default:
		return;
	}
}

int Shape::getLayer()
{
	return layer;
}

void Shape::setLayer(int newLayer)
{
	layer = newLayer;
}

void Shape::movePixels(int addX, int addY)
{
	for (size_t i = 0; i < vPixel.size(); i++)
		vPixel[i].updatePixel(addX, addY);
}

void Shape::draw(HDC hdc)
{
	for (size_t i = 0; i < vPixel.size(); i++)
		SetPixelStruct(hdc, vPixel[i]);
}

void Shape::draw(HDC hdc, COLOURREF newColour)
{
	for (size_t i = 0; i < vPixel.size(); i++)
		SetPixelFill(hdc, vPixel[i], newColour);
}

bool operator<(Shape l, Shape r)
{
	return (l.getLayer() < r.getLayer());
}

bool operator>(Shape l, Shape r)
{
	return r < l;
}

Shape makeRectange(int rootX, int rootY, int aSize, int bSize, COLOURREF colour)
{
	Shape out;
	for (int i = rootY; i < rootY + bSize; i++)
		for (int j = rootX; j < rootX + aSize; j++)
			out.addPixel(Pixel{ j, i, colour });
	return out;
}
