#include "MEMBER.h"


MEMBER::MEMBER()
{
	_name = "";
	_isMale = true;
	_date = { 0, 0, 0 };
	_ID = "";
	_bookBorrow = 0;
}

MEMBER::MEMBER(string name, bool isMale, DATE date, string ID, unsigned int bookBorrow)
{
	_name = name;
	_isMale = isMale;
	_date = date;
	_ID = ID;
	_bookBorrow = bookBorrow;
}

MEMBER::MEMBER(const MEMBER& m)
{
	_name = m._name;
	_isMale = m._isMale;
	_date = m._date;
	_ID = m._ID;
	_bookBorrow = m._bookBorrow;
}


MEMBER::~MEMBER()
{
	_name = "";
	_isMale = true;
	_date = { 0, 0, 0 };
	_ID = "";
	_bookBorrow = 0;
}

istream& operator>>(istream& inDev, DATE& date)
{
	char ch;
	inDev >> date.day >> ch >> date.month >> ch >> date.year;
	return inDev;
}

ostream& operator<<(ostream& outDev, const DATE& date)
{
	outDev << date.day << "/" << date.month << "/" << date.year;
	return outDev;
}

istream& operator>>(istream& inDev, MEMBER& member)
{
	char ch;
	string str;
	inDev >> str;
	member._name = str;
	inDev >> str;
	member._name = member._name + " " + str;
	member._name.erase(member._name.size() - 1, 1);


	inDev >> ch;
	if (ch == 'M')
		member._isMale = true;
	else if (ch == 'F')
		member._isMale = false;

	inDev >> ch;
	
	inDev >> member._date;

	inDev >> ch;

	inDev >> member._ID;
	member._ID.erase(member._ID.size() - 1, 1);

	inDev >> member._bookBorrow;
	return inDev;
}

ostream& operator<<(ostream& outDev, const MEMBER& member)
{
	outDev << member._name << ", ";
	if (member._isMale == true)
		outDev << "M,";
	else if (member._isMale == false)
		outDev << "F,";
	outDev << member._date << ", " << member._ID << ".";
	return outDev;
}