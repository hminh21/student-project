#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define max 127

struct FRACTION
{
	int numerator;
	int denominator;
};

istream& operator>>(istream& inDev, FRACTION& fr); //qua tai toan tu

ostream& operator<<(ostream& outDev, FRACTION& fr); //qua tai toan tu

void ReplaceChar(char oldChar, char newChar, fstream &fs); //thay doi ki tu

int CopyFile(string fileName1, string fileName2); //copy file 2 vao file 1

FRACTION* ReadArrayFraction(istream& inDev, int &n);//doc mang phan so tu file

void Swap(FRACTION &fr1, FRACTION &fr2); //Hoan doi vi tri

void SortFraction(FRACTION *& fr, int n);//sap xep mang phan so tang dan

void WriteArrayFraction(ostream& outDev, FRACTION* fr, int n); //ghi du lieu vao file

void ReadAndWrite(istream& inDev); //Doc va ghi du lieu

void Statistic(istream& inDev); //Thong ke file
