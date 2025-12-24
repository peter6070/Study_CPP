#include <iostream>
#include <cstring>
using namespace std;

//class SimpleClass {
//	int num1;
//	int num2;
//public:
//	SimpleClass() {
//		num1 = 0;
//		num2 = 0;
//	}
//	SimpleClass(int n) {
//		num1 = n;
//		num2 = 0;
//	}
//	SimpleClass(int n1, int n2) {
//		num1 = n1;
//		num2 = n2;
//	}
//	//SimpleClass()와 겹쳐 오류(둘 다 호출인자를 필요로 하지 않는데, 둘 중 누구를 호출해야하는지 모르기 때문)
//	/*SimpleClass(int n1 = 0, int n2 = 0) {
//		num1 = n1;
//		num2 = n2;
//	}*/
//	void ShowData() const {
//		cout << num1 << ' ' << num2 << endl;
//	}
//};

//--------------------------------------------------------
////멤버변수 이니셜라이저 초기화
//class SoSimple {
//	int num1;
//public:
//	SoSimple(int n1) : num1(n1) //변수 num1을 매개변수 n1으로 초기화
//	{
//
//	}
//};

//--------------------------------------------------------

//class AAA {
//public:
//	AAA() {
//		cout << "empty object" << endl;
//	}
//	void ShowYourName() {
//		cout << "I'm class AAA" << endl;
//	}
//};
//
//class BBB {
//	AAA& ref; //참조자가 멤버변수로 선언. 이니셜라이저를 통해 초기화
//	const int& num; //const 참조자 선언. 이니셜라이저를 통해 정수형 상수로도 초기화 가능
//
//public:
//	BBB(AAA& r, const int& n)
//		: ref(r), num(n) {
//
//	}
//	void ShowYourName() {
//		ref.ShowYourName();
//		cout << "and" << endl;
//		cout << "I ref num" << num << endl;
//	}
//};
//
//class CCC {
//	int num;
//public:
//	CCC() {} //디폴트 생성자
//	int GetNum() { return num; }
//};
//
////생성자 불일치 예시
//class SSS {
//	int num;
//public:
//	SSS(int n) : num(n){}
//	SSS() : num(0) {} //인자없이 객체 생성하기 위한 생성자
//};

//--------------------------------------------------------
////private 생성자
//class AAA {
//	int num;
//public:
//	AAA() : num(0) {}
//	AAA& CreateInitObj(int n) const {
//		AAA* ptr = new AAA(n); //private 생성자를 이용해 AAA 객체를 생성 및 반환
//		return *ptr;
//	}
//	void ShowNum() const { cout << num << endl; }
//private: //private 생성자 선언
//	AAA(int n) : num(n) {}
//};

//--------------------------------------------------------
////소멸자
//class Person {
//	char* name;
//	int age;
//public:
//	Person(const char* myname, int myage) {
//		int len = strlen(myname) + 1; //메모리를 문자열 길이만큼 동적 할당(메모리 절약)
//		name = new char[len]; //new 연산자로 객체 생성
//		strcpy_s(name, len, myname);
//		age = myage;
//	}
//	void ShowPersonInfo() const {
//		cout << "name: " << name << endl;
//		cout << "age: " << age << endl;
//	}
//	//소멸자(객체가 메모리에서 사라지기 전에 자동 호출됨)
//	~Person() {
//		delete[]name; //new로 생성한 객체 제거
//		cout << "called destructor!" << endl;
//	}
//};
//-------------------------------------------------
////문제 1.Ring 클래스에 생성자 정의
//class Point {
//	int xpos, ypos;
//public:
//	Point(int x, int y)
//		:xpos(x), ypos(y)
//	{	}
//	void ShowPointInfo() const {
//		cout << "[" << xpos << "," << ypos << "]" << endl;
//	}
//};
//
//class Circle {
//	int radius;
//	Point center;
//public:
//	Circle(int x, int y, int r) 
//		: center(x,y), radius(r)
//	{	}
//	void ShowCircleInfo() const {
//		cout << "radius: " << radius << endl;
//		center.ShowPointInfo();
//	}
//};
//
//class Ring {
//	Circle innerCircle;
//	Circle outterCircle;
//public:
//	Ring(int inX, int inY, int inR, int outX, int outY, int outR) 
//		:innerCircle(inX, inY, inR), outterCircle(outX, outY, outR)
//	{	}
//	void ShowRingInfo() const {
//		cout << "Inner Circle Info.." << endl;
//		innerCircle.ShowCircleInfo();
//		cout << "Outter Circle Info.." << endl;
//		outterCircle.ShowCircleInfo();
//	}
//};

namespace COMP_POS {
	//직급 정보
	enum {
		CLERK,
		SENIOR,
		ASSIST,
		MANAGER
	};
	//(교재)namespace에서 직급 출력하는 함수
	void ShowPositionInfo(int pos) {
		switch (pos) {
		case COMP_POS::CLERK: cout << "CLERK" << endl; break;
		case COMP_POS::SENIOR: cout << "SENIOR" << endl; break;
		case COMP_POS::ASSIST: cout << "ASSIST" << endl; break;
		case COMP_POS::MANAGER: cout << "MANAGER" << endl; break;
		default: cout << "Unknown" << endl; break;
		}
	}
}

//문제 2. 명함 NameCard  클래스
class NameCard {
	//성명, 회사이름, 전화번호, 직급
	char* name; //성명
	char* compName; //회사이름
	char* phone; //전화번호
	int position;


public:

	NameCard(const char* myname, const char* mycompName, const char* myphone, int myposition)
	{
		int len = strlen(myname) + 1; //문자열 길이만큼 길이 설정
		name = new char[len]; //name 변수에 myname 길이만큼 동적할당
		strcpy_s(name, len, myname); //name에 myname 문자열 복사

		//(교재) name = new char[strlen(myname) + 1]; 이런식으로 한번에 선언할수도 있음(strcpy_s 쓰려면 문자열 길이 필요해서 나는 따로 분리함)

		len = strlen(mycompName) + 1;
		compName = new char[len];
		strcpy_s(compName, len, mycompName);

		len = strlen(myphone) + 1;
		phone = new char[len];
		strcpy_s(phone, len, myphone);

		position = myposition;
	}
	void ShowNameCardInfo() {
		cout << "Name: " << name << endl;
		cout << "Company: " << compName << endl;
		cout << "Phone: " << phone << endl;
		cout << "Position: ";
		switch (position) {
			case COMP_POS::CLERK: cout << "CLERK" << endl; break;
			case COMP_POS::SENIOR: cout << "SENIOR" << endl; break;
			case COMP_POS::ASSIST: cout << "ASSIST" << endl; break;
			case COMP_POS::MANAGER: cout << "MANAGER" << endl; break;
			default: cout << "Unknown" << endl; break;
		}
		//(교재) cout << "Position: "; COMP_POS::ShowPositionInfo(position); //직급 출력 함수 호출
		cout << endl;

	}

	~NameCard() {
		delete[] name;
		delete[] compName;
		delete[] phone;
	}
};

int main(void) {
	/*SimpleClass sc1;
	sc1.ShowData();

	SimpleClass sc2(100);
	sc2.ShowData();

	SimpleClass sc3(100, 200);
	sc3.ShowData();*/

	//SimpleClass sc1(); //지역적으로 함수 원형 선언
	//SimpleClass mysc = sc1(); //sc1 함수를 호출하여, 이 때 반환되는 객체 값으로 mysc 객체 초기화
	//mysc.ShowData();

	//-------------------------------------------------

	/*AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();*/

	//-------------------------------------------------

	////생성자 불일치 예시
	////객체 생성 가능
	//SSS sObj1(10);
	//SSS* sPtr1 = new SSS(2);

	////객체 생성 불가능
	////생성자 호출을 위한 인자가 들어가지 않았고, 자동으로 삽입되지도 않았기 때문
	//SSS sObj2;
	//SSS* sPtr2 = new SSS;
	////SSS() : num(0) {} 를 SSS 클래스에 추가함으로써 생성 가능

	//-------------------------------------------------
	////private 생성자
	//AAA base; //스택에 저장
	//base.ShowNum();

	//AAA& obj1 = base.CreateInitObj(3); //new 연산자로 동적 할당 했기 때문에 힙에 저장(다쓰고 delete로 지워줘야함)
	//obj1.ShowNum();

	//AAA& obj2 = base.CreateInitObj(12);
	//obj2.ShowNum();

	//delete& obj1;
	//delete& obj2;
	//-------------------------------------------------
	////소멸자
	//Person man1("Lee", 29);
	//Person man2("Kim", 41);
	//man1.ShowPersonInfo();
	//man2.ShowPersonInfo();
	//-------------------------------------------------
	//문제 1.Ring 클래스에 생성자 정의
	/*Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();*/

	//-------------------------------------------------
	//문제 2. 명함 NameCard  클래스
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	return 0;
}


////함수 정의
//SimpleClass sc1() {
//	SimpleClass sc(20, 30);
//	return sc;
//}