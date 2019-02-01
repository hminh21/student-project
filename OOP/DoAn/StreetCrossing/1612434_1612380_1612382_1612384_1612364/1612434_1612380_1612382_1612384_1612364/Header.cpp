#include"Header.h"
#include<windows.h>
#include<conio.h>
#include"CPEOPLE.h"



void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX)& ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
	int x = HEIGHT_CONSOLE;
}

DWORD WINAPI DrawOpening(LPVOID x) //Ve logo
{
	int Arr[] = { 9, 10, 12, 13, 14 }, i = 0;
	
	for (int j = 0; j > -1; j++)
	{
		cg->Menu(45, 15);
		GoToXY(5, 24);
		Draw("NGUYEN HOANG LUU", 11);
		GoToXY(5, 25);
		Draw("PHAM HOANG MINH", 11);
		GoToXY(5, 26);
		Draw("HUYNH NGUYEN NHAT MINH", 11);
		GoToXY(5, 27);
		Draw("NGUYEN TRAN DUY MINH", 11);
		GoToXY(5, 28);
		Draw("LUU TUAN NGUYEN", 11);

		GoToXY(60, 25);
		Draw("GROUP 06 - OBJECT ORIENTED PROGRAMMING", 11);
		GoToXY(60, 26);
		Draw("1612364 - 1612380 - 1612382 - 1612384 - 1612434", 11);
		GoToXY(60, 27);
		Draw("16CTT3 UNIVERSITY OF SCIENCE", 11);
		GoToXY(60, 28);
		Draw("LECTURER: TRUONG TOAN THINH", 11);

		GoToXY(0, 1);
		Draw("              _|_|_|_|  _|_|_|_|_|  _|_|_|_|  _|_|_|_|  _|_|_|_|  _|_|_|_|_|               \n", Arr[i]);
		Draw("              _|            _|      _|    _|  _|        _|            _|      \n", Arr[i]);
		Draw("              _|_|_|_|      _|      _|_|_|_|  _|_|_|_|  _|_|_|_|      _|            \n", Arr[i]);
		Draw("                    _|      _|      _|  _|    _|        _|            _|    \n", Arr[i]);
		Draw("              _|_|_|_|      _|      _|    _|  _|_|_|_|  _|_|_|_|      _|            \n", Arr[i]);
		GoToXY(0, 7);
		Draw("        _|_|_|_|  _|_|_|_|  _|_|_|_|  _|_|_|_|  _|_|_|_|  _|  _|      _|  _|_|_|_|             \n", Arr[i]);
		Draw("        _|        _|    _|  _|    _|  _|        _|        _|  _|_|    _|  _|                  \n", Arr[i]);
		Draw("        _|        _|_|_|_|  _|    _|  _|_|_|_|  _|_|_|_|  _|  _|  _|  _|  _|  _|_|_|          \n", Arr[i]);
		Draw("        _|        _|  _|    _|    _|        _|        _|  _|  _|    _|_|  _|    _|       \n", Arr[i]);
		Draw("        _|_|_|_|  _|    _|  _|_|_|_|  _|_|_|_|  _|_|_|_|  _|  _|      _|  _|_|_|_|            \n", Arr[i]);

		
		i++;
		if (i == 5) i = 0;
		Sleep(500);
	}
	return 0;
}

void effectLevelUp() //Hieu ung level up
{
		PlaySound(L"levelup", NULL, SND_ASYNC); //Choi nhac khi level up
		string str[7] = { "L", "E", "V", "E", "L", "U", "P" };
		for (int i = 0, j = 33; i < 7; i++, j++)
		{
			GoToXY(j, 11);
			Draw(str[i], 14);
			Sleep(100);
		}
		for (int i = 0; i < 5; i++)
		{
			GoToXY(32, 10);
			Draw("*", 14);
			GoToXY(32, 12);
			Draw("*", 14);
			GoToXY(32, 11);
			Draw("*", 14);
			GoToXY(36, 10);
			Draw("*", 14);
			GoToXY(36, 12);
			Draw("*", 14);
			GoToXY(40, 10);
			Draw("*", 14);
			GoToXY(40, 11);
			Draw("*", 14);
			GoToXY(40, 12);
			Draw("*", 14);
	
			GoToXY(31, 9);
			Draw("*", 14);
			GoToXY(31, 13);
			Draw("*", 14);
			GoToXY(30, 11);
			Draw("* ", 14);
			GoToXY(36, 9);
			Draw("*", 14);
			GoToXY(36, 13);
			Draw("*", 14);
			GoToXY(41, 9);
			Draw("*", 14);
			GoToXY(41, 11);
			Draw(" *", 14);
			GoToXY(41, 13);
			Draw("*", 14);
	
			Sleep(200);
	
			GoToXY(32, 10);
			Draw(" ", 14);
			GoToXY(32, 12);
			Draw(" ", 14);
			GoToXY(32, 11);
			Draw(" ", 14);
			GoToXY(36, 10);
			Draw(" ", 14);
			GoToXY(36, 12);
			Draw(" ", 14);
			GoToXY(40, 10);
			Draw(" ", 14);
			GoToXY(40, 11);
			Draw(" ", 14);
			GoToXY(40, 12);
			Draw(" ", 14);
	
			GoToXY(31, 9);
			Draw(" ", 14);
			GoToXY(31, 13);
			Draw(" ", 14);
			GoToXY(30, 11);
			Draw("  ", 14);
			GoToXY(36, 9);
			Draw(" ", 14);
			GoToXY(36, 13);
			Draw(" ", 14);
			GoToXY(41, 9);
			Draw(" ", 14);
			GoToXY(41, 11);
			Draw("  ", 14);
			GoToXY(41, 13);
			Draw(" ", 14);
	
			Sleep(200);
		}
		system("cls");
}

void deadEffect() //Hieu ung chet
{
	PlaySound(L"die", NULL, SND_ASYNC);
	
	GoToXY(cg->getPeople().getX(), cg->getPeople().getY());
	cout << "  X  ";
	Sleep(200);
	GoToXY(cg ->getPeople().getX(), cg->getPeople().getY() - 1);
	cout << " X X";
	GoToXY(cg->getPeople().getX(), cg->getPeople().getY() + 1);
	cout << " X X ";
	Sleep(200);
	GoToXY(cg->getPeople().getX(), cg->getPeople().getY() + 2);
	cout << "X   X";
	GoToXY(cg->getPeople().getX(), cg->getPeople().getY() - 2);
	cout << "X   X";
	GoToXY(35, 24);
	cout << "GAME OVER";
	GoToXY(30,25);
	cout << "PRESS Y TO RESTART";
}

