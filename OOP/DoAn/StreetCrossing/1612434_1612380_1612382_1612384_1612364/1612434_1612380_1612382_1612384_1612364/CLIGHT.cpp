#include "CLIGHT.h"


CLIGHT::CLIGHT() //default constructor
{
	mX = 0;
	mY = 0;
	srand(time(NULL));
	Time = rand() % 101 + 0; //random thoi gian ban dau
	light[0] = NULL;
	light[1] = 'X';
	if (Time < 70) 
		status = true; // Den xanh
	else
		status=false; //Den do
}

CLIGHT::CLIGHT(int x, int y)
{
	if (x > 0 && y > 0)
	{
		mX = x;
		mY = y;
	}
}

CLIGHT::CLIGHT(const CLIGHT& b) //copy constructor
{
	if (b.mX > 0 && b.mY > 0)
	{
		mX = b.mX;
		mY = b.mY;
	}
}


CLIGHT::~CLIGHT()
{
	mX = 0;
	mY = 0;
}
void CLIGHT::changeStatus()						//change light
{
	if (Time < 70) status = true;
	else status = false;
	/*if (status == false)
	{
		light[0] = 'D';
		light[1] = NULL;
	}
	else
	{
		light[0] = NULL;
		light[1] = 'X';
	}*/

}
void CLIGHT::drawObj()
{
	if (status == false) {
		GoToXY(mX, mY);
		TextColor(68);
		cout << light[0];
	}
	else {
		GoToXY(mX, mY);
		TextColor(34);
		cout << light[1];
	}
	TextColor(15);
}
