#pragma once

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