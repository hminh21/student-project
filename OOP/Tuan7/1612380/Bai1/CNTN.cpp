#include "CNTN.h"


int CCNTN::calcTuitionFee()
{
	if (_newSubject + _restudySubject < 5)
		return -1;
	int iFee = 500000 + _newSubject * 200000 + _retestSubject * 50000 + _restudySubject * 100000;
	return iFee;
}

void CCNTN::Output(ostream& os)
{
	os << "He: CNTN" << endl;
	os << *this;
}