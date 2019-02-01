#include "CStudent.h"

void main()
{
	CStudent Stu;
	cin >> Stu;
	cout << "Ho va ten" << setw(25) << "Van" << setw(5) << "Toan" << setw(15) << "Xep loai" << endl;
	cout << Stu << endl;
	Stu.Set("Huynh Nguyen Nhat Minh"); //Gan bang ten khac
	Stu.Set(2, 3); //Gan diem khac
	cout << Stu << endl;
	_getch();
}