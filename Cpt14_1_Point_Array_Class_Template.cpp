#include <iostream>
//#include "Cpt14_1_ArrayTemplate.h"
//#include "Cpt14_1_PointTemplate.h"
using namespace std;

template <class T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	//클래스 템플릿에서도 일반함수에 대해 friend 선언 가능
	friend Point<int> operator+(const Point<int>&, const Point<int>&);
	friend ostream& operator<<(ostream& os, const Point<int>& pos);
};

//+ 연산자 오버로딩하는 일반함수(함수 템플릿X, template <class T> 가 붙지 않음)
Point<int> operator+(const Point<int>& pos1, const Point<int>& pos2) {
	return Point<int>(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}

//<< 연산자 오버로딩하는 일반함수
ostream& operator<<(ostream& os, const Point<int>& pos) {
	os<<'[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void) {
	/*BoundCheckArray<Point<int>> oarr1(3);
	oarr1[0] = Point<int>(3, 4);
	oarr1[1] = Point<int>(5, 6);
	oarr1[2] = Point<int>(7, 8);

	for (int i = 0; i < oarr1.GetArrLen(); i++)
		oarr1[i].ShowPosition();

	BoundCheckArray<Point<double>> oarr2(3);
	oarr2[0] = Point<double>(3.14, 4.31);
	oarr2[1] = Point<double>(5.09, 6.07);
	oarr2[2] = Point<double>(7.82, 8.54);

	for (int i = 0; i < oarr2.GetArrLen(); i++)
		oarr2[i].ShowPosition();

	typedef Point<int>* POINT_PTR;
	BoundCheckArray<POINT_PTR> oarr3(3);
	oarr3[0] = new Point<int>(11, 12);
	oarr3[1] = new Point<int>(13, 14);
	oarr3[2] = new Point<int>(15, 16);

	for (int i = 0; i < oarr3.GetArrLen(); i++)
		oarr3[i]->ShowPosition();

	delete oarr3[0];
	delete oarr3[1];
	delete oarr3[2];*/
	//-----------------------------------------------------

	Point<int> pos1(2, 4);
	Point<int> pos2(4, 8);
	Point<int> pos3 = pos1 + pos2;
	cout << pos1 << pos2 << pos3;

	return 0;
}