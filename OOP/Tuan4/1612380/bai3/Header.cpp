#include "Header.h"

void ReadFile(ifstream& fs, vector <Class> &c)
{
	Class p;
	if (!fs)
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}

	while (!fs.eof())
	{
		fs >> p;
		c.push_back(p);
	}
	fs.close();
}

void SortClass(vector <Class> &c)
{
	for (int i = 0; i < c.size() - 1; i++)
	{
		for (int j = i + 1; j < c.size(); j++)
		{
			if (c[i] > c[j])
			{
				Class temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
		}
	}
}

void WriteFile(ofstream& fs, const vector <Class> &c)
{
	fs << c[0];
	for (int i = 1; i < c.size(); i++)
	{
		fs << "-----------" << endl;
		fs << c[i];
	}
	fs.close();
}