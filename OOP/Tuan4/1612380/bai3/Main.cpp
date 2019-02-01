#include "Header.h"
#include "Class.h"
#include "SinhVien.h"

void main()
{
	vector <Class> c;
	ifstream input("DanhSachLop.txt", ios::in);
	ReadFile(input, c);
	SortClass(c);
	ofstream output("ClassList.txt", ios::out);
	WriteFile(output, c);
}