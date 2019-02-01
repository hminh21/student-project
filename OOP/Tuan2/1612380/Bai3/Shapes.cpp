//file: Shapes.cpp
#include "Shapes.h"

//Phuong thuc cua Point2D
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

void Point2D::setX(float x)
{
	_fX = x;
}

void Point2D::setY(float y)
{
	_fY = y;
}

ostream& operator<<(ostream& outDev, const Point2D& p)
{
	outDev << "(" << p._fX << "," << p._fY << ")";
	return outDev;
}




//Phuong thuc cua Triangle
Triangle::Triangle()
{
	Point2D _pA(0, 0);
	Point2D _pB(0, 0);
	Point2D _pC(0, 0);
}

Triangle::Triangle(Point2D A, Point2D B, Point2D C)
{
	float xAB, yAB, xAC, yAC; //Tao 2 vecto de kiem tra dieu kien dau vao
	xAB = B.getX() - A.getX();
	yAB = B.getY() - A.getY();
	xAC = C.getX() - A.getX();
	yAC = C.getY() - A.getY();

	if (xAB*yAC != xAC*yAB)
	{
		_pA = A;
		_pB = B;
		_pC = C;
	}
	else
		cout << "Diem nhap vao khong hop le" << endl;
}

Triangle::Triangle(const Triangle& t)
{
	_pA = t._pA;
	_pB = t._pB;
	_pC = t._pC;
}


float Triangle::Perimeter()
{
	float xAB, yAB, xBC, yBC, xAC, yAC; //Tao 3 vecto
	xAB = _pB.getX() - _pA.getX();
	yAB = _pB.getY() - _pA.getY();
	xAC = _pC.getX() - _pA.getX();
	yAC = _pC.getY() - _pA.getY();
	xBC = _pC.getX() - _pB.getX();
	yBC = _pC.getY() - _pB.getY();

	return sqrt(xAB*xAB + yAB*yAB) + sqrt(xAC*xAC + yAC*yAC) + sqrt(xBC*xBC + yBC*yBC);
}

float Triangle::Area()
{
	float xAC, yAC, xBC, yBC, xAB, yAB, p;
	p = Perimeter() / 2;
	xAB = _pB.getX() - _pA.getX();
	yAB = _pB.getY() - _pA.getY();
	xAC = _pC.getX() - _pA.getX();
	yAC = _pC.getY() - _pA.getY();
	xBC = _pC.getX() - _pB.getX();
	yBC = _pC.getY() - _pB.getY();

	return sqrt(p*(p - sqrt(xAB*xAB + yAB*yAB))*(p - sqrt(xAC*xAC + yAC*yAC))*(p - sqrt(xBC*xBC + yBC*yBC))); //Dung cong thuc heron
}

ostream& operator<<(ostream& outDev, const Triangle& t)
{
	cout << t._pA << t._pB << t._pC;
	return outDev;
}



//Phuong thuc cua Square

Square::Square()
{
	Point2D _pA(0, 0);
	Point2D _pB(0, 0);
	Point2D _pC(0, 0);
	Point2D _pD(0, 0);
}

Square::Square(Point2D A, Point2D B, Point2D C, Point2D D)
{
	float xAB, yAB, xBC, yBC, xCD, yCD; //Tao 3 vecto de kiem tra dieu kien dau vao
	xAB = B.getX() - A.getX();
	yAB = B.getY() - A.getY();
	xBC = C.getX() - B.getX();
	yBC = C.getY() - B.getY();
	xCD = D.getX() - C.getX();
	yCD = D.getY() - C.getY();

	float AB, BC;
	AB = sqrt(xAB*xAB + yAB*yAB);
	BC = sqrt(xBC*xBC + yBC*yBC);

	if (xAB*xBC + yAB*yBC == 0 && xBC*xCD + yBC*yCD == 0 && AB == BC)
	{
		_pA = A;
		_pB = B;
		_pC = C;
		_pD = D;
	}
	else
		cout << "Diem nhap vao khong hop le" << endl;
}

Square::Square(const Square& s)
{
	_pA = s._pA;
	_pB = s._pB;
	_pC = s._pC;
	_pD = s._pD;
}

float Square::Perimeter()
{
	float xAB, yAB, xBC, yBC, xCD, yCD, xAD, yAD; //Tao 4 vecto
	xAB = _pB.getX() - _pA.getX();
	yAB = _pB.getY() - _pA.getY();
	xAD = _pD.getX() - _pA.getX();
	yAD = _pD.getY() - _pA.getY();
	xBC = _pC.getX() - _pB.getX();
	yBC = _pC.getY() - _pB.getY();
	xCD = _pD.getX() - _pC.getX();
	yCD = _pD.getY() - _pC.getY();

	return sqrt(xAB*xAB + yAB*yAB) + sqrt(xAD*xAD + yAD*yAD) + sqrt(xBC*xBC + yBC*yBC) + sqrt(xCD*xCD + yCD*yCD);
}

float Square::Area()
{
	float xAB, yAB; //Tao 1 vecto
	xAB = _pB.getX() - _pA.getX();
	yAB = _pB.getY() - _pA.getY();

	return xAB*xAB + yAB*yAB;
}

ostream& operator<<(ostream& outDev, const Square& s)
{
	cout << s._pA << s._pB << s._pC << s._pD;
	return outDev;
}




//Phuong thuc cua Rectangle
Rectangle::Rectangle()
{
	Point2D _pA(0, 0);
	Point2D _pB(0, 0);
	Point2D _pC(0, 0);
	Point2D _pD(0, 0);
}

Rectangle::Rectangle(Point2D A, Point2D B, Point2D C, Point2D D)
{
	float xAB, yAB, xBC, yBC, xCD, yCD; //Tao 3 vecto de kiem tra dieu kien dau vao
	xAB = B.getX() - A.getX();
	yAB = B.getY() - A.getY();
	xBC = C.getX() - B.getX();
	yBC = C.getY() - B.getY();
	xCD = D.getX() - C.getX();
	yCD = D.getY() - C.getY();


	if (xAB*xBC + yAB*yBC == 0 && xBC*xCD + yBC*yCD == 0)
	{
		_pA = A;
		_pB = B;
		_pC = C;
		_pD = D;
	}
	else
		cout << "Diem nhap vao khong hop le" << endl;
}

Rectangle::Rectangle(const Rectangle& s)
{
	_pA = s._pA;
	_pB = s._pB;
	_pC = s._pC;
	_pD = s._pD;
}

float Rectangle::Perimeter()
{
	float xAB, yAB, xBC, yBC, xCD, yCD, xAD, yAD; //Tao 4 vecto
	xAB = _pB.getX() - _pA.getX();
	yAB = _pB.getY() - _pA.getY();
	xAD = _pD.getX() - _pA.getX();
	yAD = _pD.getY() - _pA.getY();
	xBC = _pC.getX() - _pB.getX();
	yBC = _pC.getY() - _pB.getY();
	xCD = _pD.getX() - _pC.getX();
	yCD = _pD.getY() - _pC.getY();

	return sqrt(xAB*xAB + yAB*yAB) + sqrt(xAD*xAD + yAD*yAD) + sqrt(xBC*xBC + yBC*yBC) + sqrt(xCD*xCD + yCD*yCD);
}

float Rectangle::Area()
{
	float xAB, yAB, xAD, yAD; //Tao 2 vecto
	xAB = _pB.getX() - _pA.getX();
	yAB = _pB.getY() - _pA.getY();
	xAD = _pD.getX() - _pA.getX();
	yAD = _pD.getY() - _pA.getY();

	return sqrt(xAB*xAB + yAB*yAB) * sqrt(xAD*xAD + yAD*yAD);
}

ostream& operator<<(ostream& outDev, const Rectangle& r)
{
	cout << r._pA << r._pB << r._pC << r._pD;
	return outDev;
}
