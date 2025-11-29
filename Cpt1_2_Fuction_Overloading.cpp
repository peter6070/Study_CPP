#include <iostream>

////함수 오버로딩
//void Func(void) {
//	std::cout << "Func(void) called" << std::endl;
//}
//
//void Func(char c) {
//	std::cout << "Func(char c) called" << std::endl;
//}
//
//void Func(int a,int b) {
//	std::cout << "Func(int a, int b) called" << std::endl;
//}

//-----------------------------------------------------

//문제1-2. 함수 오버로딩 실습(swap 함수 구현)
void swap(int *a, int *b) {
	int temp;
	temp=*a;
	*a = *b;
	*b = temp;
}

void swap(char *a, char *b) {
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap(double &a, double &b) {
	double temp;
	temp = a;
	a = b;
	b = temp;
}

int main(void) {
	/*Func();
	Func('A');
	Func(1,2);*/

	//문제1-2. 함수 오버로딩 실습(swap 함수 구현)
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	std::cout << num1 << ' ' << num2 << std::endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	std::cout << ch1 << ' ' << ch2 << std::endl;
	
	double dbl1 = 1.111, dbl2 = 5.555;
	swap(dbl1, dbl2);
	std::cout << dbl1 << ' ' << dbl2 << std::endl;

	return 0;
}