#include "CVEHICLE.h"
#ifndef _CTRUCK_h
#define _CTRUCK_h
class CTRUCK : public CVEHICLE {
public:
	CTRUCK();
	CTRUCK(int, int);
	CTRUCK(const CTRUCK&);
	~CTRUCK();

	CTRUCK* getList(){return this;};
	void drawObj();
	void deleteObj();
	void tell();
};
#endif