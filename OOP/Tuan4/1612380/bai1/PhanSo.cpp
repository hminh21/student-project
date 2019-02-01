#include "PhanSo.h"
#include <sstream>

PhanSo::PhanSo()
{
	mTuSo = 0;
	mMauSo = 1;
}

PhanSo::PhanSo(int tuso, int mauso)
{
	mTuSo = tuso;
	mMauSo = mauso;
}

PhanSo::PhanSo(const PhanSo& ps)
{
	mTuSo = ps.mTuSo;
	mMauSo = ps.mMauSo;
}

string PhanSo::ToString()
{
	stringstream ss;
	ss << mTuSo << "/" << mMauSo;
	return ss.str();

}

bool PhanSo::operator>(const PhanSo& ps)
{
	float ps1 = float(mTuSo) / mMauSo;
	float ps2 = float(ps.mTuSo) / ps.mMauSo;
	return (ps1 > ps2);
}

PhanSo PhanSo::operator+(const PhanSo& ps)
{
	PhanSo p;
	p.mTuSo = mTuSo*ps.mMauSo + ps.mTuSo*mMauSo;
	p.mMauSo = mMauSo*ps.mMauSo;
	return p;
}

PhanSo PhanSo::operator*(const PhanSo& ps)
{
	PhanSo p;
	p.mTuSo = mTuSo*ps.mTuSo;
	p.mMauSo = mMauSo*ps.mMauSo;
	return p;
}

PhanSo& PhanSo::operator~()
{
	int ucln = UCLN(*this);
	mTuSo = mTuSo / ucln;
	mMauSo = mMauSo / ucln;
	return *this;
}

int UCLN(PhanSo ps)
{
	int tu = abs(ps.GetTuSo());
	int mau = abs(ps.GetMauSo());
	while (tu != mau)
	{
		if (tu > mau)
			tu -= mau;
		else
			mau -= tu;
	}
	return tu;
}

PhanSo findMax(vector<PhanSo> ps)
{
	PhanSo psMax = ps[0];
	for (int i = 1; i < ps.size(); i++)
	{
		if (ps[i] > psMax)
			psMax = ps[i];
	}
	return psMax;
}

PhanSo findMin(vector<PhanSo> ps)
{
	PhanSo psMin = ps[0];
	for (int i = 1; i < ps.size(); i++)
	{
		if (psMin > ps[i])
			psMin = ps[i];
	}
	return psMin;
}

PhanSo TongPS(vector<PhanSo> ps)
{
	PhanSo p;
	for (int i = 0; i < ps.size(); i++)
		p = p + ps[i];
	return p;
}

PhanSo TichPS(vector<PhanSo> ps)
{
	PhanSo p = ps[0];
	for (int i = 1; i < ps.size(); i++)
		p = p * ps[i];
	return p;
}


