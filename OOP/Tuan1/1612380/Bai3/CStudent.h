//File: CStudent.h

#ifndef _CSTUDENT_H
#define _CSTUDENT_H

#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;

class CStudent
{
	char cName[30];
	float fLite;
	float fMath;
public:
	friend istream& operator>>(istream& inDev, CStudent& Stu);
	friend ostream& operator<<(ostream& outDev,  CStudent& Stu);
	void init(char[], float, float);
	void Set(char[]);
	void Set(float, float);
	char* GetName();
	float GetLite();
	float GetMath();
	float CalcAverage();
	char* Rank();
};

#endif
