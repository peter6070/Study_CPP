#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char* name;
	int age;
public:
	//인자받는 생성자
	Person(char* myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
	}
	//생성자
	Person() {
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	//이름, 나이 설정
	void SetPersonInfo(char* myname, int myage) {
		name = myname;
		age = myage;
	}
	//정보 출력
	void ShowPersonInfo() const {
		cout << "Name: " << name << ", ";
		cout << "Age: " << age << endl;
	}
	//소멸자
	~Person() {
		delete[] name;
		cout << "called Destructor" << endl;
	}
};

int main(void) {
	Person perArr[3]; //person array
	char nameStr[100];
	char* strptr;
	int age;
	int len;

	//for문을 이용해 배열의 각 객체마다 이름과 나이 정보를 입력받아 객체 초기화
	for (int i = 0; i < 3; i++) {
		cout << "Name: ";
		cin >> nameStr;
		cout << "Age: ";
		cin >> age;
		len = strlen(nameStr) + 1;
		strptr = new char[len];
		strcpy_s(strptr, len, nameStr);
		perArr[i].SetPersonInfo(strptr, age);
	}
	perArr[0].ShowPersonInfo();
	perArr[1].ShowPersonInfo();
	perArr[2].ShowPersonInfo();

	return 0;
}