
#ifndef _SINHVIEN_h
#define _SINHVIEN_h
#include <iostream>
#include <string>

using namespace std;
class CSINHVIEN
{
protected:
	string _Name;
	unsigned short _Age;
	string _MSSV;
	short _newSubject;
	short _retestSubject;
	short _restudySubject;

public:
	CSINHVIEN();
	CSINHVIEN(string,unsigned short, string, short, short, short);
	CSINHVIEN(const CSINHVIEN&);
	~CSINHVIEN(){};

	//getter
	string get_Name()const { return _Name; }
	unsigned short get_Age() const { return _Age; }
	string get_MSSV() const { return _MSSV; }
	short get_newSubject() const{ return _newSubject; }
	short get_retestSubject() const { return _retestSubject; }
	short get_restudySubject() const { return _restudySubject; }

	//setter
	void set_Name(string name){ _Name = name; }
	void set_Age(unsigned short age){ _Age = age; }
	void set_MSSV(string mssv){ _MSSV = mssv; }
	void set_newSubject(short newSubject){ _newSubject = newSubject; }
	void set_retestSubject(short retestSubject){ _retestSubject = retestSubject; }
	void set_restudySubject(short restudySubject){ _restudySubject = restudySubject; }

	//operator
	void Input(istream&);
	virtual void Output(ostream& os) = 0;
	virtual int calcTuitionFee()= 0;
	virtual string get_class() = 0;
	friend istream& operator>>(istream& inDev, CSINHVIEN&);
	friend ostream& operator<<(ostream& outDev, CSINHVIEN&);

};

#endif