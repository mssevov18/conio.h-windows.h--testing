#pragma once

#include "conio.h"

int putGetCin_main()
{
	char a = 0;
	while (a != 27)
	{
		_putch(a);
		a = _getch();
		if (a == 8)
		{
			_putch(a);
			_putch(' ');
		}
	}
	return 0;
}