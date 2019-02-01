#ifndef _CHILD_h
#define _CHILD_h

#include "MEMBER.h"
class CHILD : public MEMBER
{
public:
	CHILD() : MEMBER(){};
	CHILD(string name, bool isMale, DATE date, string ID, unsigned int bookBorrow) :MEMBER(name, isMale, date, ID, bookBorrow){};
	CHILD(const MEMBER& c) :MEMBER(c){};
	~CHILD();

	string getClass(){ return "CHILD"; }
	unsigned long MoneyLoan(){ return 2000 * _bookBorrow; }
};

#endif