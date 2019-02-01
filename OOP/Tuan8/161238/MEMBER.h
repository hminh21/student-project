#ifndef _MEMBER_h
#define _MEMBER_h

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

struct DATE
{
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

class MEMBER
{
protected:
	string _name;
	bool _isMale;
	DATE _date;
	string _ID;
	unsigned int _bookBorrow;

public:
	MEMBER();
	MEMBER(string name, bool isMale, DATE date, string ID, unsigned int bookBorrow);
	MEMBER(const MEMBER&);
	~MEMBER();

	//getter
	string get_name(){ return _name; }
	bool get_sex(){ return _isMale; }
	DATE get_date(){ return _date; }
	string get_ID(){ return _ID; }
	unsigned int get_bookBorrow(){ return _bookBorrow; }

	//setter
	void set_name(string name){ _name = name; }
	void set_sex(bool is){ _isMale = is; }
	void set_date(DATE date){ _date = date; }
	void set_ID(string ID){ _ID = ID; }
	void set_bookBorrow(unsigned int book){ _bookBorrow = book; }

	//operator
	friend istream& operator>>(istream& inDev, DATE& date);
	friend ostream& operator<<(ostream& outDev, const DATE& date);

	friend istream& operator>>(istream& inDev, MEMBER& member);
	friend ostream& operator<<(ostream& outDev, const MEMBER& member);

	virtual string getClass() = 0;
	virtual unsigned long MoneyLoan() = 0;
};

#endif
