#include <iostream>
using namespace std;

//template <class T, int len> //자료형과 정수형 매개변수를 받음
//class SimpleArray {
//private:
//	T arr[len];
//public:
//	T& operator[] (int idx) { return arr[idx]; }
//	SimpleArray<T, len>& operator=(const SimpleArray<T, len>&ref){
//		for (int i = 0; i < len; i++)
//			arr[i] = ref.arr[i];
//		return *this;
//	}
//};
//-------------------------------------------
//템플릿 매개변수 디폴트 값
template <class T=int, int len=7> //디폴트 값으로 int, 7이란 값을 넣음
//객체 생성시 매개변수 값이 들어오지 않으면 디폴트 값으로 설정
class SimpleArray {
private:
	T arr[len];
public:
	T& operator[] (int idx) { return arr[idx]; }
	SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref) {
		for (int i = 0; i < len; i++)
			arr[i] = ref.arr[i];
		return *this;
	}
};


int main(void) {
	//SimpleArray<int, 5> i5arr1; //int형과 정수 5를 매개변수로 자료형 정의(5는 len 값이 됨)
	//for (int i = 0; i < 5; i++)
	//	i5arr1[i] = i * 10;

	//SimpleArray<int, 5> i5arr2;
	//i5arr2 = i5arr1;
	//for (int i = 0; i < 5; i++)
	//	cout<<i5arr2[i]<<", ";
	//cout << endl;

	//SimpleArray<int, 7> i7arr1; //SimpleArray<int, 5>와 다른 자료형, 대입연산 불가
	//for (int i = 0; i < 7; i++)
	//	i7arr1[i] = i * 10;

	//SimpleArray<int, 7> i7arr2;
	//i7arr2 = i7arr1;
	//for (int i = 0; i < 7; i++)
	//	cout << i7arr2[i] << ", ";
	//cout << endl;
	// 
	//-------------------------------------------
	// 
	//템플릿 매개변수 디폴트 값
	SimpleArray<> arr; //값을 넣지 않았으므로 템플릿 매개변수의 디폴트값이 삽입됨
	for (int i = 0; i < 7; i++)
		arr[i] = i + 1;
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}