#pragma once
#include "Cpt4_1_Point.h";


//Rectangle 클래스 은닉화
class Rectangle {
Point upLeft;
Point lowRight;

public:
	bool InitMember(const Point& ul, const Point& lr);
	void ShowRecInfo() const;
};