#pragma once
#include <iostream>

#include "olcConsoleGameEngine.h"

void drawcircles();

class Demo : public olcConsoleGameEngine
{
public:
	Demo()
	{

	}

protected:
	virtual bool OnUserCreate()
	{
		m_fPlayerX = 10.0f;
		m_fPlayerY = 10.0f;
		m_fSizeX = 0.0f;
		m_fSizeY = 0.0f;
		killeyes = false;
		circle = false;
		shift = 0;
		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime)
	{
		if (m_keys['A'].bHeld or m_keys['a'].bHeld)
			m_fPlayerX -= 15.0f * fElapsedTime * shift;
		if (m_keys['D'].bHeld or m_keys['d'].bHeld)
			m_fPlayerX += 15.0f * fElapsedTime * shift;
		if (m_keys['W'].bHeld or m_keys['w'].bHeld)
			m_fPlayerY -= 15.0f * fElapsedTime * shift;
		if (m_keys['S'].bHeld or m_keys['s'].bHeld)
			m_fPlayerY += 15.0f * fElapsedTime * shift;
		if (m_keys[VK_LEFT].bHeld)
			m_fSizeX -= 15.0f * fElapsedTime * shift;
		if (m_keys[VK_RIGHT].bHeld)
			m_fSizeX += 15.0f * fElapsedTime * shift;
		if (m_keys[VK_UP].bHeld)
			m_fSizeY -= 15.0f * fElapsedTime * shift;
		if (m_keys[VK_DOWN].bHeld)
			m_fSizeY += 15.0f * fElapsedTime * shift;
		if (m_keys[VK_SPACE].bHeld)
			killeyes = true;
		else
			killeyes = false;
		if (m_keys[VK_CONTROL].bHeld)
			circle = true;
		else
			circle = false;
		if (m_keys[VK_SHIFT].bHeld)
			shift = 5;
		else
			shift = 1;


		if (m_fSizeX < 0.0f)
			m_fSizeX = 0.0f;
		if (m_fSizeY < 0.0f)
			m_fSizeY = 0.0f;

		Fill(0, 0, m_nScreenWidth, m_nScreenHeight, L' ', 0);
		if (circle)
		{
			if (killeyes)
				DrawCircle((int)m_fPlayerX, (int)m_fPlayerY, (int)m_fSizeX, L'█', rand() % 256);
			else
				DrawCircle((int)m_fPlayerX, (int)m_fPlayerY, (int)m_fSizeX, L'█', FG_WHITE);
		}
		else
		{
			if (killeyes)
				Fill((int)m_fPlayerX, (int)m_fPlayerY, (int)m_fPlayerX + 1 + (int)m_fSizeX, (int)m_fPlayerY + 1 + (int)m_fSizeY, L'█', rand() % 256);
			else
				Fill((int)m_fPlayerX, (int)m_fPlayerY, (int)m_fPlayerX + 1 + (int)m_fSizeX, (int)m_fPlayerY + 1 + (int)m_fSizeY, L'█', FG_WHITE);
		}


		return true;
	}

private:
	float m_fPlayerX;
	float m_fPlayerY;
	float m_fSizeX;
	float m_fSizeY;
	int shift;
	bool killeyes;
	bool circle;
};

int olctest_main()
{
	Demo game;
	game.ConstructConsole(160, 100, 8, 8);
	game.Start();
	return 0;
}