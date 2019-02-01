#pragma once
#ifndef _CLIGHT_h
#define _CLIGHT_h
#include "console.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
class CLIGHT
{
	int mX, mY;
	char light[2];
	bool status;
	int Time;
public:
	CLIGHT(); //default constructor
	CLIGHT(int, int); //constructor
	CLIGHT(const CLIGHT&); //copy constructor
	~CLIGHT(); //destructor
	int getX() { return mX; };
	int getY() { return mY; };
	int getTime() { return Time; };
	bool getStatus(){ return status; };//
	char getLight(int pos){ return light[pos]; };//
	void setX(int x) { mX = x; };
	void setY(int y) { mY = y; };
	void setLight(int pos, char li){ light[pos] = li; };//
	void setStatus(bool stt){ status = stt; };//
	void setTime(int time){ Time = time; };
	void changeStatus();
	void drawObj();
	void TimeDown() {
		if (Time == 100) Time = 0;
		else Time++;
	};
};
#endif

