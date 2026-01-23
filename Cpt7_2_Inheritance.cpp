#include <iostream>
using namespace std;

//class Person {
//	/*int age;
//	char name[50];*/
//	char* name;
//
//public:
//	/*Person(int myage, const char* myname) : age(myage) {
//		strcpy_s(name, 50, myname);
//	}*/
//	Person(const char* myname) {
//		int len = strlen(myname)+1;
//		name = new char[len];
//		strcpy_s(name, len, myname);
//	}
//	~Person() {
//		delete []name;
//	}
//	void WharYourName() const {
//		cout << "My name is " << name << endl;
//	}
//	/*void HowOldAreYou() const {
//		cout << "I'm " << age << " years old" << endl;
//	}*/
//};

//class UnivStudent : public Person {	//Person 클래스의 상속
//	//char major[50];
//	char* major;
//public:
//	/*UnivStudent(const char* myname, int myage, const char* mymajor) 
//		: Person(myage, myname) {
//		strcpy_s(major, 50, mymajor);
//	}*/
//	UnivStudent(const char* myname, const char* mymajor) : Person(myname) {
//		int len = strlen(mymajor) + 1;
//		major = new char[len];
//		strcpy_s(major, len, mymajor);
//	}
//	~UnivStudent() {
//		delete[] major;
//	}
//	void WhoAreYou() const {
//		WharYourName(); //상속 함수
//		//HowOldAreYou(); //상속 함수
//		cout << "My major is " << major << endl << endl;
//	}
//};

//-----------------------------------------------------

//class Base {
//	int baseNum;
//public:
//	//유도 클래스 생성 과정
//	/*Base() : baseNum(20) {
//		cout << "Base()" << endl;
//	}
//	Base(int n) : baseNum(n) {
//		cout << "Base(int n)" << endl;
//	}
//	void ShowBaseData() {
//		cout << baseNum << endl;
//	}*/
//	//---------------------------------------
//	//유도 클래스 소멸 과정
//	Base(int n) : baseNum(n) {
//		cout << "Base() : " << baseNum << endl;
//	}
//	~Base() {
//		cout << "~Base() : " << baseNum << endl;
//	}
//};

//class Derived : public Base {
//	int derivNum;
//public:
//	//유도 클래스 생성 과정
//	/*Derived() : derivNum(30) {
//		cout << "Derived():" << endl;
//	}
//	Derived(int n) : derivNum(n) {
//		cout << "Derived(int n)" << endl;
//	}
//	Derived(int n1, int n2) : Base(n1), derivNum(n2) {
//		cout << "Derived(int n1, int n2)" << endl;
//	}
//	void ShowDerivData() {
//		ShowBaseData();
//		cout << derivNum << endl;
//	}*/
//	//---------------------------------------
//	
//	//유도 클래스 소멸 과정
//	/*Derived(int n) : Base(n), derivNum(n) {
//		cout << "Derived() : " << derivNum << endl;
//	}
//	~Derived() {
//		cout << "~Derived() : " << derivNum << endl;
//	}*/
//	//---------------------------------------
//
//
//};

//-----------------------------------------------------

//문제 7-1. 상속과 클래스 호출
//클래스에 생성자 삽입
//class Car {
//	int gasolineGauge;
//public:
//	Car(int g) : gasolineGauge(g) {
//		cout << "Car(int g): " << gasolineGauge << endl;
//	}
//
//	int GetGasGauge() {
//		return gasolineGauge;
//	}
//};

//class HybridCar : public Car {
//	int electricGauge;
//public:
//	HybridCar(int e, int g) : electricGauge(e), Car(g) {
//		cout << "HybridCar(int e, int g): " << electricGauge << endl;
//	}
//	int GetElecGauge() {
//		return electricGauge;
//	}
//};
//
//class HybridWaterCar : public HybridCar {
//	int waterGauge;
//public: 
//	HybridWaterCar(int w, int e, int g) : waterGauge(w), HybridCar(e, g) {
//		cout << "HybridWaterCar(int w, int e, int g): " << waterGauge << endl;
//	}
//	void ShowCurrentGauge() {
//		cout << "Remaining gasolineGauge: " << GetGasGauge() << endl;
//		cout << "Remaining electricGauge: " << GetElecGauge() << endl;
//		cout << "Remaining waterGauge: " << waterGauge << endl;
//	}
//};

//-----------------------------------------------------

//문제 7-2. 생성자, 소멸자 정의

class MyFriendInfo {
	char* name;
	int age;
public:
	MyFriendInfo(const char* myname, int myage) : age(myage) {
		int len = strlen(myname) +1;
		name = new char[len];
		strcpy_s(name, len, myname);
	}
	~MyFriendInfo() {
		delete[] name;
	}
	void ShowMyFriendInfo() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* myname, int myage, const char* myaddr, const char* myphone)
			: MyFriendInfo(myname, myage)
		{
		int len = strlen(myaddr) + 1;
		addr = new char[len];
		strcpy_s(addr, len, myaddr);

		len = strlen(myphone) + 1;
		phone = new char[len];
		strcpy_s(phone, len, myphone);
	}
	~MyFriendDetailInfo() {
		delete[] addr;
		delete[] phone;
	}
	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		cout << "Address: " << addr << endl;
		cout << "Phone: " << phone << endl;
	}
};


int main(void) {
	/*UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();
	
	UnivStudent ustd2("Kim", 21, "Electronic eng.");
	ustd2.WhoAreYou();*/

	//-----------------------------------------------------

	//유도 클래스 생성 과정
	/*cout << "case1......." << endl;
	Derived dr1;
	dr1.ShowDerivData();
	cout << "------------------" << endl;
	cout << "case2......." << endl;
	Derived dr2(12);
	dr2.ShowDerivData();
	cout << "------------------" << endl;
	cout << "case3........" << endl;
	Derived dr3(23, 24);
	dr3.ShowDerivData();*/

	//-----------------------------------------------------

	//유도 클래스 소멸 과정
	//Derived drv1(15); //생성자는 기초 클래스부터
	//Derived drv2(27); //소멸자는 유도클래스부터(객체가 스택에 생성되기 때문)

	//-----------------------------------------------------

	/*UnivStudent st1("Kim", "Mathmatics");
	st1.WhoAreYou();
	UnivStudent st2("Lee", "Physics");
	st2.WhoAreYou();*/

	//-----------------------------------------------------

	////문제 7-1. 상속과 클래스 호출
	//HybridWaterCar hybridWaterCar(100,200,300);
	//hybridWaterCar.ShowCurrentGauge();

	//-----------------------------------------------------

	//문제 7-2. 생성자, 소멸자 정의
	MyFriendDetailInfo myFriendDetail("Lee", 20, "Republic of Korea", "010-1234-5678");
	myFriendDetail.ShowMyFriendDetailInfo();

	return 0;
}