#include "FARM.h"
void main()
{
	CFARM f;
	int b = f.printMenu();
	system("cls");
	while (b != -1)
	{
		int MaSo, time;
		float x, y;
		float food;
		switch (b)
		{
		case 0: return;
		case 1:
		{
				  CANIMAL* a;
				  string str;
				  while (1)
				  {
					  cout << "0. Thoat" << endl;
					  cout << "1. Ga" << endl;
					  cout << "2. Bo" << endl;
					  cout << "3. Heo" << endl;
					  cout << "4. Cuu" << endl;
					  cout << "Chon loai con vat:";
					  cin >> b;
					  if (b == 0) break;
					  switch (b)
					  {
					  case 1: {str = "ga"; break; }
					  case 2: {str = "bo"; break; }
					  case 3:{str = "heo"; break; }
					  case 4:{str = "cuu"; break; }
					  default: continue;
					  }
					  a = f.createAnimal(str);
					  cin >> *a;
					  f.addAnimal(a);
				  }
				  break;
		}
		case 2: f.printFarm(); break;
		case 3:
		{
				  cout << "Nhap ma so can giet:";
				  cin >> MaSo;
				  f.killAnimal(MaSo);
				  break;
		}
		case 4:
		{
				  cout << "Nhap thoi gian (gio):";
				  cin >> time;
				  f.FarmAfterTime(time);
				  break;
		}
		case 5:
		{
				  cout << "Nhap luong thuc an (kg):";
				  cin >> food;
				  f.feedFarm(food);
				  break;
		}
		case 6:
		{
				  cout << "Nhap ma so can cho an:";
				  cin >> MaSo;
				  cout << "Nhap luong thuc an (kg):";
				  cin >> food;
				  f.feedAnimal(MaSo, food);
				  break;
		}
		case 7:
		{
				  cout << "Nhap ma so can di chuyen:";
				  cin >> MaSo;
				  cout << "Nhap toa do:";
				  cin >> x >> y;
				  f.moveAnimal(MaSo, x, y);
				  break;
		}
		case 8: 
			f.readFile(); system("cls"); break;
		case 9: f.writeFile(); break;
		}
		b = f.printMenu();
		system("cls");
	}
}