#include "Header.h"


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void PrintIntArr(int Arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%i ", Arr[i]);
	printf("\n");
}

void PrintFloatArr(float Arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%.2f ", Arr[i]);
	printf("\n");
}

void SortArrDescending(int Arr[], int n) //Shaker sort
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (Arr[i] < Arr[i + 1])
			{
				swap(&Arr[i], &Arr[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (Arr[i] > Arr[i - 1])
			{
				swap(&Arr[i], &Arr[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}

void SortEvenDescending(int Arr[], int n) //Interchange sort
{
	for (int i = 0; i < n - 1; i++)
	{
		if (Arr[i] % 2 == 0)
		for (int j = i + 1; j < n; j++)
		{
			if (Arr[j] % 2 == 0 && Arr[i] < Arr[j])
				swap(&Arr[i], &Arr[j]);
		}
	}
}

void SortArr(float Arr[], int n) //Interchange sort
{
	for (int i = 0; i < n - 1; i++) //Sort negative ascending
	{
		if (Arr[i] < 0)
			for (int j = i + 1; j < n; j++)
			{
				if (Arr[j] < 0 && Arr[i] > Arr[j])
				{
					float temp = Arr[j];
					Arr[j] = Arr[i];
					Arr[i] = temp;
				}
			}
	}

	for (int i = 0; i < n - 1; i++) //Sort positive descending
	{
		if (Arr[i] > 0)
		for (int j = i + 1; j < n; j++)
		{
			if (Arr[j] > 0 && Arr[i] < Arr[j])
			{
				float temp = Arr[j];
				Arr[j] = Arr[i];
				Arr[i] = temp;
			}
		}
	}
}

bool IsPrime(int x, int i) //Check prime number
{
	if (x == 2 || i == 1)
		return true;
	if (x <= 1 || x % i == 0)
		return false;
	return IsPrime(x, i - 1);
}

void SortPrimeAscending(int Arr[], int n) //Selection sort
{
	int pos;
	for (int i = 0; i < n; i++)
	{
		if (IsPrime(Arr[i], Arr[i] - 1) == true)
		{
			pos = i;
			for (int j = i + 1; j < n; j++)
			{
				if (Arr[j] < Arr[pos] && IsPrime(Arr[j], Arr[j] - 1) == true)
					pos = j;
			}
			swap(&Arr[i], &Arr[pos]);
		}
	}
}

void SortEvenAndOdd(int Arr[], int n) //Selection sort
{
	int pos;
	for (int i = 0; i < n - 1; i++) //split even and odd into 2 part
	{
		for (int j = i + 1; j < n; j++)
		{
			if (Arr[j] % 2 == 0)
			{
				swap(&Arr[i], &Arr[j]);
				pos = i; //save the position which is between 2 part
			}
		}
	}
		int i = 0, j = pos + 1;
		while (i < pos && j < n - 1)
		{
			if (i < pos) //Sort even part 
			{
				for (int k = i + 1; k <= pos; k++)
				{
					if (Arr[i] > Arr[k])
						swap(&Arr[i], &Arr[k]);
				}
				i++;
			}
			if (j < n - 1) //Sort odd part
			{
				for (int m = j + 1 ; m <= n - 1; m++)
				{
					if (Arr[j] < Arr[m])
						swap(&Arr[j], &Arr[m]);
				}
				j++;
			}
		}
}

void SortFloatAscending(float Arr[], int n) //Bubble sort
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (Arr[j - 1] > Arr[j])
			{
				float temp = Arr[j];
				Arr[j] = Arr[j - 1];
				Arr[j - 1] = temp;
			}
		}
	}
}