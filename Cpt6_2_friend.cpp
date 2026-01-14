#include <iostream>
#include <cstring>
using namespace std;

class Girl; //뒤에 나오는 함수의 호출을 위해 함수 원형을 선언하듯이, 클래스도 선언이 가능함

class Boy {
	int height;
	friend class Girl; //Girl 클래스에 대한 friend 선언(private 영역에도 friend 선언 가능)
	//-> Girl은 클래스의 이름
	//-> 그리고 그 Girl 클래스를 friend로 선언
public:
	Boy(int len) : height(len) {}
	void ShowYourFriendInfo(Girl& frn);
};

class Girl {
	char phNum[20];
public:
	Girl(const char* num) {
		strcpy_s(phNum, 20, num);
	}
	void ShowYourFriendInfo(Boy& frn);
	friend class Boy; //Boy 클래스에 대한 friend 선언
};

void Boy::ShowYourFriendInfo(Girl& frn) {
	cout << "Her phone Number: " << frn.phNum << endl;
	//컴파일러가 제대로 컴파일하기 위해선, Girl 클래스에 멤버변수 phNum이 존재한다는 사실을 알아야함
	//따라서 이 함수의 정의가 Girl 클래스 정의보다 뒤에 위치함
}

void Girl::ShowYourFriendInfo(Boy& frn) {
	cout << "His height: " << frn.height << endl;
}

int main(void) {
	Boy boy(170);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);


	return 0;
}