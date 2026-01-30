#include <iostream>
using namespace std;

class Person {
public:
	void Sleep() {
		cout << "Sleep" << endl;
	}
};

class Student : public Person {
public:
	void Study() {
		cout << "Study" << endl;
	}
};

class PartTimeStudent : public Student {
public:
	void Work() {
		cout << "Work" << endl;
	}
};

int main(void) {
	Person* ptr1 = new Student(); //Person을 상속한 Student 객체 생성
	Person* ptr2 = new PartTimeStudent(); //Person을 상속한 Student를 상속한 PartTimeStudent 객체 생성
	Student* ptr3 = new PartTimeStudent(); //Student를 상속한 PartTimeStudent 객체 생성
	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();
	delete ptr1;
	delete ptr2;
	delete ptr3;

	return 0;
}