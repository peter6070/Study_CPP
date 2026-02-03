#include <iostream>
#include <string>
using namespace std;

//계좌 관리 프로그램 0.6
//보통예금계좌, 신용신뢰계좌 클래스 추가

//사용자 선택 메뉴
enum {
	MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
};

//신용등급
enum {
	LEVEL_A=7,
	LEVEL_B=4,
	LEVEL_C=2
};

//계좌 종류
enum {
	NORMAL=1,
	CREDIT=2
};

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
	virtual void Deposit(int money);
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
void Account::Deposit(int money) {
	balance += money;
}
int Account::Withdraw(int money) {
	if (balance < money)
		return 0;
	balance -= money;

	return balance;
}
void Account::ShowAccInfo() const {
	cout << "\nAccount ID: " << id << endl;
	cout << "Name: " << cusName << endl;
	cout << "Balance: " << balance << endl;
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
protected:
	void MakeNormalAccount();
	void MakeHighCreditAccount();
};


//조건
//계좌개설 과정에서 초기 입금되는 금액에 대해서는 이자 계산X
//계좌개설 후 별도 입금과정을 거칠 때에만 이자 발생(입금할때만 기존 금액에 이자 추가로 붙이고 추가 입금액 포함)
//이자 계산과정에서 발생하는 소수점 이하는 무시

//보통예금계좌
class NormalAccount :public Account {
private:
	int interestRate; //이자율 단위 %
public:
	NormalAccount(int myId, char* nameStr, int myBalance, int myInterRate)
		: Account(myId, nameStr, myBalance), interestRate(myInterRate) {
	}
	virtual void Deposit(int money) {
		Account::Deposit(money); //원금 추가
		Account::Deposit(money * (interestRate /100.0)); //이자 추가
	}
};

//신용신뢰계좌
class HighCreditAccount : public NormalAccount {
private:
	int specialRate;
public:
	HighCreditAccount(int myId, char* nameStr, int myBalance, int myInterRate, int special)
		: NormalAccount(myId, nameStr, myBalance, myInterRate), specialRate(special) {	}
	virtual void Deposit(int money) {
		NormalAccount::Deposit(money); //원금, 이자 추가
		Account::Deposit(money * (specialRate / 100.0)); //특별이자 추가
	}
};


//함수 정의

//메뉴 출력
void AccountHandler::PrintMenu() const {
	cout << "-------Menu-------" << endl;
	cout << "1. Account opening" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. WithDrawal" << endl;
	cout << "4. Print all accout Info" << endl;
	cout << "5. Exit program" << endl;
	cout << "Select Number: ";
}

//계좌 개설
void AccountHandler::MakeAccount() {
	int selectAccount;

	cout << "[Select Account Type]" << endl;
	cout << "1. Normal Account  2. High Credit Account: ";
	cin >> selectAccount;
	switch (selectAccount) {
	case NORMAL: 
		MakeNormalAccount();
		break;
	case CREDIT: 
		MakeHighCreditAccount();
		break;
	default: 
		cout << "Select 1 or 2" << endl;
		return;
		break;
	}
}
//보통예금계좌 개설
void AccountHandler::MakeNormalAccount() {
	int id ;
	char name[100];
	int balance;
	int interestRate;

	cout << "[Normal Account Opening]" << endl;
	cout << "Account ID: ";	cin >> id;
	cout << "Name: ";	cin >> name;
	cout << "Deposit amount: ";	cin >> balance;
	cout << "Interest Rate: ";	cin >> interestRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, name, balance, interestRate);
}
//신용신뢰계좌 개설
void AccountHandler::MakeHighCreditAccount() {
	int id ;
	char name[100];
	int balance ;
	int interestRate;
	int trustLevel;

	cout << "[High Credit Account Opening]" << endl;
	cout << "Account ID: ";	cin >> id;
	cout << "Name: ";	cin >> name;
	cout << "Deposit amount: ";	cin >> balance;
	cout << "Interest Rate: ";	cin >> interestRate;
	cout << "Trust Level(1toA, 2toB, 3toC): ";	cin >> trustLevel;
	cout << endl;

	//신용등급 따라 이자율 부여
	switch (trustLevel) {
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, name, balance, interestRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, name, balance, interestRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, name, balance, interestRate, LEVEL_C);
		break;
	}

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
		case MAKE:
			accHan.MakeAccount();
			break;
		case DEPOSIT:
			accHan.Deposit();
			break;
		case WITHDRAW:
			accHan.Withdraw();
			break;
		case INQUIRE:
			accHan.ShowAllAccInfo();
			break;
		case EXIT:
			cout << "Pragram Exit" << endl;
			return 0;
		default:
			cout << "Illegal selection.." << endl;
			break;
		}
	}
	return 0;
}