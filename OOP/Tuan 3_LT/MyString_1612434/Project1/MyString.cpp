#include"MyString.h"
#include<iostream>
#include<cstring>
using namespace std;
MyString::MyString()
{
	myString = new char[100];
	size = 0;
}
MyString::MyString(char* newString, int newSize)
{
	if (newString != NULL)
		myString = newString;
	if (newSize > 0)
		size = newSize;
}
MyString::MyString(const MyString& newString)
{
	size = newString.size;
	myString = new char[size + 1];
	for (int i = 0; i < size; i++)
		myString[i] = newString.myString[i];
}
MyString::~MyString()
{
	delete[]myString;
}
void MyString::setString(char* newString)
{
	if (newString != NULL)
	{
		int i = 0;
		for (i = 0; i < strlen(newString); i++)
			myString[i] = newString[i];
		myString[i] = '\0';
	}
}
void MyString::setSize(int newSize)
{
	if (newSize > 0)
		size = newSize;
}
char* MyString::getString()
{
	return myString;
}
int MyString::length()
{
	return size;
}
char* MyString::subString(int pos, int num)
{
	char *temp;
	temp = new char[abs(num)];
	// wrong input
	if (pos < 0)
		return NULL;

	//length of substring longer than mainstring
	if (num > size - pos)
		num = size - pos;

	if (num > 0)
	{
		for (int i = 0; i < num; i++)
			temp[i] = myString[i + pos];
		temp[num] = '\0';
		return temp;
	}
	// if num < 0, get substring from right to left
	// Ex: mystring: "hcmus" 
	// input: pos = 3, num = -3
	// output: "cmu"
	if (num < 0)
	{
		//length of substring is longer than mainstring
		if (abs(num) > pos + 1)
		{
			num = pos + 1;
			for (int i = 0; i < num; i++)
				temp[i] = myString[i];
			temp[num] = '\0';
			return temp;
		}

		for (int i = 0; i < abs(num); i++)
			temp[i] = myString[pos + num + i + 1];
		temp[abs(num)] = '\0';
		return temp;
	}
	return NULL;
}

char* MyString::operator+(const MyString& mystr)
{
	int n = size + mystr.size;
	char *temp = new char[n];
	for (int i = 0; i < size; i++)
		temp[i] = myString[i];
	for (int j = 0; j < mystr.size; j++)
		temp[j + size] = mystr.myString[j];
	temp[n] = '\0';
	return temp;
}
bool MyString::insert(int Start_Pos, char* s)
{
	if (Start_Pos > size)
	{
		cout << "Start position is bigger than size of string.";
		return false;
	}
	else
	{
		char* copyRight = new char[100];//copy information from start_pos to add back later
		int iCopyRight = 0, j = 0;
		for (iCopyRight = Start_Pos; iCopyRight < size; iCopyRight++)
		{
			copyRight[j] = myString[iCopyRight];
			j++;
		}
		copyRight[j] = '\0';
		int index = Start_Pos;
		for (int i = 0; i < strlen(s); i++)
		{
			myString[index] = s[i];
			index++;
		}//add string s to myString
		for (int i = 0; i < strlen(copyRight); i++)
		{
			myString[index] = copyRight[i];
			index++;
		}//add information been taken to myString
		myString[index] = '\0';
		setSize(size + strlen(s));
		return true;
	}
}

bool MyString::erase(int Start_Pos, int num)
{
	if (num > size - Start_Pos)
	{
		cout << "There are not enough places to erase.";
		return false;
	}
	else
	{
		char* copy = new char[100];
		int iCopy = 0;
		int j = 0;
		for (iCopy = Start_Pos+num; iCopy < size; iCopy++,j++)//copy information from start_pos+num to add back later
		{
			copy[j] = myString[iCopy];
		}
		copy[j] = '\0';
		 //decrease size of string
		for (int i = 0, j = Start_Pos; i < strlen(copy); i++,j++)
		{
			myString[j] = copy[i];
		}
		myString[size - num] = '\0';//cut information of myString
		size = size - num;
		return true;
	}
}
bool MyString::replace(int pos, int n, char* s) //replace strings
{
	if (pos > length() - n)
	{
		cout << "There are not enough places to replace.";
		return false;
	}
	else
	{
		for (int i = pos, j = 0; i < pos + n; i++, j++)
		{
			myString[i] = s[j];
		}
		return true;
	}
}
bool MyString::find(int pos, char* s) // find strings
{
	int len = strlen(s);
	for (int i = pos; i <= length() - len; i++)
	{
		int countMatches = 0;
		for (int j = 0; j < len; j++)
		{
			if (myString[i+j] == s[j])
				countMatches++;
		}
		if (countMatches==len)
			return true;
	}
	return false;
}