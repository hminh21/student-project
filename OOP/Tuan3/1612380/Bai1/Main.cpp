#include "DonThuc.h"

void main()
{
	CDonThuc A(2, 3), B, C(1,2);
	B = A;
	B /= A /= C;
	cout << B << endl;
	_getch();
}