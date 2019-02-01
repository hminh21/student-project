//file Shapes.h
#ifndef _Shapes_h
#define _Shapes_h

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
	void setX(float);
	void setY(float);
	friend ostream& operator<<(ostream& outDev, const Point2D& p);
};


class Triangle
{
	Point2D _pA, _pB, _pC;
public:
	Triangle();
	Triangle(Point2D, Point2D, Point2D);
	Triangle(const Triangle&);
	float Perimeter();
	float Area();
	friend ostream& operator<<(ostream& outDev, const Triangle& t);
};

class Square
{
	Point2D _pA, _pB, _pC, _pD;
public:
	Square();
	Square(Point2D, Point2D, Point2D, Point2D);
	Square(const Square&);
	float Perimeter();
	float Area();
	friend ostream& operator<<(ostream& outDev, const Square& s);
};

class Rectangle
{
	Point2D _pA, _pB, _pC, _pD;
public:
	Rectangle();
	Rectangle(Point2D, Point2D, Point2D, Point2D);
	Rectangle(const Rectangle&);
	float Perimeter();
	float Area();
	friend ostream& operator<<(ostream& outDev, const Rectangle& r);
};

#endif