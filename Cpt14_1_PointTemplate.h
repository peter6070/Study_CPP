#pragma once

template <class T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0); //생성자 디폴트값은 내부 함수에만 작성
	void ShowPosition() const;
};

template <class T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y){}

template <class T>
void Point<T>::ShowPosition() const {
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}