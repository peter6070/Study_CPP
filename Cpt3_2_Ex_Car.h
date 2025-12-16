//헤더파일 중복포함 문제를 해결하는 매크로 선언
#pragma once
//옛날 스타일의 헤더파일 중복포함 문제 해결 매크로 선언
//#ifndef __CAR_H__
//#define __CAR_H__

#include <iostream>
using namespace std;

namespace CAR_CONST {
    enum {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };
}

//클래스의 선언
class Car {
    //이후에 선언되는 변수 및 함수는 모두 private
private:
    //멤버변수
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

    //이후에 선언되는 변수 및 함수는 모두 public
public:
    //멤버함수
    void InitMembers(const char* ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

//#endif

//inline 키워드를 사용해 헤더파일 내에 함수 정의 가능
inline void Car::InitMembers(const char* ID, int fuel) {
    strcpy_s(gamerID, CAR_CONST::ID_LEN, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

inline void Car::ShowCarState() {
    cout << "Owner ID: " << gamerID << endl;
    cout << "Fuel Enough: " << fuelGauge << "%" << endl;
    cout << "Current Speed: " << curSpeed << "km/s" << endl << endl;
}

inline void Car::Accel() {
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

inline void Car::Break() {
    if (curSpeed < CAR_CONST::BRK_STEP) {
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}