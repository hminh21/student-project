#include "Lop.h"
#include "SinhVien.h"

CLop::CLop()
{
	_TenLop = "default";
	_Siso = 0;
}

CLop::CLop(const CLop& c)
{
	if (c._Sv.empty())
		return;
	for (int i = 0; i < c._Siso; i++)
		_Sv.push_back(c._Sv[i]);
	_Siso = c._Siso;
}

CLop::~CLop()
{
	_Sv.clear();
	_Siso = 0;
}

bool CLop::operator>(const CLop& c)
{
	return(_Siso > c._Siso);
}

istream& operator>>(istream& inDev, CLop&c)
{
	string str,temp;
	SinhVien sv;
	int cur = 0;
	getline(inDev,str);
	if (str == "") return inDev;
	c.set_TenLop(str);
	getline(inDev,str);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ':')
		{
			for (int j = i + 1; j < str.size(); j++)
				temp[cur++] = str[j];
			break;
		}
	}
	c.set_SiSo(atoi(temp.c_str()));


	for (int i = 0; i < c.get_Siso(); i++)
	{
		inDev >> sv;
		c._Sv.push_back(sv);
	}

	return inDev;
}

ostream& operator<<(ostream& outDev, const CLop& c)
{
	outDev << "Lop " << c._TenLop << endl;
	outDev << "Si so:   " << c._Siso << endl;
	for (int i = 0; i < c._Siso; i++)
		outDev << c._Sv[i] << endl;
	return outDev;
}
