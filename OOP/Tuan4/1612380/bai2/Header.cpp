#include "Header.h"


void ReadFile(ifstream &fs, vector<SinhVien> &sv)
{
	SinhVien p;
	if (!fs)
	{
		cout << "khong ton tai file" << endl;
		return;
	}
	while (!fs.eof())
	{
		fs >> p;
		sv.push_back(p);
	}
	fs.close();
}

void strtoken(char str[], const SinhVien& sv)
{
	stack <char*> s; //Dung stack de dao nguoc ten
	char HoTen[30];
	strcpy(HoTen, sv.get_HoTen());
	char* token, *substr;
	token = strtok(HoTen, " ");
	while (token != NULL)
	{
		s.push(token);
		token = strtok(NULL, " ");
	}
	
	//Lay ten ra
	substr = s.top();
	strcpy(str, substr);
	s.pop();
	//Lay ho va ten lot
	while (s.empty() != true)
	{
		substr = s.top();
		strcat(str, substr);
		s.pop();
	}
}

void SortAphalbet(vector <SinhVien> &sv)
{
	for (int i = 0; i < sv.size() - 1; i++)
	{
		for (int j = i + 1; j < sv.size(); j++)
		{
			if (sv[i] > sv[j])
			{
				SinhVien temp = sv[i]; //swap
				sv[i] = sv[j];
				sv[j] = temp;
			}
		}
	}
}

ostream& operator<<(ostream& outDev, const NGAY& Ngay)
{
	cout << Ngay.ngay << "/" << Ngay.thang << "/" << Ngay.nam;
	return outDev;
}