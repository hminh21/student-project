#ifndef _CHICKEN_h
#define _CCHICKEN_h

#include "ANIMAL.h"
class CCHICKEN : public CANIMAL
{
public:
	CCHICKEN() :CANIMAL()
	{
		_TiengKeu = "Kuc-Tac";
		RandTuoiDoi();
	}

	CCHICKEN(int MaSo, float CanNang, int Tuoi, float X, float Y, float MucDoNo) : CANIMAL(MaSo, CanNang, Tuoi, X, Y, MucDoNo)
	{
		_TiengKeu = "Kuc-Tac";
		RandTuoiDoi(); 
	};
	CCHICKEN(const CCHICKEN& c) :CANIMAL(c){}
	~CCHICKEN();

	//operator
	int RandTuoiDoi();
	 void Eat(float food);
	 void UpdateStatus(int time);
	 void Move(float x, float y);
};

#endif

