#include "CStaticArray.h"

void main()
{
	CStaticArray Array;
	Array.Input();
	Array.Output();
	int n = Array.GetSize();
	cout << n << endl;
	_getch();
}