#include "SINHVIEN.h"


CSINHVIEN::CSINHVIEN()
{
	_Name = "default";
	_MSSV = "0";
	_Date.day = 0;
	_Date.month = 0;
	_Date.year = 0;
	_Score = 0;
}


CSINHVIEN::CSINHVIEN(string name, string mssv, DATE date, float score)
{
	_Name = name;
	_MSSV = mssv;
	_Date.day = date.day;
	_Date.month = date.month;
	_Date.year = date.year;
	_Score = score;
}

CSINHVIEN::~CSINHVIEN()
{
	_Name = "";
	_MSSV = "";
	_Date.day = 0;
	_Date.month = 0;
	_Date.year = 0;
	_Score = 0;
}


CSINHVIEN::CSINHVIEN(const CSINHVIEN& sv)
{
	_Name = sv._Name;
	_MSSV = sv._MSSV;
	_Date.day = sv._Date.day;
	_Date.month = sv._Date.month;
	_Date.year = sv._Date.year;
	_Score = sv._Score;
}

istream& operator>>(istream& inDev, CSINHVIEN& sv)
{
	string str;

	cout << "Ho ten:";
	getline(inDev, str);
	sv._Name = str;

	cout << "MSSV:";
	getline(inDev, str);
	sv._MSSV = str;

	cout << "Ngay sinh(x/y/zzzz):";
	inDev >> sv._Date;

	cout << "DTB:";
	inDev >> sv._Score;

	if (sv.get_Class() == "CTT") //Neu sinh vien do thuoc he tien tien thi co them diem iBT
	{
		cout << "iBT:";
		int x;
		inDev >> x;
		sv.set_iBT(x);
	}
	return inDev;

}

ostream& operator<<(ostream& outDev, CSINHVIEN& sv)
{
	outDev << "Ho ten:" << sv._Name << endl;
	outDev << "MSSV:" << sv._MSSV << endl;
	outDev << "Ngay sinh:" << sv._Date << endl;
	outDev << "DTB:" << sv._Score << endl;
	if (sv.get_Class() == "CTT")  //Neu sinh vien do thuoc he tien tien thi co them diem iBT
		outDev << "iBT:" << sv.get_iBT() << endl;
	outDev << "Ket qua:" << sv.Result();
	return outDev;
}

void CSINHVIEN::Input(istream& is)
{
	is >> *this;
}

istream& operator>>(istream& inDev, DATE& date)
{
	char ch;
	inDev >> date.day >> ch >> date.month >> ch >> date.year;
	return inDev;
}

ostream& operator<<(ostream& outDev,const DATE& date)
{
	outDev << date.day << "/" << date.month << "/" << date.year;
	return outDev;
}

