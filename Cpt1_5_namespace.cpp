#include <iostream>
#include "Adder.h"

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

//namespace 선언
namespace AImpl {
	void SimpleFunc(void);
}
namespace AImpl {
	void PrettyFunc(void);
}
namespace BImpl {
	void SimpleFunc(void);
}

//namespace 중첩
namespace Parent {
	int num = 2;

	namespace SubOne {
		int num = 3;
	}
	namespace SubTwo {
		int num = 4;
	}
}

int main(void) {

	//AImpl::SimpleFunc();
	//BImpl::SimpleFunc();

	/*std::cout << Parent::num << std::endl;
	std::cout << Parent::SubOne::num << std::endl;
	std::cout << Parent::SubTwo::num << std::endl;*/

	//문제 1-4. 파일 분할(헤더파일, 소스파일 만들어 하나로 컴파일하기)
	int result = Add(3, 5);
	std::cout << "result: " << result << std::endl;

	return 0;
}


//namespace 정의
void AImpl::SimpleFunc(void) {
	std::cout << "A's Function" << std::endl;
	PrettyFunc(); //동일 이름공간의 함수 호출 시에는 이름공간 명시할 필요 없음
	BImpl::SimpleFunc(); //다른 이름공간
}

void AImpl::PrettyFunc(void) {
	std::cout << "So Perfect!" << std::endl;
}

void BImpl::SimpleFunc(void) {
	std::cout << "B's Function" << std::endl;
}