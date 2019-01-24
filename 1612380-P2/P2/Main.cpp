#include "Header.h"
#include <conio.h>


void main()
{
	string* name = NULL;
	cout << "     --------------------------COMPRESS AND EXTRACT - STATIC HUFFMAN---------------------------------" << endl;
	cout << "\t\t\t\t" << "0. Exit" << endl;
	cout << "\t\t\t\t" << "1. Compress folder" << endl;
	cout << "\t\t\t\t" << "2. Watch information of compressed file" << endl;
	cout << "\t\t\t\t" << "3. Extract all files" << endl;
	cout << "\t\t\t\t" << "4. Choose and extract some files" << endl;
	cout << "     ------------------------------------------------------------------------------------------------" << endl << endl;
	int x, num_of_file = 0;
	while (1)
	{
		cout << "Choose:";
		cin >> x;
		switch (x)
		{
		case 0: return;
		case 1:	select_1(name, num_of_file); break;
		case 2: select_2(name, num_of_file); break;
		case 3: select_3(); break;
		case 4: select_4(); break;
		default: break;
		}
	}
	if (name != NULL)
		delete[] name;
	_getch();
}