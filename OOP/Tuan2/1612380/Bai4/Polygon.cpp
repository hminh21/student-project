#include "Polygon.h"

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
//Phuong thuc cua Line
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

//Phuong thuc cua Polygon

Polygon::Polygon()//constructor
{
	Point = 0;
	_iN = 0;
}
Polygon::Polygon(int N)//constructor
{
	double x, y;
	Point = new Point2D[N];
	for (int i = 0; i < N; i++)
	{
		cout << "P" << i + 1 << "= ";
		cin >> x >> y;
		Point[i].setX(x);
		Point[i].setY(y);
	}
	_iN = N;
}
Polygon::Polygon(const Polygon& A)//constructor
{
	for (int i = 0; i < A._iN; i++)
	{
		Point[i] = A.Point[i];
	}
	_iN = A._iN;
}
Polygon::~Polygon()//destructor
{
	delete[] Point;
	_iN = 0;
}

float Polygon::Perimeter()
{
	float S = 0;
	for (int i = 0; i < _iN - 1; i++)
		S += Line(Point[i], Point[i + 1]).Distance();
	return S + Line(Point[0], Point[_iN - 1]).Distance();
}

float Polygon::Area()
{
		float S = 0;
		for (int i = 1; i< _iN - 1; i++)
		{
			S += Triangle(Point[0], Point[i], Point[i + 1]).Area();
		}
		return S;
}

ostream& operator<<(ostream& outDev, const Polygon& p)			
{
	for (int i = 0; i < p._iN; i++)
		outDev << "P" << i + 1 << "=" << p.Point[i] << "  ";
	return outDev;
}