#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char* name;
	int age;
public:
	//인자받는 생성자(main함수에서 Person 배열 선언할때 인자를 넣으면 그때 호출됨. 현재는 아래 코드에 인자를 안 넣었으므로 실행 안됨)
	Person(char* myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
		cout << "called Person(char, int)" << endl;
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
	/*//객체 배열
	Person perArr[3]; //여기서 배열의 각 요소에 인자를 넣어서 선언하면 인자받는 생성자가 호출됨
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
	perArr[2].ShowPersonInfo();*/

	//객체 포인터 배열
	Person* perArr[3];
	char nameStr[100];
	int age;

	for (int i = 0; i < 3; i++) {
		cout << "Name: ";
		cin >> nameStr;
		cout << "Age: ";
		cin >> age;
		perArr[i] = new Person(nameStr, age); //인자받는 생성자 호출
	}
	perArr[0]->ShowPersonInfo();
	perArr[1]->ShowPersonInfo();
	perArr[2]->ShowPersonInfo();
	delete perArr[0];
	delete perArr[1];
	delete perArr[2];


	return 0;
}