#include "TT.h"

void CTT::Output(ostream& os)
{
	os << "He: Tien tien" << endl;
	os << *this << endl;
	os << "iBT:" << _iBT << endl;
}

string CTT::Result()
{
	if (_Score >= 5 && _iBT >= 80)
		return "Dau TN";
	return "Rot TN";
}
