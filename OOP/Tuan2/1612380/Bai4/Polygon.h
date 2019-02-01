#ifndef _Polygon_h
#define _Polygon_h
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

class Polygon
{
	Point2D* Point;
	int _iN;
public:
	Polygon();
	Polygon(int);
	Polygon(const Polygon&);
	~Polygon();
	float Perimeter();
	float Area();
	friend ostream& operator<<(ostream& outDev, const Polygon& p);
};
#endif