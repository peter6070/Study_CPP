#pragma once
#include "Cpt4_1_Point.h";


//Rectangle 클래스 은닉화
class Rectangle {
Point upLeft;
Point lowRight;

public:
	//bool InitMember(const Point& ul, const Point& lr);
	Rectangle(const int& x1, const int& y1, const int& x2, const int& y2); //생성자
	void ShowRecInfo() const;
};