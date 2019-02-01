//File: CRand.cpp

#include "CRand.h"

void CRand::initSeed() //Khoi tao
{
	srand((unsigned)time(0));
}

int CRand::RandInt(int n) //Phat sinh ngau nhien so nguyen trong doan [0;n]
{
	return rand() % (n - 0 + 1) + 0; 
}

int CRand::RandInt(int a, int b) //Phat sinh ngau nhien so nguyen trong doan [a;b]
{
	return rand() % (b - a + 1) + a;
}

float CRand::RandFloat() //Phat sinh ngau nhien so thuc trong doan [0;1]
{ 
	return float(rand()) / (float)(RAND_MAX); // (1.0 - 0)*rand()/RAND_MAX + 0
}
