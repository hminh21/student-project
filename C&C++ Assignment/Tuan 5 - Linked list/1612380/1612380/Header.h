#include <malloc.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



struct FRACTION
{
	int numerator;
	int denominator;
};

typedef struct node* ref;
struct node
{
	FRACTION fr;
	ref next;
};

ref getNode(FRACTION fr); //Tao mot phan so
void AddFirst(ref& head, ref& tail, FRACTION fr); //Chen phan so vao dau danh sach
void InputFractionList(ref& head, ref& tail, FRACTION &fr); //Xay dung danh sach phan so
void PrintList(ref head, ref tail, FRACTION fr); //In danh sach phan so
void AddLast(ref& head, ref& tail, FRACTION fr); //Chen phan so vao cuoi danh sach
int Length(ref head); //Dem so phan tu
void InsertBefore(ref p, FRACTION fr); //Chen phan tu vao truoc pos
void InsertAt(ref& head, ref& tail, FRACTION fr, int pos); //Chen 1 phan so tai pos
void DeleleBeg(ref& head, ref& tail); //Xoa phan tu dau danh sach
void DeleteEnd(ref& head, ref& tail); //Xoa phan tu cuoi danh sach
void DeleteMid(ref p); //Xoa phan tu giua danh sach
void DeleteAt(ref& head, ref& tail, int pos); //Xoa phan tu tai pos
void DeleteAll(ref& head); //Huy toan bo danh sach
