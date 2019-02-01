#include "NongTrai.h"

void NongTrai::Nhap()
{
	int MaSo;
	float CanNang, Tuoi;
	cout << "Nhap Bo(nhap -1 de ket thuc)" << endl;
	while (1)
	{
		cout << "Ma So:";
		cin >> MaSo;
		if (MaSo == -1) break;
		cout << "Can Nang:";
		cin >> CanNang;
		cout << "Tuoi:";
		cin >> Tuoi;
		BoSua bo(MaSo, CanNang, Tuoi);
		ds_bo_sua.push_back(bo);
	}
	cout << "Nhap De(nhap -1 de ket thuc)" << endl;
	while (1)
	{
		cout << "Ma So:";
		cin >> MaSo;
		if (MaSo == -1) break;
		cout << "Can Nang:";
		cin >> CanNang;
		cout << "Tuoi:";
		cin >> Tuoi;
		De de(MaSo, CanNang, Tuoi);
		ds_de.push_back(de);
	}
}

void NongTrai::Xuat()
{
	for (int i = 0; i < ds_bo_sua.size(); i++)
	{
		cout << "-----------------------" << endl;
		cout << "Bo " << i + 1 << endl;
		cout << ds_bo_sua[i] << endl;
	}

	for (int i = 0; i < ds_de.size(); i++)
	{
		cout << "-----------------------" << endl;
		cout << "De " << i + 1 << endl;
		cout << ds_de[i] << endl;
	}
}

void NongTrai::Xuat_TheoTuoi(int min, int max)
{
	int temp = 0;
	cout << "Danh sach bo, de tu " << min << " " << "den " << max << " " << "tuoi" << endl;
	for (int i = 0; i < ds_bo_sua.size(); i++)
	{
		if (ds_bo_sua[i].get_Tuoi() >= min && ds_bo_sua[i].get_Tuoi() <= max)
		{
			temp++;
			cout << "-----------------------" << endl;
			cout << "Bo " << temp << endl;
			cout << ds_bo_sua[i] << endl;
		}
	}
	temp = 0;
	for (int i = 0; i < ds_de.size(); i++)
	{
		if (ds_de[i].get_Tuoi() >= min && ds_de[i].get_Tuoi() <= max)
		{
			temp++;
			cout << "-----------------------" << endl;
			cout << "De " << temp << endl;
			cout << ds_de[i] << endl;
		}
	}
}