#include <iostream>
#include <cstring>
using namespace std;

//class Girl; //뒤에 나오는 함수의 호출을 위해 함수 원형을 선언하듯이, 클래스도 선언이 가능함
//
//class Boy {
//	int height;
//	friend class Girl; //Girl 클래스에 대한 friend 선언(private 영역에도 friend 선언 가능)
//	//-> Girl은 클래스의 이름
//	//-> 그리고 그 Girl 클래스를 friend로 선언
//public:
//	Boy(int len) : height(len) {}
//	void ShowYourFriendInfo(Girl& frn);
//};
//
//class Girl {
//	char phNum[20];
//public:
//	Girl(const char* num) {
//		strcpy_s(phNum, 20, num);
//	}
//	void ShowYourFriendInfo(Boy& frn);
//	friend class Boy; //Boy 클래스에 대한 friend 선언
//};
//
//void Boy::ShowYourFriendInfo(Girl& frn) {
//	cout << "Her phone Number: " << frn.phNum << endl;
//	//컴파일러가 제대로 컴파일하기 위해선, Girl 클래스에 멤버변수 phNum이 존재한다는 사실을 알아야함
//	//따라서 이 함수의 정의가 Girl 클래스 정의보다 뒤에 위치함
//}
//
//void Girl::ShowYourFriendInfo(Boy& frn) {
//	cout << "His height: " << frn.height << endl;
//}

//----------------------------------------------------------

class Point; //아래 함수에서 호출인자로 사용하기 위해 먼저 정의

class PointOP {
	int opcnt;
	public:
		PointOP() : opcnt(0) {}
		
		Point PointAdd(const Point&, const Point&);
		Point PointSub(const Point&, const Point&);
		~PointOP() {
			cout << "Operation times: " << opcnt << endl;
		}
};

class Point {
private:
	int x;
	int y;
public:
	Point(const int& xpos, const int& ypos) : x(xpos), y(ypos) {}
	//함수 friend 선언
	friend Point PointOP::PointAdd(const Point&, const Point&);
	friend Point PointOP::PointSub(const Point&, const Point&);
	friend void ShowPointPos(const Point&);	//함수 원형의 선언이 포함되어있음
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2) {
	opcnt++;
	//Point 클래스의 friend로 선언되었기 때문에 private 멤버(x,y)에 접근 가능
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2) {
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

int main(void) {
	/*Boy boy(170);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);*/
	//----------------------------------------------------------

	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;

	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos2, pos1));


	return 0;
}

//Point 클래스의 friend로 선언되었기 때문에 private 멤버(x,y)에 접근 가능
void ShowPointPos(const Point& pos) {
	cout << "x: " << pos.x << ", ";
	cout << "y: " << pos.y << endl;
}