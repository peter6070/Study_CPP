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
int StoI(const char* str) throw(int, char) //발생 가능한 예외 종류 명시
{
	int len = strlen(str);
	int num = 0;

	if (len != 0 && str[0] == '0') //문자의 시작이 0으로 시작할 경우 예외처리
		throw 0;

	for (int i = 0; i < len; i++) {
		if (str[i] < '0' || str[i]>'9') //숫자가 아닌 형태의 문자가 있으면 예외처리
			throw str[i];
		num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7')));
		//문자열을 정수로 변환
	}	
	return num;
}

//---------------------------------------
//stack unwinding
//void SimpleFuncOne();
//void SimpleFuncTwo();
//void SimpleFuncThree();

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

	char str1[100];
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
		catch (int expn) {
			if (expn == 0)
				cout << "Can't enter the number start with 0" << endl;
			else
				cout << "Abnormal Enter" << endl;
			cout << "Restart Enter" << endl << endl;
		}
	}
	cout << "end of main" << endl;

	//---------------------------------------
	//stack unwinding
	//try {
	//	SimpleFuncOne(); 
	//}
	//catch (int e) { //SimpleFuncOne으로부터 전달받은 예외 데이터 처리
	//	cout << "Exception code: " << e << endl;
	//}

	return 0;
}

//void SimpleFuncOne() {
//	cout << "SimpleFuncOne()" << endl;
//	SimpleFuncTwo(); //3. SimpleFuncOne을 호출한 main으로 예외 데이터 전달
//}
//void SimpleFuncTwo() {
//	cout << "SimpleFuncTwo()" << endl;
//	SimpleFuncThree(); //2. SimpleFuncTwo를 호출한 SimpleFuncOne으로 예외 데이터 전달
//}
//void SimpleFuncThree() {
//	cout << "SimpleFuncThree()" << endl;
//	throw - 1; 
//	//1. 예외 발생시킴, SimpleFuncThree를 호출한 SimpleFuncTwo로 예외 데이터 전달
//}