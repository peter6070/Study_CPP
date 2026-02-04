#include <iostream>
using namespace std;

//class Data {
//private:
//	int data;
//public:
//	Data(int num) :data(num) {}
//	void ShowData() { cout << "Data: " << data << endl; }
//	void Add(int num) { data += num; }
//};
//-----------------------------------------------
////Data 클래스를 흉내 낸 영역(멤버변수 작동원리 이해)
//typedef struct Data {
//	int data;
//	//함수 포인터 변수가 구조체 멤버로 등장(함수 정의)
//	void (*ShowData)(Data*);
//	void (*Add)(Data*, int);
//
//} Data;
////함수 선언
//void ShowData(Data* THIS) { cout << "Data: " << THIS->data << endl; }
//void Add(Data* THIS, int num) { THIS->data += num; }
//-----------------------------------------------

class AAA {
private:
	int num1;
public:
	virtual void Func1() { cout << "Func1" << endl; }
	virtual void Func2() { cout << "Func2" << endl; }
};

class BBB : public AAA {
private:
	int num2;
public:
	virtual void Func1() { cout << "BBB::Func1" << endl; }
	void Func3() { cout << "Func3" << endl; }
};

int main(void) {
	/*Data obj(15);
	obj.Add(17);
	obj.ShowData();*/
	//-----------------------------------------------
	////구조체(객체) 생성
	//Data obj1 = { 15,ShowData,Add };
	//Data obj2 = { 7,ShowData,Add };

	//obj1.Add(&obj1, 17); //obj1 주소에서 Add 함수를 실행
	//obj2.Add(&obj2, 9);
	//obj1.ShowData(&obj1); //obj1 주소에서 ShowData 함수를 실행
	//obj2.ShowData(&obj2);
	//-----------------------------------------------
	AAA* aptr = new AAA();
	aptr->Func1();

	BBB* bptr = new BBB();
	bptr -> Func1();

	return 0;
}