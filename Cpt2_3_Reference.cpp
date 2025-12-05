#include <iostream>
using namespace std;


int main(void) {
	//int num1 = 1020;
	//int& num2 = num1; //num1에 대한 참조자 num2를 선언

	//int& num3 = num2;
	//int& num4 = num3;

	//num2 = 5060;

	//cout << "VAL: " << num1 << endl;
	//cout << "REF: " << num2 << endl;
	//cout << "REF: " << num3 << endl;
	//cout << "REF: " << num4 << endl;

	/*cout << "VAL: " << &num1 << endl;
	cout << "REF: " << &num2 << endl;*/

	//--------------------------------------------------------------

	//배열요소 참조자 선언
	/*int arr[3] = { 1,3,5 };
	int& ref1 = arr[0];
	int& ref2 = arr[1];
	int& ref3 = arr[2];

	cout << ref1 << endl;
	cout << ref2 << endl;
	cout << ref3 << endl;*/

	//--------------------------------------------------------------

	int num = 12;
	int* ptr = &num; //포인터 ptr을 num의 주소로 지정
	int** dptr = &ptr; //이중포인터. 포인터 ptr의 주소(num)를 지정

	int& ref = num;
	int* (&pref) = ptr; //포인터 ptr 참조
	int** (&dpref) = dptr; //이중포인터 dptr 참조

	cout << ref << endl;
	cout << *pref << endl; //*ptr의 참조자이므로 num 출력
	cout << **dpref << endl; //**dptr의 참조자이므로 *ptr(=num) 출력


	return 0;
}