#include "CPoint2D.h"

void CPoint2D::Set(double X0, double Y0)
{
	X = X0;
	Y = Y0;
}

void CPoint2D::Move(double dX, double dY)
{
	X += dX;
	Y += dY;
}

void CPoint2D::Scale(double sX, double sY)
{
	X *= sX;
	Y *= sY;
}