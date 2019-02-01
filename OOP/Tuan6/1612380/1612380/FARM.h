#ifndef _FARM_h
#define _FARM_h

#include <vector>
#include <fstream>
#include <string>
#include "CHICKEN.h"
#include "COW.h"
#include "PIG.h"
#include "SHEEP.h"
class CFARM
{
	vector <CANIMAL*> _ConVat;
public:
	CFARM();
	CFARM(CANIMAL* a);
	CFARM(const CFARM&);
	~CFARM();

	vector <CANIMAL*> get_ConVat() const { return _ConVat; };
	void set_ConVat(vector <CANIMAL*> cv){ _ConVat = cv; };

	CANIMAL* createAnimal(string type);
	void addAnimal(CANIMAL* a);
	void printFarm();
	bool killAnimal(int MaSo);
	void FarmAfterTime(int time);
	void feedFarm(float food);
	bool feedAnimal(int MaSo, float food);
	bool moveAnimal(int MaSo, float x, float y);
	int findAnimal(int MaSo); //Tra ve vi tri

	bool readFile();
	bool writeFile();

	int printMenu();
};

#endif