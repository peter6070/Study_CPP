#include "Cpt9_3_BankingCommonDecl.h"
#include "Cpt9_3_AccountHandler.h"
#include "Cpt9_3_Account.h"
#include "Cpt9_3_NormalAccount.h"
#include "Cpt9_3_HighCreditAccount.h"

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
	int id;
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
	int id;
	char name[100];
	int balance;
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