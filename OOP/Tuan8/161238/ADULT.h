#ifndef _ADULT_h
#define _ADULT_h

#include "MEMBER.h"
class ADULT:public MEMBER
{
public:
	ADULT() :MEMBER(){};
	ADULT(string name, bool isMale, DATE date, string ID, unsigned int bookBorrow) :MEMBER(name, isMale, date, ID, bookBorrow){};
	ADULT(const MEMBER& a) :MEMBER(a){};
	~ADULT();

	string getClass(){ return "ADULT"; }
	unsigned long MoneyLoan(){ return 5000 * _bookBorrow; }

};

#endif