#include "ANIMAL.h"


CANIMAL::CANIMAL()
{
	_MaSo = 0;
	_CanNang = 0;
	_Tuoi = 0;
	_TuoiDoi = 0;
	_TiengKeu = "default";
	_X = 0;
	_Y = 0;
}

CANIMAL::CANIMAL(int MaSo, float CanNang, int Tuoi, float X, float Y, float MucDoNo)
{
	_MaSo = MaSo;
	_CanNang = CanNang;
	_Tuoi = Tuoi;
	_X = X;
	_Y = Y;
	_MucDoNo = MucDoNo;
}

CANIMAL::CANIMAL(const CANIMAL& a)
{
	_MaSo = a.get_MaSo();
	_CanNang = a.get_CanNang();
	_Tuoi = a.get_Tuoi();
	_TuoiDoi = a.get_TuoiDoi();
	_TrangThai = a.get_TrangThai();
	_MucDoNo = a.get_MucDoNo();
	_X = a.get_X();
	_Y = a.get_Y();
}

CANIMAL::~CANIMAL()
{
}


istream& operator>>(istream& inDev, CANIMAL& a)
{
	cout << "Ma so:";
	inDev >> a._MaSo;

	cout << "Can nang:";
	inDev >> a._CanNang;

	cout << "Tuoi:";
	inDev >> a._Tuoi;

	cout << "Toa do:";
	inDev >> a._X >> a._Y;
	return inDev;
}

ostream& operator<<(ostream& outDev, const CANIMAL& a)
{
	if (a._TiengKeu == "Kuc-Tac")
		outDev << "Ga" << endl;
	else if (a._TiengKeu == "Booo")
		outDev << "Bo" << endl;
	else if (a._TiengKeu == "Eccc")
		outDev << "Heo" << endl;
	else
		outDev << "Cuu" << endl;

	outDev << "Ma so:" << a._MaSo << endl;
	outDev << "Can nang:" << a._CanNang << endl;
	outDev << "Tuoi:" << a._Tuoi << " ngay" << endl;
	outDev << "Tuoi doi:" << a._TuoiDoi << " ngay" << endl;
	outDev << "Muc do no:" << a._MucDoNo << endl;
	if (a._TrangThai == 0)
		outDev << "Trang thai:Dang doi" << endl;
	else if (a._TrangThai == -1)
		outDev << "Trang thai:Chet" << endl;
	else
		outDev << "Trang thai:Dang no" << endl;

	outDev << "Toa do:(" << a._X << "," << a._Y << ")";

	return outDev;
}