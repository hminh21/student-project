#include "SINHVIEN.h"


CSINHVIEN::CSINHVIEN()
{
	_Name = "default";
	_Age = 0;
	_MSSV = "0000000";
	_newSubject = 0;
	_retestSubject = 0;
	_restudySubject = 0;
}

CSINHVIEN::CSINHVIEN(string name,unsigned short age, string mssv, short newSubject, short retestSubject, short restudySubject)
{
	_Name = name;
	age = _Age;
	_MSSV = mssv;
	_newSubject = newSubject;
	_retestSubject = retestSubject;
	_restudySubject = restudySubject;
}

CSINHVIEN::CSINHVIEN(const CSINHVIEN& s)
{
	_Name = s._Name;
	_Age = s._Age;
	_MSSV = s._MSSV;
	_newSubject = s._newSubject;
	_retestSubject = s._retestSubject;
	_restudySubject = s._restudySubject;
}


istream& operator>>(istream& inDev, CSINHVIEN& s)
{
	string str;
	
	cout << "Ho ten:";
	getline(inDev, str);
	s._Name = str;

	
	cout << "Tuoi:";
	inDev >> s._Age;
	

	cout << "MSSV:";
	inDev.ignore();
	getline(inDev, str);
	s._MSSV = str;


	cout << "So luong mon moi dang ki:";
	inDev >> s._newSubject;

	cout << "So luong mon thi lai:";
	inDev >> s._retestSubject;

	cout << "So luong mon hoc lai:";
	inDev >> s._restudySubject;
	return inDev;
}

ostream& operator<<(ostream& outDev, CSINHVIEN& s)
{
	outDev << "Ho ten:" << s._Name << endl;
	outDev << "Tuoi:" << s._Age << endl;
	outDev << "MSSV:" << s._MSSV << endl;
	outDev << "So luong mon moi dang ki:" << s._newSubject << endl;
	outDev << "So luong mon thi lai:" << s._retestSubject << endl;
	outDev << "So luong mon hoc lai:" << s._restudySubject << endl;
	outDev << "Hoc phi:" << s.calcTuitionFee();
	return outDev;
}

void CSINHVIEN::Input(istream& is)
{
	is >> *this;
}

