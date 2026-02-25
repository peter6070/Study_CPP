#include <iostream>
using namespace std;



int main(void) {
	int num1, num2;
	cout << "Enter two numbers: ";
	cin >> num1 >> num2; //예외 발생 위치

	//if문을 이용한 예외처리
	//if (num2 == 0) { //예외 발견 위치
	//	cout << "num2(divisor) can't be 0" << endl; //예외 처리 위치
	//	cout << "Restart Program" << endl;
	//}
	//else {
	//	cout << "Quotient of Division: " << num1 / num2 << endl;
	//	cout << "Remain of Division: " << num1 % num2 << endl;
	//}
	
	//try, catch문을 이용한 예외처리
	try {
		if (num2 == 0) { //예외 발견 위치
			throw num2; //예외 발생하면 catch로 던짐
		}
		else {
			cout << "Quotient of Division: " << num1 / num2 << endl;
			cout << "Remain of Division: " << num1 % num2 << endl;
		}
	}
	catch (int expn) { //여기서 예외처리
		cout << "num2(divisor) can't be 0" << endl; //예외 처리 위치
		cout << "Restart Program" << endl;
	}
	cout << "end of main" << endl; //예외처리 발생여부와 상관없이 실행됨
	

	return 0;
}