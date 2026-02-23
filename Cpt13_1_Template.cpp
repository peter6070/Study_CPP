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
//template <class T>
//void SwapData(T& n1, T& n2) {
//	T temp = n1;
//	n1 = n2;
//	n2 = temp;
//}
//
//class Point {
//private:
//	int xpos, ypos;
//public:
//	Point(int x=0, int y=0):xpos(x), ypos(y){}
//	void ShowPosition() const {
//		cout << xpos << ", " << ypos << endl;
//	}
//};
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
//-----------------------------------------------------
template <class T>
T Max(T a, T b) { return a > b ? a : b; }

//char* 형 함수를 사전에 정의함으로써 char*형 템플릿 함수를 별도로 만들지 말고 해당 함수를 사용하도록 함
template <>
char* Max(char* a, char* b) {
	cout << "char* Max<char*>(char* a, char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

//const char* 형 함수를 사전에 정의함으로써 const char*형 템플릿 함수를 별도로 만들지 말고 해당 함수를 사용하도록 함
template <>
const char* Max(const char* a, const char* b) {
	cout << "const char* Max<const char>(const char* a, const char* b)" << endl;
	return strcmp(a,b) ? a : b;
}

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
	/*Point pos1(1, 2);
	Point pos2(3, 4);
	SwapData(pos1, pos2);
	pos1.ShowPosition();
	pos2.ShowPosition();*/
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
	//-----------------------------------------------------
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl; //큰따옴표에 감싸진 문자열 상수이므로 const char* 함수 호출
	//문자열 대상으로 호출할 경우, 결과에 대해서는 아무런 의미도 부여할 수 없음
	//-> 함수 템플릿 특수화

	char str1[] = "Simple"; //문자형 배열 내에 "Simple"이라는 문자열을 복사한 것이므로 char* 함수 호출
	char str2[] = "Best";
	cout << Max(str1, str2)<<endl;

	return 0;
}