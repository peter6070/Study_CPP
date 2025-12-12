#include <iostream>
using namespace std;

//상수값
//#define ID_LEN 20
//#define MAX_SPD 200
//#define FUEL_STEP 2
//#define ACC_STEP 10
//#define BRK_STEP 10
//-----------------------------------------------------------
////구조체 선언
//struct Car {
//	char gamerID[ID_LEN];
//	int fuelGauge;
//	int curSpeed;
//};
////함수 선언(구조체 밖에 선언)
////차량 상태 출력
//void ShowCarState(const Car& car) { //출력만 하기 때문에 const 참조자를 매개변수로 선언
//	cout << "Owner ID: " << car.gamerID << endl;
//	cout << "Fuel Enough: " << car.fuelGauge << "&" << endl;
//	cout << "Current Speed: " << car.curSpeed <<"km/s" << endl;
//}
//
////엑셀
//void Accel(Car& car) {
//	if (car.fuelGauge <= 0)
//		return;
//	else
//		car.fuelGauge -= FUEL_STEP;
//
//	if (car.curSpeed + ACC_STEP >= MAX_SPD) {
//		car.curSpeed = MAX_SPD;
//		return;
//	}
//
//	car.curSpeed += ACC_STEP;
//}
//
////브레이크
//void Break(Car& car) {
//	if (car.curSpeed < BRK_STEP) {
//		car.curSpeed = 0;
//		return;
//	}
//
//	car.curSpeed -= BRK_STEP;
//}

//-----------------------------------------------------------------

//구조체 선언
//struct Car {
//	char gamerID[ID_LEN];
//	int fuelGauge;
//	int curSpeed;
//
//	//함수 선언(구조체 안에 선언)
//	//차량 상태 출력
//	void ShowCarState() {
//		cout << "Owner ID: " << gamerID << endl;
//		cout << "Fuel Enough: " << fuelGauge << "&" << endl;
//		cout << "Current Speed: " << curSpeed << "km/s" << endl<<endl;
//	}
//
//	//엑셀
//	void Accel() {
//		if (fuelGauge <= 0)
//			return;
//		else
//			fuelGauge -= FUEL_STEP;
//
//		if (curSpeed + ACC_STEP >= MAX_SPD) {
//			curSpeed = MAX_SPD;
//			return;
//		}
//
//		curSpeed += ACC_STEP;
//	}
//
//	//브레이크
//	void Break() {
//		if (curSpeed < BRK_STEP) {
//			curSpeed = 0;
//			return;
//		}
//
//		curSpeed -= BRK_STEP;
//	}
//};

//-----------------------------------------------------------------

//문제3-1. 구조체 내 함수정의
struct Point {
	int xpos;
	int ypos;

	//좌표이동
	void MovePos(int x, int y) {
		xpos += x;
		ypos += y;
	}
	//좌표증가
	void AddPoint(const Point& pos) {
		xpos += pos.xpos;
		ypos += pos.ypos;
	}
	//현재 x,y 좌표 출력
	void ShowPosition() {
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}

};


int main(void) {
	/*Car initialD = {"initialD",100,0 };
	Accel(initialD);
	Accel(initialD);
	ShowCarState(initialD);
	Break(initialD);
	ShowCarState(initialD);
	Break(initialD);
	ShowCarState(initialD);

	Car initialZ = { "initialZ",100,0 };
	Accel(initialZ);
	Accel(initialZ);
	Break(initialZ);
	ShowCarState(initialZ);*/
//-----------------------------------------------------------------
	/*Car initialD = {"initialD",100,0 };
	initialD.Accel();
	initialD.Accel();
	initialD.ShowCarState();
	initialD.Break();
	initialD.ShowCarState();
	initialD.Break();
	initialD.ShowCarState();

	Car initialZ = { "initialZ",100,0 };
	initialZ.Accel();
	initialZ.Accel();
	initialZ.Break();
	initialZ.ShowCarState();*/
	//-----------------------------------------------------------------
	
	//문제3-1.구조체 내 함수정의
	Point pos1 = { 12,4 };
	Point pos2 = { 20,30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition(); //[5,14]출력

	pos1.AddPoint(pos2);
	pos1.ShowPosition(); //[25,44]출력


	return 0;
}