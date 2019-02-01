#ifndef _SHEEP_h
#define _SHEEP_h

#include "ANIMAL.h"
class CSHEEP :public  CANIMAL
{
	
public:
	CSHEEP() :CANIMAL()
	{
		_TiengKeu = "Beee";
		RandTuoiDoi();
	}
	CSHEEP(int MaSo, float CanNang, int Tuoi, float X, float Y, float MucDoNo) : CANIMAL(MaSo, CanNang, Tuoi, X, Y, MucDoNo)
	{
		_TiengKeu = "Beee";
		RandTuoiDoi();
	};
	CSHEEP(const CSHEEP& s) :CANIMAL(s){};
	~CSHEEP();

	//operator
	int RandTuoiDoi();
	void Eat(float food);
	void UpdateStatus(int time);
	void Move(float x, float y);
};

#endif
