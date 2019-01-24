#include "Header.h"


int main()
{
	cout << "----------Part 1----------" << endl;
	fstream fs;
	fs.open("hello.txt", ios::in|ios::out);
	if (!fs)
	{
		cout << "Khong the mo file hello.txt" << endl;
		return 0;
	}
	else
	{
		cout << "Mo file hello.txt thanh cong" << endl;
	}


	ReplaceChar(' ', '\t',fs);
	fs.close(); //Dong file

	cout << "----------Part 2----------" << endl;
	CopyFile("file1.txt", "file2.txt");

	cout << "----------Part 3----------" << endl;
	
	ifstream fs3("PHANSO.txt", ios::in);
	if (!fs3)
	{
		cout << "Khong the mo file PHANSO.txt" << endl;
		return 0;
	}
	else
		cout << "Mo file PHANSO.txt thanh cong" << endl;

	ReadAndWrite(fs3);
	fs3.close(); //Dong file

	cout << "----------Part 4----------" << endl;

	ifstream fs5("BYE.txt", ios::in);
	if (!fs5)
	{
		cout << "Khong the mo file BYE.txt" << endl;
		return 0;
	}
	else
	{
		cout << "Mo file BYE.txt thanh cong" << endl;
	}

	Statistic(fs5); 
	fs5.close();//Dong file

	return 1;
}