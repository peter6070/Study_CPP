#include <iostream>
using namespace std;

class First {
public:
	void FirstFunc() { cout << "FirstFunc" << endl; }
};

class Second :public First {
public:
	void SecondFunc() { cout << "SecondFunc" << endl; }
};

class Third : public Second {
public:
	void ThirdFunc() { cout << "ThirdFunc" << endl; }
};

int main(void) {
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	tptr->FirstFunc();
	tptr->SecondFunc();
	tptr->ThirdFunc();

	sptr->FirstFunc();
	sptr->SecondFunc();
	//sptr->ThirdFunc(); //sptr의 포인터형은 Second 클래스이기 때문에 Second 클래스가 접근 가능한 함수만 호출 가능

	fptr->FirstFunc();
	//fptr->SecondFunc(); //fptr의 포인터형은 First 클래스이기 때문에 First 클래스가 접근 가능한 함수만 호출 가능
	//fptr->ThirdFunc();


	return 0;
}