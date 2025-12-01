#include <iostream>
// 매크로함수
//#define SQUARE(x) ((x)*(x))

////inline 함수
//inline int SQUARE(int x) {
//	return x * x;
//}

//템플릿(인라인 함수의 자료형 의존으로 인한 데이터 손실 방지)
template <typename T> //T형 데이터 선언(임시로 사용하는 데이터형, 이후에 데이터가 들어오면 들어온 데이터의 자료형에 따라 자료형이 결정됨
inline T SQUARE(T x) {
	return x * x;
}

int main(void) {
	//매크로함수
	//std::cout << SQUARE(5) << std::endl;

	//inline 함수
	std::cout << SQUARE(5) << std::endl;
	std::cout << SQUARE(3.3) << std::endl;


	return 0;
}