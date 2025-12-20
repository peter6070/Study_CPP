#include <iostream>
#include "Cpt4_1_Rectangle.h";
using namespace std;

//bool Rectangle::InitMember(const Point& ul, const Point& lr) {
//	if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY()) {
//		cout << "invalid range" << endl;
//		return false;
//	}
//	upLeft = ul;
//	lowRight = lr;
//	return true;
//}
Rectangle::Rectangle(const int& x1, const int& y1, const int& x2, const int& y2) 
	:upLeft(x1,y1), lowRight(x2, y2) //멤버 이니셜라이저
{
	
}

void Rectangle::ShowRecInfo() const {
	cout << "Up Left: " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << endl;
	cout << "Low Right: " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << endl;
}