#include <iostream>
using namespace std;

class First {
private:
	int num1, num2;
public:
	First(int n1=0, int n2=0):num1(n1), num2(n2){}
	void ShowData() { cout << num1 << ", " << num2 << endl; }
	//자동으로 삽입되어 작성 필요X
	First& operator=(const First& ref) {
		cout << "First& operator=()" << endl;
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

//class Second {
//private:
//	int num3, num4;
//public:
//	Second(int n3=0, int n4=0):num3(n3), num4(n4){}
//	void ShowData() { cout << num3 << ", " << num4 << endl; }
//
//	//호출 확인을 위한 디폴트 대입연산자
//	Second& operator=(const Second& ref) {
//		cout << "Second& operator=()" << endl;
//		num3 = ref.num3;
//		num4 = ref.num4;
//		return *this;
//	}
//};

class Second :public First {
private:
	int num3, num4;
public:
	Second(int n1, int n2, int n3, int n4) 
		: First(n1, n2), num3(n3), num4(n4) {}
	void ShowData() { 
		First::ShowData();
		cout << num3 << ", " << num4 << endl; 
	}

	Second& operator=(const Second& ref) {
		cout << "Second& operator=()" << endl;
		First::operator=(ref); //기초 클래스 대입 연산자 호출
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
};
//---------------------------------------------------------

//class Person {
//	char* name;
//	int age;
//public:
//	Person(const char* myname, int myage) {
//		int len = strlen(myname) + 1;
//		name = new char[len];
//		strcpy_s(name, len, myname);
//		age = myage;
//	}
//	void ShowPersonInfo() const {
//		cout << "Name: " << name << endl;
//		cout << "Age: " << age << endl;
//	}
//	~Person() {
//		delete[] name;
//		cout << "Called Destructor" << endl;
//	}
//	//대입 연산자(깊은 복사를 하기 위함)
//	Person& operator=(const Person& ref) {
//		delete[] name; //메모리 누수를 막기 위한 메모리 해제 연산
//		int len = strlen(ref.name) + 1;
//		name = new char[len];
//		strcpy_s(name, len, ref.name);
//		age = ref.age;
//		return *this;
//	}
//};

int main(void) {
	//First fsrc(111, 222);
	//First fcpy;
	//Second ssrc(333, 444);
	//Second scpy;
	//fcpy = fsrc; //-> fcpy.operator=(fsrc);
	//scpy = ssrc;
	//fcpy.ShowData();
	//scpy.ShowData();

	//First fob1, fob2;
	//Second sob1, sob2;
	//fob1 = fob2 = fsrc; //대입 연산자는 오른쪽에서 왼쪽으로 진행됨
	//sob1 = sob2 = ssrc;

	//fob1.ShowData();
	//fob2.ShowData();
	//sob1.ShowData();
	//sob2.ShowData();
	//---------------------------------------------------------
	//Person man1("Lee", 29);
	//Person man2("Yoon", 22);
	//man2 = man1; //얕은 복사로 인해 소멸자가 한번만 실행됨(대입 연산자 정의 안했을 경우)

	//man1.ShowPersonInfo();
	//man2.ShowPersonInfo();
	//---------------------------------------------------------
	Second ssrc(111, 222, 333, 444);
	Second scpy(0, 0, 0, 0);
	scpy = ssrc;
	scpy.ShowData();


	return 0;
}