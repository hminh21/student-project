//File: CStaticArray.cpp

#include "CStaticArray.h"

void CStaticArray::Input() //Nhap
{
	cout << "Nhap so phan tu:";
	cin >> N;
	int* a = new int[N];
	cout << "Nhap gia tri:" << endl;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	init(a);
	delete[] a;
}

void CStaticArray::Output() //Xuat
{
	cout << "Mang phan tu: ";
	for (int i = 0; i < N; i++)
		cout << Arr[i] << " ";
	cout << endl;
}

void CStaticArray::init(int a[]) //Khoi tao
{
	for (int i = 0; i < N; i++)
		Arr[i] = a[i];
}

int CStaticArray::GetSize() //Lay size 
{
	return N;
}

int CStaticArray::Get(int i) //Lay gia tri o vi tri nao do
{
	return Arr[i];
}

void CStaticArray::Set(int a, int i) //Gan gia tri o vi tri nao do
{
	if (i < 0)
	{
		Arr[0] = a;
	}
	else if (i > N - 1)
	{
		Arr[N - 1] = a;
	}
	else
	Arr[i] = a;
}

int CStaticArray::Find(int a) //Tim phan tu nao do
{
	for (int i = 0; i < N; i++)
	if (Arr[i] == a)
		return i;
}

int CStaticArray::Min() //Tim phan tu co gia tri nho nhat
{
	int flag = Arr[0];
	for (int i = 1; i < N; i++)
	if (flag > Arr[i])
		flag = Arr[i];
	return flag;
}

int CStaticArray::Max() //Tim phan tu co gia tri lon nhat
{
	int flag = Arr[0];
	for (int i = 1; i < N; i++)
	if (flag < Arr[i])
		flag = Arr[i];
	return flag;
}

void CStaticArray::SortAscending() //Sap xep tang dan
{
	for (int i = 0; i < N - 1; i++)
	for (int j = 0; j < N; j++)
	{
		if (Arr[i] > Arr[j])
		{
			int temp = Arr[i];
			Arr[i] = Arr[j];
			Arr[j] = temp;
		}
	}
}

void CStaticArray::SortDescending() //Sap xep giam dan
{
	for (int i = 0; i < N - 1; i++)
	for (int j = 0; j < N; j++)
	{
		if (Arr[i] < Arr[j])
		{
			int temp = Arr[i];
			Arr[i] = Arr[j];
			Arr[j] = temp;
		}
	}
}
