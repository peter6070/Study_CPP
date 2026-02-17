#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y=0):xpos(x), ypos(y){}
	friend ostream& operator<<(ostream& os, const Point& pos);

	void* operator new (size_t size) {
		cout << "oeprator new : " << size << endl;
		void* adr = new char[size]; //바이트 단위로 필요 메모리 공간 할당
		//char형을 대상으로 new 연산을 하는 문장은 malloc함수의 호출문으로 대신할 수 있음
		return adr;
	}
	void operator delete(void* adr) {
		cout << "operator delete () " << endl;
		delete[]adr;
		//free함수 호출문으로 대신할 수 있음
	}
};

ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void) {
	Point* ptr = new Point(3, 4);
	cout << *ptr;
	delete ptr;


	return 0;
}