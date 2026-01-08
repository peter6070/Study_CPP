#include <iostream>
#include <string>
using namespace std;

//계좌 관리 프로그램 0.2
//구조체 -> 클래스
//고객 이름 저장 시 동적할당 형태로 저장(Acount 클래스는 멤버변수로 문자열 포인터를 지니고 있어야함)
//객체 배열 선언하지 말고, 객체 포인터 배열 선언해 객체 저장(구조체 배열 -> 포인터 배열)


//최대 고객 수
const int MAX_CLIENT = 100;

int accNum = 0; //저장된 고객수

//함수 선언
void PrintMenu();
void PrintMenu();
void MakeAccount();
void Deposit();
void Withdraw();
void ShowAllAccInfo();


//Account 클래스
class Account {
	int id;
	char* cusName;
	int balance;
public:
	Account(int myId, char* nameStr, int myBalance)
		:id(myId), balance(myBalance)
	{
		int len = strlen(nameStr) + 1;
		cusName = new char[len];
		strcpy_s(cusName, len, nameStr);
	}
	const int GetID() {
		return id;
	}
	const char* GetName() {
		return cusName;
	}
	const int GetBalance() {
		return balance;
	}
	const void DepositBalance(int changeAmount) {
		balance += changeAmount;
	}
	const int WithdrawalBalance(int changeAmount) {
		if (balance < changeAmount)
			return 0;
		balance -= changeAmount;
	}
	~Account() {
		delete[] cusName;
	}
	void ShowAccInfo() {
		cout << "\nAccount ID: " << id << endl;
		cout << "Name: " << cusName << endl;
		cout << "Balance: " << balance << endl << endl;
	}
};

Account* accArr[MAX_CLIENT];

int main(void) {

	int selectNum = 0; //번호 선택


	while (true) {
		PrintMenu();
		cin >> selectNum;
		switch (selectNum)
		{
		case 1:
			MakeAccount();
			break;
		case 2:
			Deposit();
			break;
		case 3:
			Withdraw();
			break;
		case 4:
			ShowAllAccInfo();
			break;
		case 5:
			cout << "Pragram Exit" << endl;
			for (int i = 0; i < accNum; i++) {
				delete accArr[i];
			}
			return 0;
		default:
			cout << "Illegal selection.." << endl;
			break;
		}
	}
	return 0;
}

//함수 정의

//메뉴 출력
void PrintMenu() {
	cout << "----Menu----" << endl;
	cout << "1. Account opening" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. WithDrawal" << endl;
	cout << "4. Print all accout Info" << endl;
	cout << "5. Exit program" << endl;
	cout << "Select Number: ";
}

//계좌 개설
void MakeAccount() {
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
	/*accNum++;*/
}

//입금
void Deposit() {
	int searchID = 0; //입금 계좌 ID
	int changeAmount = 0; //추가 입금액
	//bool isIDFound = false; //ID 검색 확인 여부

	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> searchID;
	for (int i = 0; i < accNum; i++) { //id 찾기
		if (searchID == accArr[i]->GetID()) {
			//isIDFound = true;
			cout << "Deposit amount: ";
			cin >> changeAmount;
			accArr[i]->DepositBalance(changeAmount);
			cout << "Deposit Complete" << endl;
			return;
		}
	}
	//if (!isIDFound)
	cout << "ID Not Found" << endl;
}

//출금
void Withdraw() {
	int searchID = 0; //입금 계좌 ID
	int changeAmount = 0; //추가 입금액
	//bool isIDFound = false; //ID 검색 확인 여부

	cout << "[WithDrawal]" << endl;
	cout << "Account ID: ";
	cin >> searchID;
	for (int i = 0; i < accNum; i++) { //id 찾기
		if (searchID == accArr[i]->GetID()) {
			//isIDFound = true;
			cout << "Withdrawal amount: ";
			cin >> changeAmount;
			if (accArr[i]->WithdrawalBalance(changeAmount) == 0) {
				cout << "Balance shortage"<<endl;
				return;
			}
			cout << "Withdrawal Complete" << endl;
			return;
		}
	}
	//if (!isIDFound)
	cout << "ID Not Found" << endl;
}

////모든 고객 계좌 정보 출력
void ShowAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		/*cout << "\nAccount ID: " << accArr[i]->GetID() << endl;
		cout << "Name: " << accArr[i]->GetName() << endl;
		cout << "Balance: " << accArr[i]->GetBalance() << endl << endl;*/
		accArr[i]->ShowAccInfo();
	}
}