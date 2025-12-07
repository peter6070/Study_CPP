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

void SwapPointer(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

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

     //문제3.포인터가 가리키는 대상 바꾸기
     int num1 = 5;
     int* ptr1 = &num1;
     int num2 = 10;
     int* ptr2 = &num2;

     cout << "Before Swap: " << num1 << ' ' << num2 << endl;

     SwapPointer(ptr1, ptr2);

     cout << "After Swap: " << num1 << ' ' << num2 << endl;

     return 0;
 }