#include <conio.h>
#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct NODE* Ref;
struct NODE
{
	void* key;
	Ref next;
};

struct Fraction
{
	int numerator;
	int denominator;
};

struct Complex
{
	int real;
	int imaUnit;
};

Ref getNode(void* k, int iSize); //Tao mot node

int Length(Ref head); //Dem so luong phan tu

Ref findList(Ref head, void* dat, bool(*cmp)(void*, void*));//Tim kiem phan tu trong danh sach

bool fracCmp(void* p, void* q); //Ham so sanh 2 truong key phan so
bool intCmp(void* p, void* q); //Ham so sanh 2 truong key so nguyen
bool douCmp(void* p, void* q); ///ham so sanh 2 truong key so thuc
bool plexCmp(void* p, void* q); //Ham so sanh 2 truong key so phuc

void PrintList(Ref head, void(*Print)(Ref)); //In ra danh sach
void PrintFrac(Ref p); //Ham in ra phan tu phan so
void PrintInt(Ref p); //Ham in ra phan tu so nguyen
void PrintDou(Ref p);//Ham in ra phan tu so thuc
void PrintPlex(Ref p); //Ham in ra phan tu so phuc

void AddFirst(Ref& head, Ref& tail, void* k, int iSize); //Chen 1 phan tu vao dau danh sach
void AddLast(Ref& head, Ref& tail, void* k, int iSize); //Chen 1 phan tu vao cuoi danh sach
Ref InsertAfter(Ref& head, void* X, void* Val, int iSize, bool(*cmp)(void*, void*)); //Chen 1 phan tu co gia tri Val vao sau phan tu co gia tri X
Ref InsertBefore(Ref& head, Ref& tail, void* X, void* Val, int iSize, bool(*cmp)(void*, void*));//Chen 1 phan tu co gia tri Val vao truoc phan tu co gia tri X
void InsertAt(Ref& head, Ref& tail, void* X, void* Val, int iSize, bool(*cmp)(void*, void*)); //Chen 1 phan tu tai vi tri bat ki

void DestroyList(Ref& head, Ref& tail); //Xoa danh sach
void DeleteBeg(Ref& head, Ref& tail); //Xoa phan tu dau tien trong danh sach
void DeleteEnd(Ref& head, Ref& tail); //Xoa phan tu cuoi cung trong danh sach
void DeleteMid(Ref p, Ref& tail, int iSize); //Xoa phan tu giua danh sach
void DeleteAt(Ref& head, Ref& tail, void* X, int iSize, bool(*cmp)(void*, void*)); //Xoa 1 phan tu tai vi tri bat ki







