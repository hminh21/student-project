 
#ifndef _CNTN_h
#define _CNTN_h

#include "SINHVIEN.h"
class CCNTN : public CSINHVIEN
{
public:
	CCNTN() :CSINHVIEN(){};
	CCNTN(string name, unsigned short age, string mssv, short newSubject, short retestSubject, short restudySubject) :CSINHVIEN(name, age, mssv, newSubject, retestSubject, restudySubject){};
	CCNTN(const CCNTN& c) :CSINHVIEN(c){};
	~CCNTN(){};

	int calcTuitionFee();
	void Output(ostream& os);
	string get_class(){ return "CCNTN"; };
};
#endif