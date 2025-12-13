#include <iostream>
using namespace std;

bool IsPositive(int num) {
	if (num <= 0)
		return false;
	else
		return true;
}

int main(void) {
	/*int num = 10;
	int i = 0;

	cout << "true: " << true << endl;
	cout << "false: " << false << endl;

	while (true) {
		cout << i++ << ' ';
		if (i > num) {
			break;
		}
	}
	cout << endl;

	cout << "sizeof 1: " << sizeof(1) << endl;
	cout << "sizeof 0: " << sizeof(0) << endl;
	cout << "sizeof true: " << sizeof(true) << endl;
	cout << "sizeof false: " << sizeof(false) << endl;*/

	//----------------------------------------------------------------------

	bool isPos;
	int num;
	cout << "Input number: ";
	cin >> num;

	isPos = IsPositive(num);
	if (isPos)
		cout << "Positive number" << endl;
	else
		cout << "Negative number" << endl;


	return 0;
}