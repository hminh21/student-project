#include "SinhVien.h"
#include "Header.h"

SinhVien::SinhVien() 
{
	strcpy(_MSSV, "NULL");
	strcpy(_HoTen, "NULL");
	_NgaySinh = { 0, 0, 0 };
	strcpy(_CMND, "NULL");
	strcpy(_SDT, "NULL");
	strcpy(_Email, "NULL");
}

SinhVien::SinhVien(const SinhVien& sv)
{
	strcpy(_MSSV, sv._MSSV);
	strcpy(_HoTen, sv._HoTen);
	_NgaySinh = sv._NgaySinh;
	strcpy(_CMND, sv._CMND);
	strcpy(_SDT, sv._SDT);
	strcpy(_Email, sv._Email);

}

SinhVien::~SinhVien()
{
}



bool SinhVien::operator>(const SinhVien& sv)
{
	char sv1[30], sv2[30];
	strtoken(sv1, *this); //cat xau ra va dao ten lai de so sanh
	strtoken(sv2, sv);
	int maxsize;
	if (strlen(sv1) >= strlen(sv2)) //Lay size nho nhat de duyet so sanh ki tu
		maxsize = strlen(sv2);
	else
		maxsize = strlen(sv1);
	for (int i = 0; i < maxsize; i++)
	{
		if (sv1[i] > sv2[i])
			return true;
		else 
		if (sv1[i] < sv2[i])
			return false;
	}
}


istream& operator>>(istream& inDev, SinhVien& sv)
{
	char* str = new char[256];
	char* token;

	//Cat chuoi
	inDev.getline(str, 256);
	token = strtok(str, ":");
	token = strtok(NULL, "\n");
	if (token == NULL) return inDev; //Neu da doc den het dong
	strcpy(sv._HoTen, token);


	inDev.getline(str, 256);
	token = strtok(str, ":");
	token = strtok(NULL, "\n");
	strcpy(sv._MSSV, token);


	inDev.getline(str, 256);
	token = strtok(str, ":");
	token = strtok(NULL, "/");
	sv._NgaySinh.ngay = atoi(token);
	token = strtok(NULL, "/");
	sv._NgaySinh.thang = atoi(token);
	token = strtok(NULL, "NULL");
	sv._NgaySinh.nam = atoi(token);

	inDev.getline(str, 256);
	token = strtok(str, ":");
	token = strtok(NULL, "\n");
	strcpy(sv._CMND, token);

	inDev.getline(str, 256);
	token = strtok(str, ":");
	token = strtok(NULL, "\n");
	strcpy(sv._SDT, token);


	inDev.getline(str, 256);
	token = strtok(str, ":");
	token = strtok(NULL, "\n");
	strcpy(sv._Email, token);
	delete str;
	return inDev;
}
ostream& operator<<(ostream& outDev, SinhVien& sv)
{
	outDev << "Ho va ten:" << sv._HoTen << endl;
	outDev << "MSSV     :" << sv._MSSV << endl;
	outDev << "Ngay Sinh:" << sv._NgaySinh << endl;
	outDev << "CMND     :" << sv._CMND << endl;
	outDev << "SDT      :" << sv._SDT << endl;
	outDev << "Email    :" << sv._Email << endl;
	return outDev;
}
