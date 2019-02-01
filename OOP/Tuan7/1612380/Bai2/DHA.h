#ifndef _DHA_h
#define _DHA_h

#include "CQ.h"
#include "TT.h"
#include <vector>

class CDHA
{
	vector <CSINHVIEN*> _sv;
public:
	//contructor & destructor
	CDHA();
	CDHA(CSINHVIEN*);
	CDHA(const CDHA&);
	~CDHA();

	//getter & setter
	vector <CSINHVIEN*> get_SV() const { return _sv; }
	void set_SV(vector <CSINHVIEN*> sv){ _sv = sv; }

	//operator

	CSINHVIEN* createSV(string type);
	void Input(istream& is);
	void Output(ostream& os);
	int TotalGraduation();
};

#endif
