#include <iostream>
#include <string>
using namespace std;

//계좌 관리 프로그램 0.6
//보통예금계좌, 신용신뢰계좌 클래스 추가

//최대 고객 수
const int MAX_CLIENT = 100;

//Account 클래스
class Account {
	int id;
	char* cusName;
	int balance;
public:
	Account(int myId, char* nameStr, int myBalance);
	Account(const Account& copy);

	int GetAccID() const;
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

Account::Account(int myId, char* nameStr, int myBalance)
	:id(myId), balance(myBalance)
{
	int len = strlen(nameStr) + 1;
	cusName = new char[len];
	strcpy_s(cusName, len, nameStr);
}
//복사 생성자
//동적 할당을 하는 클래스(char*)는 무조건 복사 생성자를 정의해서 깊은 복사를 해야 함(보험으로 작성한 것, 이 코드 예시에서는 작동 X)
Account::Account(const Account& copy)
	: id(copy.id), balance(copy.balance)
{
	int len = strlen(copy.cusName) + 1;
	cusName = new char[len];
	strcpy_s(cusName, len, copy.cusName);
}

int Account::GetAccID() const {
	return id;
}
//char* GetName() const {
//	return cusName;
//}
//int GetBalance() const {
//	return balance;
//}
void Account::Deposit(int money) { //void 형에는 const가 의미없음(const: 리턴값이 상수이다)
	balance += money;
}
int Account::Withdraw(int money) { //잔액 수정해야하므로 const 제거
	if (balance < money)
		return 0;
	balance -= money;

	return balance; //리턴 빼먹은거 추가
}
void Account::ShowAccInfo() const {
	cout << "\nAccount ID: " << id << endl;
	cout << "Name: " << cusName << endl;
	cout << "Balance: " << balance << endl << endl;
}
Account::~Account() {
	delete[] cusName;
}



//컨트롤 클래스
class AccountHandler {
private:
	int accNum = 0; //저장된 고객수
	Account* accArr[MAX_CLIENT]; //계좌정보 클래스 배열
public:
	AccountHandler();
	void PrintMenu() const;
	void MakeAccount();
	void Deposit();
	void Withdraw();
	void ShowAllAccInfo() const;
	~AccountHandler();

};
//함수 정의

//메뉴 출력
void AccountHandler::PrintMenu() const {
	cout << "----Menu----" << endl;
	cout << "1. Account opening" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. WithDrawal" << endl;
	cout << "4. Print all accout Info" << endl;
	cout << "5. Exit program" << endl;
	cout << "Select Number: ";
}

//계좌 개설
void AccountHandler::MakeAccount() {
	int id;
	char name[100];
	int balance;
	cout << "[Account opening]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Name: ";
	cin >> name;
	cout << "Deposit amount: ";
	cin >> balance;
	accArr[accNum++] = new Account(id, name, balance);
}

//입금
void AccountHandler::Deposit() {
	int searchID = 0; //입금 계좌 ID
	int changeAmount = 0; //추가 입금액

	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> searchID;
	for (int i = 0; i < accNum; i++) { //id 찾기
		if (searchID == accArr[i]->GetAccID()) {
			cout << "Deposit amount: ";
			cin >> changeAmount;
			accArr[i]->Deposit(changeAmount);
			cout << "Deposit Complete" << endl;
			return;
		}
	}
	cout << "ID Not Found" << endl;
}

//출금
void AccountHandler::Withdraw() {
	int searchID = 0; //입금 계좌 ID
	int changeAmount = 0; //추가 입금액

	cout << "[WithDrawal]" << endl;
	cout << "Account ID: ";
	cin >> searchID;
	for (int i = 0; i < accNum; i++) { //id 찾기
		if (searchID == accArr[i]->GetAccID()) {
			cout << "Withdrawal amount: ";
			cin >> changeAmount;
			if (accArr[i]->Withdraw(changeAmount) == 0) {
				cout << "Balance shortage" << endl;
				return;
			}
			cout << "Withdrawal Complete" << endl;
			return;
		}
	}
	cout << "ID Not Found" << endl;
}

AccountHandler::AccountHandler() : accNum(0) {}

//모든 고객 계좌 정보 출력
void AccountHandler::ShowAllAccInfo() const {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}


int main(void) {
	AccountHandler accHan;
	int selectNum = 0; //번호 선택

	while (true) {
		accHan.PrintMenu();
		cin >> selectNum;
		switch (selectNum)
		{
		case 1:
			accHan.MakeAccount();
			break;
		case 2:
			accHan.Deposit();
			break;
		case 3:
			accHan.Withdraw();
			break;
		case 4:
			accHan.ShowAllAccInfo();
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