#include "Header.h"

istream& operator>>(istream& inDev, FRACTION& fr) //qua tai toan tu
{
	inDev >> fr.numerator >> fr.denominator;
	return inDev;
}

ostream& operator<<(ostream& outDev, FRACTION& fr)//qua tai toan tu
{
	if (fr.denominator < 0)
	{
		fr.numerator = -fr.numerator;
		fr.denominator = -fr.denominator;
	}
	if (fr.denominator == 0 || fr.denominator == 1)
		outDev << fr.numerator;
	else
		outDev << fr.numerator << "/" << fr.denominator;
	return outDev;
}

void ReplaceChar(char oldChar, char newChar, fstream &fs)//thay doi ki tu
{
	char ch;
	while (fs.get(ch))
	{
		if (ch == oldChar)
		{
			int pos = fs.tellg();
			pos--; //Giam pos 1 don vi do ham put se di chuyen con tro ghi sang phai 1 don vi truoc khi ghi
			fs.seekp(pos); //Di chuyen con tro ghi
			fs.put(newChar); //Ghi newChar vao vi tri chua oldChar
			fs.seekg(pos + 1); //Di chuyen con tro doc ve vi tri cu
		}
	}
}

int CopyFile(string fileName1, string fileName2)//copy file 2 vao file 1
{
	ofstream fs1(fileName1, ios::out);
	ifstream fs2(fileName2, ios::in);
	
	if (!fs2)
	{
		cout << "Khong the mo file " << fileName2 << endl;
		return 0;
	}
	else 
		cout << "Mo file " << fileName2 << " thanh cong" << endl;

	char ch;
	while (fs2.get(ch))
	{
		fs1.put(ch);
	}
	fs1.close();
	fs2.close();
	return 1;
}

FRACTION* ReadArrayFraction(istream& inDev, int& n) //doc mang phan so tu file
{
	if (!inDev)
	{
		cout << "Khong mo duoc file" << endl;
	}

	const int maxsize = 255;
	char buf[maxsize + 1];
	while (inDev.getline(buf, maxsize))
	{
		n++; //Dem so dong co trong file
	}

	inDev.clear(); //Xoa con tro va thiet lap con tro moi tai vi tri ban dau
	inDev.seekg(0,inDev.beg);

	FRACTION* ArrFr = NULL;
	if (n <= 0) return ArrFr;

	ArrFr = new FRACTION[n]; //Cap bo nho cho mang n phan so
	if (ArrFr != NULL)
	{
		for (int i = 0; i < n; i++)
		{
			inDev >> ArrFr[i]; //Truyen du lieu tu file vao mang phan so

			/*inDev >> ArrFr[i].numerator;
			inDev >> ArrFr[i].denominator;*/

			if (inDev.fail())
			{
				delete[] ArrFr;
				ArrFr = NULL;
				break;
			}
		}
	}
	return ArrFr;
}

void Swap(FRACTION &fr1, FRACTION &fr2) //Hoan doi vi tri
{
	float a = (float)fr1.numerator / fr1.denominator;
	float b = (float)fr2.numerator / fr2.denominator;
	if (b < a)
	{
		FRACTION temp = fr2;
		fr2 = fr1;
		fr1 = temp;
	}
}

void SortFraction(FRACTION *& fr, int n) //sap xep mang phan so tang dan
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			Swap(fr[i], fr[j]);
		}
	}
}

void WriteArrayFraction(ostream& outDev, FRACTION* fr, int n) //ghi du lieu vao file
{

	for (int i = 0; i < n; i++)
	{
		//char buf[5];
		//itoa(fr[i].numerator, buf, 10); //Ham chuyen doi so nguyen sang ki tu
		//char num = *buf;
		//outDev.put(num); //Ghi tu so vao file
		//outDev.put(' ');
		//itoa(fr[i].denominator, buf, 10); //Ham chuyen doi so nguyen sang ki tu
		//char den = *buf;
		//outDev.put(den); //Ghi mau so vao file
		//outDev.put('\n');
		outDev << fr[i].numerator << " " << fr[i].denominator << "\n"; 
	}
}

void ReadAndWrite(istream& inDev)
{
	int n = 0;
	FRACTION *fr;

	fr = ReadArrayFraction(inDev, n);

	SortFraction(fr, n);
	
	ofstream fs4("PHANSOCPY.txt", ios::out);
	WriteArrayFraction(fs4, fr, n);
	delete[] fr;
	fs4.close();//Dong file
}

void Statistic(istream& inDev) //Thong ke file
{
	ofstream fs6("THONGKE.txt", ios::out);

	char ch;
	int icount[max]; //Tao mang dem 
	for (int i = 0; i < max; i++)
	{
		if ((i >= 33 && i <= 64) || (i >= 91 && i <= 126))
		{
			icount[i] = 0; //Gan mang dem voi 0
		}
	}

	while (inDev.get(ch))
	{
		if (ch >= 33 && ch <= 126)
		{
			if (ch > 64 && ch < 91)
				ch += 'a' - 'A';
			icount[ch]++;//Dem ki tu, khi doc duoc ki tu se tang bien dem cua ki tu tuong ung len 1 don vi
		}
	}

	for (char i = 33; i <= max - 1; i++)
	{
		if ((i >= 33 && i <= 64) || (i >= 91 && i <= 126))
		{
			if (icount[i] != 0)
				fs6 << i << ": " << icount[i] << endl; //Ghi ra file
		}
	}

	fs6.close();//Dong file
}