#pragma once

template <class T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0); //생성자 디폴트값은 내부 함수에만 작성
	void ShowPosition() const;
};