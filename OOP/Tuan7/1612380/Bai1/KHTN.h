#ifndef _KHTN_h
#define _KHTN_h

#include "CNTN.h"
#include "CTTT.h"
#include <vector>


class CKHTN
{
	vector <CSINHVIEN*> _sv;
public:
	//constructor & destructor
	CKHTN();
	CKHTN(CSINHVIEN*);
	CKHTN(const CKHTN&);
	~CKHTN();

	//getter & setter
	vector <CSINHVIEN*> get_SV()const{ return _sv; }
	void set_SV(vector <CSINHVIEN*> sv){ _sv = sv; }

	//operator
	CSINHVIEN* createSV(string type);
	void Input(istream&);
	void Output(ostream&);
	int TotalTuitionFee();
};

#endif
