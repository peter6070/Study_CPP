#include <iostream>
#include <new>
using namespace std;

void Divide(int n1, int n2) {
	try {
		if (n2 == 0)
			throw n2;
		//예외 발생 시 Divide 함수를 호출한 main에서 예외 처리
		cout << "Quotient of Division: " << n1 / n2 << endl;
		cout << "Remain of Division: " << n1 % n2 << endl;
	}
	catch (int e) {
		cout << "first catch" << endl;
		throw; //예외 던지기
		//이 문장에 의해 catch 블록으로 전달된 예외가 소멸되지 않고,
		// 이 함수를 호출한 영역으로 예외가 다시 전달됨
	}
}

int main(void) {
	/*int num = 0;
	try {
		while (1) {
			num++;
			cout << num << "th alloc attempt" << endl;
			new int[10000][10000];
		}
	}
	catch (bad_alloc& bad) {
		cout << bad.what() << endl;
		cout << "No more alloc" << endl;
	}*/
	//--------------------------------------

	try {
		Divide(9, 2);
		Divide(4, 0);
	}
	catch (int e) { //Divide 함수에 의해 던져진 예외가 이 catch블록으로 전달됨
		cout << "second catch" << endl;
	}


	return 0;
}