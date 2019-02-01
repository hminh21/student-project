#include "Header.h"

int main()
{
	vector <SinhVien> sv;
	ifstream fs("DSSV.txt", ios::in);
	if (!fs)
		return 1;
	ReadFile(fs, sv);
	SortAphalbet(sv); //Sap xep
	cout << "-------Danh sach sinh vien------" << endl;
	for (int i = 0; i < sv.size(); i++)
	{
		cout << "~~~~~~~~~ SINH VIEN " << i << " ~~~~~~~~~" << endl;
		cout << sv[i];
	}
}