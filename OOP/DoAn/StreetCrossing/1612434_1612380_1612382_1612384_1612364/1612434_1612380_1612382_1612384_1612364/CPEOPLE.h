#ifndef _CPEOPLE_h
#define _CPEOPLE_h
#include<iostream>
#include "console.h"
#include "CVEHICLE.h"
#include "CANIMAL.h"
#include<conio.h>
#include "GLOBAL.h"

using namespace std;
class CPEOPLE
{
	int mX, mY;
	int objectColor = 15;//màu của đối tượng, mặc định là màu trắng
	bool mState;//trạng thái của nhân vật
public:
	CPEOPLE();
	~CPEOPLE();
	void SetPos(int x, int y) { mX = x; mY = y; };
	int getX() { return mX; };
	int getY() { return mY; };
	void setX(int x){ mX = x; };
	void setY(int y){ mY = y; };
	void setObjectColor(int color) { objectColor = color; }
	int getObjectColor() { return objectColor; }
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool getState(){ return mState; };
	void setState(bool st){ mState = st; };
	bool isImpact(CVEHICLE **obj);
	bool isImpact(CANIMAL**obj);
	bool isFinish();//qua vòng
	bool isDead();//hàm kiểm tra xem nhân vật có chết hay không
	void drawObj();
	void deleteObj();
};
#endif