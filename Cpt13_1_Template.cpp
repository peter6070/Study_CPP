#include <iostream>
using namespace std;

//template <typename T>
//T Add(T num1, T num2) {
//	cout << "T Add(T num1, T num2)" << endl;
//	return num1 + num2;
//}
//
////일반함수 형태로 Add 함수 정의
////템플릿이 정의되어도 일반함수 정의 가능
//int Add(int num1, int num2) {
//	cout << "Add(int num1, int num2)" << endl;
//	return num1 + num2;
//}
//
//double Add(double num1, double num2) {
//	cout << "Add(double num1, double num2)" << endl;
//	return num1 + num2;
//}
//-----------------------------------------------------
//template <class T1, class T2>
//void ShowData(double num) {
//	cout << (T1)num << ", " << (T2)num << endl;
//	//cout << T1(num) << ", " << T2(num) << endl; //이렇게 괄호를 변수에 씌워도 됨
//}
//-----------------------------------------------------
//문제1. 저장된 값을 교환하는 SwapData 함수 템플릿
template <class T>
void SwapData(T& n1, T& n2) {
	T temp = n1;
	n1 = n2;
	n2 = temp;
}

class Point {
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0):xpos(x), ypos(y){}
	void ShowPosition() const {
		cout << xpos << ", " << ypos << endl;
	}
};
//-----------------------------------------------------
//문제2. int형 배열 값 덧셈 함수 템플릿 정의
//template <class T>
//
//T SumArray(T arr[], int len) {
//	T sum = 0;
//	for (int i = 0; i < len; i++)
//		sum += arr[i];
//	return sum;
//}


int main(void) {
	////자료형 명시가 없으므로 일반함수 호출
	//cout << Add(5,7) << endl; //T를 int로 해서 만들어진 Add 함수를 호출
	//cout << Add(2.9, 3.7) << endl;
	////자료형을 명시함으로써 템플릿 함수 호출
	//cout << Add<int>(5,7) << endl;
	//cout << Add<double>(2.9, 3.7) << endl;
	//-----------------------------------------------------
	/*ShowData<char, int>(65);
	ShowData<char, int>(67);
	ShowData<char, double>(68.9);
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);*/
	//-----------------------------------------------------
	//문제1. 저장된 값을 교환하는 SwapData 함수 템플릿
	Point pos1(1, 2);
	Point pos2(3, 4);
	SwapData(pos1, pos2);
	pos1.ShowPosition();
	pos2.ShowPosition();
	//-----------------------------------------------------
	//문제2. int형 배열 값 덧셈 함수 템플릿 정의
	/*int arr1[] = { 5,8,6,7,2 };
	int len1 = sizeof(arr1) / sizeof(int);
	double Iresult = SumArray<int>(arr1, len1);
	cout << Iresult << endl;

	double arr2[] = { 1.3, 4.3, 5.5, 2.5 };
	int len2 = sizeof(arr2)/sizeof(double);
	double Dresult = SumArray<double>(arr2, len2);
	cout << Dresult << endl;*/

	return 0;
}