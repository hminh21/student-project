#include "MyString.h"

void main()
{
	CMyString a("  ab   cd");
	CMyString b("abce");
	~a;
	cout << a << endl;
	cout << b << endl;
	bool x = a <= b;
	cout << x;
	_getch();
}