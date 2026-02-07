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
	Point& operator++() {
		xpos += 1;
		ypos += 1;
		return *this; //객체 자기자신을 반환
	}
	friend Point& operator--(Point& ref);

	//문제1. - 부호 연산자 오버로딩
	Point& operator-() {
		xpos = -xpos;
		ypos = -ypos;
		return *this;
	}
	//문제2. ~ 부호 연산자 오버로딩
	Point& operator~() {
		int temp = xpos;
		xpos = ypos;
		ypos = temp;
		return *this;
	}
};

Point& operator--(Point& ref) {
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}


int main(void) {
	//Point pos(1, 2);
	//++pos;
	//pos.ShowPosition();
	//--pos;
	//pos.ShowPosition();

	//++(++pos); //-> ++(pos.operator++()); 
	////++(pos의 참조 값); -> (pos의 참조 값).operator++();
	//pos.ShowPosition(); //2 증가된 값
	//--(--pos);
	//pos.ShowPosition();

	////문제1. - 부호 연산자 오버로딩
	//Point pos1(1, 2);
	//Point pos2 = -pos1;
	//pos2.ShowPosition();

	//문제2. ~ 부호 연산자 오버로딩
	Point pos1(1, 2);
	Point pos2 = ~pos1;
	pos2.ShowPosition();


	return 0;
}