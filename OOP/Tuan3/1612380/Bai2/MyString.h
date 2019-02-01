#pragma once
#include <iostream>
#include <conio.h>
#include <string.h>
#include <malloc.h>

using namespace std;
class CMyString
{
	char* _cStr;
	int _iN;
public:
	CMyString();
	CMyString(char*);
	CMyString(const CMyString&);
	~CMyString();
	int getLength();
	char getChar(int);
	void setChar(int, char);
	friend istream& operator>>(istream&, CMyString&);
	friend ostream& operator<<(ostream&, const CMyString&);
	CMyString operator+(const CMyString&);
	CMyString& operator!();
	CMyString& operator~();
	bool operator>(const CMyString&);
	bool operator>=(const CMyString&);
	bool operator<(const CMyString&);
	bool operator<=(const CMyString&);
	friend void DeleteChar(CMyString&, int);
	bool operator==(const CMyString&);
	bool operator!=(const CMyString&);
};

