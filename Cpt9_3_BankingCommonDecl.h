#pragma once
#include <iostream>
#include <string>
using namespace std;

//계좌 관리 프로그램 0.7
//헤더, 소스파일 분리

//최대 고객 수
const int MAX_CLIENT = 100;

//사용자 선택 메뉴
enum {
	MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
};

//신용등급
enum {
	LEVEL_A = 7,
	LEVEL_B = 4,
	LEVEL_C = 2
};

//계좌 종류
enum {
	NORMAL = 1,
	CREDIT = 2
};