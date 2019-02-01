#ifndef _CBIRD_h
#define _CBIRD_h
#include "CANIMAL.h"
class CBIRD :public CANIMAL
{
public:
	CBIRD(); //default constructor
	CBIRD(int, int); //constructor
	CBIRD(const CBIRD&); //copy constructor
	~CBIRD(); //destructor

	void drawObj();
	void deleteObj();
	CBIRD* getList(){ return this; };
	void tell();
};
#endif