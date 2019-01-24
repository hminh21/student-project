#include "Header.h"

void main()
{
	int ArrA[] = { 3, 4, 2, 5, -1, 6, -3, 1 }, nA = 8;
	SortArrDescending(ArrA, nA);
	PrintIntArr(ArrA, nA);
	int ArrB[] = { 3, 4, 2, 5, -1, 6, -3, 1 }, nB = 8;
	SortEvenDescending(ArrB, nB);
	PrintIntArr(ArrB, nB);
	float ArrC[] = { 4.1, 0, -1.5, -4.3, 5.5, -2, 3.2, -3 }; int nC = 8;
	SortArr(ArrC, nC);
	PrintFloatArr(ArrC, nC);
	int ArrD[] = { 2, 0, 9, 11, 5, 3, 1, 7 }, nD = 8;
	SortPrimeAscending(ArrD, nD);
	PrintIntArr(ArrD, nD);
	int ArrE[] = { 3, 4, 2, 5, -1, 6,2, 7, 0, -3, 1}, nE = 11;
	SortEvenAndOdd(ArrE, nE);
	PrintIntArr(ArrE, nE);
	float ArrF[] = { 4.1, 3.2, -1.5, -4.3, 5.5, -2, 0, -3 }; int nF = 8;
	SortFloatAscending(ArrF, nF);
	PrintFloatArr(ArrF, nF);
	_getch();
}