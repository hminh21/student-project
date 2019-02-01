#include <iostream>
#include <conio.h>

using namespace std;
class MyString
{
	char* _cStr;
	int _iSize;
public:
	MyString();
	MyString(char*, int);
	MyString(const MyString&);
	~MyString();
	int length();
	bool insert(int, char*);
	bool erase(int, int);
	friend ostream& operator<<(ostream& outDev, const MyString&);
};

int getLength(char*);
bool resize(char* &, int &, int);