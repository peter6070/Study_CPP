#include <iostream>
using namespace std;

//class Car {
//private:
//	int fuelGauge;
//public:
//	Car(int fuel):fuelGauge(fuel){}
//	void ShowCarState() {
//		cout << "Remain Fuel: " << fuelGauge << endl;
//	}
//};
//
//class Truck : public Car {
//private:
//	int freightWeight;
//public:
//	Truck(int fuel, int weight): Car(fuel), freightWeight(weight){}
//	void ShowTruckState() {
//		ShowCarState();
//		cout << "Truck Weight: " << freightWeight << endl;
//	}
//};
//
//void ShowString(char* str) {
//	cout << str << endl;
//}
//
//void ShowAddResult(int& n1, int& n2) {
//	cout << n1 + n2 << endl;
//}

class Simple { //Polymorphic 클래스 (ShowSimple가 가상함수이므로)
public:
	virtual void ShowSimple() { //가상함수
		cout << "Simple Base Class" << endl;
	}
};

class SoComplex : public Simple {
public:
	void ShowSimple() { //가상함수
		cout << "SoComplex Derived Class" << endl;
	}
};

int main(void) {
	//Car* pcar1 = new Truck(80, 200);
	//Truck* ptruck1 = (Truck*)pcar1;
	////기초 클래스의 포인터형을 유도 클래스 포인터형으로 형 변환하는 것은
	//// 일반적인 경우의 형 변환이 아님
	//ptruck1->ShowTruckState();
	//cout << endl;

	//Car* pcar2 = new Car(120);
	//Truck* ptruck2 = (Truck*)pcar2;
	////포인터 변수 pcar2가 가리키는 대상이 실제론 Car 객체이기 때문에 형 변환 연산은 문제가 됨
	//// 하지만 C스타일 형 변환 연산자는 컴파일로 하여금 이러한 일이 가능하게 함
	//ptruck2->ShowTruckState();

	//----------------------------------------------------------
	////dynamic_cast
	//Car* pcar1 = new Truck(80, 200); //기초 클래스 포인터를 유도 클래스로 형 변환 시도하려해서 오류
	////Truck* ptruck1 = dynamic_cast<Truck*>(pcar1); //컴파일 에러

	//Car* pcar2 = new Car(120); //기초 클래스 포인터를 유도 클래스로 형 변환 시도하려해서 오류
	////Truck* ptruck2 = dynamic_cast<Truck*>(pcar2); //컴파일 에러

	//Truck* ptruck3 = new Truck(70, 150); //유도 클래스의 포인터를
	//Car* pcar3 = dynamic_cast<Car*>(ptruck3); // 기초 클래스의 포인터로 형 변환

	//----------------------------------------------------------
	//static_cast
	//Car* pcar1 = new Truck(80, 200);
	////Truck 객체를 생성했지만 Car 포인터형으로 선언했기 때문에 
	//// 접근 가능한 함수, 변수는 Car 클래스에 있는 것들로만 한정됨
	//Truck* ptruck1 = static_cast<Truck*>(pcar1); 
	////Truck 객체로 생성된 pcar1의 포인터형을 Truck*으로 형 변환하면서 
	//// Truck 클래스의 함수, 변수에 접근 가능
	//ptruck1->ShowTruckState();

	//Car* pcar2 = new Car(120);
	//Truck* ptruck2 = static_cast<Truck*>(pcar2); //컴파일은 가능하지만 이상한 값 출력
	////Car는 Truck의 freightWeight값을 받지 않는데 강제로 Truck형으로 변환을 했기 때문에 
	//// 쓰레기값이 freightWeight에 들어가면서 이상한 값이 출력됨
	//ptruck2->ShowTruckState();

	//----------------------------------------------------------
	//const_cast
	//const char* name = "Lee"; //const로 선언
	//ShowString(const_cast<char*>(name)); 
	////ShowString의 매개변수는 const가 아니지만 const_cast로 형 변환하여 name을 넘겨줌

	//const int& n1 = 100; //n1, n2 둘다 const로 선언
	//const int& n2 = 200;
	//ShowAddResult(const_cast<int&>(n1), const_cast<int&>(n2));
	////ShowAddResult의 매개변수는 int&형으로 받지만 const_cast로 형 변환하여 n1, n2 넘겨줌

	//----------------------------------------------------------
	//reinterpret_cast
	//int num = 0x010203;
	//char* ptr = reinterpret_cast<char*>(&num);
	////int형 정수에 바이트 단위 접근을 위해 int형 포인터를 char형 포인터로 형 변환

	//for (int i = 0; i < sizeof(num); i++)
	//	cout << static_cast<int>(*(ptr + i)) << endl;
	////바이트 단위 데이터를 문자가 아닌 정수 형태로 출력하기 위해 char형 데이터를 int형으로 변환

	//----------------------------------------------------------
	//Polymorphic dynamic_cast
	//Simple* simPtr = new SoComplex; //simPtr이 실제 가리키는 객체는 SoComplex
	//SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
	////기초 클래스인 simPtr을 유도 클래스인 SoComplex형 포인터로 형 변환
	//// 기초 클래스에 가상함수가 존재하기 때문에(Polymorphic 클래스) 형 변환 가능
	//comPtr->ShowSimple();

	//----------------------------------------------------------
	//dynamic_cast vs static_cast
	//Simple* simPtr = new Simple; 
	//SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
	////simPtr이 가리키는 객체가 Simple이기 때문에 형 변환 불가(NULL값 들어감)
	//if (comPtr == NULL)
	//	cout << "Type Casting Failed" << endl;
	//else
	//	comPtr->ShowSimple();

	//----------------------------------------------------------
	//dynamic_cast bad_cast Exception
	SoComplex sim;
	Simple& ref = sim;

	try {
		SoComplex& comRef = dynamic_cast<SoComplex&>(ref);
		//참조자 ref가 실제 참조하는 대상이 Simple 객체이기 때문에 
		// SoComplex 참조형으로의 형 변환은 안전하지 못함
		// 그리고 참조자를 대상으로는 NULL을 반환할 수 없기 때문에 bad_cast 예외 발생
		comRef.ShowSimple();
	}
	catch (bad_cast expt) {
		cout << expt.what() << endl;
		//what(): 예외의 원인을 문자열 형태로 반환
	}

	return 0;
}