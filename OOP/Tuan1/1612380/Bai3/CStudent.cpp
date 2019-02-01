//File: CSudent.cpp

#include "CStudent.h"

istream& operator>>(istream& inDev, CStudent& Stu)
{
	char cName[30];
	float fLite, fMath;
	inDev.getline(cName,29);
	inDev >> fLite >> fMath;
	Stu.init(cName, fLite, fMath);
	return inDev;
}

ostream& operator<<(ostream& outDev, CStudent& Stu)
{
	outDev << Stu.cName << setw(34 - strlen(Stu.GetName())) << Stu.fLite << setw(5) << Stu.fMath << setw(15) << Stu.Rank();
	return outDev;
}

void CStudent::init(char name[], float lite, float math) //Khoi tao
{
	strcpy(cName, name);
	fLite = lite;
	fMath = math;
}

void CStudent::Set(char name[]) //Gan ten
{
	for (int i = 0; cName[i] != '\0'; i++) //Xoa chuoi ten
		cName[i] = NULL;
	strcpy(cName, name);
}

void CStudent::Set(float lite, float math)
{
	if (lite >= 0 && lite <= 10 && math >= 0 && math <= 10)
	{
		fLite = lite;
		fMath = math;
	}
}

char* CStudent::GetName() //Lay ten
{
	return cName;
}

float CStudent::GetLite() //Lay diem Van
{
	return fLite;
}

float CStudent::GetMath() //Lay diem Toan
{
	return fMath;
}

float CStudent::CalcAverage() //Tinh diem trung binh
{
	return (fLite + fMath) / 2;
}

char* CStudent::Rank() //Xep loai
{
	float Average = CalcAverage();
	if (Average >= 9)
		return "Xuat Sac";
	else
	if (Average >= 8)
		return "Gioi";
	else
	if (Average >= 6.5)
		return "Kha";
	else
	if (Average >= 5.0)
		return "Trung Binh";
	return "Yeu";
}