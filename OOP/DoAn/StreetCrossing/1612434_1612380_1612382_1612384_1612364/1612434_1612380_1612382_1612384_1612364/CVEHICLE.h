#ifndef _CVEHICLE_h
#define _CVEHICLE_h

#include <iostream>
#include "console.h"
using namespace std;
class CVEHICLE {
protected:
	int mX, mY;
	int objectColor = 15;//màu của đối tượng, mặc định là màu trắng
	bool isInvalid = false;
public:
	int getX(){ return mX; };
	int getY(){ return mY; };
	void setX(int x){ mX = x; };
	void setY(int y){ mY = y; };
	bool getIsInvalid(){ return isInvalid; };
	void setIsInvalid(bool is){ isInvalid = is; };
	void setObjectColor(int color) { objectColor = color; }
	int getObjectColor() { return objectColor; }
	void MoveLeft(int x){ mX -= x; };
	void MoveRight(int x){ mX += x; };
	virtual CVEHICLE* getList() = 0;;
	virtual void tell() = 0;
};
#endif