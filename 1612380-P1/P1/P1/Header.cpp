#include "Header.h" //1612380

unsigned int HashP(const char* P) //Tinh hashP
{
	unsigned int S = 0;
	for (int i = 0; i < strlen(P); i++)
		S += P[i]; //Chi phi O(m)
	return S;
}

unsigned HashT0(const char* T, int num) //Tinh hash&T[0]
{
	//num la do dai cua chuoi mau P
	unsigned HashT0 = 0;
	for (int i = 0; i < num; i++)
		HashT0 += T[i]; //Chi phi O(m)
	return HashT0;
}

unsigned int HashTi(const char* T, int pos, int OldHashT, int num) //Tinh hashT[i]
{
	unsigned HashTi = OldHashT - T[pos - 1] + T[pos - 1 + num]; //Tinh HashT[i] dua vao ket qua cua HashT[i-1], chi phi O(1)
	return HashTi;
}

bool Compare(const char* P, const char* T, int pos, int &k) //So sanh ki tu khi hashP = hashT[i]
{
	for (int i = 0; i < strlen(P); i++, pos++)
	{
		k++;
		if (P[i] != T[pos])
			return false;
	}
	return true;
}

int RabinKrap(const char* P, const char* T, int &k) //Ham tra ve vi tri tim duoc
{
	unsigned int hashP = HashP(P);
	unsigned int num = strlen(P); //Do dai cua chuoi mau P
	unsigned int *hashT = new unsigned int[strlen(T) - strlen(P) + 1];
	hashT[0] = HashT0(T, num);

	if (hashT[0] == hashP && Compare(P, T, 0, k) == true) //So sanh doan hashT[0] voi hashP
		return 0;

	for (int i = 1; i < strlen(T) - strlen(P) + 1; i++) //So sanh tiep doan hashT[i] voi hashP
	{
		hashT[i] = HashTi(T, i, hashT[i - 1], num);

		if (hashT[i] == hashP && Compare(P, T, i, k) == true) //Neu match se tra ve vi tri
			return i;
	}
	return -1;
	delete[] hashT;
}

void ReadFile(char* filenameP, char* filenameT, char** &P, char* &T, int &P_Num)
{
	ifstream fileP, fileT;
	fileP.open(filenameP, ios::in);
	fileT.open(filenameT, ios::in);
	int T_Length = 0;
	int P_Length = 0;
	char ch;

	if (!fileT) //Doc file T.txt
	{
		cout << "Khong doc duoc file T.txt" << endl;
	}
	else
	{
		while (fileT.get(ch)) //Hut ki tu tu file vao bien ch
		{
			CharPushBack(T, T_Length, ch); //Ghi vao mang ki tu
		}
		CharPushBack(T, T_Length, '\0'); //Ket thuc mang

	}
	fileT.close(); //Dong file T.txt


	if (!fileP) //Doc file P.txt
	{
		cout << "Khong doc duoc file P.txt" << endl;
	}
	else
	{
		while (fileP.get(ch))  //Doc so luong chuoi mau trong file P.txt
		{
			if (ch == '\n')
				P_Num++;
		}

		P = new char*[++P_Num]; //Tao mang 2 chieu chua chuoi mau 

		for (int i = 0; i < P_Num; i++)
			P[i] = NULL; // Gan NULL

		int j = 0;
		fileP.clear(); //Xoa bo nho dem
		fileP.seekg(0, fileP.beg); //Doi con tro ve vi tri dau tien de bat dau viec chep ki tu vao mang
		while (fileP.get(ch))
		{
			if (ch == '\n') //Loai bo ki tu '\n' va chuyen sang P[j++]
			{
				CharPushBack(P[j], P_Length, '\0');
				P_Length = 0;
				j++;
				continue;
			}
			CharPushBack(P[j], P_Length, ch); //Truyen ki tu vao mang 
		}
		CharPushBack(P[j], P_Length, '\0'); //Ket thuc mang P[P_Num - 1]
	}

	fileP.close(); //Dong file P.txt
}

void CharPushBack(char* &a, int& n, char ch) //Ghi vao mang ki tu 
{
	int m = n + 1;
	char* anew = (char*)realloc(a, m* sizeof(char));
	if (anew != NULL)
	{
		anew[n] = ch;
		n++;
		a = anew;
	}
}

void WriteFile(char* filename, char** P, char* T, int P_Num)
{
	ofstream output;
	output.open(filename, ios::out);

	if (output)
	{
		int pos;
		int k = 0;
		int *NEXT = NULL;

		output << "Rabin-Karp" << endl; //ghi vao file ket qua cua RK
		for (int i = 0; i < P_Num; i++)
		{
			pos = RabinKrap(P[i], T, k);
			if (pos != -1)
				output << i + 1 << ". " << P[i] << ":" << " true, pos=" << pos << ", " << k << endl;
			else
				output << i + 1 << ". " << P[i] << ":" << " fail" << endl;
			k = 0; //reset k
		}

		output << endl;
		output << "KMP" << endl; //Ghi vao file ket qua cua KMP

		for (int i = 0; i < P_Num; i++)
		{
			pos = KMP(P[i], T, NEXT);
			if (pos != -1)
			{
				output << i + 1 << ". " << P[i] << ":" << "true, pos=" << pos << endl;
				output << "+ " << "NEXT: ";
				for (int j = 0; j < strlen(P[i]); j++)
					output << NEXT[j] << " ";
				output << endl;
			}
			else
			{
				output << i + 1 << ". " << P[i] << ":" << "fail" << endl;
				output << "+ " << "NEXT: ";
				for (int j = 0; j < strlen(P[i]); j++)
					output << NEXT[j] << " ";
				output << endl;
			}

		}
		cout << "Ghi file output.txt thanh cong" << endl;

		for (int i = 0; i < P_Num; i++)
		{
			delete[] P[i];
			P[i] = NULL;
		}
		delete P;
		P = NULL;
		delete[] T;
		T = NULL;
	}
	else
	{
		cout << "Khong the ghi file output.txt" << endl;
		return;
	}
	output.close();

}

void initNEXT_KMP(const char* P, int* NEXT) //Tinh bang NEXT trong thuat toan KMP
{
	int i, j;
	short int m = strlen(P); //do dai cua chuoi P
	i = 0;
	j = NEXT[0] = -1;
	while (i < m - 1)
	{
		if (j == -1 || P[i] == P[j])
		{
			i++;
			j++;
			if (P[i] != P[j]) //kiem tra xem P[i] co giong P[j] khong, neu co thi cho NEXT bang nhau de tranh bi MISMATCH lan sau
				NEXT[i] = j;
			else
				NEXT[i] = NEXT[j];
		}
		else
			j = NEXT[j];
	}
}

int KMP(const char* P, const char* T, int* &NEXT)
{
	unsigned short int m = strlen(P);

	NEXT = new int[m];
	initNEXT_KMP(P, NEXT); //Tao bang next

	short int i, j, n;
	i = j = 0;
	n = strlen(T);
	while (i + j < n) //duyet den T[n - m - 1]
	{
		if (P[j] == T[i + j])
		{
			j++;
			if (j == m) return i;
		}
		else {
			i = i + j - NEXT[j];
			if (NEXT[j] == -1) //Tranh truong hop chuong trinh gan j = NEXT[j] = -1
				j = 0;
			else
				j = NEXT[j];
		}
	}
	return -1;
}