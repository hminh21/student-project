#include<iostream>
#include<cstring>
using namespace std;
class MyString
{
	char* myString;
	int size;
public:
	MyString();
	MyString(char*, int);
	MyString(const MyString&);
	~MyString();
	void setString(char* newString);
	void setSize(int newSize);
	char* getString();
	int length();
	char* subString(int, int);
	char* operator + (const MyString&);
	bool insert(int, char*);
	bool erase(int, int);
	bool replace(int, int, char*);
	bool find(int, char*);
};