#include <iostream>
using namespace std;

class Base {
private: 
	int num1;
protected:
	int num2;
public:
	int num3;

	Base() : num1(1), num2(2), num3(3) {}
};

class Derived : protected Base {
};

class DerivedPriv : protected Base {
	//private보다 접근 범위가 넓은 멤버는 private으로 변경시켜 상속
};

class DeDerived : public DerivedPriv {
	//DerivedPriv 클래스의 모든 멤버가 private, 접근불가이기 때문에 private 상속이 이뤄진 클래스를 다시 상속할 경우,
	//멤버함수를 포함한 모든 멤버가 접근불가가 되어 사실상 의미없는 상속이 됨
};

int main(void) {
	Derived drv;
	//cout << drv.num3 << endl; //컴파일 에러
	// Base 클래스를 protected로 상속하기 때문에 public으로 선언된 num3는 protected로 변경됨

	

	return 0;
}