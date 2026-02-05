#include "Cpt9_3_BankingCommonDecl.h"
#include "Cpt9_3_Account.h"

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