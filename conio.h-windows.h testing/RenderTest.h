#pragma once
#include <iostream>
#include <vector>

#include "windows.h"

#define COLOURREF COLORREF

int RenderTest_main();

struct Pixel
{
	int x, y;
	COLOURREF colour;

	void updatePixel(int addX, int addY);
};

#define SetPixelStruct(hdc, pixel) (SetPixel(hdc, pixel.x, pixel.y, pixel.colour))
#define SetPixelFill(hdc, pixel, newColour) (SetPixel(hdc, pixel.x, pixel.y, newColour))

bool operator== (Pixel l, Pixel r);
bool operator!= (Pixel l, Pixel r);

class Shape
{
public:
	Shape();

protected:
	std::vector<Pixel> vPixel;
	int layer;


public:
	void addPixel(Pixel newPixel);
	void removePixel(size_t pos);
	void removePixel(Pixel filter, char mode);

	int  getLayer();
	void setLayer(int newLayer);

	void movePixels(int addX, int addY);

	void draw(HDC hdc);
	void draw(HDC hdc, COLOURREF newColour);
};

bool operator< (Shape l, Shape r);
bool operator> (Shape l, Shape r);

Shape makeRectange(int rootX, int rootY, int aSize, int bSize, COLOURREF colour);

//add >, <, ... overloads to use std::sort
//sort a vector of shapes by layer!