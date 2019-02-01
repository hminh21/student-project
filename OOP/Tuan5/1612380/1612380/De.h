#ifndef _De_h
#define _De_h
#include <iostream>

using namespace std;
class De
{
	int _MaSo;
	float _CanNang;
	float _Tuoi;
public:
	De(); //default constructor
	De(int, float, float); //constructor
	De(const De&); //copy constructor
	~De(); //destructor

	//operator
	const int& get_MaSo() const { return _MaSo; };
	const float& get_CanNang() const{ return _CanNang; };
	const float& get_Tuoi() const { return _Tuoi; };
	void set_CanNang(float CanNang){ _CanNang = CanNang; };
	void set_Tuoi(float Tuoi){ _Tuoi = Tuoi; };
	De& operator=(const De&);
	bool CheckProperties();
	friend istream& operator>>(istream&, De&);
	friend ostream& operator<<(ostream&, const De&);
};

#endif