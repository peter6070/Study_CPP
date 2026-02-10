#include <iostream>
namespace mystd {
	using namespace std;

	//출력 클래스
	class ostream {
	public:
		/*void operator<< (const char* str) {
			printf("%s", str);
		}
		void operator<<(char str) {
			printf("%c", str);
		}
		void operator<<(int num) {
			printf("%d", num);
		}
		void operator<< (double e) {
			printf("%g", e);
		}*/
		//-----------------------------------------------
		// << 연산자 연속해서 사용시
		ostream& operator<< (const char* str) {
			printf("%s", str);
			return *this;
		}
		ostream& operator<<(char str) {
			printf("%c", str);
			return *this;
		}
		ostream& operator<<(int num) {
			printf("%d", num);
			return *this;
		}
		ostream& operator<< (double e) {
			printf("%g", e);
			return *this;
		}
		//함수 그 자체를 전달받아서 실행해주는 연산자
		ostream& operator<<(ostream& (*fp)(ostream& ostm)) { //함수 포인터(*fp)
					  //반환형  포인터 이름  매개변수
			return fp(*this);
		}
	};

	//endl 함수
	ostream& endl(ostream& ostm) {
		ostm << '\n';
		fflush(stdout);
		return ostm;
	}

	ostream cout; //변수명(ostream 클래스 기능을 가진 객체를 만들고 이름을 cout이라고 짓겠다
}



int main(void) {
	using mystd::cout;
	using mystd::endl;

	//cout << "Simple String"; //-> cout.operator<<("Simple String");
	//cout << endl; //-> cout.operator<<(endl);
	//cout << 3.14; //-> cout.operator<<(3.14);
	//cout << endl; //-> cout.operator<<(endl);
	//cout << 123; //-> cout.operator<<(123);
	//endl(cout);

	//한줄로 작성
	cout << 3.14 << endl << 123 << endl << 'a' << endl;
	//-> (((((cout << 3.14) << endl) << 123) << endl) << 'a') << endl;

	return 0;
}