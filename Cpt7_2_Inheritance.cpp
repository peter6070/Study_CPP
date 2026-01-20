#include <iostream>
using namespace std;

//class Person {
//	int age;
//	char name[50];
//public:
//	Person(int myage, const char* myname) : age(myage) {
//		strcpy_s(name, 50, myname);
//	}
//	void WharYourName() const {
//		cout << "My name is " << name << endl;
//	}
//	void HowOldAreYou() const {
//		cout << "I'm " << age << " years old" << endl;
//	}
//};
//
//class UnivStudent : public Person {	//Person 클래스의 상속
//	char major[50];
//public:
//	UnivStudent(const char* myname, int myage, const char* mymajor) 
//		: Person(myage, myname) {
//		strcpy_s(major, 50, mymajor);
//	}
//	void WhoAreYou() const {
//		WharYourName(); //상속 함수
//		HowOldAreYou(); //상속 함수
//		cout << "My major is " << major << endl << endl;
//	}
//};

//-----------------------------------------------------

class Base {
	int baseNum;
public:
	Base() : baseNum(20) {
		cout << "Base()" << endl;
	}
	Base(int n) : baseNum(n) {
		cout << "Base(int n)" << endl;
	}
	void ShowBaseData() {
		cout << baseNum << endl;
	}
};

class Derived : public Base {
	int derivNum;
public:
	Derived() : derivNum(30) {
		cout << "Derived():" << endl;
	}
	Derived(int n) : derivNum(n) {
		cout << "Derived(int n)" << endl;
	}
	Derived(int n1, int n2) : Base(n1), derivNum(n2) {
		cout << "Derived(int n1, int n2)" << endl;
	}
	void ShowDerivData() {
		ShowBaseData();
		cout << derivNum << endl;
	}
};


int main(void) {
	/*UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();
	
	UnivStudent ustd2("Kim", 21, "Electronic eng.");
	ustd2.WhoAreYou();*/

	//-----------------------------------------------------

	cout << "case1......." << endl;
	Derived dr1;
	dr1.ShowDerivData();
	cout << "------------------" << endl;
	cout << "case2......." << endl;
	Derived dr2(12);
	dr2.ShowDerivData();
	cout << "------------------" << endl;
	cout << "case3........" << endl;
	Derived dr3(23, 24);
	dr3.ShowDerivData();

	return 0;
}