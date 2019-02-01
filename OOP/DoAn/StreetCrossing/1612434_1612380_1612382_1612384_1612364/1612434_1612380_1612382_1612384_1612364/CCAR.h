#include "CVEHICLE.h"
#ifndef _CCAR_h
#define _CCAR_h
class CVEHICLE;
class CCAR : public CVEHICLE {
public:
	CCAR();
	CCAR(int, int); //constructor
	CCAR(const CCAR&); //copy constructor
	~CCAR();

	CCAR* getList() { return this; };
	void drawObj();
	void deleteObj();
	void tell();
};

#endif