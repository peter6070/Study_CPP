#include <iostream>
#include "Cpt4_1_Point.h";
using namespace std;

bool Point::InitMembers(int xpos, int ypos) {
	//x 또는 y가 0보다 작으면 false
	if (xpos < 0 || ypos < 0) {
		cout << "invalid range" << endl;
		return false;
	}

	x = xpos;
	y = ypos;
	return true;
}

int Point::GetX() const{
	return x;
}

int Point::GetY() const{
	return y;
}

bool Point::SetX(int xpos) {
	//x가 0보다 작거나 100보다 클 경우 false
	if (xpos < 0 || xpos > 100) {
		cout << "invalid range" << endl;
		return false;
	}
	x = xpos;
	return true;
}

bool Point::SetY(int ypos) {
	//y가 0보다 작거나 100보다 클 경우 false
	if (ypos < 0 || ypos > 100) {
		cout << "invalid range" << endl;
		return false;
	}
	y = ypos;
	return true;
}