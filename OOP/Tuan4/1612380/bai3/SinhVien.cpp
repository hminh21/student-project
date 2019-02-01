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

SinhVien& SinhVien::operator=(const SinhVien& sv)
{
	strcpy(_MSSV, sv._MSSV);
	strcpy(_HoTen, sv._HoTen);
	_NgaySinh.ngay = sv._NgaySinh.ngay;
	_NgaySinh.thang = sv._NgaySinh.thang;
	_NgaySinh.nam = sv._NgaySinh.nam;
	strcpy(_CMND, sv._CMND);
	strcpy(_SDT, sv._SDT);
	strcpy(_Email, sv._Email);
	return *this;
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

ostream& operator<<(ostream& outDev,const SinhVien& sv)
{
	outDev << "Ho va ten:" << sv._HoTen << endl;
	outDev << "MSSV     :" << sv._MSSV << endl;
	outDev << "Ngay Sinh:" << sv._NgaySinh.ngay << "/" << sv._NgaySinh.thang << "/" << sv._NgaySinh.nam << endl;
	outDev << "CMND     :" << sv._CMND << endl;
	outDev << "SDT      :" << sv._SDT << endl;
	outDev << "Email    :" << sv._Email << endl;
	return outDev;
}
