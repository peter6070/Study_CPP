#include <iostream>
#include <string>
using namespace std;

//계좌 관리 프로그램 0.2
//구조체 -> 클래스

//기능1. 계좌개설
//기능2. 입금
//기능3. 출금
//기능4. 전체고객 잔액조회

//가정
// 통장 계좌번호 중복없음(중복검사 안함)
// 입금, 출금액은 무조건 0보다 큼(오류검사 안함)
// 고객 계좌정보는 계좌번호, 이름, 잔액 세가지만 저장
// 둘 이상의 고객 정보 저장을 위해 배열 사용
// 계좌번호는 정수형

//최대 고객 수
const int MAX_CLIENT = 100;

struct Client {
	int id;
	string name;
	int balance;
};

//전역변수
Client accArr[MAX_CLIENT];
int accNum = 0; //저장된 고객수

//함수 선언
void PrintMenu();
void PrintMenu();
void MakeAccount();
void Deposit();
void Withdraw();
void ShowAllAccInfo();


int main(void) {
	//int index = 0; //인덱스
	int selectNum = 0; //번호 선택

	//bool isExit = true; //프로그램 종료 상태
	//int searchID = 0; //입금 계좌 ID
	//int changeAmount = 0; //추가 입금액


	while (true) {
		//selectNum = 0;
		PrintMenu();
		cin >> selectNum;
		switch (selectNum)
		{
		case 1:
			MakeAccount();
			break;
		case 2:
			Deposit();
			break;
		case 3:
			Withdraw();
			break;
		case 4:
			ShowAllAccInfo();
			break;
		case 5:
			cout << "Pragram Exit" << endl;
			return 0;
		default:
			cout << "Illegal selection.." << endl;
			break;
		}
	}
	return 0;
}

//함수 정의

//메뉴 출력
void PrintMenu() {
	cout << "----Menu----" << endl;
	cout << "1. Account opening" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. WithDrawal" << endl;
	cout << "4. Print all accout Info" << endl;
	cout << "5. Exit program" << endl;
	cout << "Select Number: ";
}

//계좌 개설
void MakeAccount() {
	cout << "[Account opening]" << endl;
	cout << "Account ID: ";
	cin >> accArr[accNum].id;
	cout << "Name: ";
	cin >> accArr[accNum].name;
	cout << "Deposit amount: ";
	cin >> accArr[accNum].balance;
	accNum++;
}

//입금
void Deposit() {
	int searchID = 0; //입금 계좌 ID
	int changeAmount = 0; //추가 입금액
	bool isIDFound = false; //ID 검색 확인 여부

	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> searchID;
	for (int i = 0; i < accNum; i++) { //id 찾기
		if (searchID == accArr[i].id) {
			isIDFound = true;
			cout << "Deposit amount: ";
			cin >> changeAmount;
			accArr[i].balance += changeAmount;
			cout << "Deposit Complete" << endl;
			break;
		}
	}
	if (!isIDFound)
		cout << "ID Not Found" << endl;
}

//출금
void Withdraw() {
	int searchID = 0; //입금 계좌 ID
	int changeAmount = 0; //추가 입금액
	bool isIDFound = false; //ID 검색 확인 여부

	cout << "[WithDrawal]" << endl;
	cout << "Account ID: ";
	cin >> searchID;
	for (int i = 0; i < accNum; i++) { //id 찾기
		if (searchID == accArr[i].id) {
			isIDFound = true;
			cout << "Withdrawal amount: ";
			cin >> changeAmount;
			accArr[i].balance -= changeAmount;
			cout << "Withdrawal Complete" << endl;
			break;
		}
	}
	if (!isIDFound)
		cout << "ID Not Found" << endl;
}

//모든 고객 계좌 정보 출력
void ShowAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		cout << "\nAccount ID: " << accArr[i].id << endl;
		cout << "Name: " << accArr[i].name << endl;
		cout << "Balance: " << accArr[i].balance << endl << endl;
	}
}