#include <iostream>
using namespace std;

//class First {
//private:
//	char* strOne;
//public:
//	First(const char* str) {
//		strOne = new char[strlen(str) + 1];
//	}
//	virtual ~First() {
//		cout << "~First()" << endl;
//		delete[] strOne;
//	}
//};
//
//class Second : public First {
//private:
//	char* strTwo;
//public:
//	Second(const char* str1, const char* str2) :First(str1) {
//		strTwo = new char[strlen(str2) + 1];
//	}
//	virtual ~Second() {
//		cout << "~Second()"<<endl;
//		delete[] strTwo;
//	}
//};
//---------------------------------------------------

class First {
public:
	void FirstFunc() {
		cout << "FirstFunc()" << endl;
	}
	virtual void SimpleFunc() {
		cout << "First's SimpleFunc()" << endl;
	}
};

class Second :public First {
public:
	void SecondFunc() {
		cout << "SecondFunc()" << endl;
	}
	virtual void SimpleFunc() {
		cout << "Second's SimpleFunc()" << endl;
	}
};

class Third :public Second {
public:
	void ThirdFunc() {
		cout << "ThirdFunc()" << endl;
	}
	virtual void SimpleFunc() {
		cout << "Third's SimpleFunc()" << endl;
	}
};

int main(void) {
	//First* ptr = new Second("simple", "complex");
	//delete ptr;
	//---------------------------------------------------

	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second& sref = obj; 
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc(); //sref가 참조하는 객체가 Third이기 때문에 가상함수로 선언된 SimpleFunc는 실제 객체에서 함수 호출

	First& fref = obj;
	fref.FirstFunc();
	fref.SimpleFunc();

	return 0;
}