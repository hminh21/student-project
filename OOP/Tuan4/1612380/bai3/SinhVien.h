#pragma once
#ifndef SinhVien_H
#define SinhVien_H
#include "Class.h"
#include "Header.h"

using namespace std;

struct NGAY
{
	unsigned short ngay;
	unsigned short thang;
	unsigned short nam;
};


class SinhVien
{
	char _MSSV[8];
	char _HoTen[30];
	NGAY _NgaySinh;
	char _CMND[10];
	char _SDT[12];
	char _Email[30];

public:
	SinhVien(); //default constructor
	SinhVien(const SinhVien&); //copy constructor
	~SinhVien(); //destructor

	//operator
	const char* get_MSSV() const { return _MSSV; };
	const char* get_HoTen() const { return _HoTen; };
	const char* get_CMND() const { return _CMND; };
	const char* get_SDT() const { return _SDT; };
	const char* get_Email() const { return _Email; };
	const NGAY& get_NgaySinh() const { return _NgaySinh; };

	void set_MSSV(char* MSSV) { strcpy(_MSSV, MSSV); };
	void set_HoTen(char* HoTen) { strcpy(_HoTen, HoTen); };
	void set_CMND(char* CMND) { strcpy(_CMND, CMND); };
	void set_SDT(char* SDT) { strcpy(_SDT, SDT); };
	void set_Email(char* Email) { strcpy(_Email, Email); };
	void set_NgaySinh(NGAY NgaySinh) { _NgaySinh = NgaySinh; };

	SinhVien& operator=(const SinhVien&);

	friend istream& operator>>(istream&, SinhVien&);
	friend ostream& operator<<(ostream&,const SinhVien&);
};


#endif