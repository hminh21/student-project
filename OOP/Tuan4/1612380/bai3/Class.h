#pragma once
#ifndef Class_H
#define Class_H
#include "Header.h"
#include "SinhVien.h"

using namespace std;
class SinhVien;

class Class
{
	char _TenLop[7];
	SinhVien* _Sv;
	unsigned short _Siso;
public:
	Class(); //default constructor
	Class(char[], SinhVien*, unsigned short);
	Class(const Class&); //copy constructor
	~Class(); //destructor

	//operator
	const SinhVien& get_SinhVien() const { return *_Sv; };
	const unsigned short& get_Siso() const { return _Siso; };
	void set_SinhVien(SinhVien *sv) {_Sv = sv; _Siso++; };
	void set_SiSo(const unsigned short siso) { _Siso = siso; };

	bool operator>(const Class&);
	Class& operator=(const Class&);
	friend istream& operator>>(istream&, Class&);
	friend ostream& operator<<(ostream&,const Class&);
};

#endif