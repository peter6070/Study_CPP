#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

template <class T>
class SimpleDataWrapper {
private:
	T mdata;
public:
	SimpleDataWrapper(T data) : mdata(data){}
	void ShowDataInfo() {
		cout << "Data: " << mdata << endl;
	}
};

template <> //클래스 정의할 때 자료형을 미리 지정하므로 template <> 에는 T 같은 임의 자료형 문자를 넣을 필요 없음
//SimpleDataWrapper를 char*형에 대해 특수화
//문자열 저장을 위함. 이를 목적으로 동적할당 기반 생성자, 소멸자를 정의
class SimpleDataWrapper <char*> {
private:
	char* mdata;
public:
	SimpleDataWrapper(const char* data) {
		int len = strlen(data) + 1;
		mdata = new char[len];
		strcpy_s(mdata, len, data);
	}
	void ShowDataInfo() {
		cout << "String: " << mdata << endl;
		cout << "Length: " << strlen(mdata) << endl;
	}
	~SimpleDataWrapper() { delete[] mdata; }
};

//SimpleDataWrapper를 Point<int>형에 대해 특수화
template <>
class SimpleDataWrapper <Point<int>> {
private:
	Point<int> mdata;
public:
	SimpleDataWrapper(int x, int y) :mdata(x,y) {	}
	void ShowDataInfo() {
		mdata.ShowPosition();
	}
};

int main(void) {
	SimpleDataWrapper<int> iwrap(170); 
	//int형에 대해선 특수화가 진행되지 않았으므로, 
	// 컴파일 될 때 템플릿 클래스인 SimpleDataWrapper<int> 가 생성되고, 이 클래스를 기반으로 객체 생성
	iwrap.ShowDataInfo();
	SimpleDataWrapper<char*> swrap("Class Template Specialization");
	swrap.ShowDataInfo();
	SimpleDataWrapper<Point<int>> poswrap(3, 7);
	poswrap.ShowDataInfo();


	return 0;
}