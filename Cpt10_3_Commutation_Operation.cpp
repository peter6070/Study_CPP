#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point operator*(int times) {
		Point pos(xpos * times, ypos * times);
		return pos;
	}
	friend Point operator*(int times, Point& ref);
};

//교환법칙 문제 해결을 위한 오버로딩(int * pos -> pos * int형태로 전환)
Point operator*(int times, Point& ref) {
	//이렇게도 가능
	//Point pos(ref.xpos*times, ref.ypos*times);
	//return pos;

	return ref * times; //Point operator*(int times) 이 함수 불러옴
}

int main(void) {
	Point pos(1, 2);
	Point cpy;


	//cpy = pos*3;
	cpy = 3 * pos; //교환법칙에 의해 3과 pos의 위치가 바뀌어도 연산이 가능해야 함
	cpy.ShowPosition();

	cpy = 2 * pos * 3;
	cpy.ShowPosition();


	return 0;
}