#include <iostream>
using namespace std;

//class Point {
//private:
//	int xpos, ypos;
//public:
//	Point(int x = 0, int y=0):xpos(x), ypos(y){}
//	friend ostream& operator<<(ostream& os, const Point& pos);
//
// //new 연산자 오버로딩
//	void* operator new (size_t size) {
//		cout << "oeprator new : " << size << endl;
//		void* adr = new char[size]; //바이트 단위로 필요 메모리 공간 할당
//		//char형을 대상으로 new 연산을 하는 문장은 malloc함수의 호출문으로 대신할 수 있음
//		return adr;
//	}
//	
//	void* operator new[] (size_t size) {
//		cout << "oeprator new[] : " << size << endl;
//		void* adr = new char[size]; 
//		return adr;
//	}
//
// //delete 연산자 오버로딩
//	void operator delete(void* adr) {
//		cout << "operator delete () " << endl;
//		delete[]adr;
//		//free함수 호출문으로 대신할 수 있음
//	}
//	//배열할당 시 호출됨(operator delete와 차이 X)
//	void operator delete[](void* adr) {
//		cout << "operator delete[] () " << endl;
//		delete[]adr;
//		//free함수 호출문으로 대신할 수 있음
//	}
//};
//
//ostream& operator<<(ostream& os, const Point& pos) {
//	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
//	return os;
//}

//---------------------------------------------------
//포인터 연산자 오버로딩
//class Number {
//private:
//	int num;
//public:
//	Number(int n):num(n){}
//	void ShowData() { cout << num << endl; }
//
//	Number* operator->() { return this; } //객체 자신의 주소 값을 반환
//
//	Number& operator*() { return *this; } //객체 자신의 참조 형태를 반환
//};

//---------------------------------------------------
//스마트 포인터
class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {
		cout << "Point Object Construction" << endl;
	}
	~Point() {
		cout << "Point Object Destruction" << endl;
	}
	void SetPos(int x, int y) {
		xpos = x;
		ypos = y;
	}
	friend ostream& operator<<(ostream& os, const Point& pos);
};
ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class SmartPtr {
private:
	Point* posptr;
public:
	SmartPtr(Point * ptr):posptr(ptr){}
	//스마트포인터의 기본이 되는 함수(포인터처럼 동작하기 위함)
	Point& operator*() const {
		return *posptr;
	}
	//스마트포인터의 기본이 되는 함수(포인터처럼 동작하기 위함)
	Point* operator->() const {
		return posptr;
	}
	~SmartPtr() {
		delete posptr;
		//SmartPtr이 소멸되지 전에 posptr(Point 객체) 먼저 지운 후 소멸
	}
};

int main(void) {
	//new, delete 연산자 오버로딩(배열 포함)
	/*Point* ptr = new Point(3, 4);
	Point* arr = new Point[3];
	delete ptr;
	delete []arr;*/

	//---------------------------------------------------
	//포인터 연산자 오버로딩
	//Number num(20);
	//num.ShowData();

	//(*num) = 30; //-> (num.operator*())=30;
	//num->ShowData(); //num.operator->() -> ShowData();
	//(*num).ShowData(); //-> (num.operator*()).ShowData();

	//---------------------------------------------------
	//스마트 포인터
	SmartPtr sptr1(new Point(1, 2));
	SmartPtr sptr2(new Point(2, 3));
	SmartPtr sptr3(new Point(4, 5));
	cout << *sptr1; //연산자 오버로딩을 하였으므로 포인터처럼 사용하는 것처럼 보임
	cout << *sptr2;
	cout << *sptr3;

	sptr1->SetPos(10, 20); //연산자 오버로딩을 하였으므로 포인터처럼 사용하는 것처럼 보임
	sptr2->SetPos(30, 40);
	sptr3->SetPos(50, 60);
	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	//Functor: 객체를 함수처럼 사용


	return 0;
}