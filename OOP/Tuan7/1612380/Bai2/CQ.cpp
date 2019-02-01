#include "CQ.h"

void CCQ::Output(ostream& os)
{
	os << "He: Chinh quy" << endl;
	os << *this << endl;
}

string CCQ::Result()
{
	if (_Score >= 5)
		return "Dau TN";
	return "Rot TN";
}