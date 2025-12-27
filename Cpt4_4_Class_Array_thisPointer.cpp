#include <iostream>
#include <cstring>
using namespace std;

//class Person {
//	char* name;
//	int age;
//public:
//	//인자받는 생성자(main함수에서 Person 배열 선언할때 인자를 넣으면 그때 호출됨. 현재는 아래 코드에 인자를 안 넣었으므로 실행 안됨)
//	Person(char* myname, int myage) {
//		int len = strlen(myname) + 1;
//		name = new char[len];
//		strcpy_s(name, len, myname);
//		age = myage;
//		cout << "called Person(char, int)" << endl;
//	}
//	//생성자
//	Person() {
//		name = NULL;
//		age = 0;
//		cout << "called Person()" << endl;
//	}
//	//이름, 나이 설정
//	void SetPersonInfo(char* myname, int myage) {
//		name = myname;
//		age = myage;
//	}
//	//정보 출력
//	void ShowPersonInfo() const {
//		cout << "Name: " << name << ", ";
//		cout << "Age: " << age << endl;
//	}
//	//소멸자
//	~Person() {
//		delete[] name;
//		cout << "called Destructor" << endl;
//	}
//};

////this 포인터
//class ThisClass {
//	int num;
//public:
//	ThisClass(int n) : num(n) {
//		cout << "num = " << num << ", ";
//		cout << "address=" << this << endl;
//	}
//	void ShowThisClassData() {
//		cout << num << endl;
//	}
//	ThisClass* GetThisPointer() {
//		return this; //이 문장을 실행하는 객체 포인터 반환. 그래서 호출 시 반환형도 ThisClass * 로 선언
//	}
//};

//class TwoNumber {
//	int num1;
//	int num2;
//public:
//	TwoNumber(int num1, int num2) {
//		this->num1 = num1; //this->num1,2 = TwoNumber에서 private으로 선언된 멤버변수
//		this->num2 = num2; // num1,2 = 인자로 받은 매개변수
//	}
//	//멤버 이니셜라이저에서는 this포인터 사용불가
//	// //대신 저장하는 변수는 멤버변수로, 저장되는 값은(소괄호 안의 변수 및 상수) 매개변수로 인식하기 때문에 아래 예시처럼 구성 가능
//	//TwoNumber(int num1, int num2) : num1(num1), num2(num2) { }
//
//	void ShowTwoNumber() {
//		cout << this->num1 << endl; //멤버변수에 접근함을 명확히 함
//		cout << this->num2 << endl; //일반적으로는 this 생략
//	}
//};

class SelfRef {
	int num;
public:
	SelfRef(int n) : num(n) {
		cout << "Object Construct" << endl;
	}
	SelfRef& Adder(int n) {
		num += n;
		return *this;
	}
	SelfRef& ShowTwoNumber() {
		cout << num << endl;
		return *this;
	}
};

int main(void) {
	/*//객체 배열
	Person perArr[3]; //배열 선언하자 마자 기본 생성자 호출
	//배열의 각 요소에 인자를 넣어서 선언하면 인자받는 생성자가 호출됨
	char nameStr[100];
	char* strptr;
	int age;
	int len;


	//for문을 이용해 배열의 각 객체마다 이름과 나이 정보를 입력받아 객체 초기화
	for (int i = 0; i < 3; i++) {
		cout << "Name: ";
		cin >> nameStr;
		cout << "Age: ";
		cin >> age;
		len = strlen(nameStr) + 1;
		strptr = new char[len];
		strcpy_s(strptr, len, nameStr);
		perArr[i].SetPersonInfo(strptr, age);
	}
	perArr[0].ShowPersonInfo();
	perArr[1].ShowPersonInfo();
	perArr[2].ShowPersonInfo();*/

	//----------------------------------------------------

	////객체 포인터 배열
	//Person* perArr[3];
	//char nameStr[100];
	//int age;

	//for (int i = 0; i < 3; i++) {
	//	cout << "Name: ";
	//	cin >> nameStr;
	//	cout << "Age: ";
	//	cin >> age;
	//	perArr[i] = new Person(nameStr, age); //인자받는 생성자 호출
	//}
	//perArr[0]->ShowPersonInfo();
	//perArr[1]->ShowPersonInfo();
	//perArr[2]->ShowPersonInfo();
	////객체를 3번 생성했으므로 다시 삭제
	//delete perArr[0];
	//delete perArr[1];
	//delete perArr[2];

	//----------------------------------------------------

	//this 포인터
	//ThisClass tcl1(100);
	//ThisClass* ptr1 = tcl1.GetThisPointer(); //tcl1 객체 주소 값 저장(반환형이 포인터)
	//cout << ptr1 << ", ";
	//ptr1->ShowThisClassData();

	//ThisClass tcl2(200);
	//ThisClass* ptr2 = tcl2.GetThisPointer();
	//cout << ptr2 << ", ";
	//ptr2->ShowThisClassData();

	/*TwoNumber two(2, 4);
	two.ShowTwoNumber();*/

	//----------------------------------------------------
	//Self-Reference
	SelfRef obj(3);
	SelfRef& ref = obj.Adder(2);

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();


	return 0;
}