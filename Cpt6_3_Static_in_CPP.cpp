#include <iostream>
using namespace std;

//int simObjCnt = 0;
//int cmxObjCnt = 0;

class Simple {
public:
	//static 변수 외부 접근
	static int simObjCnt; //static 멤버변수
public: //변수와 함수의 구분을 목적으로 삽입하기도 함
	Simple() {
		simObjCnt++;
		//cout << simObjCnt << "'s Simple Object" << endl;
	}
};
int Simple::simObjCnt = 0;

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


int main(void) {
	/*Simple sim1;
	Simple sim2;

	Complex com1;
	Complex com2 = com1;
	Complex();*/

	//---------------------------------
	cout << Simple::simObjCnt << "'s Simple Object" << endl;
	Simple sim1;
	Simple sim2;

	cout << Simple::simObjCnt << "'s Simple Object" << endl;
	cout << sim1.simObjCnt << "'s Simple Object" << endl; //simObjCnt 변수가 public으로 선언되었기 때문에 외부에서도 접근 가능
	cout << sim2.simObjCnt << "'s Simple Object" << endl;


	return 0;
}