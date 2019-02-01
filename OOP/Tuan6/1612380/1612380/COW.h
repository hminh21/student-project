#ifndef _CCOW_h
#define _CCOW_h

#include "ANIMAL.h"
class CCOW:public CANIMAL
{
public:
	CCOW() :CANIMAL()
	{
		_TiengKeu = "Booo";
		RandTuoiDoi();
	}

	CCOW(int MaSo, float CanNang, int Tuoi, float X, float Y, float MucDoNo) : CANIMAL(MaSo, CanNang, Tuoi, X, Y, MucDoNo)
	{
		_TiengKeu = "Booo";
		RandTuoiDoi();
	};
	CCOW(const CCOW& c) :CANIMAL(c){}
	~CCOW();

	//operator
	int RandTuoiDoi();
	void Eat(float food);
	void UpdateStatus(int time);
	void Move(float x, float y);
};
#endif

