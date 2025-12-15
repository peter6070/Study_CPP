#include <iostream>
#include <cstring>
#include "Car.h" //CAR_CONST에 선언된 상수 사용을 위해 헤더파일 포함
using namespace std;

//클래스의 정의
void Car::InitMembers(const char* ID, int fuel) {
    strcpy_s(gamerID, CAR_CONST::ID_LEN, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState() {
    cout << "Owner ID: " << gamerID << endl;
    cout << "Fuel Enough: " << fuelGauge << "%" << endl;
    cout << "Current Speed: " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel() {
    if (fuelGauge <= 0)
        return;
    else
        fuelGauge -= CAR_CONST::FUEL_STEP;

    if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD) {
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