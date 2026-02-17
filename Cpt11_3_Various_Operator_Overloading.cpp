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
class Number {
private:
	int num;
public:
	Number(int n):num(n){}
	void ShowData() { cout << num << endl; }

	Number* operator->() { return this; } //객체 자신의 주소 값을 반환

	Number& operator*() { return *this; } //객체 자신의 참조 형태를 반환
};


int main(void) {
	//new, delete 연산자 오버로딩(배열 포함)
	/*Point* ptr = new Point(3, 4);
	Point* arr = new Point[3];
	delete ptr;
	delete []arr;*/

	//---------------------------------------------------
	//포인터 연산자 오버로딩
	Number num(20);
	num.ShowData();

	(*num) = 30; //-> (num.operator*())=30;
	num->ShowData(); //num.operator->() -> ShowData();
	(*num).ShowData(); //-> (num.operator*()).ShowData();


	return 0;
}