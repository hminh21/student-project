#include "Polygon.h"

void main()
{
	Polygon P(4);
	cout << P << endl;
	cout << "Chu vi:" << P.Perimeter() << endl;
	cout << "Dien tich:" << P.Area() << endl;
}