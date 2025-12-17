#include <iostream>
#include <cstring>
using namespace std;

#include "Cpt3_2_Q1_Calculator.h"

//파일 분할
//#include "Cpt3_2_Ex_Car.h"
//
//namespace CAR_CONST {
//    enum {
//        ID_LEN=20,
//        MAX_SPD=200,
//        FUEL_STEP=2,
//        ACC_STEP=10,
//        BRK_STEP=10
//    };
//}
//
////클래스의 선언
//class Car {
////이후에 선언되는 변수 및 함수는 모두 private
//private:
//    //멤버변수
//    char gamerID[CAR_CONST::ID_LEN];
//    int fuelGauge;
//    int curSpeed;
//
////이후에 선언되는 변수 및 함수는 모두 public
//public:
//    //멤버함수
//    void InitMembers(const char * ID, int fuel);
//    void ShowCarState();
//    void Accel();
//    void Break();
//};
//
////클래스의 정의
//void Car::InitMembers(const char * ID, int fuel) {
//    strcpy_s(gamerID, CAR_CONST::ID_LEN, ID);
//    fuelGauge = fuel;
//    curSpeed = 0;
//}
//
//void Car::ShowCarState() {
//    cout << "Owner ID: " << gamerID << endl;
//    cout << "Fuel Enough: " << fuelGauge <<"%" << endl;
//    cout << "Current Speed: " << curSpeed << "km/s" << endl << endl;
//}
//
//void Car::Accel() {
//    if (fuelGauge <= 0)
//        return;
//    else
//        fuelGauge -= CAR_CONST::FUEL_STEP;
//
//    if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD) {
//        curSpeed = CAR_CONST::MAX_SPD;
//        return;
//    }
//    curSpeed += CAR_CONST::ACC_STEP;
//}
//
//void Car::Break() {
//    if (curSpeed < CAR_CONST::BRK_STEP) {
//        curSpeed = 0;
//        return;
//    }
//    curSpeed -= CAR_CONST::BRK_STEP;
//}

class Printer {
private:
    string str;
public:
    void SetString(string str);
    void ShowString();
};

void Printer::SetString(string str) {
    Printer::str = str;
}

void Printer::ShowString() {
    cout << str << endl;
}


 int main(void) {
     /*Car run111;
     run111.InitMembers("run111", 100);
     run111.Accel();
     run111.Accel();
     run111.Accel();
     run111.ShowCarState();
     run111.Break();
     run111.ShowCarState();*/

     //문제 3-2 1. 계산기 클래스(Calcuator)
     /*Calculator cal;
     cal.Init();
     cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
     cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
     cout << "2.2 - 1.5 = " << cal.Min(2.2,1.5) << endl;
     cout << "4.9 / 1.2 = " << cal.Div(4.9,1.2) << endl;
     cal.ShowOpCount();*/
     
     //--------------------------------------------------------
     //문제 3-2 2. Printer 클래스
     //기능: 문자열 저장, 출력
     Printer pnt;
     pnt.SetString("Hello World!");
     pnt.ShowString();

     pnt.SetString("I love Project RX~");
     pnt.ShowString();

     return 0;
 }