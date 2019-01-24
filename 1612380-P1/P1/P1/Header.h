#include <conio.h> //1612380
#include <iostream>
#include <string>
#include <fstream>
#include <malloc.h>

using namespace std;

unsigned int HashP(const char* P); //Tinh hash P

unsigned int HashT(const char* T, int pos, int num); //Tinh hash T

unsigned int HashTi(const char* T, int pos, int OldHashT, int num); //Tinh hashT[i]

bool Compare(const char* P, const char* T, int pos, int &k); //So sanh ki tu cua 2 chuoi

int RabinKrap(const char* P, const char* T, int &k); //Ham tra ve vi tri tim duoc 

void ReadFile(char* filenameP, char* filenameT, char** &P, char* &T, int &P_Num); //Doc file

void CharPushBack(char* &a, int& n, char ch); //Ghi vao mang ki tu

void WriteFile(char* filename, char** P, char* T, int P_Num); //Ghi file

void initNEXT_KMP(const char* p, int* NEXT); //Tao bang next

int KMP(const char* P, const char* T, int* &NEXT); //Ham tra ve vi tri tim duoc