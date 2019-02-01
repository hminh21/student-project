#ifndef _CTTT_h
#define _CTTT_h

#include "SINHVIEN.h"
class CCTTT: public CSINHVIEN
{
public:
	CCTTT() :CSINHVIEN(){};
	CCTTT(string name, unsigned short age, string mssv, short newSubject, short retestSubject, short restudySubject) :CSINHVIEN(name, age, mssv, newSubject, retestSubject, restudySubject){};
	CCTTT(const CCTTT& c) :CSINHVIEN(c){};
	~CCTTT(){};

	int calcTuitionFee();
	void Output(ostream& os);
	string get_class(){ return "CCTTT"; }
};

#endif