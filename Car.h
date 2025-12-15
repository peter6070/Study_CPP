//헤더파일 중복포함 문제를 해결하는 매크로 선언
#pragma once
//옛날 스타일의 헤더파일 중복포함 문제 해결 매크로 선언
//#ifndef __CAR_H__
//#define __CAR_H__

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