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
////스마트 포인터
//class Point {
//private:
//	int xpos, ypos;
//public:
//	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {
//		cout << "Point Object Construction" << endl;
//	}
//	~Point() {
//		cout << "Point Object Destruction" << endl;
//	}
//	void SetPos(int x, int y) {
//		xpos = x;
//		ypos = y;
//	}
//	friend ostream& operator<<(ostream& os, const Point& pos);
//};
//ostream& operator<<(ostream& os, const Point& pos) {
//	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
//	return os;
//}
//
//class SmartPtr {
//private:
//	Point* posptr;
//public:
//	SmartPtr(Point * ptr):posptr(ptr){}
//	//스마트포인터의 기본이 되는 함수(포인터처럼 동작하기 위함)
//	Point& operator*() const {
//		return *posptr;
//	}
//	//스마트포인터의 기본이 되는 함수(포인터처럼 동작하기 위함)
//	Point* operator->() const {
//		return posptr;
//	}
//	~SmartPtr() {
//		delete posptr;
//		//SmartPtr이 소멸되지 전에 posptr(Point 객체) 먼저 지운 후 소멸
//	}
//};

//---------------------------------------------------

//() 연산자
//class Point {
//private:
//	int xpos, ypos;
//public:
//	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {	}
//	Point operator+(const Point& pos) const {
//		return Point(xpos + pos.xpos, ypos + pos.ypos);
//	}
//	friend ostream& operator<<(ostream& os, const Point& pos);
//};
//ostream& operator<<(ostream& os, const Point& pos) {
//	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
//	return os;
//}
//
////Functor(함수 오브젝트): 함수처럼 동작하는 클래스
//class Adder {
//public:
//	//() 연산자 오버로딩
//	int operator()(const int& n1, const int& n2) {
//		return n1 + n2;
//	}
//	double operator()(const double& e1, const double& e2) {
//		return e1 + e2;
//	}
//	Point operator()(const Point& pos1, const Point& pos2) {
//		return pos1 + pos2;
//	}
//};

//---------------------------------------------------
////버블정렬(Functor 사용)
//class SortRule {
//public:
//	virtual bool operator()(int num1, int num2) const = 0;
//	// 추상클래스로 정의, operator()함수는 순수가상함수로 정의
//	// 이는 함수 기능을 유도 클래스에서 확정 짓겠다는 의미(지금은 명시만 하겠다는 뜻)
//};
//
////오름차순
//class AscendingSort : public SortRule {
//public:
//	bool operator()(int n1, int n2) const {
//		if (n1 > n2)
//			return true;
//		else
//			return false;
//	}
//};
//
////내림차순
//class DescendingSort : public SortRule {
//public:
//	bool operator()(int n1, int n2) const {
//		if (n1 < n2)
//			return true;
//		else
//			return false;
//	}
//};
//
////int형 정수 저장소
//class DataStorage {
//private:
//	int* arr;
//	int idx;
//	const int MAX_LEN;
//public:
//	DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen) {
//		arr = new int[MAX_LEN];
//	}
//	void AddData(int num) {
//		if (MAX_LEN <= idx) {
//			cout << "Full Storage" << endl;
//			return;
//		}
//		arr[idx++] = num;
//	}
//	void ShowAllData() {
//		for (int i = 0; i < idx; i++)
//			cout << arr[i] << ' ';
//		cout << endl;
//	}
//	//SortRule을 상속하는 AscendingSort, DescendingSort 클래스를 인자로 전달 가능
//	void SortData(const SortRule& functor) {
//		for (int i = 0; i < (idx - 1); i++) {
//			for (int j = 0; j < (idx - 1) - i; j++) {
//				if (functor(arr[j], arr[j + 1])) {
//					int temp = arr[j];
//					arr[j] = arr[j + 1];
//					arr[j + 1] = temp;
//				}
//			}
//		}
//	}
//};
//---------------------------------------------------
//형 변환 연산자
class Number {
private:
	int num;
public:
	//b형 데이터를 인자로 전달받는 a형 클래스의 생성자 호출을 통해 a형 임시객체를 생성
	Number(int n = 0) :num(n) {
		cout << "Number(int n=0)" << endl;
	}
	//굳이 오버로딩 할 필요 없지만 대입 연산자 호출 확인을 위함
	Number& operator=(const Number& ref) {
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}
	//형 변환 연산자 오버로딩(Object to int)
	operator int() {
		return num;
	}
	void ShowNumber() { cout << num << endl; }
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
	////스마트 포인터
	//SmartPtr sptr1(new Point(1, 2));
	//SmartPtr sptr2(new Point(2, 3));
	//SmartPtr sptr3(new Point(4, 5));
	//cout << *sptr1; //연산자 오버로딩을 하였으므로 포인터처럼 사용하는 것처럼 보임
	//cout << *sptr2;
	//cout << *sptr3;

	//sptr1->SetPos(10, 20); //연산자 오버로딩을 하였으므로 포인터처럼 사용하는 것처럼 보임
	//sptr2->SetPos(30, 40);
	//sptr3->SetPos(50, 60);
	//cout << *sptr1;
	//cout << *sptr2;
	//cout << *sptr3;

	//---------------------------------------------------
	////() 연산자
	//Adder adder;
	//cout << adder(1, 3) << endl; //adder 클래스를 () 연산자 오버로딩을 통해 함수처럼 사용 -> Functor
	//cout << adder(1.5, 3.7) << endl;
	//cout << adder(Point(3,4), Point(7,9)) << endl;
	
	//---------------------------------------------------
	////버블정렬(Functor 사용)
	//DataStorage storage(5);
	//storage.AddData(40);
	//storage.AddData(30);
	//storage.AddData(50);
	//storage.AddData(20);
	//storage.AddData(10);

	//storage.ShowAllData();

	//storage.SortData(AscendingSort());
	//storage.ShowAllData();

	//storage.SortData(DescendingSort());
	//storage.ShowAllData();

	//---------------------------------------------------
	//형 변환 연산자
	//Number num;
	//num = 30; 
	//// -> num=Number(30) 1. 임시 객체 생성
	//// -> num.operator=(Number(30)) 2. 임시객체 대상으로 하는 대입 연산자 호출
	//num.ShowNumber();

	Number n1; 
	n1 = 30;
	Number n2 = n1 + 20; //객체와 정수 간 덧셈. 이때 객체(n1)가 int형으로 변환됨
	n2.ShowNumber();

	return 0;
}