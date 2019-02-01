#pragma once
#ifndef Lop_H
#define Lop_H
#include "Header.h"
#include "SinhVien.h"

class SinhVien;

class CLop
{
	/*char _TenLop[7];*/
	string _TenLop;
	vector <SinhVien> _Sv;
	unsigned short _Siso;
public:
	CLop(); //default constructor
	CLop(const CLop&); //copy constructor
	~CLop(); //destructor

	//operator
	string get_TenLop() { return _TenLop; };
	vector <SinhVien> get_SinhVien() const { return _Sv; };
	const unsigned short& get_Siso() const { return _Siso; };
	void set_TenLop(string TenLop){ _TenLop = TenLop; };
	void set_SinhVien(const SinhVien &sv) { _Sv.push_back(sv); _Siso++; };
	void set_SiSo(const unsigned short siso) { _Siso = siso; };

	bool operator>(const CLop&);
	friend istream& operator>>(istream& inDev, CLop& c);
	friend ostream& operator<<(ostream& outDev, const CLop& c);
};

#endif