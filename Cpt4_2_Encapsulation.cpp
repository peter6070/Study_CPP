#include <iostream>
using namespace std;


class SinivelCap {
public:
	void Take() const {
		cout << "SinivelCap" << endl;
	}
};

class SneezeCap {
public:
	void Take() const {
		cout << "SneezeCap" << endl;
	}
};

class SnuffleCap {
public:
	void Take() const {
		cout << "SnuffleCap" << endl;
	}
};

class CONTAC600 {
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;

public:
	void Take() const {
		sin.Take();
		sne.Take();
		snu.Take();
	}
};

class ColdPatient {
public:
	//캡슐화의 무너진 예시
	/*void TakeSinivelCap(const SinivelCap& cap) const { cap.Take(); }
	void TakeSneezeCap(const SneezeCap& cap) const { cap.Take(); }
	void TakeSnuffleCap(const SnuffleCap& cap) const { cap.Take(); }*/

	void TakeCONTAC600(const CONTAC600& cap) const { cap.Take(); }
};

int main(void) {
	/*SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;

	ColdPatient sufferer;
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);*/

	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);

	return 0;
}