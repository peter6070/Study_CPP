#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0):xpos(x),ypos(y){}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	friend Point operator+(const Point& pos1, const Point& pos2);
	//private 영역 접근 허용을 위해 friend 선언
	//friend 선언을 통해 전역함수인 operator+ 가 Point의 private 영역에 접근 가능 
	// 또한 Point 클래스가 + 연산에 대해 연산자 오버로딩이 되어있음을 알 수 있음
	
	//문제1. - 연산자 오버로딩
	friend Point operator-(const Point& pos1, const Point& pos2);
	//문제3. ==,!= 연산자 오버로딩
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);

	//문제2.+=, -= 연산자 오버로딩
	Point operator+=(const Point& ref) {
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}
	Point operator-=(const Point& ref) {
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}
};

//전역함수 기반의 오버로딩 함수
Point operator+(const Point &pos1, const Point &pos2) {
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}
//문제1. - 연산자 오버로딩
Point operator-(const Point& pos1, const Point& pos2) {
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

//문제3. ==,!= 연산자 오버로딩
bool operator==(const Point& pos1, const Point& pos2) {
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
		return true;
	else
		return false;
}
bool operator!=(const Point& pos1, const Point& pos2) {
	return !(pos1==pos2); //오버로딩된 == 연산자 호출
}

int main(void) {

	//Point pos1(3, 4);
	//Point pos2(10, 20);
	////Point pos3 = pos1.operator+(pos2);
	//Point pos3 = pos1+pos2;

	Point pos1(20, 30);
	Point pos2(5, 7);
	Point pos3(5, 7);

	(pos1 - pos2).ShowPosition();
	(pos2 += pos3).ShowPosition();

	if (pos2 == pos3)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;

	(pos2 -= pos3).ShowPosition();

	if(pos2!=pos3)
		cout << "not equal" << endl;
	else
		cout << "equal" << endl;

	return 0;
}