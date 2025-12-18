#pragma once

class Point {
	int x;
	int y;

public:
	bool InitMembers(int xpos, int ypos);
	//엑세스 함수
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
};

