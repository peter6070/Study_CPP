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

////구조체 선언
//struct Car {
//	//상수값을 열거형으로 구조체 내에 선언(구조체에서만 필요한 상수들이기 때문)
//	enum {
//		ID_LEN = 20,
//		MAX_SPD = 200,
//		FUEL_STEP = 2,
//		ACC_STEP = 10,
//		BRK_STEP = 10
//	};
//	char gamerID[ID_LEN];
//	int fuelGauge;
//	int curSpeed;
//
//	//함수 선언(구조체 안에 선언)
//	//차량 상태 출력
//	void ShowCarState() {
//		cout << "Owner ID: " << gamerID << endl;
//		cout << "Fuel Enough: " << fuelGauge << "&" << endl;
//		cout << "Current Speed: " << curSpeed << "km/s" << endl << endl;
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

////문제3-1. 구조체 내 함수정의
//struct Point {
//	int xpos;
//	int ypos;
//
//	//좌표이동
//	void MovePos(int x, int y) {
//		xpos += x;
//		ypos += y;
//	}
//	//좌표증가
//	void AddPoint(const Point& pos) {
//		xpos += pos.xpos;
//		ypos += pos.ypos;
//	}
//	//현재 x,y 좌표 출력
//	void ShowPosition() {
//		cout << "[" << xpos << "," << ypos << "]" << endl;
//	}
//};

//-----------------------------------------------------------------

//상수값을 열거형으로 구조체 외부에 선언(이름공간을 이용해 가독성 향상)
namespace CAR_CONST {
	enum {
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

////구조체 선언
//struct Car {
//	
//	char gamerID[CAR_CONST::ID_LEN];
//	int fuelGauge;
//	int curSpeed;
//
//	//함수 선언(구조체 안에 선언)
//	//차량 상태 출력
//	void ShowCarState() {
//		cout << "Owner ID: " << gamerID << endl;
//		cout << "Fuel Enough: " << fuelGauge << "&" << endl;
//		cout << "Current Speed: " << curSpeed << "km/s" << endl << endl;
//	}
//
//	//엑셀
//	void Accel() {
//		if (fuelGauge <= 0)
//			return;
//		else
//			fuelGauge -= CAR_CONST::FUEL_STEP;
//
//		if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
//			curSpeed = CAR_CONST::MAX_SPD;
//			return;
//		}
//
//		curSpeed += CAR_CONST::ACC_STEP;
//	}
//
//	//브레이크
//	void Break() {
//		if (curSpeed < CAR_CONST::BRK_STEP) {
//			curSpeed = 0;
//			return;
//		}
//
//		curSpeed -= CAR_CONST::BRK_STEP;
//	}
//};

//-----------------------------------------------------------------

//함수를 구조체 밖에 정의
struct Car {
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

	//함수 선언
	void ShowCarState();
	void Accel();
	void Break();
};

void Car::ShowCarState() {
	cout << "Owner ID: " << gamerID << endl;
	cout << "Fuel Enough: " << fuelGauge << "&" << endl;
	cout << "Current Speed: " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel() {
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;

	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}

	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break() {
	if (curSpeed < CAR_CONST::BRK_STEP) {
		curSpeed = 0;
		return;
	}

	curSpeed -= CAR_CONST::BRK_STEP;
}

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
	Car initialD = { "initialD",100,0 };
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
	initialZ.ShowCarState();
	//-----------------------------------------------------------------

	//문제3-1.구조체 내 함수정의
	//Point pos1 = { 12,4 };
	//Point pos2 = { 20,30 };

	//pos1.MovePos(-7, 10);
	//pos1.ShowPosition(); //[5,14]출력

	//pos1.AddPoint(pos2);
	//pos1.ShowPosition(); //[25,44]출력

	//-----------------------------------------------------------------





	return 0;
}