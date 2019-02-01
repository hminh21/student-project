#ifndef _CDINOSAUR_h
#define _CDINOSAUR_h

#include "CANIMAL.h"
class CANIMAL;
class CDINOSAUR :public CANIMAL
{
public:
	CDINOSAUR(); //default constructor
	CDINOSAUR(int, int); //constructor
	CDINOSAUR(const CDINOSAUR&); //copy constructor
	~CDINOSAUR(); //destructor

	CDINOSAUR* getList(){ return this; };
	void drawObj();
	void deleteObj();
	void tell();
};
#endif