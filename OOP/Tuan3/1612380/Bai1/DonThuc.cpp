#include "DonThuc.h"


CDonThuc::CDonThuc()
{
	_fA = 0;
	_fB = 0;
}

CDonThuc::CDonThuc(float a, float b)
{
	if (b >= 0)
	{
		_fA = a;
		_fB = b;
	}
	else
		cout << "Don thuc khong hop le" << endl;
}

CDonThuc::CDonThuc(const CDonThuc& d)
{
	_fA = d._fA;
	_fB = d._fB;
}

CDonThuc::~CDonThuc()
{
	return;
}

float CDonThuc::getA()
{
	return _fA;
}

float CDonThuc::getB()
{
	return _fB;
}

void CDonThuc::setA(float a)
{
	_fA = a;
}

void CDonThuc::setB(float b)
{
	if (b >= 0)
	_fB = b;
}

void CDonThuc::Nhap()
{
	cout << "Nhap he so:";
	cin >> _fA;
	cout << "Nhap luy thua:";
	cin >> _fB;
}

void CDonThuc::Xuat()
{
	if (_fA == 0)
	{
		cout << "0" << endl;
		return;
	}
	else 
	if (_fB == 0)
	{
		cout << _fA << endl;
		return;
	}

	if (_fA == 1)
	{
		if (_fB == 1)
		{
			cout << "x" << endl;
			return;
		}
		else
		{
			cout << "x^" << _fB << endl;
			return;
		}
	}

	if (_fB == 1)
	{
		cout << _fA << "*x" << endl;
	}
	else
		cout << _fA << "*X^" << _fB << endl;
}

istream& operator>>(istream& inDev, CDonThuc& d)
{
	cout << "Nhap he so:";
	inDev >> d._fA;
	cout << "Nhap luy thua:";
	inDev >> d._fB;
	return inDev;
}

ostream& operator<<(ostream& outDev,const CDonThuc& d)
{
	if (d._fA == 0)
	{
		cout << "0" << endl;
		return outDev;
	}
	else
	if (d._fB == 0)
	{
		cout << d._fA << endl;
		return outDev;
	}

	if (d._fA == 1)
	{
		if (d._fB == 1)
		{
			cout << "x" << endl;
			return outDev;
		}
		else
		{
			cout << "x^" << d._fB << endl;
			return outDev;
		}
	}

	if (d._fB == 1)
	{
		cout << d._fA << "*x" << endl;
	}
	else
		cout << d._fA << "*X^" << d._fB << endl;
}

float CDonThuc::Calc(float x)
{
	return _fA*pow(x, _fB);
}

CDonThuc CDonThuc::operator*(const CDonThuc& d)
{
	CDonThuc dt;
	dt._fA = _fA * d._fA;
	dt._fB = _fB + d._fB;
	return dt;
}

CDonThuc CDonThuc::operator/(const CDonThuc& d)
{
	CDonThuc dt;
	dt._fA = _fA / d._fA;
	dt._fB = _fB - d._fB;
	return dt;
}
CDonThuc& CDonThuc::operator*=(const CDonThuc& d)
{
	_fA *= d._fA;
	_fB += d._fB;
	return *this;

}

CDonThuc& CDonThuc::operator/=(const CDonThuc& d)
{
	_fA /= d._fA;
	_fB -= d._fB;
	return *this;
}

CDonThuc &CDonThuc::operator=(const CDonThuc& d)
{
	_fA = d._fA;
	_fB = d._fB;
	return *this;
}

bool CDonThuc::operator==(const CDonThuc& d)
{
	return(_fA == d._fA && _fB == d._fB);
}

bool CDonThuc::operator!=(const CDonThuc& d)
{
	if (*this == d)
		return false;
	return true;
}