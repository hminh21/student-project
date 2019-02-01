
#ifndef _CANIMAL_h
#define _CANIMAL_h
#include "console.h"
#include <iostream>
using namespace std;
class CANIMAL
{
protected:
	int mX, mY;
	int objectColor= 15;//màu của đối tượng, mặc định là màu trắng
	bool isInvalid = false;
public:
	

	int getX(){ return mX; };
	int getY(){ return mY; };
	void setX(int x){ mX = x; };
	void setY(int y){ mY = y; };
	bool getIsInvalid(){ return isInvalid; };
	void setIsInvalid(bool is) { isInvalid = is; };
	void setObjectColor(int color) { objectColor = color; }
	int getObjectColor() { return objectColor; }
	void MoveLeft(int x){ mX -= x; };
	void MoveRight(int x){ mX += x; };

	virtual CANIMAL* getList() = 0;
	virtual void tell() = 0;
};
#endif