#include <iostream>
using namespace std;

//객체지향 프로그래밍의 과일가게 비유

//과일장수
class FruitSeller {
private:
	int APPLE_PRICE; //대문자인 이유는 사과의 판매가격은 일정하다고 가정했기 때문(const 상수 정의할 때 이름 짓는 규칙)
	int numOfApples;
	int myMoney;

public:
	void InitMember(int price, int num, int money) {
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money) {
		int num = money / APPLE_PRICE; //num 변수에 금액 나누기 사과 가격의 결과값을 담음(금액으로 살수있는 최대 개수의 사과가 담김)
		numOfApples -= num; //현재 사과 재고에서 판 재고만큼 차감
		myMoney += money; //수익 증가
		return num; //판매한 사과 전달
	}
	void ShowSalesResult() {
		cout << "Remain apples: " << numOfApples << endl;
		cout << "Revenue: " << myMoney << endl<<endl;
	}
};

class FruitBuyer {
	//클래스는 아무런 선언이 없으면 자동으로 private으로 선언됨(구조체는 public)
	int myMoney; //소유한 금액
	int numOfApples; //소유한 사과 수
public:
	void InitMember(int money) {
		myMoney = money;
		numOfApples = 0;
	}
	//참조자를 사용하여 원본(판매자)의 사과 개수 및 판매금액에 영향
	//참조자를 안쓰면 원본의 복사본에서 정보 전달이 발생하기 때문에 원본은 값이 그대로, 복사본은 함수 끝나면 사라짐
	void BuyApples(FruitSeller &seller, int money) {
		//메시지 패싱 방법: "돈 줄 테니 사과 주셈"이라고 메시지만 보냄
		//돈 주면 준만큼 맞춰서 사과 개수 반환해줌
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() {
		cout << "Revenue: " << myMoney << endl;
		cout << "Remain apples: " << numOfApples << endl<<endl;
	}
};

int main(void) {
	FruitSeller seller;
	seller.InitMember(1000, 20, 0);
	
	FruitBuyer buyer;
	buyer.InitMember(5000);
	buyer.BuyApples(seller, 2000); //과일 구매

	cout << "FruitSeller state" << endl;
	seller.ShowSalesResult();
	cout << "FruitBuyer state" << endl;
	buyer.ShowBuyResult();

	return 0;
}