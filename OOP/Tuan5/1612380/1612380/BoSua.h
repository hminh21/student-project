#ifndef _BoSua_h
#define _BoSua_h

#include <iostream>

using namespace std;
class BoSua
{
	int _MaSo;
	float _CanNang;
	float _Tuoi;
public:
	BoSua(); //default constructor
	BoSua(int, float, float); //constructor
	BoSua(const BoSua&); //copy constructor
	~BoSua();

	//operator
	const int& get_MaSo() const { return _MaSo; };
	const float& get_CanNang() const{ return _CanNang; };
	const float& get_Tuoi() const { return _Tuoi; };
	void set_CanNang(float CanNang){ _CanNang = CanNang; };
	void set_Tuoi(float Tuoi){ _Tuoi = Tuoi; };
	BoSua& operator=(const BoSua&);
	bool CheckProperties();
	friend ostream& operator<<(ostream&, const BoSua&);
};

#endif