#include <iostream>
using namespace std;
//#include "Cpt13_2_BoundCheckArray.h"

//파일 분할 시 헤더 파일 뿐만 아니라 소스 파일에 담긴 정보도 넘겨받아야 하므로 포함해야 함
//#include "Cpt13_2_PointTemplate.h"
//#include "Cpt13_2_PointTemplate.cpp"

//template <class T>
//class Point {
//private:
//	T xpos, ypos;
//public:
//	Point(T x = 0, T y = 0); //생성자 디폴트값은 내부 함수에만 작성
//	void ShowPosition() const;
//};
//
////중괄호를 벗어나는 순간 컴파일러는 T가 뭔지 모르게되므로 외부에 함수를 정의할 때는 일일이 템플릿 정의를 해야함
//template <class T>
//Point<T>::Point(T x, T y) : xpos(x), ypos(y){} //이니셜라이저는 외부 함수에만 작성
//
//template <class T>
//void Point<T>::ShowPosition() const {
//	cout << xpos << ", " << ypos << endl;
//}

//---------------------------------------
//문제1. 스마트 포인터 템플릿화
class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {	}
	void SetPos(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void ShowPosition() const {
		cout << xpos << ", " << ypos << endl;
	}
};

template <class T>
class SmartPtr {
private:
	T* posptr;
public:
	SmartPtr(T * ptr):posptr(ptr){}
	//스마트포인터의 기본이 되는 함수(포인터처럼 동작하기 위함)
	T& operator*() const {
		return *posptr;
	}
	//스마트포인터의 기본이 되는 함수(포인터처럼 동작하기 위함)
	T* operator->() const {
		return posptr;
	}
	~SmartPtr() {
		delete posptr;
		//SmartPtr이 소멸되지 전에 posptr(Point 객체) 먼저 지운 후 소멸
	}
};

int main(void) {
	/*Point<int> pos1(3, 4);
	pos1.ShowPosition();

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	Point<char> pos3('p', 'f');
	pos3.ShowPosition();*/
	//---------------------------------------
	////배열 클래스 템플릿화
	///*** int형 정수 저장 ***/
	//BoundCheckArray<int> iarr(5);
	//for (int i = 0; i < 5; i++)
	//	iarr[i] = (i + 1) * 11; 
	//for(int i=0;i<5;i++)
	//	cout<<iarr[i]<<endl;

	///*** Point 객체 저장 ***/
	//BoundCheckArray<Point> oarr(3);
	//oarr[0] = Point(3, 4);
	//oarr[1] = Point(5, 6);
	//oarr[2] = Point(7, 8);
	//for (int i = 0; i < oarr.GetArrLen(); i++)
	//	cout << oarr[i];

	///*** Point 객체 주소 값 저장 ***/
	//typedef Point* POINT_PTR;
	//BoundCheckArray<POINT_PTR> parr(3);
	//parr[0] = new Point(3, 4);
	//parr[1] = new Point(5, 6);
	//parr[2] = new Point(7, 8);
	//for (int i = 0; i < parr.GetArrLen(); i++)
	//	cout << *(parr[i]);

	//delete parr[0];
	//delete parr[1];
	//delete parr[2];

	//---------------------------------------
	//문제1. 스마트 포인터 템플릿화
	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(3, 4));
	sptr1->ShowPosition();
	sptr2->ShowPosition();

	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr1->ShowPosition();
	sptr2->ShowPosition();

	return 0;
}