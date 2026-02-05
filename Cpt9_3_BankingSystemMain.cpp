#include "Cpt9_3_BankingCommonDecl.h"
#include "Cpt9_3_AccountHandler.h"

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