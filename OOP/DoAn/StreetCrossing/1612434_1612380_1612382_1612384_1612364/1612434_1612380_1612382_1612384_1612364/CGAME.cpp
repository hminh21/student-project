#include "CGAME.h"
CGAME::CGAME()
{
	int x = 60, y = 40;
	level = 1;
	//Cap phat vung nho cho cac object
	axt = new CTRUCK[MAX_OBJ];
	axh = new CCAR[MAX_OBJ];
	akl = new CDINOSAUR[MAX_OBJ];
	ac = new CBIRD[MAX_OBJ];
	li = new CLIGHT[MAX_LIGHT];
	cn.SetPos(35, 23);
	if (axt == NULL || axh == NULL || akl == NULL || ac == NULL)
		return;

	//Thiet lap vi tri cho cac object
	for (int i = 0; i < 3; i++)
	{
		ac[i].setX(x);
		ac[i].setY(7);

		axh[i].setX(y);
		axh[i].setY(11);

		akl[i].setX(x);
		akl[i].setY(15);

		axt[i].setX(y);
		axt[i].setY(19);

		//Chia khoang cach giua cac object
		x -= 15;
		y -= 15;

		
		//Level 1 chi co 4 phan tu dau tien duoc in ra man hinh
			axt[i].setIsInvalid(true);
			axh[i].setIsInvalid(true);
			akl[i].setIsInvalid(true);
			ac[i].setIsInvalid(true);

	}
	// thiet lap vi tri cho den
	li[0].setX(4);
	li[0].setY(11);
	li[1].setX(75);
	li[1].setY(19);
}

CGAME::~CGAME()
{
	//Giai phong vung nho
	delete[] ac;
	delete[] akl;
	delete[] axh;
	delete[] axt;
	delete[] li;
}

void CGAME::resetGame()
{
	level = 1;
	int x = 60;
	int y = 40;
	for (int i = 0; i < 3; i++)
	{
		axt[i].setX(y);
		axt[i].setY(19);

		axh[i].setX(x);
		axh[i].setY(11);

		akl[i].setX(y);
		akl[i].setY(15);

		ac[i].setX(x);
		ac[i].setY(7);

			//Level 1 chi co 4 phan tu dau tien duoc in ra man hinh
			axt[i].setIsInvalid(true);
			axh[i].setIsInvalid(true);
			akl[i].setIsInvalid(true);
			ac[i].setIsInvalid(true);
		x -= 15;
		y -= 15;
	}

	for (int i = 3; i < 5; i++)
	{
		axt[i].setIsInvalid(false);
		axh[i].setIsInvalid(false);
		akl[i].setIsInvalid(false);
		ac[i].setIsInvalid(false);
	}
	//thiet lap vi tri cho den
	li[0].setX(4);
	li[0].setY(11);
	li[1].setX(75);
	li[1].setY(19);


	cn.SetPos(35, 23);
	cn.setState(true);

	system("cls");

	x = 3, y = 1;
	int curPosX = 0, curPosY = 0;

	//Ve 2 canh day
	for (int i = 0; i <= WIDTH_CONSOLE; i++)
	{
		GoToXY(x, y); Draw("_", 11);
		GoToXY(x, HEIGHT_CONSOLE + y); Draw("_", 11);
		//Ve lane
		GoToXY(x, 22); Draw("-", 15);
		GoToXY(x, 18); Draw("-", 15);
		GoToXY(x, 14); Draw("-", 15);
		GoToXY(x, 10); Draw("-", 15);
		GoToXY(x, 6); Draw("-", 15);
		x++;
	}

	x = 3;
	//Ve 2 canh ben
	for (int i = y + 1; i <= HEIGHT_CONSOLE + 1; i++)
	{
		GoToXY(x, i); Draw("|", 11);
		GoToXY(WIDTH_CONSOLE + x, i); Draw("|", 11);
	}
	
	//Tra ve vi tri ban dau
	GoToXY(curPosX, curPosY);


}

void CGAME::exitGame(HANDLE t)
{
	system("cls");
	TerminateThread(t, 0);
	ExitThread(0);
}


void CGAME::drawBoard()
{
	int x = 3, y = 1;
	int curPosX = 0, curPosY = 0;

	//Ve 2 canh day
	for (int i = 0; i <= WIDTH_CONSOLE; i++)
	{
		GoToXY(x, y); Draw("_", 11);
		GoToXY(x, HEIGHT_CONSOLE + y); Draw("_", 11);
		//Ve lane
		GoToXY(x, 22); Draw("-", 15);
		GoToXY(x, 18); Draw("-", 15);
		GoToXY(x, 14); Draw("-", 15);
		GoToXY(x, 10); Draw("-", 15);
		GoToXY(x, 6); Draw("-", 15);
		x++;
		Sleep(10);
	}

	x = 3;
	//Ve 2 canh ben
	for (int i = y + 1; i <= HEIGHT_CONSOLE + 1; i++)
	{
		GoToXY(x, i); Draw("|", 11);
		GoToXY(WIDTH_CONSOLE + x, i); Draw("|", 11);
		Sleep(20);
	}
	//Tra ve vi tri ban dau
	GoToXY(curPosX, curPosY);
}
void CGAME::Menu(int x, int y)// vẽ menu
{
	GoToXY(x, y);
	std::cout << "   ==  MENU ==  ";
	GoToXY(x, y + 1);
	std::cout << " | 1. New game  |";
	GoToXY(x, y + 2);
	std::cout << " | 2. Load game |";
	GoToXY(x, y + 3);
	std::cout << " | 3. Settings  |";
	GoToXY(x, y + 4);
	std::cout << " | 4. Exit game |";
}

void CGAME::LevelUp()
{
	if (level == 1)
	{
		//Tang object len 1 phan tu
		ac[3].setIsInvalid(true);
		akl[3].setIsInvalid(true);
		axh[3].setIsInvalid(true);
		axt[3].setIsInvalid(true);

		int x = 60, y = 50;
		for (int i = 0; i < 4; i++) //Cai dat lai vi tri object
		{
			ac[i].setX(x);
			ac[i].setY(7);

			axh[i].setX(y);
			axh[i].setY(11);

			akl[i].setX(x);
			akl[i].setY(15);

			axt[i].setX(y);
			axt[i].setY(19);

			//Chia khoang cach giua cac object
			x -= 12; 
			y -= 12;
		}
		//Vi tri nguoi
		cn.SetPos(35, 23);
		level++;
		//Hieu ung
		effectLevelUp();
	}
	else if (level == 2)
	{
			//Tang object len 1 phan tu
			ac[4].setIsInvalid(true);
			akl[4].setIsInvalid(true);
			axh[4].setIsInvalid(true);
			axt[4].setIsInvalid(true);

			int x = 60, y = 50;
			for (int i = 0; i < 5; i++) //Cai dat lai vi tri object
			{
				ac[i].setX(x);
				ac[i].setY(7);

				axh[i].setX(y);
				axh[i].setY(11);

				akl[i].setX(x);
				akl[i].setY(15);

				axt[i].setX(y);
				axt[i].setY(19);

				//Chia khoang cach giua cac object
				x -= 9;
				y -= 9;
			}
			//Vi tri nguoi
			cn.SetPos(35, 23);
			level++;
			//Hieu ung
			effectLevelUp();
	}
		else resetGame();
}
void CGAME::drawSettings()
{
	int colorChoice = -1;//lựa chọn màu của người chơi
	std::cout << "COLOR CODES: "<<endl;
	//các màu code được define trong console.h
	std::cout << "White: " << ColorCode_White<<endl;
	std::cout << "Red: " << ColorCode_Red<<endl;
	std::cout << "Yellow: " << ColorCode_Yellow<<endl;
	std::cout << "Blue: " << ColorCode_Blue<<endl;
	std::cout << "Choose objects color: "<<endl;
	std::cout << "CHOOSE OBJECT COLORS: "<<endl;

	//set car colors
	while (colorChoice != ColorCode_White&&colorChoice != ColorCode_Yellow&&colorChoice != ColorCode_Red&&colorChoice != ColorCode_Blue)
	{
		std::cout << "Cars: "; cin >> colorChoice;
		if (colorChoice != ColorCode_White&&colorChoice != ColorCode_Yellow&&colorChoice != ColorCode_Red&&colorChoice != ColorCode_Blue)
			std::cout << "Color code is not in options. Please insert again." << endl;
	}
	axh->setObjectColor(colorChoice);

	colorChoice = -1;

	//set truck colors
	while (colorChoice != ColorCode_White&&colorChoice != ColorCode_Yellow&&colorChoice != ColorCode_Red&&colorChoice != ColorCode_Blue)
	{
		std::cout << "Trucks: "; cin >> colorChoice;
		if (colorChoice != ColorCode_White&&colorChoice != ColorCode_Yellow&&colorChoice != ColorCode_Red&&colorChoice != ColorCode_Blue)
			std::cout << "Color code is not in options. Please insert again." << endl;
	}
	axt->setObjectColor(colorChoice);

	colorChoice = -1;

	//set bird colors
	while (colorChoice != ColorCode_White&&colorChoice != ColorCode_Yellow&&colorChoice != ColorCode_Red&&colorChoice != ColorCode_Blue)
	{
		std::cout << "Birds: "; cin >> colorChoice;
		if (colorChoice != ColorCode_White&&colorChoice != ColorCode_Yellow&&colorChoice != ColorCode_Red&&colorChoice != ColorCode_Blue)
			std::cout << "Color code is not in options. Please insert again." << endl;
	}
	ac->setObjectColor(colorChoice);

	colorChoice = -1;

	//set dinosaurs colors
	while (colorChoice != ColorCode_White&&colorChoice != ColorCode_Yellow&&colorChoice != ColorCode_Red&&colorChoice != ColorCode_Blue)
	{
		std::cout << "Dinosaurs: "; cin >> colorChoice;
		if (colorChoice != ColorCode_White&&colorChoice != ColorCode_Yellow&&colorChoice != ColorCode_Red&&colorChoice != ColorCode_Blue)
			std::cout << "Color code is not in options. Please insert again." << endl;
	}
	akl->setObjectColor(colorChoice);

	colorChoice = -1;

	//set people color
	while (colorChoice != ColorCode_White&&colorChoice != ColorCode_Yellow&&colorChoice != ColorCode_Red&&colorChoice != ColorCode_Blue)
	{
		std::cout << "People: "; cin >> colorChoice;
		if (colorChoice != ColorCode_White&&colorChoice != ColorCode_Yellow&&colorChoice != ColorCode_Red&&colorChoice != ColorCode_Blue)
			std::cout << "Color code is not in options. Please insert again." << endl;
	}
	cn.setObjectColor(colorChoice);
}
void CGAME::startGame()
{
	drawBoard();
	drawGame();
}

void CGAME::updatePosPeople(char ch)
{
	prevX = cn.getX();
	prevY = cn.getY();
	switch (ch)
	{
	case 'W':
	{
		if (cn.getY()>=5)//đảm bảo CPEOPLE không đi qua cạnh trên
		{
			cn.Up(4);
		}
		break;
	}
	case 'A':
	{
				if (cn.getX() - 1 == 3)// đảm bảo CPEOPLE không đi qua cạnh trái
					break;
				else
					cn.Left(1);
				break;
	}
	case 'S': 
	{
		if (cn.getY() <= HEIGHT_CONSOLE-3)// đảm bảo CPEOPLE không đi qua cạnh dưới
		{
			cn.Down(4);
		}
		break;
	}
	case 'D':
	{
				if (cn.getX() + 1 == WIDTH_CONSOLE )// đảm bảo CPEOPLE không đi qua cạnh phải
					break;
				else
					cn.Right(1);
				break;
	}
	}
}

void CGAME::pauseGame(HANDLE t)
{
	SuspendThread(t);
}

void CGAME::resumeGame(HANDLE t)
{
	ResumeThread(t);
}

void CGAME::updatePosAnimal()
{
	for (int i = 0; i < MAX_OBJ; i++)
	{
		if (ac[i].getIsInvalid() == true) //Kiem tra xem object co ton tai khong
		{
			if (ac[i].getX() + 6 == WIDTH_CONSOLE + 3) //Neu dung vao canh phai
				ac[i].setX(4);
			else
				ac[i].MoveRight(1);
		}

		if (akl[i].getIsInvalid() == true)//Kiem tra xem object co ton tai khong
		{
			if (akl[i].getX() + 6 == WIDTH_CONSOLE + 3) //Neu dung vao canh phai
				akl[i].setX(4);
			else
				akl[i].MoveRight(1);
		}
	}
}

void CGAME::updatePosVehicle()
{
	int j = 0;
	if (li[j].getTime() < 70) //Chi di chuyen khi den xanh
	{
		for (int i = 0; i < MAX_OBJ; i++)
		{
			if (axh[i].getIsInvalid() == true)
			{
				if (axh[i].getX() - 1 == 4) //Neu dung vao canh trai
					axh[i].setX(WIDTH_CONSOLE - 6);
				else
					axh[i].MoveLeft(1);
			}
		}
	}
	if (li[j + 1].getTime() < 70) //Chi di chuyen khi den xanh
	{
		for (int i = 0; i < MAX_OBJ; i++)
		{
			if (axt[i].getIsInvalid() == true)
			{
				if (axt[i].getX() + 6 == WIDTH_CONSOLE + 2)
					axt[i].setX(4);
				else
					axt[i].MoveRight(1);
			}
		}
	}
}
void CGAME::updateLightStatus() //Cap nhat trang thai den
{
	for (int i = 0; i < MAX_LIGHT; i++)
	{
		li[i].changeStatus();
		li[i].TimeDown(); //Dem nguoc thoi gian doi mau
	}

}

void CGAME::drawGame()
{
	//vẽ hình và màu cho từng obj
	TextColor(cn.getObjectColor());
	cn.drawObj();
	TextColor(ColorCode_White);
	for (int i = 0; i < MAX_OBJ; i++)
	{
		if (ac[i].getIsInvalid() == true)
		{
			TextColor(ac->getObjectColor());
			ac[i].drawObj();
			TextColor(ColorCode_White);
		}

		if (akl[i].getIsInvalid() == true)
		{
			TextColor(akl ->getObjectColor());
			akl[i].drawObj();
			TextColor(ColorCode_White);
		}

		if (axh[i].getIsInvalid() == true)
		{
			TextColor(axh->getObjectColor());
			axh[i].drawObj();
			TextColor(ColorCode_White);
		}

		if (axt[i].getIsInvalid() == true)
		{
			TextColor(axt->getObjectColor());
			axt[i].drawObj();
			TextColor(ColorCode_White);
		}
	}

	Sleep(100);
	//Xoa di hinh ve ma cac obj da duoc in tren console
	for (int i = 0; i < MAX_OBJ; i++)
	{
		if (ac[i].getIsInvalid() == true)
			ac[i].deleteObj();

		if (akl[i].getIsInvalid() == true)
			akl[i].deleteObj();

		if (axh[i].getIsInvalid() == true && li[0].getTime() < 70)
			axh[i].deleteObj();
		
		if (axt[i].getIsInvalid() == true && li[1].getTime() < 70)
			axt[i].deleteObj();

	}
	//Ve den
	for (int i = 0; i < MAX_LIGHT; i++)
	{
		li[i].drawObj();
	}
	//in menu tiến trình game
	GoToXY(WIDTH_CONSOLE+6,3);
	std::cout << "LEVEL: " << level;
	GoToXY(WIDTH_CONSOLE+6,5);
	std::cout << "OBJECTS: " << level + 2;
	GoToXY(WIDTH_CONSOLE + 6, 7);
	std::cout << "PRESS L TO SAVE GAME";
	GoToXY(WIDTH_CONSOLE + 6, 9);
	std::cout << "PRESS T TO LOAD GAME";
	GoToXY(WIDTH_CONSOLE + 6, 11);
	std::cout << "PRESS P TO PAUSE GAME";
	GoToXY(WIDTH_CONSOLE + 6, 13);
	std::cout << "PRESS ESC TO EXIT GAME";

}
void SoundThread() //Thread chay am thanh
{
	while (1) {
		if (!cg->getPeople().isDead() && cg->getPeople().getY() != 3 && cg->getPeople().getY() != 23) //Bo 2 lane dau, lane cuoi
		{
			if (cg->getPeople().getY() == 19)
				PlaySound(L"truckhorn", NULL, SND_ASYNC);
			else if (cg->getPeople().getY() == 15)
				PlaySound(L"dinosaursound", NULL, SND_ASYNC);
			else if (cg->getPeople().getY() == 11)
				PlaySound(L"carhorn", NULL, SND_ASYNC);
			else if (cg->getPeople().getY() == 7)
				PlaySound(L"chickensound", NULL, SND_ASYNC);
			else
				PlaySound(NULL, NULL, 0);
			Sleep(1500);
		}
		
	}
}


void SubThread()
{
	while (1)
	{
		if (!cg->getPeople().isDead() && cg->getPeople().getY() != 3)
		{
			cg->updatePosPeople(MOVING); //Cap nhat vi tri nguoi
			cg->cn.deleteObj(); //Xoa hinh nguoi da ve
			MOVING = ' '; //Tam khoa khong cho di chuyen, cho nhan phim tu ham main	
			cg->updateLightStatus();
			cg->drawGame(); //Ve obj
			cg->updatePosVehicle(); //Cap nhat vi tri xe
			cg->updatePosAnimal(); //Cap nhat vi tri thu

			//Neu va cham
			if (cg->getPeople().isImpact(cg->getAnimal()) == true || cg->getPeople().isImpact(cg->getVehicle()) == true)
			{
				cg->cn.setState(false);
				deadEffect();
			}
			//Neu di den dich
			if (cg->getPeople().isFinish() == true)
			{
				cg->LevelUp();
				cg->drawBoard();
			}
		}
			Sleep(10);
	}
}

CVEHICLE** CGAME::getVehicle() //Lay danh sach xe
{
	CVEHICLE** p = new CVEHICLE*[2];
	p[0] = axt->getList(); 
	p[1] = axh->getList();
	return p;
}

CANIMAL** CGAME::getAnimal() //Lay danh sach thu
{
	CANIMAL** p = new CANIMAL*[2];
	p[0] = ac->getList();
	p[1] = akl->getList();
	return p;
}

bool CGAME::saveGame(string filename)
{
	ofstream f;
	f.open(filename, ios_base::out | ios_base::binary);

	// Kiem tra viec mo file co thanh cong.
	if (f.fail())
		return false;

	int temp_int;
	bool temp_bool;
	char temp_char;
	// ghi lan luot bien MOVING, level, prevX, prevY vao file
	f.write(reinterpret_cast<const char*> (&MOVING), sizeof (MOVING));
	f.write(reinterpret_cast<const char*> (&level), sizeof (level));
	f.write(reinterpret_cast<const char*> (&prevX), sizeof (prevX));
	f.write(reinterpret_cast<const char*> (&prevY), sizeof (prevY));

	// ghi cac mang axt, axh, akl, ac trong bien cg vao file
	for (int i = 0; i < MAX_OBJ; i++)
	{
		// Ghi tung thuoc tinh cua moi phan tu axt vao file.
		temp_int = cg->axt[i].getX(); // lay toa do X
		f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int)); // ghi toa do X vao file
		temp_int = cg->axt[i].getY(); // lay toa do Y
		f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int)); // ghi toa do Y vao file
		temp_bool = cg->axt[i].getIsInvalid(); // lay thuoc tinh isInvalid
		f.write(reinterpret_cast<const char*> (&temp_bool), sizeof (temp_bool)); // ghi thuoc tinh isInvalid vao file
		temp_int = cg->axt[i].getObjectColor();
		f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));

		// tuong tu nhu tren
		temp_int = cg->axh[i].getX();
		f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));
		temp_int = cg->axh[i].getY();
		f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));
		temp_bool = cg->axh[i].getIsInvalid();
		f.write(reinterpret_cast<const char*> (&temp_bool), sizeof (temp_bool));
		temp_int = cg->axh[i].getObjectColor();
		f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));

		// tuong tu nhu tren
		temp_int = cg->akl[i].getX();
		f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));
		temp_int = cg->akl[i].getY();
		f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));
		temp_bool = cg->akl[i].getIsInvalid();
		f.write(reinterpret_cast<const char*> (&temp_bool), sizeof (temp_bool));
		temp_int = cg->akl[i].getObjectColor();
		f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));

		// tuong tu nhu tren
		temp_int = cg->ac[i].getX();
		f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));
		temp_int = cg->ac[i].getY();
		f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));
		temp_bool = cg->ac[i].getIsInvalid();
		f.write(reinterpret_cast<const char*> (&temp_bool), sizeof (temp_bool));
		temp_int = cg->ac[i].getObjectColor();
		f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));
	}

	//Ghi bien cn trong cg vao file, ghi lan luot cac thuoc tinh cua cn ra file
	temp_int = cg->cn.getX();
	f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));
	temp_int = cg->cn.getY();
	f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));
	temp_bool = cg->cn.getState();
	f.write(reinterpret_cast<const char*> (&temp_bool), sizeof (temp_bool));
	temp_int = cg->cn.getObjectColor();
	f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));

	// Ghi bien li ra file
	for (int i = 0; i < MAX_LIGHT; i++)
	{
		temp_int = cg->li[i].getX();
		f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));
		temp_int = cg->li[i].getY();
		f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));
		temp_char = cg->li[i].getLight(0);
		f.write(reinterpret_cast<const char*> (&temp_char), sizeof (temp_char));
		temp_char = cg->li[i].getLight(1);
		f.write(reinterpret_cast<const char*> (&temp_char), sizeof (temp_char));
		temp_bool = cg->li[i].getStatus();
		f.write(reinterpret_cast<const char*> (&temp_bool), sizeof (temp_bool));
		temp_int = cg->li[i].getTime();
		f.write(reinterpret_cast<const char*> (&temp_int), sizeof (temp_int));
	}

	f.close();
	return true;
}

bool CGAME::loadGame(string filename)
{
	ifstream f;
	f.open(filename, ios_base::in | ios_base::binary);

	if (f.fail())
		return false;

	int temp_int;
	bool temp_bool;
	char temp_char;
	// doc lan luot bien MOVING, level, prevX, prevY tu file va luu cac bien toan cuc tuong ung
	f.read(reinterpret_cast <char*> (&MOVING), sizeof (MOVING));
	f.read(reinterpret_cast<char*> (&level), sizeof (level));
	f.read(reinterpret_cast<char*> (&prevX), sizeof (prevX));
	f.read(reinterpret_cast<char*> (&prevY), sizeof (prevY));

	// doc cac mang axt, axh, akl, ac tu file va luu vao bien cg 
	for (int i = 0; i < MAX_OBJ; i++)
	{
		// Doc lan luot cac thuoc tinh tu file va luu vao moi phan tu axt
		// Thu tu luc doc tuong ung voi thu tu luc ghi file: X - Y - isInvalid
		f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
		cg->axt[i].setX(temp_int);
		f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
		cg->axt[i].setY(temp_int);
		f.read(reinterpret_cast <char*> (&temp_bool), sizeof (temp_bool));
		cg->axt[i].setIsInvalid(temp_bool);
		f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
		cg->axt[i].setObjectColor(temp_int);

		// tuong tu nhu tren
		f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
		cg->axh[i].setX(temp_int);
		f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
		cg->axh[i].setY(temp_int);
		f.read(reinterpret_cast <char*> (&temp_bool), sizeof (temp_bool));
		cg->axh[i].setIsInvalid(temp_bool);
		f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
		cg->axh[i].setObjectColor(temp_int);

		// tuong tu nhu tren
		f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
		cg->akl[i].setX(temp_int);
		f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
		cg->akl[i].setY(temp_int);
		f.read(reinterpret_cast <char*> (&temp_bool), sizeof (temp_bool));
		cg->akl[i].setIsInvalid(temp_bool);
		f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
		cg->akl[i].setObjectColor(temp_int);

		// tuong tu nhu tren
		f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
		cg->ac[i].setX(temp_int);
		f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
		cg->ac[i].setY(temp_int);
		f.read(reinterpret_cast <char*> (&temp_bool), sizeof (temp_bool));
		cg->ac[i].setIsInvalid(temp_bool);
		f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
		cg->ac[i].setObjectColor(temp_int);
	}

	// Doc cac thuoc tinh cua bien cn tu file, luu lan luot cac thuoc tinh vua doc vao bien cn
	f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
	cg->cn.setX(temp_int);
	f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
	cg->cn.setY(temp_int);
	f.read(reinterpret_cast <char*> (&temp_bool), sizeof (temp_bool));
	cg->cn.setState(temp_bool);
	f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
	cg->cn.setObjectColor(temp_int);

	// Doc bien light tu file
	for (int i = 0; i < MAX_LIGHT; i++)
	{
		f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int)); 
		cg->li[i].setX(temp_int);
		f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
		cg->li[i].setY(temp_int);
		f.read(reinterpret_cast <char*> (&temp_char), sizeof (temp_char));
		cg->li[i].setLight(0, temp_char);
		f.read(reinterpret_cast <char*> (&temp_char), sizeof (temp_char));
		cg->li[i].setLight(1, temp_char);
		f.read(reinterpret_cast <char*> (&temp_bool), sizeof (temp_bool));
		cg->li[i].setStatus(temp_bool);
		f.read(reinterpret_cast <char*> (&temp_int), sizeof (temp_int));
		cg->li[i].setTime(temp_int);
	}
	f.close();
	return true;
}

bool CGAME::checkLane(int y) //ktra xem nguoi co dung tren duong ke lane hay khong
{
	if (y == 22 || y == 18 || y == 14 || y == 10 || y == 6)
		return true;
	return false;
}