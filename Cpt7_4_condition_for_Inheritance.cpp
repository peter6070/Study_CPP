#include <iostream>
#include <cstring>
using namespace std;

//컴퓨터
class Computer {
private:
	char owner[50];
public:
	Computer(const char* name) {
		strcpy_s(owner, 50, name);
	}
	void Calculate() {
		cout << "Calculate the request";
	}
};

//노트북(컴퓨터를 상속함 -> LabtopComp은 Computer이다)
class LabtopComp : public Computer {
private:
	int Battery;
public:
	LabtopComp(const char* name, int initChag)
		: Computer(name), Battery(initChag) {
	}
	void Charging() { Battery += 5;  }
	void UseBattery() { Battery -= 1; }
	void MovingCal() {
		if (GetBatteryInfo() < 1) {
			cout << "Need Charging" << endl;
			return;
		}
		Calculate();
		UseBattery();
		cout << " as you move" << endl;
	}
	int GetBatteryInfo() { return Battery; }
};

//태블릿(노트북을 상속함 -> TabletLabtop은 LabtopComp이다 -> TabletLabtop은 Computer이다)
class TabletLabtop : public LabtopComp {
private:
	char regstPenModel[50];
public:
	TabletLabtop(const char* name, int initChag, const char* pen) 
	: LabtopComp(name, initChag)
	{
		strcpy_s(regstPenModel, 50, pen);
	}
	void Write(const char* penInfo) {
		if (GetBatteryInfo() < 1) {
			cout << "Need Charging" << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0) {
			cout << "Not Registrated pen";
			return;
		}
		cout << "Process Writing contents" << endl;
		UseBattery();
	}
};

int main(void) {

	LabtopComp lc("Lee", 5);
	TabletLabtop tl("Jung", 5, "ISE-241-242");
	lc.MovingCal();
	tl.Write("ISE-241-242");

	return 0;
}