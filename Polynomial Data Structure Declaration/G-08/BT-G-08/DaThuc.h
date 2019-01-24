#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include "DonThuc.h"

using namespace std;

template< class T>
class DonThuc;

template <class T>
class DaThuc
{
	DonThuc* _Donthuc;
public:
	DaThuc();
	DaThuc(const DaThuc&);
	DaThuc(const DonThuc&);
	~DaThuc();

	// Operator
	const DonThuc* & get_DonThuc() const { return _Donthuc; };
	void set_DonThuc(DonThuc Donthuc){ _Donthuc = Donthuc; };
	void AddDonThuc(float HeSo, char Bien, int SoMu);

	DaThuc operator+(const DaThuc&);
	DaThuc operator-(const DaThuc&);
	DaThuc operator*(const DaThuc&);
	DaThuc& operator~(); //Rut gon
	DaThuc& operator!(); //Chuan hoa

	ostream& operator<<(ostream&, const DaThuc&);
};

