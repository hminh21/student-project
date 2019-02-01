#include "MyString.h"

void main()
{
	MyString a("abcdef", 6);
	a.insert(2, "xy");
	cout << a << endl;
	a.erase(2, 2);
	cout << a << endl;
	_getch();
}