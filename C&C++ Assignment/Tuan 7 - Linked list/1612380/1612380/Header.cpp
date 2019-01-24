#include "Header.h"

Ref getNode(void* k, int iSize) //Tao mot node
{
	Ref p = (Ref)malloc(sizeof(NODE));

	if (p == NULL)
	{
		printf("Khong du bo nho\n");
		exit(0);
	}
	else
	{
		p->key = new char[iSize]; //Cap phat bang kieu char
		p->next = NULL;
		if (p->key == NULL)
		{
			delete[] p;
			return NULL;
		}
			memcpy(p->key, k, iSize); //Sao chep dia chi
	}
	return p;
}

int Length(Ref head) //Dem so luong phan tu
{
	int i = 0;
	for (Ref p = head; p != NULL; i++, p = p->next);
	return i;
}

Ref findList(Ref head, void* dat, bool(*cmp)(void*, void*))//Tim kiem phan tu trong danh sach
{
	Ref p = head;
	while (p)
	{
		if (cmp(p->key, dat) == true)
			break;
		p = p->next;
	}
	return p;
}

bool fracCmp(void* p, void* q) //Ham so sanh 2 truong key
{
	Fraction* r = (Fraction*)p;
	Fraction* s = (Fraction*)q;
	int num1 = r->numerator * s->denominator;
	int num2 = r->denominator * s->numerator;
	if (num1 == num2)
		return true;
	return false;
}

bool intCmp(void* p, void* q) //Ham so sanh 2 truong key so nguyen
{
	int *r = (int*)p, *s = (int*)q;
	if (*r == *s)
		return true;
	return false;
}

bool douCmp(void* p, void* q) ///ham so sanh 2 truong key so thuc
{
	double *r = (double*)p, *s = (double*)q;
	if (*r == *s)
		return true;
	return false;
}

bool plexCmp(void* p, void* q) //Ham so sanh 2 truong key so phuc
{
	Complex *r = (Complex*)p, *s = (Complex*)q;
	if (r->real == s->real && r->imaUnit == s->imaUnit)
		return true;
	return false;
}




void PrintList(Ref head, void(*Print)(Ref)) //In ra danh sach
{
	Ref p = head;
	while (p)
	{
		Print(p);
		p = p->next;
	}
	cout << endl;
}

void PrintFrac(Ref p) //Ham in ra phan tu
{
	Fraction* x = (Fraction*)p->key;
	cout << x->numerator << "/" << x->denominator << " ";

}

void PrintInt(Ref p) //Ham in ra phan tu so nguyen
{
	int* i = (int*)p->key;
	cout << *i << " ";
}

void PrintDou(Ref p) //Ham in ra phan tu so thuc
{
	double *x = (double*)p->key;
	cout << *x << " ";
}

void PrintPlex(Ref p) //Ham in ra phan tu so phuc
{
	Complex *q = (Complex*)p->key;
	cout << q->real << " + " << q->imaUnit << "i" << endl;
}

void AddFirst(Ref& head, Ref& tail, void* k, int iSize) //Chen 1 phan tu vao dau danh sach
{
	Ref p = getNode(k, iSize);

	if (p == NULL || k == NULL) return; 

	if (head == NULL) //Khi danh sach chua co phan tu
	{
		head = tail = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
}

void AddLast(Ref& head, Ref& tail, void* k, int iSize) //Chen 1 phan tu vao cuoi danh sach
{
	Ref p = getNode(k, iSize);

	if (head == NULL)
	{
		head = tail = p;
	}
	else
	{
		tail->next = p;
		tail = p;
	}
}

Ref InsertAfter(Ref& head, void* X, void* Val, int iSize, bool(*cmp)(void*, void*)) //Chen 1 phan tu co gia tri Val vao sau phan tu co gia tri X
{
	Ref q = findList(head, X, cmp);
	if (q == NULL)
	{
		cout << "Khong tim thay vi tri de chen" << endl;
		return NULL;
	}
	Ref p = getNode(Val, iSize);
	if (p != NULL)
	{
		p->next = q->next;
		q->next = p;
	}
	return p;
}

Ref InsertBefore(Ref& head, Ref& tail, void* X, void* Val, int iSize, bool(*cmp)(void*, void*))//Chen 1 phan tu co gia tri Val vao truoc phan tu co gia tri X
{
	Ref p;
	p = findList(head, X, cmp);
	if (p == NULL)
	{
		cout << "Khong tim thay vi tri de chen" << endl;
		return NULL;
	}
	Ref q = getNode(Val, iSize);
	memcpy(q->key, p->key, iSize);
	q->next = p->next;
	p->next = q;
	memcpy(p->key, Val, iSize);
	if (tail->next != NULL)
		tail = tail->next;
	return p;
}

void InsertAt(Ref& head, Ref& tail, void* X, void* Val, int iSize, bool(*cmp)(void*, void*)) //Chen 1 phan tu tai vi tri bat ki
{
	int n = Length(head), i = 0;
	Ref p = findList(head, X, cmp);
	for (Ref q = head; q != p; i++, q = q->next);
	if (i == 0)
		AddFirst(head, tail, Val, iSize);
	else
	if (i > 0 && i <= n - 1)
		InsertBefore(head, tail, X, Val, iSize, cmp);
}


void DestroyList(Ref& head, Ref& tail) //Xoa danh sach
{
	Ref p;
	while (head != NULL)
	{
		p = head;
		if (p->key != NULL)
			delete[] (char*)p->key;

		head = p->next;
		delete p;
	}
	tail = NULL;
}

void DeleteBeg(Ref& head, Ref& tail) //Xoa phan tu dau tien trong danh sach
{
	if (head == tail)
	{
		if (head->key != NULL)
			delete[] head->key;

		if (head != NULL)
			delete head;

		head = tail = NULL;
		return;
	}
	Ref p = head;
	if (p != NULL)
	{
		head = head->next;
		if (p->key != NULL)
			delete[] p->key;

		delete p;
	}

}

void DeleteEnd(Ref& head, Ref& tail) //Xoa phan tu cuoi cung trong danh sach
{
	if (head == tail)
	{
		if (tail->key != NULL)
			delete[] tail->key;

		if (tail != NULL)
			delete tail;

		head = tail = NULL;
		return;
	}
	Ref p;
	for (p = head; p->next != tail; p = p->next);
	free(tail);
	tail = p;
	tail->next = NULL;
}

void DeleteMid(Ref p, Ref& tail, int iSize) //Xoa phan tu giua danh sach
{
	Ref q;
	q = p->next;
	p->next = q->next;
	memcpy(p->key, q->key, iSize);
	if (q->key != NULL)
	{
		delete[] q->key;
		return;
	}
	delete(q);
	if (tail->next != NULL)
		tail = tail->next;
}

void DeleteAt(Ref& head, Ref& tail, void* X, int iSize, bool(*cmp)(void*, void*)) //Xoa 1 phan tu tai vi tri bat ki
{
	int n = Length(head), i = 0;
	Ref p = findList(head, X, cmp);
	for (Ref q = head; q != p; i++, q = q->next);
	if (i == 0)
	{
		DeleteBeg(head, tail);
		return;
	}
	if (i == n - 1)
	{
		DeleteEnd(head, tail);
		return;
	}
	if (i > 0 && i < n - 1)
		DeleteMid(p, tail, iSize);
}







