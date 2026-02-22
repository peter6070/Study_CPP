#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string str1 = "I like";
	string str2 = "string class";
	string str3 = str1 + str2; //string 객체간 덧셈연산 가능(operator+ 연산자 오버로딩 되어있음)

	cout << str1 << endl; //string 클래스가 << 연산자에 대해서도 오버로딩됨
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2; //+= 연산의 결과로 두 문자열이 합쳐져 str1에 저장됨
	if (str1 == str3) //str1과 str2의 덧셈연산으로 생성된 str3는 위에서 +=연산을 진행한 str1과 동일
		cout << "Equal string" << endl;
	else
		cout << "Not Equal string" << endl;

	string str4;
	cout << "Enter string: ";
	cin >> str4; // >> 연산자 오버로딩
	cout << "Your string: " << str4 << endl;

	return 0;
}