//#define _CRT_SECURE_NO_WARNINGS //비주얼스튜디오에서 메모리 오버플로우 막으려고 strcpy를 금지했는데 무시하고 실행하는 코드
//#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

////malloc&free
//char* MakeStrAdr(int len) {
//	char* str = (char*)malloc(sizeof(char) * len);
//	return str;
//}

////new & delete
//char* MakeStrAdr(int len) {
//	char* str = new char[len];
//	return str;
//}

int main(void) {
	////malloc&free
	//char* str = MakeStrAdr(50);
	//strcpy(str, "I'm trunt a fxxk up~"); //비주얼스튜디오에서 오버플로우 문제 때문에 금지시킴
	//cout << str << endl;
	//free(str);

	////new & delete
	//char* str = MakeStrAdr(20);
	//strcpy_s(str, 20, "I'm vibin. bruh");
	//cout << str << endl;
	//delete[]str;

	//new연산자로 할당된 메모리 공간도 변수로 간주
	int* ptr = new int;
	int& ref = *ptr; //변수로 간주하기 때문에 참조자 선언 가능
	ref = 20;
	cout << *ptr << endl; //20


	return 0;
}