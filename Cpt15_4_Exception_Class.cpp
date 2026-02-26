#include <iostream>
#include <cstring>
using namespace std;


//class AccountException {
//public:
//	virtual void ShowExceptionReason() = 0; //순수 가상함수(유도 클래스에서 정의)
//};
//
////상속관계의 예외클래스
//class DepositException : public AccountException{
//private:
//	int reqDep; //요청 입금액
//public:
//	DepositException(int money) : reqDep(money){}
//	void ShowExceptionReason() {
//		cout << "[Exception Message: " << reqDep << " is can't Deposit]" << endl;
//	}
//};
//
//class WithdrawException : public AccountException {
//private:
//	int balance; //잔고
//public:
//	WithdrawException(int money) : balance(money){}
//	void ShowExceptionReason() {
//		cout << "[Exception Message: balace " << balance << ", balance shortage]" << endl;
//	}
//};
//
//
//class Account {
//private:
//	char accNum[50]; //계좌번호
//	int balance; //잔액
//public:
//	Account(const char* acc, int money) :balance(money) {
//		strcpy_s(accNum, strlen(acc) + 1, acc);
//	}
//	void Deposit(int money) throw (AccountException) {
//		//상속에 의해 DepositException 객체도 AccountException로 간주
//		if (money < 0) {
//			DepositException expn(money);
//			throw expn;
//		}
//		balance += money;
//	}
//	void Withdraw(int money) throw(AccountException) {
//		//상속에 의해 WithdrawException 객체도 AccountException로 간주
//		if (money > balance)
//			throw WithdrawException(balance);
//		//예외객체 전달 방법. 예외객체는 임시객체 형태로 생성하는 것이 보통
//		balance -= money;
//	}
//	void ShowMyMoney() {
//		cout << "Balance: " << balance << endl << endl;
//	}
//};

//----------------------------------------

class AAA {
public:
	void Show() { cout << "AAA Exception" << endl; }
};

class BBB :public AAA {
public:
	void Show() { cout << "BBB Exception" << endl; }
};

class CCC :public BBB {
public:
	void Show() { cout << "CCC Exception" << endl; }
};

void ExceptionGenerator(int e) {
	if (e == 1)
		throw AAA();
	else if (e == 2)
		throw BBB();
	else
		throw CCC();
}

int main(void) {
	//Account myAcc("45678-456789", 5000);

	//try {
	//	myAcc.Deposit(2000);
	//	myAcc.Deposit(-300);
	//}
	//catch(AccountException &expn){ 
	//	//상속 관계로 묶여있어 catch의 참조자를 AccountException형으로 선언 가능
	//	expn.ShowExceptionReason();
	//}
	//myAcc.ShowMyMoney();

	//try {
	//	myAcc.Withdraw(3500);
	//	myAcc.Withdraw(4500);
	//}
	//catch (AccountException& expn) {
	//	expn.ShowExceptionReason();
	//}
	//myAcc.ShowMyMoney();

	//----------------------------------------
	try {
		ExceptionGenerator(3); 
		ExceptionGenerator(2);
		ExceptionGenerator(1);
		
	}
	//위쪽 catch블록부터 아래로 내려가면서 판단함
	//BBB, CCC 객체가 모두 AAA를 상속하므로, AAA 객체로 판단하여 AAA exception만 출력
	/*catch (AAA& e) {
		cout << "catch (AAA& e)" << endl;
		e.Show();
	}
	catch (BBB& e) {
		cout << "catch (BBB& e)" << endl;
		e.Show();
	}
	catch (CCC& e) {
		cout << "catch (CCC& e)" << endl;
		e.Show();
	}*/
	//---따라서 순서를 역순으로 하여 원하는 결과값으로 출력되게 해야함---
	catch (CCC& e) {
		cout << "catch (CCC& e)" << endl;
		e.Show();
	}
	catch (BBB& e) {
		cout << "catch (BBB& e)" << endl;
		e.Show();
	}
	catch (AAA& e) {
		cout << "catch (AAA& e)" << endl;
		e.Show();
	}

	return 0;
}