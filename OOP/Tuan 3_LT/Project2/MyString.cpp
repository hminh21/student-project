#include "MyString.h"

MyString::MyString()
{
	_cStr = NULL;
	_iSize = 0;
}

MyString::MyString(char* str, int size)
{
	if (str != NULL && size >= 0)
	{
		_cStr = new char[size + 1];
		for (int i = 0; i <= size; i++)
			_cStr[i] = str[i];
		_iSize = size;
	}
	else
		cout << "Tham so khong hop le" << endl;
}

MyString::MyString(const MyString& s)
{
	if (s._cStr != NULL && s._iSize >= 0)
	{
		_iSize = s._iSize;
		_cStr = new char[_iSize + 1]; //Khoi tao chuoi voi kich thuoc = size + '\0'
		for (int i = 0; i < _iSize; i++)
			_cStr[i] = s._cStr[i]; //copy noi dung

		_cStr[_iSize] = '\0'; //ket thuc chuoi
	}
}

MyString::~MyString()
{
	if (_cStr != NULL)
	{
		delete[] _cStr;
		_cStr = NULL;
		_iSize = 0;
	}
}

int MyString::length()
{
	return _iSize;
}

int getLength(char* s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;

}

ostream& operator<<(ostream& outDev, const MyString& s)
{
	outDev << s._cStr;
	return outDev;
}

bool resize(char* &str, int &size, int newsize)
{
	char* newstr = new char[newsize + 1];
	if (newstr != NULL)
	{
		for (int i = 0; i <= size; i++)
			newstr[i] = str[i]; // copy noi dung
		delete[] str;
		str = newstr; //tro den vi tri moi
		size = newsize; //thay doi kich thuoc
		return true;
	}
	return false;
}

bool MyString::insert(int Start_Pos, char* s)
{
	int n = getLength(s);
	if (s != NULL && Start_Pos >= 0 && Start_Pos <= _iSize)
	{
		int oldsize = _iSize;
		
		if (resize(_cStr, _iSize, _iSize + n) == false) //Tang chieu dai cua chuoi len = oldsize + length(s)
			return false;

		for (int i = oldsize; i >= Start_Pos; i--) 
			_cStr[i + n] = _cStr[i]; //Doi doan ki tu bat dau tu start_pos ve cuoi mang (ke ca \0)

		for (int i = Start_Pos; i < Start_Pos + n; i++)
			_cStr[i] = s[i - Start_Pos]; //Dien chuoi s vao nhung cho con trong cua chuoi _cStr
		return true;
	}
	return false;
}

bool MyString::erase(int Start_Pos, int size)
{
	if (Start_Pos >= 0 && Start_Pos + size <= _iSize)
	{
		for (int i = Start_Pos; i <= _iSize - size; i++)
			_cStr[i] = _cStr[i + size]; //Doi doan ki tu ve start_pos

		if (resize(_cStr, _iSize, _iSize - size) == false) //thu hep lai chuoi
			return false;

		return true;
	}
	return false;
}