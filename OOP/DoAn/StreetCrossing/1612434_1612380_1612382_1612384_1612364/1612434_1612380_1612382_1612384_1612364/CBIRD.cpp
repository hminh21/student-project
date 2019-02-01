#include "CBIRD.h"

CBIRD::CBIRD() //default constructor
{
	mX = 0;
	mY = 0;
}

CBIRD::CBIRD(int x, int y)
{
	if (x > 0 && y > 0)
	{
		mX = x;
		mY = y;
	}
}

CBIRD::CBIRD(const CBIRD& b) //copy constructor
{
	if (b.mX > 0 && b.mY > 0)
	{
		mX = b.mX;
		mY = b.mY;
	}
}


CBIRD::~CBIRD()
{
	mX = 0;
	mY = 0;
}

void CBIRD::drawObj()
{
	GoToXY(mX, mY);
	cout << " __/*>";
	GoToXY(mX, mY + 1);

	cout << "/  _/";
	GoToXY(mX, mY + 2);
	cout << " ^^";
}

void CBIRD::deleteObj()
{
	GoToXY(mX, mY);
	cout << "      ";
	GoToXY(mX, mY + 1);
	cout << "     ";
	GoToXY(mX, mY + 2);
	cout << "   ";
}
void CBIRD::tell()
{
	PlaySound(L"chickensound", NULL, SND_ASYNC | SND_LOOP);
}