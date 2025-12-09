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

//문제2-3. 구조체에 대한 new&delete
//typedef: 구조체 별명 붙이기(중괄호 뒤에 붙일 별명 작성)
typedef struct __Point {
	int xpos;
	int ypos;
} Point; //struct __Point라는 구조체는 Point라는 이름으로 쓰일거임

Point& PntAdder(const Point& p1, const Point& p2) {
	//1. 힙 영역에 새 Point 생성(동적 할당)
	//질문 2. 함수 내에 선언된 변수를 참조형으로 반환하려면 어떻게 선언해야 하는가?
	Point* pPtr = new Point;
	//-> new 연산자로 힙 영역에 동적 할당된 변수로 선언

	//2. 덧셈 계산
	pPtr->xpos = p1.xpos + p2.xpos;
	pPtr->ypos = p1.ypos + p2.ypos;

	//3. 포인터가 가리키는 '공간(참조)' 리턴
	return *pPtr;
}

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

	////new연산자로 할당된 메모리 공간도 변수로 간주
	//int* ptr = new int;
	//int& ref = *ptr; //변수로 간주하기 때문에 참조자 선언 가능
	//ref = 20;
	//cout << *ptr << endl; //20

	//-------------------------------------------------------------

	//문제2-3. 구조체에 대한 new&delete
	
	//구조체 선언(힙 방식)
	Point *p1 = new Point;
	//좌표할당
	p1->xpos = 3; 
	p1->ypos = 4;

	Point *p2 = new Point;
	p2->xpos = 10;
	p2->ypos = 20;

	//질문1. 동적할당 한 변수를 함수의 참조형 매개변수로 어떻게 전달하는가?
	//-> 주소 앞에 *를 붙여 인자로 전달
	Point& result = PntAdder(*p1, *p2);

	cout << "result x: " << result.xpos << endl;
	cout << "result y: " << result.ypos << endl;

	//공간 소멸
	delete p1;
	delete p2;

	//PntAdder의 리턴값인 pPtr를 참조자로 선언했기 때문에 실체는 힙에 있음
	delete& result;


	return 0;
}
