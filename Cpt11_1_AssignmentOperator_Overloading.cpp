#include <iostream>
using namespace std;

//class First {
//private:
//	int num1, num2;
//public:
//	First(int n1=0, int n2=0):num1(n1), num2(n2){}
//	void ShowData() { cout << num1 << ", " << num2 << endl; }
//	//자동으로 삽입되어 작성 필요X
//	/*First& operator=(const First& ref) {
//		num1 = ref.num1;
//		num2 = ref.num2;
//		return *this;
//	}*/
//};

//class Second {
//private:
//	int num3, num4;
//public:
//	Second(int n3=0, int n4=0):num3(n3), num4(n4){}
//	void ShowData() { cout << num3 << ", " << num4 << endl; }
//
//	//호출 확인을 위한 디폴트 대입연산자
//	Second& operator=(const Second& ref) {
//		cout << "Second& operator=()" << endl;
//		num3 = ref.num3;
//		num4 = ref.num4;
//		return *this;
//	}
//};

int main(void) {
	//First fsrc(111, 222);
	//First fcpy;
	//Second ssrc(333, 444);
	//Second scpy;
	//fcpy = fsrc; //-> fcpy.operator=(fsrc);
	//scpy = ssrc;
	//fcpy.ShowData();
	//scpy.ShowData();

	//First fob1, fob2;
	//Second sob1, sob2;
	//fob1 = fob2 = fsrc; //대입 연산자는 오른쪽에서 왼쪽으로 진행됨
	//sob1 = sob2 = ssrc;

	//fob1.ShowData();
	//fob2.ShowData();
	//sob1.ShowData();
	//sob2.ShowData();
	//---------------------------------------------------------



	return 0;
}