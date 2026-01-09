#include <iostream>
using namespace std;

class Simple {
	int num1;
	int num2;
public:
	Simple(int n1, int n2) : num1(n1), num2(n2) {}
	
	//복사 생성자를 정의하지 않아도 자동으로 디폴트 복사 생성자가 삽입됨
	//묵시적 변환 막음(Simple sim2 = sim1; <- 불가)
	explicit Simple(const Simple& copy) //복사 생성자
		: num1(copy.num1), num2(copy.num2) {
		cout << "Called Simple(Simple &copy)" << endl;
	}
	void ShowSimpleData() {
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main(void) {
	////C++ 스타일 변수 초기화 방법
	//int num(20); //{}중괄호도 가능
	//cout << num << endl;


	Simple sim1(15, 20);
	cout << "Before Construct and Initialize" << endl;
	//Simple sim2 = sim1; //클래스 복사
	cout << "After Construct and Initialize" << endl;
	Simple sim2(sim1); //위랑 같음
	sim2.ShowSimpleData();


	return 0;
}