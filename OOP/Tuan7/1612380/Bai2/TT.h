#ifndef _TT_h
#define _TT_h

#include "SINHVIEN.h"
class CTT : public CSINHVIEN
{
	int	_iBT;
public:
	//constructor & destructor
	CTT() :CSINHVIEN(){ _iBT = 0; };
	CTT(string name, string mssv, DATE date, float score, int iBt) :CSINHVIEN(name, mssv, date, score)
	{
		_iBT = iBt;
	};
	CTT(const CTT& c) : CSINHVIEN(c){ _iBT = c._iBT; };
	~CTT()
	{
		_iBT = 0;
	}

	//getter & setter
	int get_iBT(){ return _iBT; };
	void set_iBT(int iBT){ _iBT = iBT; };

	//operator
	void Output(ostream&);
	string Result();
	string get_Class()
	{
		return "CTT";
	}
};

#endif