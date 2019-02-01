#ifndef _LINE_H
#define _LINE_H
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

class Point2D
{
	float _fX, _fY;
public:
	Point2D();
	Point2D(float, float);
	Point2D(const Point2D&);
	float getX();
	float getY();
	friend ostream& operator<<(ostream& outDev, const Point2D& p);
};

class Line
{
	Point2D _pA, _pB;
public:
	Line();
	Line(Point2D, Point2D);
	Line(const Line&);
	float Distance();
	friend ostream& operator<<(ostream& outDev, const Line& l);
};

#endif