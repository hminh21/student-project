#include "FARM.h"


CFARM::CFARM()
{
}

CFARM::CFARM(CANIMAL* a)
{
	_ConVat.push_back(a);
}

CFARM::CFARM(const CFARM& f)
{
	for (int i = 0; i < f.get_ConVat().size(); i++)
	{
		_ConVat.push_back(f.get_ConVat().at(i));
	}
}

CFARM::~CFARM()
{
	_ConVat.clear();
}

void CFARM::addAnimal(CANIMAL* a)
{
	_ConVat.push_back(a);
	if (a->get_Tuoi() > a->get_TuoiDoi()) 
		a->set_TrangThai(-1); //Chet
}

CANIMAL* CFARM::createAnimal(string type)
{
	CANIMAL* a;
	if (type == "ga")
		a = new CCHICKEN;
	else if (type == "bo")
		a = new CCOW;
	else if (type == "heo")
		a = new CPIG;
	else if (type == "cuu")
		a = new CSHEEP;
	else
	{
		cout << "Loai con vat khong ton tai" << endl;
		return NULL;
	}

	if (a == NULL)
	{
		cout << "khong du bo nho" << endl;
		return NULL;
	}
	return a;
}

void CFARM::printFarm()
{
	for (int i = 0; i < _ConVat.size(); i++)
	{
		cout << "--------------- Con vat " << i + 1 << " ---------------" << endl;
		cout << *(_ConVat.at(i)) << endl;
	}
}

bool CFARM::killAnimal(int MaSo)
{
	int pos = findAnimal(MaSo);
	if (pos == -1)
		return false;
	_ConVat.erase(_ConVat.begin() + pos);
	return true;
}

void CFARM::feedFarm(float food)
{
	for (int i = 0; i < _ConVat.size(); i++)
		_ConVat[i]->Eat(food);
}

bool CFARM::feedAnimal(int MaSo, float food)
{
	int pos = findAnimal(MaSo);
	if (pos == -1)
		return false;
	_ConVat[pos]->Eat(food);
	return true;
}

bool CFARM::moveAnimal(int MaSo, float x, float y)
{
	int pos = findAnimal(MaSo);
	if (pos == -1)
		return false;
	_ConVat[pos]->Move(x,y);
	return true;
}

int CFARM::findAnimal(int MaSo)
{
	for (int i = 0; i < _ConVat.size(); i++)
	{
		if (MaSo == _ConVat[i]->get_MaSo())
			return i; //Tra ve vi tri tim ra 
	}
	return -1;
}

void CFARM::FarmAfterTime(int time)
{
	for (int i = 0; i < _ConVat.size(); i++)
		_ConVat[i]->UpdateStatus(time);
}

bool CFARM::readFile()
{
	ifstream fin;
	fin.open("input.txt", ios::in);
	if (!fin)
	{
		cout << "Khong the doc file" << endl;
		return false;
	}

	CANIMAL* a;
	string str, temp;

	while (!fin.eof())
	{
		fin >> str;
		a = createAnimal(str);
		fin >> *a;
		addAnimal(a);
	}
	fin.close();
	return true;
}

bool CFARM::writeFile()
{
	ofstream fout;
	fout.open("output.txt", ios::out);
	if (!fout)
	{
		cout << "Khong the ghi file" << endl;
		return false;
	}

	for (int i = 0; i < _ConVat.size(); i++)
	{
		fout << "--------------- Con vat " << i + 1 << " ---------------" << endl;
		fout << *_ConVat[i] << endl;
	}
	fout.close();
	return true;
}

int CFARM::printMenu()
{
	cout << "----------MENU----------" << endl;
	cout << "1. Them cac con vat vao trang trai" << endl;
	cout << "2. Liet ke danh sach cac con vat" << endl;
	cout << "3. Giet mot con vat" << endl;
	cout << "4. Xuat ra thong tin cua cac con vat sau t gio" << endl;
	cout << "5. Cho dong loat tat ca cac con vat an" << endl;
	cout << "6. Cho 1 con an" << endl;
	cout << "7. Cho con vat di chuyen" << endl;
	cout << "8. Doc thong tin tu file input" << endl;
	cout << "9. Xuat thong tin ra file output" << endl;
	cout << "0. Thoat" << endl;
	cout << "--------------------" << endl;

	cout << "Nhap so can thao tac:";
	int b;
	cin >> b;
	while (b < 0 || b > 9)
	{
		cout << "Thao tac khong hop le" << endl;
		cout << "Nhap so can thao tac:";
		cin >> b;
	}
	return b;
}