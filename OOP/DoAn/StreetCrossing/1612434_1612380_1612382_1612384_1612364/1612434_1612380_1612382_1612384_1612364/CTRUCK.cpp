#include "CTRUCK.h"

CTRUCK::CTRUCK() //default constructor
{
	mX = 0;
	mY = 0;
}

CTRUCK::CTRUCK(int x, int y)
{
	if (x > 0 && y > 0)
	{
		mX = x;
		mY = y;
	}
}

CTRUCK::CTRUCK(const CTRUCK& b) //copy constructor
{
	if (b.mX > 0 && b.mY > 0)
	{
		mX = b.mX;
		mY = b.mY;
	}
}

CTRUCK::~CTRUCK()//destructor
{
	mX = 0;
	mY = 0;
}

void CTRUCK::drawObj()
{
	GoToXY(mX, mY);
	printf(" ___");
	GoToXY(mX, mY + 1);
	printf("%c   %c]", 179, 179);
	GoToXY(mX, mY + 2);
	printf(" O--O");
}

void CTRUCK::deleteObj()
{
	GoToXY(mX, mY);
	printf("    ");
	GoToXY(mX, mY + 1);
	printf("      ");
	GoToXY(mX, mY + 2);
	printf("     ");
}
void CTRUCK::tell()
{
	PlaySound(L"truckhorn", NULL, SND_ASYNC | SND_LOOP);
}