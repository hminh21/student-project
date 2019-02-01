#include "DHA.h"

void main(){
	CDHA k;
	int x;
	cout << "0. Thoat" << endl;
	cout << "1. Nhap danh sach sinh vien" << endl;
	cout << "2. Xuat danh sach sinh vien" << endl;
	cout << "3. Tong so sinh vien tot nghiep" << endl;
	while (1)
	{
		cin >> x;
		fflush(stdin);
		switch (x)
		{
		case 0: return;
		case 1: k.Input(cin); break;
		case 2: k.Output(cout); break;
		case 3: cout << "Tong so sinh vien tot nghiep:" << k.TotalGraduation() << endl; break;
		}
	}
}