#include "Shapes.h"

void main()
{
	Point2D A(1, 2), B(2, 3), C(3, 5), D(1, 1), E(3, 2), F(3, 1), G(2,2), H(2,1);
	Triangle T(A, B, C);
	cout << "Tam giac T: " << T << endl;
	cout << "Chu vi:" << T.Perimeter() << endl;
	cout << "Dien tich:" << T.Area() << endl;
	Rectangle R(A, E, F, D);
	cout << "Hinh chu nhat R: " << R << endl;
	cout << "Chu vi:" << R.Perimeter() << endl;
	cout << "Dien tich:" << R.Area() << endl;
	Square S(A, G, H, D);
	cout << "Hinh vuong S: " << S << endl;
	cout << "Chu vi:" << S.Perimeter() << endl;
	cout << "Dien tich:" << S.Area() << endl;
}