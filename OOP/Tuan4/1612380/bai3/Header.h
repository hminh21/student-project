#ifndef Header_H
#define Header_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Class.h"
using namespace std;


class Class;
void ReadFile(ifstream&, vector <Class> &);
void SortClass(vector <Class> &);
void WriteFile(ofstream&, const vector <Class> &);
#endif