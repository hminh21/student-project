#include "CPEOPLE.h"
#include<iostream>
using namespace std;
CPEOPLE::CPEOPLE()
{
	//mặc định vị trí bắt đầu chơi
	mX = 35;
	mY = 24;
	mState = true; //is alive
}

CPEOPLE::~CPEOPLE()
{
	if (isDead() == true)
	{
		mX = 0;
		mY = 0;
		mState = false;
	}
}

void CPEOPLE::Up(int y)
{
	mY -= y;
}
void CPEOPLE::Left(int x)
{
	mX -= x;
}
void CPEOPLE::Right(int x)
{
	mX += x;
}
void CPEOPLE::Down(int y)
{
	mY += y;
}
void CPEOPLE::drawObj()
{
	//vẽ người
	GoToXY(mX, mY);
	cout << "_O_";


	GoToXY(mX, mY + 1);
	printf(" %c ", 179);

	GoToXY(mX, mY + 2);
	cout << "/ \\";
	
}
bool CPEOPLE::isImpact(CANIMAL** obj)// hàm va chạm với CANIMAL
{
	//CANIMAL obj[0] là CBIRD với mặc định mY=7
	if (mY == 7)
	{
		for (int i = 0; i < MAX_OBJ; i++)
		{
			if (obj[0][i].getIsInvalid() == true)
			{
				//do 4 obj được vẽ quy định trong 1 HCN có độ cao 3 và độ dài 6
				//nên hàm va chạm sẽ được tùy chỉnh để sự va chạm hợp lý
				if ((mX >= obj[0][i].getX() && mX <= obj[0][i].getX() + 6)||(mX+2 >= obj[0][i].getX() && mX+2 <= obj[0][i].getX() + 6))
					return true;
			}
		}
	}
	//CANIMAL obj[1] là CDINOSAUR với mặc định mY=15
	if (mY == 15)
	{
		for (int i = 0; i < MAX_OBJ; i++)
		{
			if (obj[1][i].getIsInvalid() == true)
			{
				if ((mX >= obj[1][i].getX() && mX <= obj[1][i].getX() + 6) || (mX + 2 >= obj[1][i].getX() && mX + 2 <= obj[1][i].getX() + 6))
					return true;
			}
		}
	}
	return false;
}

bool CPEOPLE::isImpact(CVEHICLE** obj)//hàm va chạm với CVEHICLE
{
	//CVEHICLE obj[0] là CTRUCK với mặc định mY=19
	if (mY == 19)
	{
		for (int i = 0; i < MAX_OBJ; i++)
		{
			if (obj[0][i].getIsInvalid() == true)
			{
				if ((mX >= obj[0][i].getX() && mX <= obj[0][i].getX() + 6) || (mX + 2 >= obj[0][i].getX() && mX + 2 <= obj[0][i].getX() + 6))
					return true;
			}
		}
	}
	//CVEHICLE obj[1] là CCAR với mặc định mY=11
	if (mY == 11)
	{
		for (int i = 0; i < MAX_OBJ; i++)
		{
			if (obj[1][i].getIsInvalid() == true)
			{
				if ((mX >= obj[1][i].getX() && mX <= obj[1][i].getX() + 6) || (mX + 2 >= obj[1][i].getX() && mX + 2 <= obj[1][i].getX() + 6))
					return true;
			}
		}
	}
	return false;
}

bool CPEOPLE::isDead()
{
	return(mState == false);
}

bool CPEOPLE::isFinish()
{
	return (mY == 3);
	//nếu tọa độ của CPEOPLE có mY=3 tức là đã đi đến lane cuối -> qua vòng
}

void CPEOPLE::deleteObj()
{
	//xóa tàn dư ảnh của CPEOPLE
	GoToXY(prevX, prevY);
	cout << " ";
	GoToXY(prevX, prevY + 1);
	cout << " ";
	GoToXY(prevX, prevY + 2);
	cout << " ";
	GoToXY(prevX - 1, prevY + 1);
	cout << " ";
	GoToXY(prevX - 1, prevY + 2);
	cout << " ";
	GoToXY(prevX - 1, prevY);
	cout << " ";
	GoToXY(prevX - 2, prevY + 1);
	cout << " ";
	GoToXY(prevX - 2, prevY + 2);
	cout << " ";
	GoToXY(prevX - 2, prevY);
	cout << " ";
	GoToXY(prevX + 1, prevY);
	cout << " ";
	GoToXY(prevX + 1, prevY + 2);
	cout << " ";
	GoToXY(prevX + 1, prevY + 1);
	cout << " ";
	GoToXY(prevX + 2, prevY);
	cout << " ";
	GoToXY(prevX + 2, prevY + 2);
	cout << " ";
	GoToXY(prevX + 2, prevY + 1);
	cout << " ";
}