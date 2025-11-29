#include <iostream>

int main(void) {
	////데이터 출력(std::cout<<)
	//int num = 100; //변수 선언
	//std::cout << "Hello World!" << std::endl; //Hello World 출력 후 줄바꿈(endl)
	//std::cout << "Hello " << "World!" << std::endl; //Hello, World 따로 출력 후 줄바꿈
	//std::cout << num << ' ' << 'A'; // 아까 선언한 num 변수 출력, A 출력
	//std::cout << ' ' << 3.14 << std::endl; //3.14 출력 후 줄바꿈
	//std::cout << "a " << "b " << 123 << ' ' << 123.44 << ' ' << std::endl;

	//---------------------------------------------------------------------------------------

	////데이터 입력(std::cin>>)
	//int val1;
	//std::cout << "첫 번째 숫자입력: ";
	//std::cin >> val1; //정수 입력 받은 후 val1에 저장

	//int val2;
	//std::cout << "두 번째 숫자입력: ";
	//std::cin >> val2; //정수 입력 받은 후 val2에 저장

	//int result = val1 + val2; //두 변수 더하기
	//int result2 = val1 * val2; //두 변수 곱하기
	//std::cout << "덧셈결과: " << result << std::endl;
	//std::cout << "곱셈결과: " << result2 << std::endl;

	//---------------------------------------------------------------------------------------

	////실수 입력
	//double val1;
	//std::cout << "첫 번째 숫자입력: ";
	//std::cin >> val1; //실수 입력 받은 후 val1에 저장

	//double val2;
	//std::cout << "두 번째 숫자입력: ";
	//std::cin >> val2; //실수 입력 받은 후 val2에 저장

	//double result = val1 + val2; //두 변수 더하기
	//double result2 = val1 * val2; //두 변수 곱하기
	//std::cout << "덧셈결과: " << result << std::endl;
	//std::cout << "곱셈결과: " << result2 << std::endl;

	//---------------------------------------------------------------------------------------

	////문장 입력
	//char str[100];
	//std::cout << "Write user name: ";
	//std::cin >> str;
	//std::cout << "Welcome "<< str << std::endl;

	//---------------------------------------------------------------------------------------

	//두 수 사이 정수의 합
	/*int val1, val2;
	int result = 0;
	std::cout << "두 개의 숫자입력: ";
	std::cin >> val1 >> val2;

	if (val1 < val2) {
		for (int i = val1 + 1; i < val2; i++)
			result += i;
	}
	else {
		for (int i = val2 + 1; i < val1; i++)
			result += i;
	}

	std::cout << "두 수 사이 정수 합: " << result << std::endl;*/

	//---------------------------------------------------------------------------------------

	////배열 기반 문자열 입출력
	//char name[100];
	//char lang[200];

	//std::cout << "what's your name bruh?: ";
	//std::cin >> name;

	//std::cout << "what's your favorite language dawg?: ";
	//std::cin >> lang;

	//std::cout << "Ayo, your name is " << name << ". right?\n";
	//std::cout << "yo, and your language is " << lang << ". right?"<<std::endl;
	//std::cout << "damm, bruh. that's clean~~";


	//---------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------

	////문제1. 5개의 정수를 입력받아 그 합을 출력
	//int num[5];
	//int result = 0;
	//for (int i = 0; i < 5; i++) {
	//	std::cout << i+1 << "번째 정수 입력: ";
	//	std::cin >> num[i];
	//	result += num[i];
	//}
	//std::cout << "합계: " << result << std::endl;

	//---------------------------------------------------------------------------------------

	////문제2. 사용자 이름, 전번을 문장열로 입력받아, 입력받은 데이터를 그대로 출력
	//char name[10];
	//char phone[20];

	//std::cout << "이름을 입력해주세요: ";
	//std::cin >> name;

	//std::cout << "전화번호를 입력해주세요: ";
	//std::cin >> phone;

	//std::cout << "이름: " << name << ", 전화번호: " << phone << std::endl;

	//---------------------------------------------------------------------------------------

	////문제3. 숫자 입력받아 그 숫자에 해당하는 구구단 출력(5 입력시 5단 전부 출력)
	//int num;
	//std::cout << "2~9 사이 숫자를 입력해주세요: ";
	//std::cin >> num;
	//for (int i = 1; i < 10; i++) {
	//	std::cout << num << " x " << i << " = " << num * i << std::endl;
	//}

	//---------------------------------------------------------------------------------------

	//문제4. 판매원 급여 계산
	int sell;
	std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
	std::cin >> sell;
	if (sell == -1) {
		std::cout << "프로그램을 종료합니다.";
	}
	else std::cout << "이번 달 급여: "<< 50 + sell * 0.12 << "만원"<<std::endl;

	return 0; //클래스 종료 선언
}