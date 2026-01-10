#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char* name;
	int age;
public:
	Person(const char* myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
	}
	//복사 생성자(깊은 복사를 하기 위함)
	Person(const Person& copy) :age(copy.age) {
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy_s(name, len, copy.name);
	}
	void ShowPersonInfo() const {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
	~Person() {
		delete[] name;
		cout << "Called Destructor" << endl;
		//한번만 호출됨, man2의 소멸자가 먼저 호출되면서 name을 소멸함
		// 그런데 man1이 참조하는 name도 같이 사라졌기 때문에 삭제가 안됨 -> 오류(Double Free Error)
	}
};

int main(void) {
	Person man1("Lee", 29);
	Person man2 = man1;
	//man1, man2가 참조하는 name 문자열의 주소값이 동일해짐 = 얕은 복사
	//-> 복사 생성자를 정의하여 깊은 복사로 해결
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();


	return 0;
}