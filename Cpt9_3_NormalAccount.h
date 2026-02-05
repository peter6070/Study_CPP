#pragma once
#include "Cpt9_3_Account.h"

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
		Account::Deposit(money * (interestRate / 100.0)); //이자 추가
	}
};