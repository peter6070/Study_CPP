#include <iostream>
using namespace std;

//클래스 캡슐화
//class SinivelCap {
//public:
//	void Take() const {
//		cout << "SinivelCap" << endl;
//	}
//};
//
//class SneezeCap {
//public:
//	void Take() const {
//		cout << "SneezeCap" << endl;
//	}
//};
//
//class SnuffleCap {
//public:
//	void Take() const {
//		cout << "SnuffleCap" << endl;
//	}
//};
//
//class CONTAC600 {
//	SinivelCap sin;
//	SneezeCap sne;
//	SnuffleCap snu;
//
//public:
//	void Take() const {
//		sin.Take();
//		sne.Take();
//		snu.Take();
//	}
//};
//
//class ColdPatient {
//public:
//	//캡슐화의 무너진 예시
//	/*void TakeSinivelCap(const SinivelCap& cap) const { cap.Take(); }
//	void TakeSneezeCap(const SneezeCap& cap) const { cap.Take(); }
//	void TakeSnuffleCap(const SnuffleCap& cap) const { cap.Take(); }*/
//
//	void TakeCONTAC600(const CONTAC600& cap) const { cap.Take(); }
//};

//------------------------------------------------
//문제 4-2
class Point {
	int xpos, ypos;
public:
	void Init(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const {
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
};

class Circle {
	int radius;
	Point center;
public:
	void Init(int x, int y, int r) {
		radius = r;
		center.Init(x,y);
	}
	void ShowCircleInfo() const {
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring {
	Circle innerCircle;
	Circle outterCircle;
public:
	void Init(int inX, int inY, int inR, int outX, int outY, int outR) {
		innerCircle.Init(inX, inY, inR);
		outterCircle.Init(outX, outY, outR);
	}
	void ShowRingInfo() const {
		cout << "Inner Circle Info.." << endl;
		innerCircle.ShowCircleInfo();
		cout << "Outter Circle Info.." << endl;
		outterCircle.ShowCircleInfo();
	}
};

int main(void) {
	/*SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;

	ColdPatient sufferer;
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);*/

	/*CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);*/

	//------------------------------------------------------------
	//문제 4-2. Circle 클래스
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;
}