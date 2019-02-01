#include "MyString.h"


CMyString::CMyString()
{
	_cStr = NULL;
	_iN = 0;
}

CMyString::CMyString(char* str)
{
	int N = strlen(str);
	if (N >= 0)
	{
		_iN = N;
		_cStr = new char[_iN + 1];
		if (_cStr == NULL)
		{
			cout << "Khong du bo nho" << endl;
			return;
		}
		strcpy(_cStr, str);	
	}
	else
		cout << "Chuoi khong hop le" << endl;
}

CMyString::CMyString(const CMyString& c)
{
	if (c._iN >= 0)
	{
		_iN = c._iN;
		_cStr = new char[_iN + 1];
		if (_cStr == NULL)
		{
			cout << "Khong du bo nho" << endl;
			return;
		}
		strcpy(_cStr, c._cStr);
	}
	else
		cout << "Chuoi khong hop le" << endl;
}

CMyString::~CMyString()
{
	if (_cStr != NULL)
	{
		delete[] _cStr;
		_cStr = NULL;
		_iN = 0;
	}
}

int CMyString::getLength()
{
	return _iN;
}

char CMyString::getChar(int pos)
{
	if (pos >= 0 && pos < _iN)
		return _cStr[pos];
	return NULL;
}

void CMyString::setChar(int pos, char ch)
{
	if (pos >= 0 && pos < _iN)
		_cStr[pos] = ch;
}

istream& operator>>(istream& inDev, CMyString& c)
{
	char str[256];
	cout << "Nhap chuoi: " << endl;
	inDev.getline(str, 256);
	if (strlen(str) > 0)
	{
		CMyString a(str);
		c._cStr = a._cStr;
		c._iN = a._iN;
	}
	return inDev;
}

ostream& operator<<(ostream& outDev, const CMyString& c)
{
	outDev << c._cStr;
	return outDev;
}

CMyString CMyString::operator+(const CMyString& c)
{
	CMyString sum;
	sum._iN = _iN + c._iN;
	sum._cStr = new char[sum._iN + 1];
	strcpy(sum._cStr,_cStr);
	strcat(sum._cStr, c._cStr);
	return sum;
}

CMyString& CMyString::operator!()
{
	_strrev(_cStr);
	return *this;
}

CMyString& CMyString::operator~()
{
	for (int i = 0; i < _iN; i++)
	{
		if (_cStr[i] == ' ' && _cStr[i + 1] == ' ')
		{
			DeleteChar(*this, i);
			i--; //Giam pos dang duyet vi _iN da bi giam
		}
	}

	if (_cStr[0] == ' ') //Ktra o dau chuoi
		DeleteChar(*this, 0);
	return *this;
}

void DeleteChar(CMyString& c,int pos)
{
	for (int i = pos; i <= c._iN; i++)
		c._cStr[i] = c._cStr[i + 1];
	c._iN--;
}

bool CMyString::operator>(const CMyString& c)
{
	return (strcmp(_cStr, c._cStr) == 1);
}

bool CMyString::operator>=(const CMyString& c)
{
	return (strcmp(_cStr, c._cStr) >= 0);
}
bool CMyString::operator<(const CMyString& c)
{
	return (strcmp(_cStr, c._cStr) == -1);
}

bool CMyString::operator<=(const CMyString& c)
{
	return (strcmp(_cStr, c._cStr) <= 0);
}

bool CMyString::operator==(const CMyString& c)
{
	return (strcmp(_cStr, c._cStr) == 0);
}

bool CMyString::operator!=(const CMyString& c)
{
	if (*this == c)
		return false;
	return true;
}