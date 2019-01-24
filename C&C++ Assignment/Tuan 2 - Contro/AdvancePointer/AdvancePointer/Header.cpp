#include "Header.h"

void InputArray2D(int *arr[], int &iRow, int &iCol)
{
	cout << "Nhap so dong: ";
	cin >> iRow;
	cout << "Nhap so cot";
	cin >> iCol;

	arr = new int*[iRow];
	
	
	for (int i = 0; i < iRow; i++)
	{
		int *p = (int*)arr;
		p = new int[iCol];
		p++;
		for (int j = 0; j < iCol; j++)
		{
			cout << "arr[" << i << "][" << j << "]= ";
			cin >> *p++;
		}
	}
}

void OutputArray2D(int *arr[], int iRow, int iCol)
{
	for (int i = 0; i < iRow; i++)
	{
		int *p = (int*)arr;
		p++;
		for (int j = 0; j < iCol; j++)
		{
			cout << *p++ << " ";
		}
		cout << endl;
	}
}