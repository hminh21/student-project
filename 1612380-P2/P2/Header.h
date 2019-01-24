#ifndef _Header_h
#define _Header_h
#include <iostream>
#include <fstream>
#include "PRIORITY_QUEUE.h"
#include <string>
#include <Windows.h>
#include <vector>
#include "Queue.h"
#include <iomanip>
using namespace std;

#define MAX_NODE 511 //256*2-1
#define MAX_UNSIGNED_CHAR 256
#define MAX_BIT 8
struct HUFFNode
{
	unsigned char c; //character
	long freq; //frequency
	int left; //left child
	int right; //right child
};



struct TYPE_FILE
{
	string oldName;
	unsigned int bytes;
	unsigned int length;
	short bit_LastByte; //number of zero in the last byte
};


void InitHuffTree(int size);
int createHuffTree(int num);
string inverse(string &str);
void get_all_files_names_within_folder(string folder, Queue& names);
int heightHuffTree(int nNode, int num);
bool Allocate(int size, bool isCompress);
void Free(int size, bool isCompress);
int countChar(string str,char ch);

//COMPRESS

bool readFileToEncode(string filename, string type, int pos);
void processHuffTree(int nNode, string bit, int num);
bool encode(int size,string* fInput, string fOutput);
void writeHeader(ofstream& fOutput, int& pos, int size);
void createBit(char &c, char bit, int i);
bool COMPRESSTO(string* fInput, string* type, int num_of_file, string fOutput);

//EXTRACT
bool readFileToDecode(string filename, int& size, int& pos);
bool getBit(char c, int i);
bool decode(string fInput, string folder, string file, int& size);
unsigned char reprocessingHuffTree(string bin, int &pos, int nNode, int num);
bool checkSum(int sizeBefore, int sizeAfter);
bool EXTRACTTO(string fInput, string folder, string file);
bool findFileToExtract(int* num,int number, int i);

//MENU
void select_1(string* &temp, int& num_of_file);
void select_2(string *name, int num_of_file);
void select_3();
void select_4();
#endif