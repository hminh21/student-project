#include "Line.h"

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

float Point2D::getX()
{
	return _fX;
}

float Point2D::getY()
{
	return _fY;
}

ostream& operator<<(ostream& outDev, const Point2D& p)
{
	outDev << "(" << p._fX << "," << p._fY << ")";
	return outDev;
}
Line::Line()
{
	Point2D _pA(0, 0);
	Point2D _pB(0, 0);
}

Line::Line(Point2D a, Point2D b)
{
	_pA = a;
	_pB = b;
}

Line::Line(const Line& l)
{
	_pA = l._pA;
	_pB = l._pB;
}

float Line::Distance()
{
	int x = abs(_pA.getX() - _pB.getX());
	int y = abs(_pA.getY() - _pB.getY());

	return sqrt(x*x + y*y);
}

ostream& operator<<(ostream& outDev, const Line& l)
{
	outDev << l._pA << l._pB;
	return outDev;
}

