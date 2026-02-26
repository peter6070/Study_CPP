#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

//void Divide(int n1, int n2) {
//	if (n2 == 0)
//		throw n2; 
//		//예외 발생 시 Divide 함수를 호출한 main에서 예외 처리
//	cout << "Quotient of Division: " << n1 / n2 << endl;
//	cout << "Remain of Division: " << n1 % n2 << endl;
//}
//---------------------------------------

//String to Int(문자열을 정수로 변환)
//int StoI(const char* str) {
//	int len = strlen(str);
//	int num = 0;
//
//	for (int i = 0; i < len; i++) {
//		if (str[i] < '0' || str[i]>'9') //숫자가 아닌 형태의 문자가 있으면 예외처리
//			throw str[i];
//		num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7')));
//		//문자열을 정수로 변환
//	}
//	return num;
//}

//---------------------------------------
//stack unwinding

void SimpleFuncOne();
void SimpleFuncTwo();
void SimpleFuncThree();

int main(void) {
	/*int n1, n2;
	cout << "Enter two numbers: ";
	cin >> n1 >> n2;
	 
	try {
		Divide(n1, n2);
		cout << "Complete Divide" << endl;
	}
	catch (int expn) {
		cout << "Divisor can't be " << expn << endl;
		cout << "Restart Program" << endl;
	}
	cout << "end of main" << endl;*/
	//---------------------------------------

	/*char str1[100];
	char str2[100];

	while (1) {
		cout << "Enter two numbers: ";
		cin >> str1 >> str2;

		try {
			cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
			break; //예외가 없으면 break로 while문 빠져나옴
		}
		catch (char ch) {
			cout << "Entered char " << ch << endl;
			cout << "Restart Enter" << endl << endl;
			//예외 발생하면 break를 실행하지 않아 while문의 처음으로 돌아가 다시 실행
		}
	}
	cout << "end of main" << endl;*/

	//---------------------------------------
	//stack unwinding
	try {
		SimpleFuncOne();
	}
	catch (int e) {
		cout << "Exception code: " << e << endl;
	}

	return 0;
}

void SimpleFuncOne() {
	cout << "SimpleFuncOne()" << endl;
	SimpleFuncTwo();
}
void SimpleFuncTwo() {
	cout << "SimpleFuncTwo()" << endl;
	SimpleFuncThree();
}
void SimpleFuncThree() {
	cout << "SimpleFuncThree()" << endl;
	throw - 1;
}