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

//멤버변수 이니셜라이저 초기화
class SoSimple {
	int num1;
public:
	SoSimple(int n1) : num1(n1) //변수 num1을 매개변수 n1으로 초기화
	{

	}
};


//int main(void) {
//	/*SimpleClass sc1;
//	sc1.ShowData();
//
//	SimpleClass sc2(100);
//	sc2.ShowData();
//
//	SimpleClass sc3(100, 200);
//	sc3.ShowData();*/
//
//	//SimpleClass sc1(); //지역적으로 함수 원형 선언
//	//SimpleClass mysc = sc1(); //sc1 함수를 호출하여, 이 때 반환되는 객체 값으로 mysc 객체 초기화
//	//mysc.ShowData();
//
//	//-------------------------------------------------
//
//
//	return 0;
//}

////함수 정의
//SimpleClass sc1() {
//	SimpleClass sc(20, 30);
//	return sc;
//}