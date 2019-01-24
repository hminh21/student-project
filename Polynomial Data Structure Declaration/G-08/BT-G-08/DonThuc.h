#pragma once
#include "DaThuc.h"

using namespace std;

template <class T>
struct Node_Bien_Mu
{
	T data;
	Node_Bien_Mu* next;
};

template <class T>
class DonThuc
{
	float _HeSo;
	Node_Bien_Mu* _Bien;
	Node_Bien_Mu* _SoMu;
	DonThuc* _Next;
public:
	DonThuc();
	DonThuc(float, T);
	DonThuc(const DonThuc&);
	~DonThuc();

	//Operator
	const float& get_HeSo() const { return _HeSo; };
	const T& get_SoMu() const { return _SoMu; };
	const T& get_Bien() const { return _Bien; };
	const DonThuc* &get_Next() const{ return _Next; };
	void set_HeSo(float HeSo){ _HeSo = HeSo; };
	void set_SoMu(T SoMu){ _SoMu->data = SoMu; };
	void set_Bien(T Bien){ _Bien->data = Bien; };
	void set_Next(DonThuc* Next){ _Next = Next; };

	DonThuc operator+(const DonThuc&);
	DonThuc operator-(const DonThuc&);
	DonThuc operator*(const DonThuc&);

	ostream& operator<<(ostream&, const DonThuc&);
};

