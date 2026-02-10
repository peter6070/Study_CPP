#include <iostream>
using namespace std;
//namespace mystd {
//	using namespace std;
//
//	//출력 클래스
//	class ostream {
//	public:
//		/*void operator<< (const char* str) {
//			printf("%s", str);
//		}
//		void operator<<(char str) {
//			printf("%c", str);
//		}
//		void operator<<(int num) {
//			printf("%d", num);
//		}
//		void operator<< (double e) {
//			printf("%g", e);
//		}*/
//		//-----------------------------------------------
//		// << 연산자 연속해서 사용시
//		ostream& operator<< (const char* str) {
//			printf("%s", str);
//			return *this;
//		}
//		ostream& operator<<(char str) {
//			printf("%c", str);
//			return *this;
//		}
//		ostream& operator<<(int num) {
//			printf("%d", num);
//			return *this;
//		}
//		ostream& operator<< (double e) {
//			printf("%g", e);
//			return *this;
//		}
//		//함수 그 자체를 전달받아서 실행해주는 연산자
//		ostream& operator<<(ostream& (*fp)(ostream& ostm)) { //함수 포인터(*fp)
//					  //반환형  포인터 이름  매개변수
//			return fp(*this);
//		}
//	};
//
//	//endl 함수
//	ostream& endl(ostream& ostm) {
//		ostm << '\n'; //줄바꿈
//		fflush(stdout); //버퍼비움(출력을 바로바로 하도록)(cout은 버퍼가 꽉 찰 때까지는 화면에 안 보여주고 모아두는 성질)
//		return ostm; //객체 반환
//	}
//
//	ostream cout; //변수명(ostream 클래스 기능을 가진 객체를 만들고 이름을 cout이라고 짓겠다
//}

//-------------------------------------------------
// << 연산자 오버로딩
class Point {
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0):xpos(x),ypos(y){}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']'<<endl;
	}
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point&);
};

//전역함수이기 때문에 operator<<(os, pos) 형태로 해석
ostream& operator<<(ostream& os, const Point& pos) { //ostream형의 os, Point형의 pos 객체를 받음
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

istream& operator>>(istream& is, Point& pos) { //pos 값을 수정해야 하므로 const 제거
	is >> pos.xpos >> pos.ypos;
	return is;
}


int main(void) {
	/*using mystd::cout;
	using mystd::endl;*/

	//cout << "Simple String"; //-> cout.operator<<("Simple String");
	//cout << endl; //-> cout.operator<<(endl);
	//cout << 3.14; //-> cout.operator<<(3.14);
	//cout << endl; //-> cout.operator<<(endl);
	//cout << 123; //-> cout.operator<<(123);
	//endl(cout);

	// << 연산자 연쇄 작용
	//cout << 3.14 << endl << 123 << endl << 'a' << endl;
	//-> (((((cout << 3.14) << endl) << 123) << endl) << 'a') << endl;

	//-------------------------------------------------
	// << 연산자 오버로딩
	//Point pos1(1, 3);
	//cout << pos1; //-> operator.(cout, pos1)
	//Point pos2(101, 303);
	//cout << pos2;

	//-------------------------------------------------
	// 문제1. >> 연산자 오버로딩
	Point pos1;
	cout << "Enter in x,y coordinate order: ";
	cin >> pos1; //operator.(cin, pos1);
	cout << pos1;

	Point pos2;
	cout << "Enter in x,y coordinate order: ";
	cin >> pos2; //operator.(cin, pos2);
	cout << pos2;

	return 0;
}