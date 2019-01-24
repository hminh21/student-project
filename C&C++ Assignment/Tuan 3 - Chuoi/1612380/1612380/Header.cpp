#include "Header.h"

//Count number of Array string
int StringLength(char* src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return i;
}

//Copy number of char from src to dest
char* StringNCopy(char* dest, char *src, int numChars)
{
	int DestLength = StringLength(dest); 

	if (numChars > StringLength(src)) //When user type numChars > length of string src
		numChars = StringLength(src);

	for (int i = 0; i < numChars; i++)
	{
		dest[DestLength] = src[i]; //Copy chars of string src to string of dest, start at dest[DestLength] position
		DestLength++;
	}

	dest[DestLength] = '\0'; //End of string

	return dest;
}

//Copy src string to dest string
char* StringCopy(char* dest, char* src)
{
	int i = 0, DestLength = StringLength(dest);
	do
	{
		dest[DestLength++] = src[i++];//Copy chars of string src to string of dest 
	} 
	while (src[i-1] != '\0');
	return dest;
}

//Delete numChars of src string from startPos
void DeleteSubString(char* str, int startPos, int numChars)
{
	int i = startPos - 1;
	do
	{
		str[i] = str[i + numChars]; //Move chars after deleting - chars with distance is "numChars" 
		i++;
	}
	while (str[i + numChars] != '\0');

	str[StringLength(str) - numChars] = NULL; //Delete chars, start at str[StringLength(str) - numChars]

	str[StringLength(str)] = '\0';  //end of string
}

//Find sub string from string
int FindSubString(char* str, char* substr, int startPos)
{
	int LengthStr = StringLength(str);
	int LengthSubStr = StringLength(substr);

	if (LengthStr < LengthSubStr) //when length of str < length of substr, false logic
		return -1;

	for (int i = startPos - 1; i <= LengthStr; i++) //Check char in str with substr one by one
	{
		if (str[i] == substr[0]) //when char in str == first char of substr
		{
			int Pos = i + 1, flag = 0; //use Pos to check next chars in str with the other chars of substr
			for (int j = 1; j < LengthSubStr; j++)  
			{
				if (str[Pos] != substr[j]) //when 1 situation is false, flag++ and break the loop immediately
				{
					flag++;
					break;
				}
				Pos++;
			}
			if (flag == 0) //when flag == 0 -> there is substr in str -> return its position
				return i+1;
		}
	}
	return -1; 
}

//Check sub string from string
bool IsSubString(char* str, char* substr)
{
	if (FindSubString(str, substr, 1) == -1) //find substr in str, start at fist position
		return false;
	return true;
}

//Count times sub string appear in string
int CountMatches(char* str, char* substr) 
{
	int icount = 0;
	
	int LengthStr = StringLength(str);
	int LengthSubStr = StringLength(substr);

	if (LengthStr < LengthSubStr) //when length of str < length of substr, false logic
		return -1;

	for (int i = 0; i <= LengthStr; i++) //Check char in str with substr one by one
	{
		if (str[i] == substr[0]) //when char in str == first char of substr
		{
			int Pos = i + 1, flag = 0; //use Pos to check next chars in str with the other chars of substr
			for (int j = 1; j < LengthSubStr; j++)
			{
				if (str[Pos] != substr[j]) //when 1 situation is false, flag++ and break the loop immediately
				{
					flag++;
					break;
				}
				Pos++;
			}
			if (flag == 0) //when flag == 0 -> there is substr in str 
				icount++;
		}
	}
	return icount;
}