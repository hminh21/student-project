#include "Header.h"
HUFFNode **huffTree;
long **freq;
TYPE_FILE *header;
string** bit;
int* bytesAfter = NULL;

void get_all_files_names_within_folder(string folder, Queue& names)
{
	string search_path = folder + "/*.*";
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				names.enqueue(fd.cFileName);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
}

string inverse(string &str)
{
	unsigned char temp;
	for (int i = 0; i < str.size() / 2; i++)
	{
		temp = str[i];
		str[i] = str[str.size() - i - 1];
		str[str.size() - i - 1] = temp;
	}
	return str;
}

void InitHuffTree(int size)
{
	for (int i = 0; i < size ; i++)
	{
		for (int j = 0; j < MAX_NODE; j++)
		{
			huffTree[i][j].c = j;
			huffTree[i][j].freq = 0;
			huffTree[i][j].left = -1;
			huffTree[i][j].right = -1;
		}
	}

}

int createHuffTree(int num)
{
	int newNode = MAX_UNSIGNED_CHAR;
	PRIORITY_QUEUE p(MAX_UNSIGNED_CHAR);

	for (int i = 0; i < MAX_UNSIGNED_CHAR; i++)
	{
		if (freq[num][i] > 0)
		{
			KEY_TYPE key;
			key.data = key.address = i;
			key.freq = freq[num][i];
			p.insert(key); //push key to priority_queue
		}
	}

	KEY_TYPE min1, min2, key1;

	while (p.isEmpty() == false)
	{
		//Find 2 min in priority_queue
		p.deleteMin(min1);
		if (p.deleteMin(min2) == false) //case: the last node in heap
		{
			//Create father node
			huffTree[num][newNode].c = key1.data;
			huffTree[num][newNode].freq = key1.freq + min2.freq;
			huffTree[num][newNode].left = key1.address;
			huffTree[num][newNode].right = min2.address;

			break;
		}
		//min1 < min2

		//Create father node
		huffTree[num][newNode].c = min1.data;
		huffTree[num][newNode].freq = min1.freq + min2.freq;
		huffTree[num][newNode].left = min1.address;
		huffTree[num][newNode].right = min2.address;


		KEY_TYPE key;
		key1 = min1;
		key.data = huffTree[num][newNode].c;
		key.freq = huffTree[num][newNode].freq;
		key.address = newNode;
		p.insert(key); //push key to priority queue

		newNode++;
	}
	return newNode - 1; //return nRoot
}

int heightHuffTree(int nNode, int num)
{
	if (nNode == -1)
		return 0;

	int HL, HR;
	HL = heightHuffTree(huffTree[num][nNode].left, num);
	HR = heightHuffTree(huffTree[num][nNode].right, num);

	if (HL > HR)
		return (HL + 1);
	return (HR + 1);
}

bool Allocate(int size, bool isCompress)
{
	//allocate hufftree
	huffTree = new HUFFNode*[size];
	if (huffTree == NULL)
	{
		cout << "FULL MEMORY" << endl;
		return false;
	}

	for (int i = 0; i < size; i++)
	{
		huffTree[i] = new HUFFNode[MAX_NODE];
		if (huffTree[i] == NULL)
		{
			cout << "FULL MEMORY" << endl;
			return false;
		}
	}
	//allocate frequency and bittable and bytesAfter
	freq = new long*[size];
	if (freq == NULL)
	{
		cout << "FULL MEMORY" << endl;
		return false;
	}
	
	if (isCompress == true)
	{
		bytesAfter = new int[size];
		bit = new string*[size];

		if (bit == NULL || bytesAfter == NULL)
		{
			cout << "FULL MEMORY" << endl;
			return false;
		}
	}

	for (int i = 0; i < size; i++)
	{
		freq[i] = new long[MAX_UNSIGNED_CHAR];
		if (freq[i] == NULL)
		{
			cout << "FULL MEMORY" << endl;
			return false;
		}
		
		if (isCompress == true)
		{
			bit[i] = new string[MAX_UNSIGNED_CHAR];
			if (bit[i] == NULL)
			{
				cout << "FULL MEMORY" << endl;
				return false;
			}
		}
		for (int j = 0; j < MAX_UNSIGNED_CHAR; j++)
			freq[i][j] = 0;
	}

	//allocate header
	header = new TYPE_FILE[size];
	if (header == NULL)
	{
		cout << "FULL MEMORY" << endl;
		return false;
	}


	for (int i = 0; i < size; i++)
	{
		header[i].bit_LastByte = 0;
		header[i].bytes = 0;
		header[i].length = 0;
		if (isCompress == true)
		bytesAfter[i] = 0;
	}

	return true;
}

void Free(int size, bool isCompress)
{
	if (size > 1)
	{
		delete[] huffTree;
		delete[] freq;
		if (isCompress == true)
			delete[] bit;

	}
	else
	{
		delete huffTree;
		delete freq;
		if (isCompress == true)
			delete bit;
	
	}
}

int countChar(string str, char ch)
{
	int sum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ch)
			sum++;
	}
	return sum;
}

//COMPRESS

bool readFileToEncode(string filename, string type, int pos)
{
	ifstream fInput;
	fInput.open(filename, ios::in | ios::binary);
	if (!fInput)
	{
		cout << "Khong the nen file" << endl;
		return false;
	}

	header[pos].oldName = type; //save old name for extraction
	header[pos].bytes = 0; //save size of file before compression
	 char ch;
	 unsigned char x;
	while (!fInput.eof())
	{
		fInput.read(&ch, 1);

		if (ch < 0)
			x = ch + 128 * 2;
		else
			x = ch;

			freq[pos][x]++; //calc frequency
			header[pos].bytes++;
	}
	freq[pos][(int)ch]--;
	header[pos].bytes--;
	fInput.close();
	return true;
}

void processHuffTree(int nNode, string s, int num)
{
	if (nNode == -1) //If it's a NULL tree
		return;

	//process node leaf
	if (huffTree[num][nNode].left == -1 && huffTree[num][nNode].right == -1)
	{
		bit[num][nNode] = s;
		return;
	}


	//turn left
	if (huffTree[num][nNode].left != -1)	
		processHuffTree(huffTree[num][nNode].left, s + '0',num);

	//turn right
	if (huffTree[num][nNode].right != -1)
		processHuffTree(huffTree[num][nNode].right, s + '1', num);
	
}

void createBit(char &c, char bit, int i)
{
	char x = 1;
	x = x << i;
	if (bit == '1')
		c = c | x;
	else
		c = c & (~x);
}

void writeHeader(ofstream& fOutput, int& pos,int size)
{

	//             write Header
	char signature[8] = "Huffman"; //identification code of the file

	//write signature
	for (int i = 0; i < 8; i++) //8 bytes
		fOutput.write(&signature[i], sizeof(char));

	//write num_of_file
	fOutput.write((char*)&size, sizeof(int));
	
	//write frequency
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < MAX_UNSIGNED_CHAR; j++)
			fOutput.write((char*)&freq[i][j], sizeof(long));
	}
	pos = fOutput.tellp(); //remember the pointer to header - type file
	//write type file
	for (int i = 0; i < size; i++)
		fOutput.write((char*)&header[i], sizeof(header[i]));
}

bool encode(int size,string* fInput, string fOutput)
{
	ofstream fout;
	string name = fOutput + "." + "huff";
	fout.open(name, ios::out | ios::binary);

	if (!fout)
		return false;


	int pos;
	writeHeader(fout, pos, size);
	
	char ch, co = 0;
	unsigned char x;
	int z = 7;
	for (int i = 0; i < size; i++)
	{
		header[i].length = 0;
		ifstream input;
		input.open(fInput[i], ios::in | ios::binary); //open every file in folder

		if (!input)
			return false;

		while (!input.eof())
		{
			input.read(&ch, 1); //read character one by one

			if (ch < 0)
				x = ch + 128 * 2;
			else
				x = ch;
	
				for (int j = 0; j < bit[i][x].length(); j++) 
				{
					createBit(co, bit[i][x][j], z); //convert 
					if (z == 0)
					{
						z = 8;
						fout.write(&co, 1);
						header[i].length++;
						bytesAfter[i]++;
						co = 0;
					}
					z--;
			}
				
		}
		z = 7;

		fout.write(&co, 1);
		header[i].length++;
		bytesAfter[i]++;
		header[i].bit_LastByte = MAX_BIT - bit[i][x].length();
		input.close();
	}

	fout.seekp(pos);
	//write type file
	for (int i = 0; i < size; i++)
		fout.write((char*)&header[i], sizeof(header[i])); // [10 + sizeof(string)] * size bytes

	fout.close();
	return true;
}

bool COMPRESSTO(string* fInput,string* type, int num_of_file, string fOutput)
{
	cout << "COMPRESSING..." << endl << endl;

	if (Allocate(num_of_file,true) == false)
		return false;


	for (int i = 0; i < num_of_file; i++)
	{
		if (readFileToEncode(fInput[i],type[i], i) == false)
		{
			cout << "COMPRESS FAILED" << endl << endl;
			return false;
		}
	}

	InitHuffTree(num_of_file);

	int* nRoot = new int[num_of_file];

	for (int i = 0; i < num_of_file; i++)
	{
		nRoot[i] = createHuffTree(i);
		processHuffTree(nRoot[i], "", i);
	}

	if (encode(num_of_file,fInput, fOutput) == false)
	{
		cout << "COMPRESS FAILED" << endl << endl;
		return false;
	}


	Free(num_of_file, true);
	cout << "COMPRESS SUCCESFULLY" << endl << endl;
	return true;
	
}

//EXTRACT
bool readFileToDecode(string filename, int& size, int& pos)
{
	ifstream fInput;
	fInput.open(filename, ios::in | ios::binary);

	if (!fInput)
		return false;

	//                 read Header
	char signature[8];
	char temp[8] = "Huffman";

	//read signature
	for (int i = 0; i < 8; i++)
		fInput.read((char*)&signature[i], sizeof(char));

	//check signature
	for (int i = 0; i < 8; i++)
	{
		if (signature[i] != temp[i])
		{
			cout << "SIGNATURE IS WRONG, FILE IS NOT SUPPORTED" << endl;
			return false;
		}
	}

	//read num_of_file
	fInput.read((char*)&size, sizeof(int));


	if (Allocate(size,false) == false)
		return false;
	
	//read frequency
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < MAX_UNSIGNED_CHAR; j++)
			fInput.read((char*)&freq[i][j], sizeof(long));
	}


	//read type file
	for (int i = 0; i < size; i++)
		fInput.read((char*)&header[i], sizeof(header[i]));


	pos = fInput.tellg(); //remember the postion of data compression
	
	fInput.close();
}

bool getBit(char c, int i)
{
	c = c >> i;
	c = c & 1;
	return c;
}

bool decode(string fInput, string folder, string file, int& size)
{
	int pos1, pos2, number;
	if (readFileToDecode(fInput,size,pos2) == false)
		return false;
	int* num = NULL;

	//FIND OUT THE NUMBER OF FILE THAT USER WANT TO EXTRACT
	if (file != "")
	{
		 number = countChar(file, ',');
		if (number >= size)
		{
			cout << "User typed wrong command, number of extracted file must be less than number of compressed file" << endl;
			return false;
		}
		else if (number == 0)
		{
			num = new int;
			num[0] = atoi(file.c_str());
		}
		else
		{
			num = new int[++number];
			for (int i = 0; i < number;i++)
			{
				pos1 = file.find(",");
				num[i] = atoi(file.substr(0, pos1).c_str());
				file.erase(0, pos1 + 1);

				if (i > 0 && num[i] < num[i - 1])
				{
					cout << "User typed wrong command, list file must be sorted ascendingly" << endl;
					return false;
				}
			}
		}
	}



	ifstream input;
	input.open(fInput, ios::in | ios::binary);
	if (!input)
		return false;

	InitHuffTree(size);

	int *nRoot = new int[size];

	for (int i = 0; i < size; i++)
		nRoot[i] = createHuffTree(i);


	input.seekg(pos2); //move pointer to an extracted data in the file
	
	unsigned char ch;
	char ci, co = 0;
	string temp_data = "";
	int countBytes = 0;

	for (int i = 0; i < size; i++)
	{
		if (num != NULL && findFileToExtract(num,number, i + 1) == true)//case extracting some file not all
		{
			for (int j = 0; j < header[i].length;j++)
			input.read(&ci, 1);
		}
		else //case extracting all file
		{
			ofstream fOutput;
			fOutput.open(folder + "\\" + header[i].oldName, ios::out | ios::binary); //write every file

			if (!fOutput)
				return false;

			int nNode = nRoot[i];
			for (int j = 0; j < header[i].length; j++)
			{
				input.read(&ci, 1);
				for (int z = 7; z >= 0; z--)
				{
					if (j == header[i].length - 1 && z == MAX_BIT - header[i].bit_LastByte + 1)
						break; //when reading the last byte, dont covert useless bits

					if (getBit(ci, z) == true)
					{
						nNode = huffTree[i][nNode].right;
						temp_data += '1';
					}
					else
					{
						nNode = huffTree[i][nNode].left;
						temp_data += '0';
					}

					if (countBytes == header[i].bytes)
						break;
					if (huffTree[i][nNode].left == -1 && huffTree[i][nNode].right == -1)
					{
						co = huffTree[i][nNode].c;
						fOutput.write(&co, 1);
						countBytes++;
						nNode = nRoot[i];
						temp_data = "";
					}
				}
			}
			if (checkSum(header[i].bytes, countBytes) == false) //check size of the file
				cout << header[i].oldName << " checksum = false" << endl;

			countBytes = 0; //reset countBytes
			fOutput.close();
		}
	}

	input.close();
	if (num != NULL)
		delete[] num;
	return true;
}

unsigned char reprocessingHuffTree(string bin, int &pos, int nNode, int num)
{
	if (nNode == -1)
		return 256;

	//Node leaf
	if (huffTree[num][nNode].left == -1 && huffTree[num][nNode].right == -1)
	{
		return huffTree[num][nNode].c;
	}

	//turn left
	if (bin[pos] == '0')
		return reprocessingHuffTree(bin, ++pos, huffTree[num][nNode].left,num);

	//turn right
	if (bin[pos] == '1')
		return reprocessingHuffTree(bin, ++pos, huffTree[num][nNode].right,num);
}

bool checkSum(int sizeBefore, int sizeAfter)
{
	return (sizeBefore == sizeAfter);
}

bool EXTRACTTO(string fInput, string folder, string file)
{
	int size;

	cout << "EXTRACTING..." << endl << endl;
	
	if (decode(fInput,folder, file, size) == false)
	{
		cout << "EXTRACT FAILED" << endl << endl;
		return false;
	}

	Free(size, false);
	cout << "EXTRACT SUCCESFULLY" << endl << endl;
	return true;
}

bool findFileToExtract(int* num, int number, int i)
{
	for (int j = 0; j < number; j++)
	{
		if (num[j] == i)
			return false;
	}
	return true;
}
//MENU

void select_1( string* &temp, int& num_of_file)
{
	string in, out;
	Queue names;

	fflush(stdin);
	cout << "The folder path to be compressed:" << endl;
	getline(cin, in);

	cout << "The folder path after compressed:" << endl;
	getline(cin, out);

	string *name = NULL;

		get_all_files_names_within_folder(in, names);

		num_of_file = names.size();
		name = new string[num_of_file];
		temp = new string[num_of_file];
		for (int i = 0; i < num_of_file; i++)
		{
			name[i] = in + "\\";
			names.dequeue(temp[i]);
			name[i] += temp[i];
		}
		COMPRESSTO(name, temp, num_of_file, out);

		delete[] name;
}

void select_2(string *name, int num_of_file)
{
	if (bytesAfter == NULL || name == NULL)
	{
		cout << "User did NOT compressed any files, please compress first." << endl;
		return;
	}

	cout << "NO." << setw(20) << "FILE NAME" << setw(30) << "SIZE BEFORE (byte)" << setw(30) << "SIZE AFTER (byte)" << endl;
	for (int i = 0; i < num_of_file; i++)
		cout << i + 1 << setw(20) << name[i] << setw(30) << header[i].bytes << setw(30) << bytesAfter[i] << endl;

	if (bytesAfter != NULL)
		delete[] bytesAfter;
}

void select_3()
{
	string in, out;
	fflush(stdin);
	cout << "The file path to be extracted:" << endl;
	getline(cin, in);

	cout << "The folder path after extracted:" << endl;
	getline(cin, out);

	EXTRACTTO(in, out,"");
}

void select_4()
{
	string in, out, file;
	fflush(stdin);
	cout << "The file path to be extracted:" << endl;
	getline(cin, in);

	cout << "Choose number that you want to extract:" << endl;
	getline(cin, file);

	cout << "The folder path after extracted:" << endl;
	getline(cin, out);
	
	EXTRACTTO(in, out, file);
}