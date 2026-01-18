#include <iostream>
using namespace std;

//int simObjCnt = 0;
//int cmxObjCnt = 0;

//class Simple {
//public:
//	//static 변수 외부 접근
//	static int simObjCnt; //static 멤버변수
//public: //변수와 함수의 구분을 목적으로 삽입하기도 함
//	Simple() {
//		simObjCnt++;
//		//cout << simObjCnt << "'s Simple Object" << endl;
//	}
//};
//int Simple::simObjCnt = 0;

//class Complex {
//	static int cmxObjCnt; //static 멤버변수
//public:
//	Complex() {
//		cmxObjCnt++;
//		cout << cmxObjCnt << "'s Complex Object" << endl;
//	}
//	Complex(Complex& copy) {
//		cmxObjCnt++;
//		cout << cmxObjCnt << "'s Complex Object" << endl;
//	}
//};
//int Complex::cmxObjCnt = 0;

//----------------------------------------------------

//class CountryArea {
//public:
//	const static int RUSSIA = 1707540;
//	const static int CANADA = 7845222;
//	const static int CHINA = 5982523;
//	const static int SOUTH_KOREA = 9922;
//};

//----------------------------------------------------

class Simple {
	int num1;
	mutable int num2; //const 함수에 대해 예외를 둠
public:
	Simple(int n1, int n2) : num1(n1), num2(n2){}
	void ShowSimpleData() const {
		cout << num1 << ", " << num2 << endl;
	}
	void CpoyToNum2() const {
		num2 = num1;
		//const 함수 내에서 값 변경함
		//num2가 mutable로 선언되었기 때문에 가능
	}
};


int main(void) {
	/*Simple sim1;
	Simple sim2;

	Complex com1;
	Complex com2 = com1;
	Complex();*/

	//----------------------------------------------------
	//cout << Simple::simObjCnt << "'s Simple Object" << endl;
	//Simple sim1;
	//Simple sim2;

	//cout << Simple::simObjCnt << "'s Simple Object" << endl;
	//cout << sim1.simObjCnt << "'s Simple Object" << endl; //simObjCnt 변수가 public으로 선언되었기 때문에 외부에서도 접근 가능
	//cout << sim2.simObjCnt << "'s Simple Object" << endl;
	//----------------------------------------------------

	////상수 접근을 위해 객체를 생성할 필요 없음
	//cout << "Area of RUSSIA: " << CountryArea::RUSSIA << "km" << endl;
	//cout << "Area of CANADA: " << CountryArea::CANADA << "km" << endl;
	//cout << "Area of CHINA: " << CountryArea::CHINA << "km" << endl;
	//cout << "Area of SOUTH_KOREA: " << CountryArea::SOUTH_KOREA << "km" << endl;
	//----------------------------------------------------

	Simple sm(1, 2);
	sm.ShowSimpleData();
	sm.CpoyToNum2();
	sm.ShowSimpleData();

	return 0;
}