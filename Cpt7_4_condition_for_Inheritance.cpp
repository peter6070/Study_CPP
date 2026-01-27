#include <iostream>
#include <cstring>
using namespace std;

////컴퓨터
//class Computer {
//private:
//	char owner[50];
//public:
//	Computer(const char* name) {
//		strcpy_s(owner, 50, name);
//	}
//	void Calculate() {
//		cout << "Calculate the request";
//	}
//};
//
////노트북(컴퓨터를 상속함 -> LabtopComp은 Computer이다)
//class LabtopComp : public Computer {
//private:
//	int Battery;
//public:
//	LabtopComp(const char* name, int initChag)
//		: Computer(name), Battery(initChag) {
//	}
//	void Charging() { Battery += 5;  }
//	void UseBattery() { Battery -= 1; }
//	void MovingCal() {
//		if (GetBatteryInfo() < 1) {
//			cout << "Need Charging" << endl;
//			return;
//		}
//		Calculate();
//		UseBattery();
//		cout << " as you move" << endl;
//	}
//	int GetBatteryInfo() { return Battery; }
//};
//
////태블릿(노트북을 상속함 -> TabletLabtop은 LabtopComp이다 -> TabletLabtop은 Computer이다)
//class TabletLabtop : public LabtopComp {
//private:
//	char regstPenModel[50];
//public:
//	TabletLabtop(const char* name, int initChag, const char* pen) 
//	: LabtopComp(name, initChag)
//	{
//		strcpy_s(regstPenModel, 50, pen);
//	}
//	void Write(const char* penInfo) {
//		if (GetBatteryInfo() < 1) {
//			cout << "Need Charging" << endl;
//			return;
//		}
//		if (strcmp(regstPenModel, penInfo) != 0) {
//			cout << "Not Registrated pen";
//			return;
//		}
//		cout << "Process Writing contents" << endl;
//		UseBattery();
//	}
//};
//----------------------------------------------

class Gun {
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum) {}
	void Shot() {
		cout << "Bang!" << endl;
		bullet--;
	}
};

//class Police : public Gun {
//private:
//	int handcuffs;
//public:
//	Police(int bnum, int bcuff) : Gun(bnum), handcuffs(bcuff) {}
//	void PutHandcuff() {
//		cout << "SNAP!" << endl;
//		handcuffs--;
//	}
//};

//HAS-A 상속이 아닌 다른 방법
class Police {
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff) : handcuffs(bnum) {
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	void PutHandcuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot() { //Gun 객체를 멤버변수를 통해 참조하는 구조이기 때문에 별도의 함수 정의 필요
		if (pistol == NULL)
			cout << "No Armo!" << endl;
		else
			pistol->Shot();
	}
	~Police() {
		if (pistol != NULL)
			delete pistol;
	}
};

int main(void) {
	//IS-A
	/*LabtopComp lc("Lee", 5);
	TabletLabtop tl("Jung", 5, "ISE-241-242");
	lc.MovingCal();
	tl.Write("ISE-241-242");*/

	//----------------------------------------------
	//HAS-A
	//Police pman(5, 3); //총알 5, 수갑 3
	//pman.Shot();
	//pman.PutHandcuff();

	//HAS-A 상속이 아닌 다른 방법
	Police pman1(5, 3);
	pman1.Shot();
	pman1.PutHandcuff();

	Police pman2(0, 3); //권총 소유 X
	pman2.Shot();
	pman2.PutHandcuff();


	return 0;
}