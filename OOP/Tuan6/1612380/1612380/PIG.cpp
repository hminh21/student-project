#include "PIG.h"

int CPIG::RandTuoiDoi()
{
	_TuoiDoi = rand() % ((10 - 5 + 1) * 365) + 5 * 365;
	return _TuoiDoi;
}

void CPIG::Eat(float food)
{
	_MucDoNo = _MucDoNo + 0.3 * food; //Tang muc do no
	if (_MucDoNo >= 1)
	{
		_MucDoNo = 1; //max la 100%
		float Delta = (2.0 - 1.0)*rand() / RAND_MAX + 1.0; //random do tang can nang
		_CanNang += Delta;
	}
}

void CPIG::UpdateStatus(int time)
{
	_MucDoNo -= 0.07 / 8 * time; //Sau "time" thi muc do no se giam
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

void CPIG::Move(float x, float y)
{
	float dx = abs(x - _X);
	float dy = abs(y - _Y);
	float kc = sqrt(dx*dx + dy*dy);
	_MucDoNo -= kc * 0.07; //Di chuyen thi muc do no giam

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