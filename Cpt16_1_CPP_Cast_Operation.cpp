#include <iostream>
using namespace std;

class Car {
private:
	int fuelGauge;
public:
	Car(int fuel):fuelGauge(fuel){}
	void ShowCarState() {
		cout << "Remain Fuel: " << fuelGauge << endl;
	}
};

class Truck :public Car {
private:
	int freightWeight;
public:
	Truck(int fuel, int weight): Car(fuel), freightWeight(weight){}
	void ShowTruckState() {
		ShowCarState();
		cout << "Truck Weight: " << freightWeight << endl;
	}
};

int main(void) {
	Car* pcar1 = new Truck(80, 200);
	Truck* ptruck1 = (Truck*)pcar1;
	//기초 클래스의 포인터형을 유도 클래스 포인터형으로 형 변환하는 것은
	// 일반적인 경우의 형 변환이 아님
	ptruck1->ShowTruckState();
	cout << endl;

	Car* pcar2 = new Car(120);
	Truck* ptruck2 = (Truck*)pcar2;
	//포인터 변수 pcar2가 가리키는 대상이 실제론 Car 객체이기 때문에 형 변환 연산은 문제가 됨
	// 하지만 C스타일 형 변환 연산자는 컴파일로 하여금 이러한 일이 가능하게 함
	ptruck2->ShowTruckState();


	return 0;
}