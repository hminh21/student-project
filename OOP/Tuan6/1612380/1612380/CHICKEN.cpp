#include "CHICKEN.h"

int CCHICKEN::RandTuoiDoi()
{
	_TuoiDoi = rand() % ((8 - 7 + 1) * 365) + 7 * 365;
	return _TuoiDoi;
}

void CCHICKEN::Eat(float food)
{
	_MucDoNo = _MucDoNo + 5 * food;//Tang muc do no
	if (_MucDoNo >= 1)
	{
		_MucDoNo = 1;//max la 100%
		float Delta = (0.2 - 0.01)*rand() / RAND_MAX + 0.01;//random do tang can nang
		_CanNang += Delta;
	}
}

void CCHICKEN::UpdateStatus(int time)
{
	_MucDoNo -= 0.1 / 12 * time;//Sau "time" thi muc do no se giam
	if (_MucDoNo < 0)
		_MucDoNo = 0;

	//Cap nhat lai trang thai
	if (_MucDoNo >= 0.5)
		_TrangThai = 1;
	else if (_MucDoNo < 0.5 && _MucDoNo >= 0.1)
		_TrangThai = 0;
	else
		_TrangThai = -1;
}

void CCHICKEN::Move(float x, float y)
{
	float dx = abs(x - _X);
	float dy = abs(y - _Y);
	float kc = sqrt(dx*dx + dy*dy);
	_MucDoNo -= kc * 0.1; //Di chuyen thi muc do no giam

	//Di chuyen den toa do (x, y)
	_X = x;
	_Y = y;

	//min = 0%
	if (_MucDoNo < 0)
		_MucDoNo = 0;

	//Cap nhat trang thai
	if (_MucDoNo >= 0.5)
		_TrangThai = 1;
	else if (_MucDoNo < 0.5 && _MucDoNo >= 0.1)
		_TrangThai = 0;
	else
		_TrangThai = -1;
}