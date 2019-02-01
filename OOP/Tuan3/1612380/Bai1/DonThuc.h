#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
class CDonThuc
{
	float _fA;
	float _fB;
public:
	CDonThuc();
	CDonThuc(float,float);
	CDonThuc(const CDonThuc&);
	~CDonThuc();
	float getA();
	float getB();
	void setA(float);
	void setB(float);
	void Nhap();
	void Xuat();
	friend istream& operator>>(istream&, CDonThuc&);
	friend ostream& operator<<(ostream&,const CDonThuc&);
	float Calc(float);
	CDonThuc operator*(const CDonThuc&);
	CDonThuc operator/(const CDonThuc&);
	CDonThuc& operator*=(const CDonThuc&);
	CDonThuc& operator/=(const CDonThuc&);
	CDonThuc& operator=(const CDonThuc&);
	bool operator==(const CDonThuc&);
	bool operator!=(const CDonThuc&);
};

