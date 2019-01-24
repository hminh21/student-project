#include "Header.h"


void swap(void *a, void *b, int size) //Ham doi cho
{
	void *temp = malloc(size);
	memcpy(temp, a, size);
	memcpy(a, b, size);
	memcpy(b, temp, size);
	free(temp);
}

template <class T>
void Sort(T a[], int n, bool(*compare)(T, T)) //Ham sap xep
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n ; j++)
		{
			if (compare(a[i], a[j]) == false)
				swap(&a[i], &a[j], sizeof(T));
		}
	}
}

template <class T>
bool Ascending(T a, T b) //a < b
{
	if (a > b)
		return false;
	return true;
}

template <class T>
bool Descending(T a, T b) //a > b
{
	if (a < b)
		return false;
	return true;
}

template <class T>
bool AbsAscending(T a, T b) // |a| < |b|
{
	if (abs(a) > abs(b))
		return false;
	return true;
}

template <class T>
void PrintArr(T a[], int n) //In mang
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}


void PrintFractionArr(FRACTION Arr[], int n) //In mang phan so
{
	for (int i = 0; i < n; i++)
		cout << Arr[i].numerator << "/" << Arr[i].denominator << " ";
	cout << endl;
}

bool AscendingFraction(FRACTION a, FRACTION b) //x < y
{
	float x = a.numerator / (float)a.denominator;
	float y = b.numerator / (float)b.denominator;
	if (x > y)
		return false;
	return true;
}

bool DescendingFraction(FRACTION a, FRACTION b) //x > y
{
	float x = a.numerator / (float)a.denominator;
	float y = b.numerator / (float)b.denominator;
	if (x < y)
		return false;
	return true;
}

bool AbsAscendingFraction(FRACTION a, FRACTION b) // |x| < |y|
{
	float x = a.numerator / (float)a.denominator;
	float y = b.numerator / (float)b.denominator;

	if (abs(x) > abs(y))
		return false;
	return true;
}

int StringLength(string s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
		return i;
	}
}

bool AscendingString(string s1, string s2)
{	
		int n1 = StringLength(s1);
	
		int n2 = StringLength(s2);
	
		int i, n = (n1 < n2) ? n1 : n2;
	
		for (i = 0; i < n; i++)
		{
			if (s1[i] > s2[i]) 
				return false;
			else 
			if (s1[i] < s2[i]) 
				return true;
		}
		if (n1 > n) 
			return false;
		if (n2 > n) 
			return true;
		return true;
	}

bool DescendingString(string s1, string s2)
{
	int n1 = StringLength(s1);

	int n2 = StringLength(s2);

	int i, n = (n1 < n2) ? n1 : n2;

	for (i = 0; i < n; i++)
	{
		if (s1[i] > s2[i])
			return true;
		else
		if (s1[i] < s2[i])
			return false;
	}
	if (n1 > n)
		return true;
	if (n2 > n)
		return false;
	return true;
}

bool FirstAscendingString(string s1, string s2)
{
	if (s1[0] > s2[0])
		return false;
	return true;
}


//DANH SACH LIEN KET

template <class T>
Node<T>* getNode(T key)
{
	Node<T>* p = (Node<T>*)calloc(1,sizeof(Node<T>)); // Node <T>* p = new Node <T>
	if (p == NULL)
	{
		cout << "Khong du bo nho" << endl;
		exit(0);
	}
	p->key = key;
	p->next = NULL;
	return p;
}

template <class T>
void AddLast(Node<T>* &head, Node<T>* &tail, T key)
{
	Node<T>* p = getNode(key);

	if (head == NULL)
	{
		head = tail = p;
		return;
	}
	tail->next = p;
	tail = p;
}

template <class T>
void PrintList(Node<T>* head)
{
	Node<T> *p;
	for (p = head; p != NULL; p = p->next)
		cout << p->key << " ";
	cout << endl;
}

template <class T>
bool AscendingList(T a, T b)
{
	if (a > b)
		return false;
	return true;
}

template <class T>
bool DescendingList(T a, T b)
{
	if (a < b)
		return false;
	return true;
}

template <class T>
bool AbsAscendingList(T a, T b)
{
	if (abs(a) > abs(b))
		return false;
	return true;
}

template <class T>
void SortList(Node<T>* &head, Node<T>* &tail, bool (*Compare)(T,T))
{
	Node<T> *p, *q;
	for (p = head; p->next != NULL; p = p->next)
	{
		for (q = p->next; q != NULL; q = q->next)
		{
			if (Compare(p->key, q->key) == false)
			{
				swap(p->key, q->key);
			}
		}
	}
}

void PrintFractionList(Node<FRACTION>* head)
{
	Node<FRACTION> *p;
	for (p = head; p != NULL; p = p->next)
		cout << p->key.numerator << "/" << p->key.denominator << " ";
	cout << endl;
}



void main()
{
	//MANG
	cout << "--------------------------------------------------------MANG MOT CHIEU--------------------------------------" << endl;
	//SO NGUYEN
	cout << "----------INT----------" << endl;
	int ArrA[] = { 3, 2, 3, 6, 7, 1, 5, -2, 0, -1 }; int nA = 10;
	PrintArr(ArrA, nA);
	Sort(ArrA, nA, &Ascending);
	PrintArr(ArrA, nA);
	Sort(ArrA, nA, &Descending);
	PrintArr(ArrA, nA);
	Sort(ArrA, nA, &AbsAscending);
	PrintArr(ArrA, nA);

	cout << "----------LONG----------" << endl;
	long ArrE[] = { 3, 2, 3, 6, 7, 1, 5, -2, 0, -1 }, nE = 10;
	PrintArr(ArrE, nE);
	Sort(ArrE, nE, &Ascending);
	PrintArr(ArrE, nE);
	Sort(ArrE, nA, &Descending);
	PrintArr(ArrE, nE);
	Sort(ArrE, nE, &AbsAscending);
	PrintArr(ArrE, nE);

	//SO THUC
	cout << "----------FLOAT----------" << endl;
	float ArrB[] = { 3.2, 2.1, 3.6, 6.5, 7, 1, 5, -2.3, 0, -1.5 }, nB = 10;
	PrintArr(ArrB, nB);
	Sort(ArrB, nB, &Ascending);
	PrintArr(ArrB, nB);
	Sort(ArrB, nB, &Descending);
	PrintArr(ArrB, nB);
	Sort(ArrB, nB, &AbsAscending);
	PrintArr(ArrB, nB);

	cout << "----------DOUBLE----------" << endl;
	double ArrF[] = { 3.2, 2.1, 3.6, 6.5, 7, 1, 5, -2.3, 0, -1.5 }; int nF = 10;
	PrintArr(ArrF, nF);
	Sort(ArrF, nF, &Ascending);
	PrintArr(ArrF, nF);
	Sort(ArrF, nF, &Descending);
	PrintArr(ArrF, nF);
	Sort(ArrF, nF, &AbsAscending);
	PrintArr(ArrF, nF);

	//PHAN SO
	cout << "----------FRACTION----------" << endl;
	FRACTION ps[] = { 2, 3, -1, 2, 4, 5, 5, 4, 3, 2, 1, -3 }; int nC = 6;
	PrintFractionArr(ps, nC);
	Sort(ps, nC, &AscendingFraction);
	PrintFractionArr(ps, nC);
	Sort(ps, nC, &DescendingFraction);
	PrintFractionArr(ps, nC);
	Sort(ps, nC, &AbsAscendingFraction);
	PrintFractionArr(ps, nC);

	//STRING
	cout << "----------STRING----------" << endl;
	string str[] = { "hello", "chao", "bonjour", "hi" }; int nD = 4;
	PrintArr(str, nD);
	Sort(str, nD, &AscendingString);
	PrintArr(str, nD);
	Sort(str, nD, &DescendingString);
	PrintArr(str, nD);
	Sort(str, nD, &FirstAscendingString);
	PrintArr(str, nD);

	cout << endl;
	//DSLK
	cout << "-------------------------------------------------------------DSLK------------------------------------------------------" << endl;
	Node<int> *head1 = NULL, *tail1 = NULL;
	//SO NGUYEN
	cout << "----------INT----------" << endl;
	for (int i = 0; i < nA;i++)
	AddLast(head1, tail1, ArrA[i]);
	PrintList(head1);
	SortList(head1, tail1, &AscendingList);
	PrintList(head1);
	SortList(head1, tail1, &DescendingList);
	PrintList(head1);
	SortList(head1, tail1, &AbsAscendingList);
	PrintList(head1);

	
	//SO NGUYEN
	Node<long> *head2 = NULL, *tail2 = NULL;
	cout << "----------LONG----------" << endl;
	for (int i = 0; i < nB;i++)
	AddLast(head2, tail2, ArrE[i]);
	PrintList(head2);
	SortList(head2, tail2, &AscendingList);
	PrintList(head2);
	SortList(head2, tail2, &DescendingList);
	PrintList(head2);
	SortList(head2, tail2, &AbsAscendingList);
	PrintList(head2);
	
	//SO THUC
	Node<float> *head3 = NULL, *tail3 = NULL;
	cout << "----------FLOAT----------" << endl;
	for (int i = 0; i < nB;i++)
	AddLast(head3, tail3, ArrB[i]);
	PrintList(head3);
	SortList(head3, tail3, &AscendingList);
	PrintList(head3);
	SortList(head3, tail3, &DescendingList);
	PrintList(head3);
	SortList(head3, tail3, &AbsAscendingList);
	PrintList(head3);

	Node<double> *head4 = NULL, *tail4 = NULL;
	cout << "----------DOUBLE----------" << endl;
	for (int i = 0; i < nF; i++)
		AddLast(head4, tail4, ArrF[i]);
	PrintList(head4);
	SortList(head4, tail4, &AscendingList);
	PrintList(head4);
	SortList(head4, tail4, &DescendingList);
	PrintList(head4);
	SortList(head4, tail4, &AbsAscendingList);
	PrintList(head4);

	//PHANSO
	Node<FRACTION> *head5 = NULL, *tail5 = NULL;
	cout << "----------FRACTION----------" << endl;
	for (int i = 0; i < nC; i++)
		AddLast(head5, tail5, ps[i]);
	PrintFractionList(head5);
	SortList(head5, tail5, &AscendingFraction);
	PrintFractionList(head5);
	SortList(head5, tail5, &DescendingFraction);
	PrintFractionList(head5);
	SortList(head5, tail5, &AbsAscendingFraction);
	PrintFractionList(head5);

	//STRING
	Node<string> *head6 = NULL, *tail6 = NULL;
	cout << "----------STRING----------" << endl;
	for (int i = 0; i < nD; i++)
		AddLast(head6, tail6, str[i]);
	PrintList(head6);
	SortList(head6, tail6, &AscendingString);
	PrintList(head6);
	SortList(head6, tail6, &DescendingString);
	PrintList(head6);
	SortList(head6, tail6, &FirstAscendingString);
	PrintList(head6);
}