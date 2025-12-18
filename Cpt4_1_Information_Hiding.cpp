#include <iostream>
using namespace std;
#include "Cpt4_1_Point.h";
#include "Cpt4_1_Rectangle.h";

//class Point {
//public:
//	int x;
//	int y;
//};
//
//class Rectangle {
//public:
//	//Rectangle 클래스 안에 Point 객체 선언
//	Point upLeft;
//	Point lowRight;
//
//public:
//	void ShowRecInfo() {
//		cout << "Up Left: " << '[' << upLeft.x << ", ";
//		cout << upLeft.y << ']' << endl;
//		cout << "Low Right: " << '[' << lowRight.x << ", ";
//		cout << lowRight.y << ']' << endl;
//	}
//};

int main(void) {
	////멤버변수가 public으로 선언되면, 구조체 변수를 초기화하듯이 초기화 가능
	//Point pos1 = { -2, 4 }; 
	//Point pos2 = { 5, 9 };
	////위에서 생성한 Point 객체를 이용해 Rectangle 객체 생성 및 초기화
	//Rectangle rec = { pos2, pos1 }; //pos2 = Rectangle.upLeft, pos1 = Rectangle.lowRight
	//rec.ShowRecInfo();

	//----------------------------------------------------

	Point pos1;
	if (!pos1.InitMembers(-2, 4))//x가 0보다 작으므로 오류
		cout << "Initialization failed" << endl;
	if(!pos1.InitMembers(2,4))
		cout << "Initialization failed" << endl;

	Point pos2;
	if(!pos2.InitMembers(5,9))
		cout << "Initialization failed" << endl;

	Rectangle rec;
	if(!rec.InitMember(pos2, pos1)) //pos1의 좌푯값이 pos2보다 크므로 오류
		cout << "Rectangle initialization failed" << endl;

	if (!rec.InitMember(pos1, pos2)) //pos1의 좌푯값이 pos2보다 작으므로 정상출력
		cout << "Rectangle initialization failed" << endl;
	
	rec.ShowRecInfo();

	return 0;
}