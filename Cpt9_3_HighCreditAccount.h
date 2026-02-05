#pragma once
#include "Cpt9_3_NormalAccount.h"

//신용신뢰계좌
class HighCreditAccount : public NormalAccount {
private:
	int specialRate;
public:
	HighCreditAccount(int myId, char* nameStr, int myBalance, int myInterRate, int special)
		: NormalAccount(myId, nameStr, myBalance, myInterRate), specialRate(special) {
	}
	virtual void Deposit(int money) {
		NormalAccount::Deposit(money); //원금, 이자 추가
		Account::Deposit(money * (specialRate / 100.0)); //특별이자 추가
	}
};