#include <iostream>
using namespace std;

//class Simple {
//	int num;
//public:
//	Simple(int n) : num(n) {}
//	Simple(const Simple& copy) : num(copy.num) {
//		cout << "Called Simple(const Simple& copy)" << endl;
//	}
//	//복사 생성자 호출(객체 반환하되, 참조형으로 반환하지않는 경우)
//	Simple& AddNum(int n) {
//		num += n;
//		return *this;
//	}
//	void ShowData() {
//		cout << "num: " << num << endl;
//	}
//};

//void SimpleFunc(Simple ob) { //obj 객체를 인자로 받아 ob 객체를 생성하면서 메모리 공간 할당됨. 이때 복사생성자 호출
//	ob.ShowData();
//}

//Simple SimpleFuncObj(Simple ob) { //첫번째 복사 생성자 호출(인자 전달에 의한 호출)
//	cout << "Before return" << endl;
//	return ob; //두번째 복사 생성자 호출(반환에 의한 호출)
//	//ob를 반환할 때 임시객체라는 것이 생성되고, 이 객체의 복사생성자가 호출되면서 return문에 명시된 객체가 인자로 전달됨
//}

//----------------------------------------------------------------

//class Temporary {
//	int num;
//public:
//	Temporary(int n) : num(n) {
//		cout << "create obj: " << num << endl;
//	}
//	~Temporary() {
//		cout << "destroy obj: " << num << endl;
//	}
//	void ShowTempInfo() {
//		cout << "My num is " << num << endl;
//	}
//};
// 
//----------------------------------------------------------------

class Simple {
	int num;
public:
	Simple(int n) : num(n) {
		cout << "New Object: " << this << endl;
	}
	Simple(const Simple& copy) : num(copy.num) {
		cout << "New Copy Obj: " << this << endl;
	}
	~Simple() {
		cout << "Destroy obj: " << this << endl;
	}
};

Simple SimpleFuncObj(Simple ob) { //함수호출로 ob객체 생성(복사 생성자 호출)
	cout << "Parm ADR: " << &ob << endl;
	return ob; //ob 객체 반환할 때 임시객체 생성(복사 생성자 호출)
	//함수가 반환값 돌려주면서 함수 종료와 동시에 ob객체 소멸
	//return 시 생성된 임시객체 소멸
}

int main(void) {
	//Simple obj(10);
	///*cout << "Before Func Call" << endl;
	//SimpleFunc(obj);
	//cout << "After Func Call" << endl;*/
	//SimpleFuncObj(obj).AddNum(30).ShowData();
	//obj.ShowData();

	//----------------------------------------------------------------

	//Temporary(100); //임시객체 직접생성
	//cout << "********** after make!" << endl << endl;

	//Temporary(200).ShowTempInfo();
	//cout << "********** after make!" << endl << endl;
	//
	//const Temporary& ref = Temporary(300); //참조값이 반환되므로 참조자로 참조 가능
	//cout << "********** end of main!" << endl << endl;

	//----------------------------------------------------------------

	Simple obj(7); //객체 생성
	SimpleFuncObj(obj);

	cout << endl;
	Simple tempRef = SimpleFuncObj(obj); //참조자로 참조하기 때문에 SimpleFuncObj함수의 반환 객체는 소멸X
	cout << "Return Obj" << &tempRef << endl;

	return 0;
	//main함수가 끝나면서 obj, tempRef 객체 소멸(소멸자 2번 호출)
}