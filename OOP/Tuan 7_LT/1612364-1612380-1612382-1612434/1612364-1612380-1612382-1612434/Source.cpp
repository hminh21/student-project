#include <iostream> //1612364 - 1612380 - 1612382 - 1612384 - 1612434

using namespace std;
#define MAX_NAME 50

class SINHVIEN{
private:
	char name[MAX_NAME + 1];
	float score;
public:
	SINHVIEN(){ strcpy(name, "Default"); score = 0; };
	SINHVIEN(char *student_name, float student_score){ strcpy(name, student_name); score = student_score; };

	SINHVIEN& operator=(const SINHVIEN&);
	bool operator<(const SINHVIEN&);
	bool operator>(const SINHVIEN&);
	friend istream& operator>>(istream& inDev, SINHVIEN& sv);
	friend ostream& operator<<(ostream& outDev, SINHVIEN& sv);
};


SINHVIEN& SINHVIEN::operator =(const SINHVIEN &sv1)
{
	strcpy(name, sv1.name);
	score = sv1.score;
	return *this;
}

bool SINHVIEN::operator<(const SINHVIEN& sv)
{
	return (score < sv.score);
}

bool SINHVIEN::operator>(const SINHVIEN& sv)
{
	return (score > sv.score);
}

ostream& operator<<(ostream& outDev, SINHVIEN& sv)
{
	outDev << " == STUDENT == " << endl;
	outDev << "Name: " << sv.name << endl;
	outDev << "Score: " << sv.score << endl;
	return outDev;
}

template <class T>
class SortAlgorithm
{
	static SortAlgorithm<T>* _algorithm;
	void(*currentAlgorithm)(T[], int);
	SortAlgorithm<T>();
public:
	static SortAlgorithm<T>* getObject(void(*pAlg)(T[], int) = NULL);
	static void SelectionSort(T[], int);
	static void InsertionSort(T[], int);
	static void InterchangeSort(T[], int);
	void Sort(T[], int);
};

//
template<class T>
SortAlgorithm<T>* SortAlgorithm<T>::_algorithm = NULL;
template<class T>
SortAlgorithm<T>::SortAlgorithm<T>()
{
	currentAlgorithm = InsertionSort;
}

template<class T>
SortAlgorithm<T>* SortAlgorithm<T>::getObject(void(*pAlg)(T[], int))
{
	if (_algorithm == NULL)
	{
		_algorithm = new SortAlgorithm<T>();
	}
	if (pAlg != NULL)
	{
		_algorithm->currentAlgorithm = pAlg;
	}
	return _algorithm;
}
template<class T>
void SortAlgorithm<T>::Sort(T a[], int n)
{
	if (currentAlgorithm != NULL)
	{
		currentAlgorithm(a, n);
	}
}
template<class T>
void SortAlgorithm<T>::SelectionSort(T a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		if (a[j] < a[min])
		{
			min = j;
		}
		if (min != i)
		{
			T temp = a[min]; 
			a[min] = a[i]; 
			a[i] = temp;
		}
	}
}
template<class T>
void SortAlgorithm<T>::InsertionSort(T a[], int n)
{
	int pos;
	T x;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		for (pos = i; (pos > 0) && (a[pos - 1] > x); pos--)
			a[pos] = a[pos - 1];
		a[pos] = x;
	}
}
template<class T>
void SortAlgorithm<T>::InterchangeSort(T a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				T temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main()
{
	/*float a[] = { 1.4F, -5.2F, 3.3F, 0 };*/
	

	char a[] = { 'B', 'A', 'G', 'F' };
	
	/*SINHVIEN a[] = { SINHVIEN("abc", 8.5), SINHVIEN("def", 9.5), SINHVIEN("adef", 7.5) };*/


	int n = sizeof(a) / sizeof(a[0]);

	/*SortAlgorithm<float>* alg = SortAlgorithm<float>::getObject(SortAlgorithm<float>::SelectionSort);*/
	SortAlgorithm<char>* alg = SortAlgorithm<char>::getObject(SortAlgorithm<char>::SelectionSort);
	/*SortAlgorithm<SINHVIEN>* alg = SortAlgorithm<SINHVIEN>::getObject(SortAlgorithm<SINHVIEN>::SelectionSort);*/
	
	alg->Sort(a, n);

	cout << "Mang sau khi sap xep tang dan" << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	return 0;


}