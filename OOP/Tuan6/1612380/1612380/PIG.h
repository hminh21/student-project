#ifndef _CPIG_h
#define _CPIG_h

#include "ANIMAL.h"
class CPIG:public CANIMAL
{
public:
	CPIG() :CANIMAL()
	{
		_TiengKeu = "Eccc";
		RandTuoiDoi();
	}
	CPIG(int MaSo, float CanNang, int Tuoi, float X, float Y, float MucDoNo) : CANIMAL(MaSo, CanNang, Tuoi, X, Y, MucDoNo)
	{
		_TiengKeu = "Eccc";
		RandTuoiDoi();
	};
	CPIG(const CPIG& p) :CANIMAL(p){}
	~CPIG();

	//operator
	int RandTuoiDoi();
	void Eat(float food);
	void UpdateStatus(int time);
	void Move(float x, float y);
};
#endif
