#ifndef _ANIMAL_h
#define _ANIMAL_h
#include <iostream>
#include <time.h>
#include <string>

using namespace std;
class CANIMAL
{
protected:
	int _MaSo;
	float _CanNang;
	int _Tuoi; //Tinh theo ngay
	int _TuoiDoi;
	string _TiengKeu;
	int _TrangThai = 1; //-1: chet // 0: dang doi // 1:con song
	float _MucDoNo = 0.5;
	float _X;
	float _Y;
public:
	CANIMAL();
	CANIMAL(int MaSo, float CanNang, int Tuoi,float X, float Y, float MucDoNo);
	CANIMAL(const CANIMAL&);
	~CANIMAL();

	//operator
	//getter
	int get_MaSo() const{ return _MaSo; };
	float get_CanNang() const{ return _CanNang; };
	int get_Tuoi() const{ return _Tuoi; };
	int get_TuoiDoi() const { return _TuoiDoi; };
	string get_TiengKeu() const { return _TiengKeu; };
	int get_TrangThai() const { return _TrangThai; };
	float get_MucDoNo() const { return _MucDoNo; };
	float get_X() const { return _X; };
	float get_Y() const { return _Y; };
	
	//setter
	void set_CanNang(float CanNang){ _CanNang = CanNang; };
	void set_Tuoi(int Tuoi){ _Tuoi = Tuoi; };
	void set_TrangThai(int status){ _TrangThai = status; };
	void set_MucDoNo(float MucDoNo){ _MucDoNo = MucDoNo; };
	void set_X(float x){ _X = x; };
	void set_Y(float y){ _Y = y; };


	friend istream& operator>>(istream& inDev, CANIMAL& a);
	friend ostream& operator<<(ostream& outDev, const CANIMAL& a);

	virtual void Eat(float food) = 0;
	virtual void UpdateStatus(int time) = 0;
	virtual void Move(float x, float y) = 0;
};

#endif