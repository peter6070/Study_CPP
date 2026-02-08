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
	Point& operator++() { //전위증가
		xpos += 1;
		ypos += 1;
		return *this; //객체 자기자신을 반환
	}
	const Point operator++(int) { //후위증가
		const Point retobj(xpos, ypos); //const Point retobj(*this);
		xpos += 1;
		ypos += 1;
		return retobj;
	}
	friend Point& operator--(Point& ref);
	friend const Point operator--(Point &ref, int);

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

Point& operator--(Point& ref) { //전위감소
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

const Point operator--(Point &ref, int) { //후위감소
	const Point retobj(ref);
	ref.xpos -= 1;
	ref.ypos -= 1;
	return retobj;
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

	////문제2. ~ 부호 연산자 오버로딩
	//Point pos1(1, 2);
	//Point pos2 = ~pos1;
	//pos2.ShowPosition();

	//전위, 후위 증가/감소
	Point pos(3, 5);
	Point cpy;
	cpy = pos--; //후위감소
	cpy.ShowPosition(); //원래 값 먼저 출력 후 값을 감소시킴
	pos.ShowPosition(); //감소된 값 출력

	cpy = pos++; //후위증가
	cpy.ShowPosition(); //원래 값 먼저 출력 후 값을 증가시킴
	pos.ShowPosition(); //증가된 값 출력

	return 0;
}