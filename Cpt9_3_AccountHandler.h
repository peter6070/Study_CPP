#pragma once
#include "Cpt9_3_BankingCommonDecl.h"
#include "Cpt9_3_Account.h"

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