#include "Class.h"
#include "SinhVien.h"

Class::Class()
{
	strcpy(_TenLop, "0");
	_Siso = 0;
}

Class::Class(const Class& c)
{
	if (c._Siso < 0)
		return;
	_Sv = new SinhVien[c._Siso];
	for (int i = 0; i < c._Siso; i++)
		_Sv[i] = c._Sv[i];
	_Siso = c._Siso;
	strcpy(_TenLop, c._TenLop);
}

Class::Class(char tenlop[], SinhVien* sv, unsigned short siso)
{
	strcpy(_TenLop, tenlop);
	_Siso = siso;
	_Sv = new SinhVien[_Siso];
	_Sv = sv;
}

Class::~Class()
{
	if (_Sv != NULL)
	{
		delete[] _Sv;
		_Sv = NULL;
	}
	_Siso = 0;
}

bool Class::operator>(const Class& c)
{
	return(_Siso > c._Siso);
}

Class& Class::operator=(const Class& c)
{
	strcpy(_TenLop, c._TenLop);
	_Siso = c._Siso;
	_Sv = new SinhVien[_Siso];
	for (int i = 0; i < _Siso; i++)
		_Sv[i] = c._Sv[i];
	return *this;
}
istream& operator>>(istream& inDev, Class& c)
{
	char* token;
	char* str = new char[256];

	inDev.getline(str, 256);
	token = strtok(str, "\n");
	if (token == NULL) return inDev;
	strcpy(c._TenLop, token);

	inDev.getline(str, 256);
	token = strtok(str, ":");
	token = strtok(NULL, "\n");
	c._Siso = atoi(token);

	c._Sv = new SinhVien[c._Siso];
	for (int i = 0; i < c._Siso; i++)
		inDev >> c._Sv[i];
	return inDev;
}

ostream& operator<<(ostream& outDev,const Class& c)
{
	outDev << "Lop " << c._TenLop << endl;
	outDev << "Si so:   " << c._Siso << endl;
	for (int i = 0; i < c._Siso; i++)
		outDev << c._Sv[i] << endl;
	return outDev;
}
