#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class PhanSo
{
	int mTuSo;
	int mMauSo;
public:
	const int& GetTuSo() const { return mTuSo; };
	const int& GetMauSo() const {return mMauSo; };
	void SetTuSo(int value) { mTuSo = value; };
	void SetMauSo(int value){ mMauSo = value; };
public:
	PhanSo();
	PhanSo(int, int);
	PhanSo(const PhanSo&);
	string ToString();
	bool operator>(const PhanSo&);
	PhanSo operator+(const PhanSo&);
	PhanSo operator*(const PhanSo&);
	PhanSo& operator~();
};

int UCLN(PhanSo);
 PhanSo findMax(vector<PhanSo>);
 PhanSo findMin(vector<PhanSo>);
 PhanSo TongPS(vector<PhanSo>);
 PhanSo TichPS(vector<PhanSo>);