
#include<conio.h>
#include"Dathuc.h"
#include<iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv) 
{
	DaThuc A;
	DaThuc B;
	
	string str;

	ifstream F1;
	F1.open(argv[1], ios_base::in);
	ifstream F2;
	F2.open(argv[2], ios_base::in);

	ofstream F_result;
	F_result.open("F-result.txt", ios_base::out);


	if (!F1.is_open()) {
		cout << "Can not open "<< argv[1] << " file" << endl;
		return 0;
	}

	if (!F2.is_open()) {
		cout << "Can not open " << argv[2] << " file" << endl;
		return 0;
	}

	if (!F_result.is_open()) {
		cout << "Can not open result file" << endl;
		return 0;
	}

	str = A.ReadFile(F1);
	A.ReadString(str);

	str = B.ReadFile(F2);
	B.ReadString(str);

	
	F_result << "F1" << endl;
	F_result << A << endl;
	F_result << "F2" << endl;
	F_result << B << endl;

	DaThuc F3 = A + B;
	F_result << "F3" << endl;
	F_result << F3 << endl;

	DaThuc F4 = A - B;
	F_result << "F4" << endl;
	F_result << F4 << endl;

	DaThuc F5 = A * B;
	F_result << "F5" << endl;
	F_result << F5 << endl;
	
	
	F1.close();
	F2.close();
	F_result.close();
	_getch();
}