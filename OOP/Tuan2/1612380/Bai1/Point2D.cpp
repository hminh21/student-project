//File: Point2D.cpp

#include "Point2D.h"

Point2D::Point2D()
{
	_fX = 0;
	_fY = 0;
}

Point2D::Point2D(float x, float y)
{
	_fX = x;
	_fY = y;
}

Point2D::Point2D(const Point2D& p)
{
	_fX = p._fX;
	_fY = p._fY;
}

ostream& operator<<(ostream& outDev, const Point2D& p)
{
	outDev << "(" << p._fX << "," << p._fY << ")";
	return outDev;
}