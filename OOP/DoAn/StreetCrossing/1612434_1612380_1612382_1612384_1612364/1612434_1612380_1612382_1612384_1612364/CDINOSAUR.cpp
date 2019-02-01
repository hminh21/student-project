#include "CDINOSAUR.h"


CDINOSAUR::CDINOSAUR() //default constructor
{
	mX = 0;
	mY = 0;
}

CDINOSAUR::CDINOSAUR(int x, int y)
{
	if (x > 0 && y > 0)
	{
		mX = x;
		mY = y;
	}
}

CDINOSAUR::CDINOSAUR(const CDINOSAUR& b) //copy constructor
{
	if (b.mX > 0 && b.mY > 0)
	{
		mX = b.mX;
		mY = b.mY;
	}
}


CDINOSAUR::~CDINOSAUR()
{
	mX = 0;
	mY = 0;
}
void CDINOSAUR::drawObj()
{
	GoToXY(mX, mY);
	cout << "   /*=";
	GoToXY(mX, mY + 1);
	cout << " _/ /";
	GoToXY(mX, mY + 2);
	cout << "/__/";
}

void CDINOSAUR::deleteObj()
{
	GoToXY(mX, mY);
	cout << "      ";
	GoToXY(mX, mY + 1);
	cout << "     ";
	GoToXY(mX, mY + 2);
	cout << "    ";
}
void CDINOSAUR::tell()
{
	PlaySound(L"dinosaursound", NULL, SND_ASYNC | SND_LOOP);
}