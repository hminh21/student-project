#include <conio.h>
#include <iostream>
#include <string>


using namespace std;

struct FRACTION
{
	int numerator;
	int denominator;
};

template <class T>
	struct Node
	{
		T key;
		Node* next;
	};

void swap(void *a, void *b, int size); //Ham doi cho

template <class T>
void Sort(T a[], int n, bool (*compare)(T, T)); //Ham sap xep

template <class T>
bool Ascending(T a, T b); //a < b

template <class T>
bool Descending(T a, T b); //a > b

template <class T>
bool AbsAscending(T a, T b); // |a| < |b|

template <class T>
void PrintArr(T a[], int n); //In mang

void PrintFractionArr(FRACTION Arr[], int n); //In mang phan so

bool AscendingFraction(FRACTION a, FRACTION b); //x < y

bool DescendingFraction(FRACTION a, FRACTION b); //x > y

bool AbsAscendingFraction(FRACTION a, FRACTION b);

int StringLength(string s);

bool AscendingString(string s1, string s2);

bool DescendingString(string s1, string s2);

bool FirstAscendingString(string s1, string s2);

//DSLK

template <class T>
Node<T>* getNode(T key);

template <class T>
void AddLast(Node<T>* &head, Node<T>* &tail, T key);

template <class T>
void PrintList(Node<T>* head);

template <class T>
bool AscendingList(T a, T b);

template <class T>
bool DescendingList(T a, T b);

template <class T>
bool AbsAscendingList(T a, T b);

template <class T>
void SortList(Node<T>* &head, Node<T>* &tail,bool (*Compare)(T,T));

void PrintFractionList(Node<FRACTION>* head);

bool AscendingFractionList(Node<FRACTION> a, Node<FRACTION> b);



