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


int main(void) {
	/*UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();
	
	UnivStudent ustd2("Kim", 21, "Electronic eng.");
	ustd2.WhoAreYou();*/

	//-----------------------------------------------------


	return 0;
}