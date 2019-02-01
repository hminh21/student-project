#include "De.h"


De::De()
{
	_MaSo = 0;
	const_cast <int&> (_MaSo);
	_CanNang = 0;
	_Tuoi = 0;
}

De::De(int MaSo, float CanNang, float Tuoi)
{
	_MaSo = MaSo;
	const_cast<int&> (_MaSo);
	_CanNang = CanNang;
	_Tuoi = Tuoi;
	
}

De::De(const De& d)
{
	_MaSo = d._MaSo;
	const_cast <int&> (_MaSo);
	_CanNang = d._CanNang;
	_Tuoi = d._Tuoi;
}

De::~De()
{
}

//Operator

 ostream& operator<<(ostream& outDev, const De& d)
{
	 cout << "Ma so: " << d.get_MaSo() << endl;
	 cout << "Can nang: " << d.get_CanNang() << endl;
	 cout << "Tuoi: " << d.get_Tuoi();
	 return outDev; 
}

 De& De::operator=(const De& d)
 {
	 _CanNang = d._CanNang;
	 _Tuoi = d._Tuoi;
	 return *this;
 }

 bool De::CheckProperties()
 {
	 return(_CanNang > 0 && _Tuoi > 0);
 }