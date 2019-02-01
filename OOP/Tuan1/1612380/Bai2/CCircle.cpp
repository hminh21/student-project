//File: Circle.cpp
#include "CCircle.h"

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

double CPoint2D::GetX() //Lay X
{
	return X;
}

double CPoint2D::GetY() //Lay Y
{
	return Y;
}

void CCircle::intit(double dX, double dY, double dRadius)
{
	m_pt2DCenter.Set(dX, dY);
	if (dRadius < 0)
		m_dRadius = 0;
}

void CCircle::SetCenter(double dX0, double dY0)
{
	m_pt2DCenter.Set(dX0, dY0);
}

void CCircle::SetRadius(double dRadius0)
{
	m_dRadius = dRadius0;
}

CPoint2D CCircle::GetCenter()
{
	return m_pt2DCenter;
}

double CCircle::GetRadius()
{
	return m_dRadius;
}

void CCircle::move(double dX, double dY)
{
	m_pt2DCenter.Move(dX, dY);
}

const double PI = 3.14159;
double CCircle::getPerimeter()
{
	return 2 * PI*m_dRadius;
}

double CCircle::getArea()
{
	return PI * pow(m_dRadius, 2);
}

double CCircle::Distance(CCircle cir) //Tinh khoang cach giua 2 tam hinh tron
{
	return sqrt(pow(cir.GetCenter().GetX() - m_pt2DCenter.GetX(), 2) + pow(cir.GetCenter().GetY() - m_pt2DCenter.GetY(), 2));
}

bool CCircle::isInside(CCircle cir) //Xet moi quan he nam trong hinh tron cir
{
	if (Distance(cir) < cir.GetRadius())
		return true;
	return false;
}

bool CCircle::isOverlap(CCircle cir) //Xet moi quan he trung nhau
{
	if (Distance(cir) == cir.GetRadius())
		return true;
	return false;
}

bool CCircle::isBoundary(CCircle cir) //Xet moi quan he chua hinh tron cir
{
	if (Distance(cir) < GetRadius())
		return true;
	return false;
}

bool CCircle::isIntersection(CCircle cir) //Xet moi quan he cat nhau
{
	if (Distance(cir) > abs(cir.GetRadius() - GetRadius()) && Distance(cir) < cir.GetRadius() + GetRadius())
		return true;
	return false;
}

bool CCircle::isContact(CCircle cir) //Xet moi quan he tiep xuc
{
	if (Distance(cir) == cir.GetRadius() + GetRadius())
		return true;
	return false;
}

bool CCircle::isOutside(CCircle cir) //Xet moi quan he ngoai hinh tron cir
{
	if (Distance(cir) > cir.GetRadius() + GetRadius())
		return true;
	return false;
}
