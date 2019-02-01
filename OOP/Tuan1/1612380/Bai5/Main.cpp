#include "CRand.h"

void main()
{
	CRand rand;
	rand.initSeed();
	cout << rand.RandInt(5) << endl;
	cout << rand.RandInt(11, 20) << endl;
	cout << rand.RandFloat() << endl;
	_getch();
}