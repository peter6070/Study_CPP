#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char* name;
	int age;
public:
	Person(char* myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
	}
	Person() {
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	void SetPersonInfo(char* myname, int myage) {
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const {
		cout << "Name: " << name << ", ";
		cout << "Age: " << age << endl;
	}
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