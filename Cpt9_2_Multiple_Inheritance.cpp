#include <iostream>
using namespace std;

//class BaseOne {
//public:
//	void SimpleFunc() { cout << "BaseOne" << endl; }
//};
//
//class BaseTwo {
//public:
//	void SimpleFunc() { cout << "BaseTwo" << endl; }
//};
//
//class MultiDerived : public BaseOne, protected BaseTwo { //다중상속
//public:
//	void ComplexFunc() {
//		BaseOne::SimpleFunc();
//		BaseTwo::SimpleFunc();
//	}
//};
//-------------------------------------------

class Base {
public:
	Base() { cout << "Base Constructor" << endl; }
	void SimpleFunc() { cout << "BaseOne" << endl; }
};

class MiddleDerivedOne :virtual public Base { //가상상속
public:
	MiddleDerivedOne() :Base() { //기초클래스 생성자 호출 명시(굳이 필요없음)
		cout << "MiddleDerivedOne Constructor" << endl;
	}
	void MiddleFuncOne() {
		SimpleFunc();
		cout << "MiddleDerivedOne" << endl;
	}
};

class MiddleDerivedTwo :virtual public Base { //가상상속
public:
	MiddleDerivedTwo() :Base() { //기초클래스 생성자 호출 명시(굳이 필요없음)
		cout << "MiddleDerivedTwo Constructor" << endl;
	}
	void MiddleFuncTwo() {
		SimpleFunc();
		cout << "MiddleDerivedTwo" << endl;
	}
};

class LastDerived :public MiddleDerivedOne, public MiddleDerivedTwo {
public:
	LastDerived() :MiddleDerivedOne(), MiddleDerivedTwo() { //기초클래스 생성자 호출 명시(굳이 필요없음)
		cout << "LastDerived Constructor" << endl;
	}
	void ComplexFunc() {
		MiddleFuncOne();
		MiddleFuncTwo();
		SimpleFunc();
	}
};

int main(void) {
	/*MultiDerived mdr;
	mdr.ComplexFunc();*/
	//-------------------------------------------
	cout << "Before Generate Object" << endl;
	LastDerived ldr;
	cout << "After Generate Object" << endl;
	ldr.ComplexFunc();


	return 0;
}