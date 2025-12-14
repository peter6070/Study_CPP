#include <iostream>
#include <cstring>
using namespace std;

namespace CAR_CONST {
    enum {
        ID_LEN=20,
        MAX_SPD=200,
        FUEL_STEP=2,
        ACC_STEP=10,
        BRK_STEP=10
    };
}

class Car {
private:
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

public:
    void InitMembers(const char * ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

void Car::InitMembers(const char * ID, int fuel) {
    strcpy_s(gamerID, CAR_CONST::ID_LEN, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState() {
    cout << "Owner ID: " << gamerID << endl;
    cout << "Fuel Enough: " << fuelGauge <<"%" << endl;
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

 int main(void) {
     Car run111;
     run111.InitMembers("run111", 100);
     run111.Accel();
     run111.Accel();
     run111.Accel();
     run111.ShowCarState();
     run111.Break();
     run111.ShowCarState();
 
     return 0;
 }