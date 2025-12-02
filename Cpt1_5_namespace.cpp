#include <iostream>
//#include "Adder.h"

//using std::cin;
//using std::cout;
//using std::endl;

//이름공간 std에 선언된 모든 것에 대해 이름공간 지정의 생략 명령
using namespace std;

//namespace 선언 및 정의
//namespace AImpl {
//    void SimpleFunc(void) {
//        std::cout << "A's Function" << std::endl;
//    }
//
//}
//namespace BImpl {
//    void SimpleFunc(void) {
//        std::cout << "B's Function" << std::endl;
//    }
//}

//------------------------------------------------------------------

////namespace 선언
//namespace AImpl {
//	void SimpleFunc(void);
//}
//namespace AImpl {
//	void PrettyFunc(void);
//}
//namespace BImpl {
//	void SimpleFunc(void);
//}
//
////namespace 중첩
//namespace Parent {
//	int num = 2;
//
//	namespace SubOne {
//		int num = 3;
//	}
//	namespace SubTwo {
//		int num = 4;
//	}
//}

//------------------------------------------------------------------

////using 이용하기
//namespace Hybrid {
//	void HybFunc(void) {
//		std::cout << "So simple funcion!" << std::endl;
//		std::cout << "In namespace Hybrind!" << std::endl;
//	}
//}

//------------------------------------------------------------------
//이름공간 별칭
namespace AAA {
	namespace BBB {
		namespace CCC {
			int num1;
			int num2;
		}
	}
}

int main(void) {

	//AImpl::SimpleFunc();
	//BImpl::SimpleFunc();

	/*std::cout << Parent::num << std::endl;
	std::cout << Parent::SubOne::num << std::endl;
	std::cout << Parent::SubTwo::num << std::endl;*/

	//------------------------------------------------------------------

	////문제 1-4. 파일 분할(헤더파일, 소스파일 만들어 하나로 컴파일하기)
	//int result = Add(3, 5);
	//std::cout << "result: " << result << std::endl;

	//------------------------------------------------------------------

	////using 이용하기
	//using Hybrid::HybFunc; //HybFunc를 이름공간 Hybrid에서 찾으라
	//HybFunc();

	//int num = 20;
	////맨 위에서 using을 이용하여 이름공간 지정을 생략함
	//cout << "Hello World!" << endl;
	//cout << num << ' ' << 'A';
	//cout << ' ' << 3.14 << endl;

	//------------------------------------------------------------------

	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;

	namespace ABC = AAA::BBB::CCC;
	cout << ABC::num1 << endl;
	cout << ABC::num2 << endl;


	return 0;
}

//------------------------------------------------------------------

////namespace 정의
//void AImpl::SimpleFunc(void) {
//	std::cout << "A's Function" << std::endl;
//	PrettyFunc(); //동일 이름공간의 함수 호출 시에는 이름공간 명시할 필요 없음
//	BImpl::SimpleFunc(); //다른 이름공간
//}
//
//void AImpl::PrettyFunc(void) {
//	std::cout << "So Perfect!" << std::endl;
//}
//
//void BImpl::SimpleFunc(void) {
//	std::cout << "B's Function" << std::endl;
//}