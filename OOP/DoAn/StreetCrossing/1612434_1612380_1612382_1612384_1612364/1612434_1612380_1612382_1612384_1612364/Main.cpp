#include "GLOBAL.h"
#include "CGAME.h"
#include<iostream>
#include<conio.h>
#include"console.h"
#include"Header.h"
#include<fstream>
#include<thread>
#include<time.h>
#pragma comment (lib, "winmm.lib")
using namespace std;
void main()
{
	int temp;
	ShowCur(false);
	FixConsoleWindow();
	DWORD third;
	HANDLE handle_Menu = CreateThread(NULL, 0, DrawOpening, NULL, 0, &third);
	PlaySound(L"theme", NULL, SND_ASYNC | SND_LOOP);
	GoToXY(0, 2);
	//Vao giao dien Menu
	while (1)
	{
		temp = toupper(getch());
		if (temp == '2') //Luu
		{
			cg->pauseGame(handle_Menu);
			system("cls");
			GoToXY(WIDTH_CONSOLE + 5, 15);
			cout << "----------LOAD GAME----------" << endl;
			GoToXY(WIDTH_CONSOLE + 5, 16);
			cout << "File location:";
			fflush(stdin);
			string str;
			getline(cin, str);
			if (cg->loadGame(str)== true) //Xu li khi mo file thanh cong
			{
				TerminateThread(handle_Menu,0);
				PlaySound(NULL, NULL, 0);
				system("cls");
				fflush(stdin);
				cg->startGame();
				break;
			}
			else //Xu li de ham tiep tuc chay thread handle_t2
			{
				GoToXY(WIDTH_CONSOLE + 5, 18);
				cout << "Cannot load the file" << endl;
				Sleep(2000);
				system("cls");
				continue;
			}
		}
		else
		if (temp == '4') //Esc
		{
			TerminateThread(handle_Menu, 0);
			PlaySound(NULL, NULL, 0);
			system("cls");
			return;
		}
		else if (temp == '3') //Settings
		{
			PlaySound(NULL, NULL, 0);
			TerminateThread(handle_Menu, 0);
			system("cls");
			cg->drawSettings();
			system("cls");
			cg->startGame();
			break;

		}
		else if (temp == '1') //Vao game
		{
			TerminateThread(handle_Menu, 0);
			PlaySound(NULL, NULL, 0);
			system("cls");
			fflush(stdin);
			cg->startGame();
			break;
		}
	}

	thread t1(SubThread); //Tao thread game
	thread tSound(SoundThread); //Tao thread sound
	HANDLE handle_sound = tSound.native_handle();

	HANDLE handle_t1 = t1.native_handle();

	int PauseTemp = 0;
	
	//Vao game
	while (1)
	{
		temp = toupper(_getch());
		if (temp == 27) //Esc
		{
			cg->exitGame(handle_t1);
			cg->exitGame(handle_sound);
			return;
		}
		else if (temp == 'L') //Save
		{
			cg->pauseGame(handle_t1);
			cg->pauseGame(handle_sound);
			string str;
			GoToXY(WIDTH_CONSOLE + 5, 15);
			cout << "----------SAVE GAME----------" << endl;
			GoToXY(WIDTH_CONSOLE + 5, 16);
			cout << "File location:";
			fflush(stdin);
			getline(cin, str);
			if (cg->saveGame(str) == true) //Neu save thanh cong
			{
				system("cls");
				cg->drawBoard();
				cg->drawGame();
				cg->resumeGame(handle_t1);
				cg->resumeGame(handle_sound);
			}
			else
			{
				GoToXY(WIDTH_CONSOLE + 5, 18);
				cout << "Cannot save the file" << endl;
				Sleep(2000);
				system("cls");
				cg->drawBoard();
				cg->drawGame();
				cg->resumeGame(handle_t1);
				cg->resumeGame(handle_sound);
			}

		}
		else if (temp == 'T') //Load
		{
			cg->pauseGame(handle_t1);
			cg->pauseGame(handle_sound);
			GoToXY(WIDTH_CONSOLE + 5, 15);
			cout << "----------LOAD GAME----------" << endl;
			GoToXY(WIDTH_CONSOLE + 5, 16);
			cout << "File location:";
			string str;
			fflush(stdin);
			getline(cin, str);
			if (cg->loadGame(str) == true) //Neu load game duoc
			{
				system("cls");
				cg->drawBoard();
				cg->drawGame();
				cg->resumeGame(handle_t1);
				cg->resumeGame(handle_sound);
			}
			else
			{
				GoToXY(WIDTH_CONSOLE + 5, 18);
				cout << "Cannot load the file" << endl;
				Sleep(2000);
				system("cls");
				cg->drawBoard();
				cg->drawGame();
				cg->resumeGame(handle_t1);
				cg->resumeGame(handle_sound);
			}
		}
		else
			MOVING = temp; //Truyen temp vao MOVING


		if (cg->getPeople().isDead() == false)
		{
			if (PauseTemp == 1) //Neu nhu da pause game
			{			
				PauseTemp = 0; //unpause
				cg->resetGame();
				cg->resumeGame(handle_t1);
				cg->resumeGame(handle_sound);
			
			}
			else if (temp == 'P') //Pause
			{
				GoToXY(30, HEIGHT_CONSOLE + 3);
				cout << "GAME PAUSED";
				GoToXY(20, HEIGHT_CONSOLE + 4);
				cout << "Press P to continue the game";
				fflush(stdin);
				cg->pauseGame(handle_t1);
				cg->pauseGame(handle_sound);
				PauseTemp = 1;

			}
		}
		else //Neu chet
		{
				if (temp == 'Y') //Yes de choi lai
				{
					cg->pauseGame(handle_t1);
					cg->resetGame();
					cg->resumeGame(handle_t1);
				}
				else if (temp == 27)// Nhan nut ESC de thoat
				{
					cg->exitGame(handle_t1);
					cg->exitGame(handle_sound);
					return;
				}
		}
	}
	delete cg;
	_getch();
}