#include <iostream>
using namespace std;

//함수 템플릿, static 지역변수
//template <class T>
//void ShowStaticValue() {
//	static T num = 0;
//	//함수 템플릿을 기반으로 컴파일러가 템플릿 함수들을 만드는데
//	// static 지역변수도 템플릿 함수 별로 각각 존재함
//	num += 1;
//	cout << num << " ";
//}
//-----------------------------------
//클래스 템플릿, static 멤버변수
template <class T>
class SimpleStaticMem {
private:
	static T mem;
public:
	void AddMem(T num) {
		mem += num;
	}
	void ShowMem() const {
		cout << mem << endl;
	}
};

template <class T>
T SimpleStaticMem<T>::mem = 0; //static 멤버 초기화

//템플릿 static 멤버변수 초기화의 특수화
template <>
long SimpleStaticMem<long>::mem = 5; //SimpleStaticMem<long>로 생성된 객체의 mem값은 5로 선언

int main(void) {
	//함수 템플릿, static 지역변수
	//ShowStaticValue<int>();
	//ShowStaticValue<int>();
	//ShowStaticValue<int>();
	//cout << endl;
	//ShowStaticValue<long>();
	//ShowStaticValue<long>();
	//ShowStaticValue<long>();
	//cout << endl;
	//ShowStaticValue<double>();
	//ShowStaticValue<double>();
	//ShowStaticValue<double>();

	//-----------------------------------
	//클래스 템플릿, static 멤버변수
	SimpleStaticMem<int> obj1; 
	SimpleStaticMem<int> obj2;
	//obj1, obj2 둘다 같은 자료형이므로 SimpleStaticMem<int>::mem 값을 공유
	obj1.AddMem(2); 
	obj2.AddMem(3);
	obj1.ShowMem();
	// 0으로 초기화된 SimpleStaticMem<int>::mem의 값을 2,3 만큼 증가
	// 5 출력

	SimpleStaticMem<long> obj3;
	SimpleStaticMem<long> obj4;
	//obj3, obj4 둘다 같은 자료형이므로 SimpleStaticMem<long>::mem 값을 공유
	obj3.ShowMem(); //long형에 대해 static 멤버변수를 특수화하여 5 출력
	obj3.AddMem(100);
	obj4.ShowMem();
	// 0으로 초기화된 SimpleStaticMem<long>::mem의 값을 100 만큼 증가
	// 100 출력

	return 0;
}