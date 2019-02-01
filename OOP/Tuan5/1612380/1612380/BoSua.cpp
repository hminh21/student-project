#include "BoSua.h"


BoSua::BoSua()
{
	_MaSo = 0;
	const_cast<int&> (_MaSo);
	_CanNang = 0;
	_Tuoi = 0;
}

BoSua::BoSua(int MaSo, float CanNang, float Tuoi)
{
	_MaSo = MaSo;
	const_cast<int&> (_MaSo);
	_CanNang = CanNang;
	_Tuoi = Tuoi;
}

BoSua::BoSua(const BoSua& b)
{
	_MaSo = b._MaSo;
	const_cast<int&> (_MaSo);
	_CanNang = b._CanNang;
	_Tuoi = b._Tuoi;
}


BoSua::~BoSua()
{
}

//Operator

ostream& operator<<(ostream& outDev, const BoSua& b)
{
	cout << "Ma so: " << b.get_MaSo() << endl;
	cout << "Can nang: " << b.get_CanNang() << endl;
	cout << "Tuoi: " << b.get_Tuoi();
	return outDev;
}

BoSua& BoSua::operator=(const BoSua& b)
{
	_CanNang = b._CanNang;
	_Tuoi = b._Tuoi;	
	return *this;
}

bool BoSua::CheckProperties()
{
	return(_CanNang > 0 && _Tuoi > 0);
}
