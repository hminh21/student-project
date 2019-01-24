#include "Header.h"

ref getNode(FRACTION fr) //Tao mot phan so
{
	ref p = (ref)malloc(sizeof(node));
	if (p == NULL)
	{
		printf("Khong du bo nho\n");
		exit(0);
	}
	p->fr = fr;
	p->next = NULL;
	return p;
}

void AddFirst(ref& head, ref& tail, FRACTION fr) //Chen phan so vao dau danh sach
{
	ref p = getNode(fr);
	if (head == NULL) //Neu chi co phan tu
	{
		head = tail = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
}

void InputFractionList(ref& head, ref& tail, FRACTION &fr) //Xay dung danh sach phan so
{
	int icount = 1;
	while (1)
	{
		printf("Nhap phan so thu %i (qua trinh nhap se ket thuc khi nhap mau so = 0)\n", icount);
		scanf("%i%i", &fr.numerator, &fr.denominator);
		if (fr.denominator == 0) //dieu kien dung nhap
			break;
		AddFirst(head, tail, fr);
		icount++;
	}
}
 
void PrintList(ref head, ref tail, FRACTION fr) //In danh sach phan so
{
	for (ref p = head; p != NULL; p = p->next)
	{
		if (p->fr.denominator < 0) //dieu chinh lai phan so cho hop logic
		{
			p->fr.numerator = -p->fr.numerator;
			p->fr.denominator = -p->fr.denominator;
		}
			if (p->fr.numerator == 0)
				printf("%i ", 0);
		{
			printf("%i/%i ", p->fr.numerator, p->fr.denominator);
		}
	}
	printf("\n");
}

void AddLast(ref& head, ref& tail, FRACTION fr) //Chen phan so vao cuoi danh sach
{
	ref p = getNode(fr);
	if (head == NULL) //Neu chi co 1 phan tu
	{
		head = tail = p;
	}
	else
	{
		tail->next = p;
		tail = p;
	}
}

int Length(ref head) //Dem so phan tu
{
	int count = 0;
	for (ref p = head; p != NULL; p = p->next)
		count++;
	return count;
}

void InsertBefore(ref p, FRACTION fr)
{
	ref q = getNode(fr);
	*q = *p;
	p->next = q;
	p->fr = fr;
}
	
void InsertAt(ref& head, ref& tail, FRACTION fr, int pos)//Chen 1 phan so tai pos
{
	int i, n = Length(head);
	ref p;
	if (pos < 0 || pos > n)
	{
		printf("Vi tri chen khong hop le\n");
		return;
	}
	if (pos == 0) //Chen vao dau ds
		AddFirst(head, tail, fr);
	else
	{
		if (pos == n) //Chen vao cuoi ds
			AddLast(head, tail, fr);
		else
		{
			for (i = 0, p = head; i < pos; p = p->next, i++);
			InsertBefore(p, fr);
			if (tail->next) //Neu chen vao phan tu ke cuoi thi phai cap nhat lai tail
				tail = tail->next;
		}
	}
}

void DeleleBeg(ref& head, ref& tail) //Xoa phan tu dau danh sach
{
	ref p;
	if (head == tail) //Neu chi co 1 phan tu
	{
		free(head);
		head = tail = NULL;
	}
	else
	{
		p = head;
		head = head->next;
		free(p);
	}
}

void DeleteEnd(ref& head, ref& tail) //Xoa phan tu cuoi danh sach
{
	ref p;
	if (head == tail) //Neu chi co 1 phan tu
	{
		free(head);
		head = tail = NULL;
	}
	else
	{
		for (p = head; p->next != tail; p = p->next);
		free(tail);
		tail = p; //Cap nhat lai tail
		p->next = NULL;
	}
}

void DeleteMid(ref p) //Xoa phan tu giua danh sach
{
	ref r;
	r = p->next;
	*p = *r;
	free(r);
}
void DeleteAt(ref& head, ref& tail, int pos) //Xoa phan tu tai vi tri pos
{
	ref p;
	int n = Length(head);
	if (pos < 0 || pos >= n)
	{
		printf("Vi tri xoa khong hop le\n");
		return;
	}
	else
	{
		if (pos == 0) //Xoa phan tu dau danh sach
			DeleleBeg(head, tail);
		else
		{
			if (pos == n - 1) //Xoa phan tu cuoi danh sach
				DeleteEnd(head, tail);
			else
			{
				int i;
				for (p = head, i = 0; i < pos; i++, p = p->next);
				DeleteMid(p);
				if (p->next == NULL) //Neu xoa phan tu ke cuoi thi phai cap nhat lai tail
					tail = p;
			}
		}
	}
}

void DeleteAll(ref& head) //Huy toan bo danh sach
{
	ref p;
	while (head)
	{
		p = head;
		head = head->next;
		free(p);
	}
}