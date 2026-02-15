#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x),ypos(y){}
	friend ostream& operator<<(ostream& os, const Point& pos);
};
ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']'<<endl;
	return os;
}

//class BoundCheckIntArray {
//private:
//	int* arr; //포인터(주소만 가리켜줌)
//	int arrlen;
//	//복사, 대입 막음
//	BoundCheckIntArray(const BoundCheckIntArray& arr){}
//	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr){}
//public:
//	BoundCheckIntArray(int len) : arrlen(len) {
//		arr = new int[len]; //매개변수 만큼의 힙 메모리 공간 생성
//		//포인터인 arr은 생성된 힙 메모리 공간의 주소를 알려주는 포인터가 됨
//		//arr[0]은 arr이 가리키는 메모리 공간의 첫번째[0] 주소값을 의미함
//	}
//	//배열 인덱스 연산자
//	int& operator[](int idx) {
//		if (idx < 0 || idx >= arrlen) { //인덱스가 0보다 작거나 배열 길이보다 크면 종료
//			cout << "Array index out of bound exception" << endl;
//			exit(1);
//		}
//		return arr[idx];
//	}
//	//const 멤버함수 추가
//	//int& operator[](int idx) 함수와 오버로딩 관계, 참조값이 아닌 배열요소의 값을 단순 반환하는 형태
//	int& operator[](int idx) const {
//		if (idx < 0 || idx >= arrlen) { //인덱스가 0보다 작거나 배열 길이보다 크면 종료
//			cout << "Array index out of bound exception" << endl;
//			exit(1);
//		}
//		return arr[idx];
//	}
//	int GetArrLen() const { return arrlen; }
//	~BoundCheckIntArray() {
//		delete[]arr;
//	}
//};

//void ShowAllData(const BoundCheckIntArray& ref) {
//	int len = ref.GetArrLen();
//	for (int idx = 0; idx < len; idx++)
//		cout << ref[idx] << endl; //const 참조자를 이용한 연산이므로, int& operator[](int idx) const 함수 호출
//}

class BoundCheckIntArray {
private:
	Point* arr; //포인터(주소만 가리켜줌)
	int arrlen;
	//복사, 대입 막음
	BoundCheckIntArray(const BoundCheckIntArray& arr) {}
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}
public:
	BoundCheckIntArray(int len) : arrlen(len) {
		arr = new Point[len]; //매개변수 만큼의 힙 메모리 공간 생성
		//포인터인 arr은 생성된 힙 메모리 공간의 주소를 알려주는 포인터가 됨
		//arr[0]은 arr이 가리키는 메모리 공간의 첫번째[0] 주소값을 의미함
	}
	//배열 인덱스 연산자
	Point& operator[](int idx) {
		if (idx < 0 || idx >= arrlen) { //인덱스가 0보다 작거나 배열 길이보다 크면 종료
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	//const 멤버함수 추가
	//int& operator[](int idx) 함수와 오버로딩 관계, 참조값이 아닌 배열요소의 값을 단순 반환하는 형태
	Point& operator[](int idx) const {
		if (idx < 0 || idx >= arrlen) { //인덱스가 0보다 작거나 배열 길이보다 크면 종료
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckIntArray() {
		delete[]arr;
	}
};

int main(void) {
	//BoundCheckIntArray arr(5); //길이 5짜리 힙 메모리 생성
	//for (int i = 0; i < 5; i++)
	//	arr[i] = (i + 1) * 11; //const로 선언되지 않은 arr을 이용한 연산이므로 int& operator[](int idx) 함수 호출
	/*for(int i=0;i<6;i++)
		cout<<arr[i]<<endl;*/
	//BoundCheckIntArray cpy = arr; //대입연산자를 private으로 선언하여 대입 불가
	//ShowAllData(arr);

	BoundCheckIntArray arr(3);
	arr[0] = Point(3, 4);
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << arr[i];

	return 0;
}