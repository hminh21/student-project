#ifndef _Header_h
#define _Header_h
#include<iostream>
#include<Windows.h>
#include<string>
#include"console.h"
#include <thread>
#include "GLOBAL.h"
#include "CGAME.h"
using namespace std;
void Draw(string str, int color);
void FixConsoleWindow();
DWORD WINAPI DrawOpening(LPVOID x); //Ve logo
void effectLevelUp(); //Hieu ung level up
void deadEffect(); //Hieu ung chet

#endif