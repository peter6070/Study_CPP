#include <iostream>
using namespace std;

class Simple {
	int num;
public:
	Simple(int n) : num(n) {}
	Simple& AddNum(int n) {
		num += n;
		return *this;
	}
	/*void ShowData() const {
		cout << "num: " << num << endl;
	}*/
	void SimpleFunc() {
		cout << "SimpleFunc: " << num << endl;
	}
	void SimpleFunc() const {
		cout << "const SimpleFunc: " << num << endl;
	}
};

void YourFunc(const Simple& obj) { //객체를 const로 받아 const함수가 호출되도록 함
	obj.SimpleFunc();
}

int main(void) {
	//const Simple obj(7); //const 객체로 선언
	////obj.AddNum(20); //AddNum은 const 함수가 아니기 때문에 호출 불가
	//obj.ShowData();

	//-------------------------------------------------

	Simple obj1(2);
	const Simple obj2(7);

	obj1.SimpleFunc(); //const 객체가 아니므로 "SimpleFunc:" 출력
	obj2.SimpleFunc(); //const 객체이므로 "const SimpleFunc:" 출력

	YourFunc(obj1);
	YourFunc(obj2);

	return 0;
}