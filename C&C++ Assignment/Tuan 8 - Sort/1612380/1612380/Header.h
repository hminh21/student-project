#include <stdio.h>
#include <conio.h>

void swap(int* a, int* b); 
void PrintIntArr(int Arr[], int n);
void PrintFloatArr(float Arr[], int n);
void SortArrDescending(int Arr[], int n); //Shaker sort
void SortEvenDescending(int Arr[], int n); //Interchange sort
void SortArr(float Arr[], int n); //Interchange sort
void SortPrimeAscending(int Arr[], int n); //Selection sort  
bool IsPrime(int x, int i); //Check prime number
void SortEvenAndOdd(int Arr[], int n); //Selection sort
void SortFloatAscending(float Arr[], int n); //Bubble sort