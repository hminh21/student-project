//File: CCircle.h
#ifndef _CCIRCLE_H
#define _CCIRCLE_H

#include <iostream>
#include <conio.h>
#include <math.h>

class CPoint2D
{
	double X, Y;
public:
	void Set(double X0, double Y0);
	void Move(double dX, double dY);
	void Scale(double sX, double sY);
	double GetX();
	double GetY();
};

class CCircle
{
	CPoint2D m_pt2DCenter;
	double m_dRadius;
public:
	void intit(double dX, double dY, double dRadius);
	void SetCenter(double dX0, double dY0);
	void SetRadius(double dRadius0);
	CPoint2D GetCenter();
	double GetRadius();
	void move(double dX, double dY);
	double getPerimeter();
	double getArea();
	double Distance(CCircle cir);
	bool isInside(CCircle cir);
	bool isOverlap(CCircle cir);
	bool isBoundary(CCircle cir);
	bool isIntersection(CCircle cir);
	bool isContact(CCircle cir);
	bool isOutside(CCircle cir);
};

#endif

