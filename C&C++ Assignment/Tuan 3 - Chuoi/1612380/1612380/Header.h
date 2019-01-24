#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

#define max 50

//Count length of string
int StringLength(char* src);

//Copy number of char from src string to dest string
char* StringNCopy(char* dest, char* src, int numChars);

//Copy src string to dest string
char* StringCopy(char* dest, char* src);

//Delete numChars of src string from startPos
void DeleteSubString(char* str, int startPos, int numChars);

//Find sub string from string
int FindSubString(char* str, char* substr, int startPos);

//Check sub string from string
bool IsSubString(char* str, char* substr);

//Count times sub string appear in string
int CountMatches(char* str, char* substr);