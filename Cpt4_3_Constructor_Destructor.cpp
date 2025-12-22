#include <iostream>
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
//private 생성자
class AAA {
	int num;
public:
	AAA() : num(0) {}
	AAA& CreateInitObj(int n) const {
		AAA* ptr = new AAA(n); //private 생성자를 이용해 AAA 객체를 생성 및 반환
		return *ptr;
	}
	void ShowNum() const { cout << num << endl; }
private: //private 생성자 선언
	AAA(int n) : num(n) {}
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
	//private 생성자
	AAA base;
	base.ShowNum();

	AAA& obj1 = base.CreateInitObj(3);
	obj1.ShowNum();

	AAA& obj2 = base.CreateInitObj(12);
	obj2.ShowNum();

	delete& obj1;
	delete& obj2;

	return 0;
}


////함수 정의
//SimpleClass sc1() {
//	SimpleClass sc(20, 30);
//	return sc;
//}