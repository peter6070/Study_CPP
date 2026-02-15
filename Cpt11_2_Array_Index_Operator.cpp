#include <iostream>
#include <cstdlib>
using namespace std;

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

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

//class BoundCheckIntArray {
//private:
//	Point* arr;
//	int arrlen;
//	BoundCheckIntArray(const BoundCheckIntArray& arr) {}
//	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}
//public:
//	BoundCheckIntArray(int len) : arrlen(len) {
//		arr = new Point[len]; //Point 객체로 이뤄진 배열 생성
//		// 인자를 받지 않는 void 생성자의 호출을 통해 배열요소를 이루는 객체가 생성되므로
//		// Point(int x=0, int y=0) 이 생성자에 설정된 디폴트 값에 의해 객체의 모든 멤버가 0으로 초기화됨
//	}
//	//배열 인덱스 연산자
//	Point& operator[](int idx) {
//		if (idx < 0 || idx >= arrlen) {
//			cout << "Array index out of bound exception" << endl;
//			exit(1);
//		}
//		return arr[idx];
//	}
//	Point& operator[](int idx) const {
//		if (idx < 0 || idx >= arrlen) {
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

typedef Point* POINT_PTR;
//Point 포인터 형을 의미하는 POINT_PTR 정의
// 저장의 대상, 연산의 주 대상이 포인터인 경우, 별도의 자료형을 정의하는 것이 좋음

class BoundCheckPointPtrArray {
private:
	POINT_PTR* arr;
	int arrlen;
	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) {}
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) {}
public:
	BoundCheckPointPtrArray(int len) : arrlen(len) {
		arr = new POINT_PTR[len];
	}
	//배열 인덱스 연산자
	POINT_PTR& operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	POINT_PTR& operator[](int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckPointPtrArray() {
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

	//객체 저장 배열 클래스
	//BoundCheckIntArray arr(3);
	//arr[0] = Point(3, 4);
	//arr[1] = Point(5, 6);
	//arr[2] = Point(7, 8);
	//// 임시 객체를 생성해서 배열요소 초기화

	//for (int i = 0; i < arr.GetArrLen(); i++)
	//	cout << arr[i];

	//객체 주소 값 저장 방식 배열 클래스
	BoundCheckPointPtrArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);
	//Point 객체 주소값을 저장함
	// 객체 주소 값을 저장할 경우, 깊은 복사, 얕은 복사에 관한 문제를 신경쓰지 않아도 됨

	/*for (int i = 0; i < arr.GetArrLen(); i++)
		cout << *(arr[i]);*/

	//문제1. 포인터 출력 오버로딩
	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << arr[i]; //cout.operator<<(new Point(3, 4))

	delete arr[0];
	delete arr[1];
	delete arr[2];

	return 0;
}