#include "Header.h"

int main()
{
	FRACTION fr;
	ref head = NULL, tail = NULL;
	printf("----------Cau 1----------\n");
	InputFractionList(head, tail, fr);
	printf("----------Cau 2----------\n");
	PrintList(head, tail, fr);
	printf("----------Cau 3----------\n");
	printf("Nhap mot phan so chen vao cuoi danh sach:\n");
	scanf("%i%i", &fr.numerator, &fr.denominator);
	AddLast(head, tail, fr);
	PrintList(head, tail, fr);
	printf("----------Cau 4----------\n");
	printf("Nhap mot phan so can chen:\n");
	scanf("%i%i", &fr.numerator, &fr.denominator);
	int iPos;
	printf("Nhap vi tri can chen (vi tri dau tien = 0): ");
	scanf("%i", &iPos);
	InsertAt(head, tail, fr, iPos);
	PrintList(head, tail, fr);
	printf("----------Cau 5----------\n");
	printf("Nhap vi tri can xoa (vi tri dau tien = 0): ");
	scanf("%i", &iPos);
	DeleteAt(head, tail, iPos);
	PrintList(head, tail, fr);
	printf("----------Cau 6----------\n");
	DeleteAll(head);
	PrintList(head, tail, fr);
	getch();
}