#ifndef _CGAME_H
#define _CGAME_H

#include <iostream>
#include "CBIRD.h"
#include "CDINOSAUR.h"
#include "CCAR.h"
#include "CTRUCK.h"
#include "CLIGHT.h"
#include "CPEOPLE.h"
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <thread>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "console.h"
#include "Header.h"
using namespace std;



class CGAME
{
	CTRUCK* axt;
	CCAR* axh;
	CDINOSAUR* akl;
	CBIRD* ac;
	CLIGHT *li;
	CPEOPLE cn;

public:
	CGAME(); //Chuẩn bị dữ liệu cho tất cả các đối tượng
	void drawBoard();
	void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
	void Menu(int, int); //Ve Menu
	~CGAME(); // Hủy tài nguyên đã cấp phát
	CPEOPLE getPeople() { return cn; };//Lấy thông tin người
	CVEHICLE** getVehicle();//Lấy danh sách các xe
	CANIMAL** getAnimal(); //Lấy danh sách các thú
    void resetGame(); // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void exitGame(HANDLE); // Thực hiện thoát Thread
	void startGame(); // Thực hiện bắt đầu vào trò chơi
	void drawSettings(); //Settings ve
	void pauseGame(HANDLE); // Tạm dừng Thread
	void resumeGame(HANDLE); //Quay lai Thread
	void updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosVehicle(); //Thực hiện cho CTRUCK & CCAR di chuyển
	void updatePosAnimal();//Thực hiện cho CDINAUSOR & CBIRD di chuyển
	void updateSound(); //Cap nhat am thanh
	void updateLightStatus(); //Cap nhat trang thai cua den
	CGAME& operator=(const CGAME& cgame);
	bool saveGame(string filename);
	bool loadGame(string filename);
	bool checkLane(int); //ktra xem nguoi co dung tren duong ke lane hay khong
	
	//void DrawGameOver();
	void LevelUp();
	friend void SubThread();
	friend void SoundThread();

};

#endif