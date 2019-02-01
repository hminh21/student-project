#include "CCAR.h"
CCAR::CCAR() //default constructor
{
	mX = 0;
	mY = 0;
}

CCAR::CCAR(int x, int y)
{
	if (x > 0 && y > 0)
	{
		mX = x;
		mY = y;
	}
}

CCAR::CCAR(const CCAR& b) //copy constructor
{
	if (b.mX > 0 && b.mY > 0)
	{
		mX = b.mX;
		mY = b.mY;
	}
}

CCAR::~CCAR()
{
	mX = 0;
	mY = 0;
}
void CCAR::drawObj()
{
	GoToXY(mX, mY);
	cout <<"  _  ";
	GoToXY(mX, mY + 1);
	cout<<"_/_\\_";
	GoToXY(mX, mY + 2);
	cout<<"-O-O-";
}

void CCAR::deleteObj()
{
	GoToXY(mX, mY);
	cout << "     ";
	GoToXY(mX, mY + 1);
	cout << "      ";
	GoToXY(mX, mY + 2);
	cout << "     ";
}
void CCAR::tell()
{
	PlaySound(L"carhorn", NULL, SND_ASYNC | SND_LOOP);
}