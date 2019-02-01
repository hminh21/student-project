#include "LIBRARY.h"

vector <int> codeReader;

LIBRARY::LIBRARY()
{

}

LIBRARY::~LIBRARY()
{
	_mem.clear();
}

LIBRARY::LIBRARY(MEMBER* &m)
{
	_mem.push_back(m);
}

LIBRARY::LIBRARY(const LIBRARY& l)
{
	for (int i = 0; i < l._mem.size(); i++)
	{
		MEMBER* m = NULL;
		if (l._mem[i]->getClass() == "CHILD")
			m = new CHILD(*l._mem[i]);
		else if (l._mem[i]->getClass() == "ADULT")
			m = new ADULT(*l._mem[i]);

		_mem.push_back(m);
	}
}

bool LIBRARY::Input()
{
	ifstream fin;

	fin.open("INPUT.txt", ios::in);

	if (!fin)
	{
		cout << "Khong the doc file INPUT.txt" << endl;
		return false;
	}
	char ch;
	int CodeReader, pos;
	while (!fin.eof())
	{
		fin >> CodeReader >> ch;
		pos = fin.tellg();
		if (!fin.eof())
		{
			codeReader.push_back(CodeReader);
			MEMBER* m = new CHILD;
			fin >> *m;
			if (2017 - m->get_date().year > 12)
			{
				delete m;
				m = new ADULT;
				fin.seekg(pos);
				fin >> *m;
			}
			_mem.push_back(m);
		}
	}
	fin.close();
}

bool LIBRARY::Output()
{
	ofstream fout;
	fout.open("OUTPUT.txt", ios::out);

	if (!fout)
	{
		cout << "Khong the ghi file OUTPUT.txt" << endl;
		return false;
	}

	for (int i = 0; i < _mem.size(); i++)
		fout << codeReader[i] << ", " << *_mem[i] << endl;
	fout.close();
	codeReader.clear();
}

bool LIBRARY::Total()
{
	ofstream fout;
	fout.open("TOTAL.txt", ios::out);
	
	if (!fout)
	{
		cout << "Khong the ghi file TOTAL.txt" << endl;
		return false;
	}
	unsigned long sum = 0;
	for (int i = 0; i < _mem.size(); i++)
		sum += _mem[i]->MoneyLoan();

	fout << sum;
	fout.close();
	return true;
}

bool LIBRARY::Statistic()
{
	ofstream fout;
	fout.open("STATISTIC.txt", ios::out);

	if (!fout)
	{
		cout << "Khong the ghi file STATISTIC.txt" << endl;
		return false;
	}
	int aM, aF, cM, cF, adult, child;
	aM = aF = cM = cF = adult = child = 0;
	for (int i = 0; i < _mem.size(); i++)
	{
		if (_mem[i]->getClass() == "ADULT")
		{
			adult++;
			if (_mem[i]->get_sex() == true)
				aM++;
			else
				aF++;
		}
		else
		{
			child++;
			if (_mem[i]->get_sex() == true)
				cM++;
			else
				cF++;
		}
	}
	fout << "Adult: " << adult << "(" << aM << " M," << aF << " F)" << endl;
	fout << "Adult: " << adult << "(" << cM << " M," << cF << " F)";

	fout.close();
}