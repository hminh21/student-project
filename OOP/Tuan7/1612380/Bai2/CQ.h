#ifndef _CQ_h
#define _CQ_h

#include "SINHVIEN.h"

class CCQ : public CSINHVIEN
{
public:
	//constructor & destructor
	CCQ() :CSINHVIEN(){};
	CCQ(string name, string mssv, DATE date, float score) :CSINHVIEN(name, mssv, date, score){};
	CCQ(const CCQ& c) : CSINHVIEN(c){};
	~CCQ();

	//getter & setter
	int get_iBT(){ return -1; };
	void set_iBT(int iBT){};

	void Output(ostream&);
	string Result();
	string get_Class()
	{
		return "CCQ";
	}
};

#endif
