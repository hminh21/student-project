#ifndef _NongTrai_h
#define _NongTrai_h
#include "De.h"
#include"BoSua.h"
#include <iostream>
#include <vector>
using namespace std;

class NongTrai
{
	vector <BoSua> ds_bo_sua;
	vector <De> ds_de;

public:
	void Nhap();
	void Xuat();
	void Xuat_TheoTuoi(int min, int max);

	friend istream& operator>>(istream&,NongTrai&);
	friend ostream& operator<<(ostream&, const NongTrai&);
};

#endif