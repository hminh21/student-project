#ifndef _SINHVIEN_h
#define _SINHVIEN_h

#include <iostream>
#include <string>

using namespace std;

struct DATE{
	short day;
	short month;
	short year;
};
class CSINHVIEN
{
protected:
	string _Name;
	string _MSSV;
	DATE _Date;
	float _Score;
public:
	//constructor & destructor
	CSINHVIEN();
	CSINHVIEN(string, string, DATE, float);
	CSINHVIEN(const CSINHVIEN&);
	~CSINHVIEN();

	//getter
	string get_Name(){ return _Name; }
	string get_MSSV(){ return _MSSV; }
	DATE get_Date(){ return _Date; }
	float get_Score(){ return _Score; }
	virtual int get_iBT() = 0;

	//setter
	void set_Name(string name){ _Name = name; }
	void set_MSSV(string mssv){ _MSSV = mssv; }
	void set_Date(DATE date){ _Date = date; }
	void set_Score(float score){ _Score = score; }
	virtual void set_iBT(int iBT) = 0;

	//operator
	void Input(istream&);
	virtual void Output(ostream&) = 0;
	virtual string Result() = 0;
	virtual string get_Class() = 0;

	friend istream& operator>>(istream& inDev, CSINHVIEN&);
	friend ostream& operator<<(ostream& outDev, CSINHVIEN&);

	friend istream& operator>>(istream& inDev, DATE&);
	friend ostream& operator<<(ostream& outDev, const DATE&);

};

#endif