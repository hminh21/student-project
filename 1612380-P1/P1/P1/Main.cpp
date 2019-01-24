#include "Header.h" //1612380

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		cout << "Tham so dong lenh nhap sai" << endl;
		return 1;
	}
	char* T = NULL;
	char** P = NULL;
	int P_Num = 0;
	int k = 0;
	ReadFile(argv[1], argv[2], P, T, P_Num);
	WriteFile(argv[3], P, T, P_Num);
	return 0;
	_getch();
}