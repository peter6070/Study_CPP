//C++에서 C 표준 함수 사용
//#include <cmath>
//#include <cstdio>
//#include <cstring>
#include <ctime>
#include <cstdlib>

#include <iostream>
using namespace std;


int main(void) {
	/*char str1[] = "Result";
	char str2[30];

	strcpy_s(str2, 30, str1);
	printf("%s: %f \n", str1, sin(0.14));
	printf("%s: %f \n", str2, abs(-1.25));*/

	//------------------------------------------------

	////문제1. C++ 헤더를 선언해서 표준함수 호출
	//char str_ex[30] = "Example";
	//char strCpy[30];

	////strlen: 문자열 길이 계산
	//printf("Length of '%s': %d \n", str_ex, (int)strlen(str_ex));
	//
	////strcat: 문자열 뒤에 덧붙이기
	//strcat_s(str_ex, sizeof(str_ex), "Hello");
	//printf("add 'Hello': '%s' \n", str_ex);

	////strcpy: 문자열 복사
	//strcpy_s(strCpy, 30, str_ex);
	//printf("Cpoy '%s': %s \n", str_ex, strCpy);

	////strcmp: 문자열 비교
	//if (!strcmp(str_ex, strCpy)) printf("It's same!");
	//else printf("It's not same...");

	//------------------------------------------------

	//문제2. 0이상 100미만의 난수를 5개 생성

	srand(time(NULL)); //현재 시간 기준으로 랜덤 패턴 초기화(시드 설정)

	int randNum[5];

	for (int i = 0; i < 5; i++) {
		randNum[i] = rand() % 100; //0~100미만 사이의 수
		cout << randNum[i] << endl;
	}


	return 0;
}