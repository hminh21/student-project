//File: Point2D.h
#ifndef _POINT2D_H
#define _POINT2D_H

#include <iostream>
#include <conio.h>

using namespace std;

class Point2D
{
	float _fX, _fY;
public:
	Point2D();
	Point2D(float, float);
	Point2D(const Point2D&);
	friend ostream& operator<<(ostream& outDev, const Point2D& p);
};

#endif