#include <iostream>
using namespace std;

////참조자를 이용한 Call-by-reference
//void SwapByRef2(int& ref1, int& ref2) {
//    int temp = ref1;
//    ref1 = ref2;
//    ref2 = temp;
//}

//-----------------------------------------------------------------

////문제1.인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
//void PlusOne(int& num) {
//    num += 1;
//}
////문제1.인자로 전달된 int형 변수의 부호를 바꾸는 함수
//void SwapSign(int& num) {
//    num -= (num * 2);
//}

//-----------------------------------------------------------------

//void SwapPointer(int *ptr1, int *ptr2) {
//    int temp = *ptr1;
//    *ptr1 = *ptr2;
//    *ptr2 = temp;
//}

//-----------------------------------------------------------------

////반환형이 참조형인 경우
//int& RefRetFuncOne(int& ref) {
//	ref++; //num1이 1 증가(참조자이기 때문)
//	return ref; //참조자 리턴(num1 = 2인 상황)
//}
////num1을 참조자 ref로 받아 돌려줌. 즉 함수 자체가 참조자가 되는 셈
//
////-----------------------------------------------------------------
//
////반환형이 기본자료형(매개변수만 참조자)
//int RefRetFuncTwo(int& ref) {
//	ref++; //num1이 1 증가(참조자이기 때문)
//	return ref; //참조자 리턴(num1 = 2인 상황)
//}
//
////-----------------------------------------------------------------
//
////const 참조자(상수화된 변수)
//int Adder(const int& num1, const int& num2) {
//	return num1 + num2;
//}

////-----------------------------------------------------------------



int main(void) {
	/*int val1 = 10;
	int val2 = 20;

	SwapByRef2(val1, val2);
	cout << "val1: " << val1 << endl;
	cout << "val2: " << val2 << endl;*/

	//-----------------------------------------------------------------

	//문제1. 참조자를 이용해 함수 정의
	//- 인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
	//- 인자로 전달된 int형 변수의 부호를 바꾸는 함수

	//int num = 5;

	////문제1.인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
	//PlusOne(num);
	//cout << "PlusOne: " << num << endl;
	////문제1.인자로 전달된 int형 변수의 부호를 바꾸는 함수
	//SwapSign(num);
	//cout << "SwapSign: " << num << endl;

	//-----------------------------------------------------------------

	////문제3.포인터가 가리키는 대상 바꾸기
	//int num1 = 5;
	//int* ptr1 = &num1;
	//int num2 = 10;
	//int* ptr2 = &num2;

	//cout << "Before Swap: " << num1 << ' ' << num2 << endl;

	//SwapPointer(ptr1, ptr2);

	//cout << "After Swap: " << num1 << ' ' << num2 << endl;

	//-----------------------------------------------------------------

	//int num1 = 1;
	//int& num2 = RefRetFuncOne(num1); 

	//num1++;
	//num2++;
	//cout << "num1: " << num1 << endl;
	//cout << "num2: " << num2 << endl;
	//cout << "RefRetFuncOne(num1): " << RefRetFuncOne(num1) << endl;
	////num1 = num2 = ref

	//-----------------------------------------------------------------

	//int num1 = 1;
	//int num2 = RefRetFuncOne(num1); //정수형 num2로 선언
	////num2는 RefRetFuncOne(num1)의 값(주소X)을 가진 또 하나의 변수(참조자가 아니기 때문)

	//num1++;
	//num2+=100;
	//cout << "num1: " << num1 << endl; //3
	//cout << "num2: " << num2 << endl; //102
	////num1 != num2

	//-----------------------------------------------------------------

	//int num1 = 1;
	//int num2 = RefRetFuncTwo(num1);
	////반환형이 기본자료형(int)인 RefRetFuncTwo 함수의 반환 값은 반드시 변수에 저장해야함
	////반환 값은 상수나 다름없기 때문
	////int &num2 = RefRetFuncTwo(num1); XX

	//num1 += 1;
	//num2 += 100;
	//cout << "num1: " << num1 << endl; //3
	//cout << "num2: " << num2 << endl; //102

	//-----------------------------------------------------------------

	////const 참조자를 사용하여 참조자임에도 변수가 아닌 리터럴 상수 대입(실제로는 상수화된 변수)
	//cout<<Adder(3, 4) << endl;
	 
	//-----------------------------------------------------------------

	//문제2-2. const 포인터와 const 참조자

	const int num = 12;

	//1. 포인터 변수를 선언해 위 변수를 가리키게 하기
	//2. 이 포인터 변수를 참조하는 참조자 선언
	//3. 선언된 포인터 변수, 참조자를 이용해 num에 저장된 값을 출력

	const int* ptr = &num; //포인터 선언
	const int* (&ref) = ptr; //포인터 참조
	//ref의 본질은 참조자이지만, 값은 ptr이 가리키는 주소값이 들어있음

	cout << "ptr: " << *ptr << endl;
	cout << "ref: " << *ref << endl;


	return 0;
}