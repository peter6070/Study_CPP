#include <iostream>
using namespace std;

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


struct client {
	int id;
	char name[100];
	int balance;
};

//함수 선언
//메뉴출력
void printMenu();

//계좌개설
//int AccountOpening(int num);


int main(void) {

	client Client[100] = {}; //고객 정보 담을 공간
	int index = 0; //인덱스

	int selectNum = 0; //번호 선택
	bool isExit = true; //프로그램 종료 상태


	int depositAmountID = 0; //입금 계좌 ID
	int depositAmount = 0; //추가 입금액

	while (isExit) {
		selectNum = 0;
		printMenu();
		cin >> selectNum;
		switch (selectNum)
		{
		case 1:
			cout << "[Account opening]" << endl;
			cout << "Account ID: ";
			cin >> Client[index].id;
			cout << "Name: ";
			cin >> Client[index].name;
			cout << "Deposit amount: ";
			cin >> Client[index].balance;
			index++;
			break;
		case 2:
			cout << "[Deposit]" << endl;
			cout << "Account ID: ";
			cin >> depositAmountID;
			for (int i = 0; i <= index; i++) { //id 찾기
				if (depositAmountID == Client[i].id) {
					cout << "Deposit amount: ";
					cin >> depositAmount;
					Client[i].balance += depositAmount;
					cout << "Deposit Complete" << endl;
					break;
				}
				/*else {
					cout << "ID not found" << endl;
				}*/
			}
			break;
		case 3:
			break;
		case 4:
			for (int i = 0; i < index; i++) {
				cout << "\nAccount ID: " << Client[i].id << endl;
				cout << "Name: " << Client[i].name << endl;
				cout << "Balance: " << Client[i].balance << "\n" << endl;
			}
			break;
		case 5:
			cout << "Pragram Exit" << endl;
			isExit = false;
			break;
		default:
			break;
		}
		cout << "" << endl;
	}


	return 0;
}

//함수 정의

//메뉴 출력
void printMenu() {
	cout << "----Menu----" << endl;
	cout << "1. Account opening" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. WithDrawal" << endl;
	cout << "4. Print all accout Info" << endl;
	cout << "5. Exit program" << endl;
	cout << "Select Number: ";
}

//계좌개설
