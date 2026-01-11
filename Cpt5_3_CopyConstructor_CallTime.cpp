#include <iostream>
using namespace std;

class Simple {
	int num;
public:
	Simple(int n) : num(n) {}
	Simple(const Simple& copy) : num(copy.num) {
		cout << "Called Simple(const Simple& copy)" << endl;
	}
	//복사 생성자 호출(객체 반환하되, 참조형으로 반환하지않는 경우)
	Simple& AddNum(int n) {
		num += n;
		return *this;
	}
	void ShowData() {
		cout << "num: " << num << endl;
	}
};

void SimpleFunc(Simple ob) { //obj 객체를 인자로 받아 ob 객체를 생성하면서 메모리 공간 할당됨. 이때 복사생성자 호출
	ob.ShowData();
}

Simple SimpleFuncObj(Simple ob) { //첫번째 복사 생성자 호출(인자 전달에 의한 호출)
	cout << "Before return" << endl;
	return ob; //두번째 복사 생성자 호출(반환에 의한 호출)
	//ob를 반환할 때 임시객체라는 것이 생성되고, 이 객체의 복사생성자가 호출되면서 return문에 명시된 객체가 인자로 전달됨
}

int main(void) {
	Simple obj(10);
	/*cout << "Before Func Call" << endl;
	SimpleFunc(obj);
	cout << "After Func Call" << endl;*/
	SimpleFuncObj(obj).AddNum(30).ShowData();
	obj.ShowData();


	return 0;
}