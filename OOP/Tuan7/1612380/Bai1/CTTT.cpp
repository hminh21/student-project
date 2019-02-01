#include "CTTT.h"

int CCTTT::calcTuitionFee()
{
	if (_newSubject + _restudySubject < 3)
		return -1;
	int iFee = 10000000 + 1000000 * _newSubject + 100000 * _retestSubject + 500000 * _restudySubject;
	return iFee;
}

void CCTTT::Output(ostream& os)
{
	os << "He: CTTT" << endl;
	os << *this;
}