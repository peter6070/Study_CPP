#pragma once
#include <iostream>
using namespace std;

//계산기 클래스
//각 사칙연산 함수, 연산 수행 횟수 출력 함수
class Calculator {
    //멤버변수: private
private:
    int addNum, minNum, mulNum, divNum;
    //멤버함수: public
public:
    void Init();
    double Add(double a, double b);
    double Min(double a, double b);
    double Mul(double a, double b);
    double Div(double a, double b);
    void ShowOpCount();
};

//함수 내 코드가 짧으므로 인라인으로 효율화
inline void Calculator::Init() {
	//addNum, minNum, mulNum, divNum = 0;
	addNum = 0;
	minNum = 0;
	mulNum = 0;
	divNum = 0;
}
inline double Calculator::Add(double a, double b) {
	addNum++;
	return a + b;
}
inline double Calculator::Min(double a, double b) {
	minNum++;
	return a - b;
}
inline double Calculator::Mul(double a, double b) {
	mulNum++;
	return a * b;
}
inline double Calculator::Div(double a, double b) {
	divNum++;
	return a / b;
}
inline void Calculator::ShowOpCount() {
	cout << "Add: " << addNum << " Min: " << minNum << " Mul: " << mulNum << " Div: " << divNum << endl;
}