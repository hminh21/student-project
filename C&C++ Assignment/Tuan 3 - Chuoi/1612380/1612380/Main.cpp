#include "Header.h"

void main()
{
	char str1[max], str2[max];
	int numChars;
	printf("Enter the str1 string:");
	gets(str1);
	printf("Enter the str2 string:");
	gets(str2);

	printf("Enter number of char to copy from str1 string: ");
	scanf("%i", &numChars);
	StringNCopy(str2, str1, numChars);
	printf("str2 string after copy %i chars from str1 string:\n",numChars);
	puts(str2);

	StringCopy(str2, str1);
	printf("str2 string after copy from str1 string:\n");
	puts(str2);

	int Pos;
	printf("Enter number of char to delete from str2 string: ");
	scanf("%i", &numChars);
	printf("Enter position to delete char from str 2 string: ");
	scanf("%i", &Pos);
	printf("str2 string after delete 2 chars from position %i:\n",Pos);
	DeleteSubString(str2, Pos, numChars);
	puts(str2);
	printf("Position of str1 in str2: %i\n", FindSubString(str2, str1, 1));

	printf("Check str1 in str2: ");
	if (IsSubString(str2, str1) == true)
		printf("true\n");
	else
		printf("false\n");
	printf("Time str1 appear in str2: %i\n", CountMatches(str2, str1));
	_getch();
}