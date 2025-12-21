#include <iostream>
using namespace std;
#include "Cpt4_1_Point.h";
#include "Cpt4_1_Rectangle.h";

//class Point {
//public:
//	int x;
//	int y;
//};
//
//class Rectangle {
//public:
//	//Rectangle 클래스 안에 Point 객체 선언
//	Point upLeft;
//	Point lowRight;
//
//public:
//	void ShowRecInfo() {
//		cout << "Up Left: " << '[' << upLeft.x << ", ";
//		cout << upLeft.y << ']' << endl;
//		cout << "Low Right: " << '[' << lowRight.x << ", ";
//		cout << lowRight.y << ']' << endl;
//	}
//};

//----------------------------------------------------
//문제 4-1. 과일 판매 시뮬레이션에 '사과 구매 목적으로 0보다 작은 수 전달 불가' 조건 추가

//과일장수
class FruitSeller {
private:
	int APPLE_PRICE; //대문자인 이유는 사과의 판매가격은 일정하다고 가정했기 때문(const 상수 정의할 때 이름 짓는 규칙)
	int numOfApples;
	int myMoney;

public:
	////초기화 함수(생성자가 있어서 굳이 선언안해도 됨)
	//void InitMember(int price, int num, int money) {
	//	APPLE_PRICE = price;
	//	numOfApples = num;
	//	myMoney = money;
	//}
	
	//void InitMember -> FruitSeller 생성자로 선언
	/*FruitSeller(int price, int num, int money) {
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}*/

	//멤버 이니셜라이저로 const 상수 초기화
	FruitSeller(int price, int num, int money) 
		: APPLE_PRICE(price), numOfApples(num), myMoney(money)
	{
	}

	int SaleApples(int money) {
		if (money < 0) {
			cout << "Incorrect value" << endl;
			return 0;
		}
		int num = money / APPLE_PRICE; //num 변수에 금액 나누기 사과 가격의 결과값을 담음(금액으로 살수있는 최대 개수의 사과가 담김)
		numOfApples -= num; //현재 사과 재고에서 판 재고만큼 차감
		myMoney += money; //수익 증가
		return num; //판매한 사과 전달
	}
	void ShowSalesResult() const {
		cout << "Revenue: " << myMoney << endl;
		cout << "Remain apples: " << numOfApples << endl << endl;
	}
};

class FruitBuyer {
	//클래스는 아무런 선언이 없으면 자동으로 private으로 선언됨(구조체는 public)
	int myMoney; //소유한 금액
	int numOfApples; //소유한 사과 수
public:

	////초기화 함수(생성자가 있어서 굳이 선언안해도 됨)
	//void InitMember(int money){
	//	myMoney = money;
	//	numOfApples = 0;
	//}

	////void InitMember -> FruitBuyer 생성자로 선언
	//FruitBuyer(int money) {
	//	myMoney = money;
	//	numOfApples = 0;
	//}

	//멤버 이니셜라이저로 const 상수 초기화
	FruitBuyer(int money) 
		: myMoney(money), numOfApples(0)
	{
	}

	//참조자를 사용하여 원본(판매자)의 사과 개수 및 판매금액에 영향
	//참조자를 안쓰면 원본의 복사본에서 정보 전달이 발생하기 때문에 원본은 값이 그대로, 복사본은 함수 끝나면 사라짐
	void BuyApples(FruitSeller& seller, int money) {
		if (money < 0) {
			cout << "Incorrect value" << endl<<endl;
			return;
		}
		//메시지 패싱 방법: "돈 줄 테니 사과 주셈"이라고 메시지만 보냄
		//돈 주면 준만큼 맞춰서 사과 개수 반환해줌
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const {
		cout << "Revenue: " << myMoney << endl;
		cout << "Remain apples: " << numOfApples << endl << endl;
	}
};

int main(void) {
	////멤버변수가 public으로 선언되면, 구조체 변수를 초기화하듯이 초기화 가능
	//Point pos1 = { -2, 4 }; 
	//Point pos2 = { 5, 9 };
	////위에서 생성한 Point 객체를 이용해 Rectangle 객체 생성 및 초기화
	//Rectangle rec = { pos2, pos1 }; //pos2 = Rectangle.upLeft, pos1 = Rectangle.lowRight
	//rec.ShowRecInfo();

	//----------------------------------------------------

	//Point pos1;
	//if (!pos1.InitMembers(-2, 4))//x가 0보다 작으므로 오류
	//	cout << "Initialization failed" << endl;
	//if(!pos1.InitMembers(2,4))
	//	cout << "Initialization failed" << endl;

	//Point pos2;
	//if(!pos2.InitMembers(5,9))
	//	cout << "Initialization failed" << endl;

	//Rectangle rec;
	//if(!rec.InitMember(pos2, pos1)) //pos1의 좌푯값이 pos2보다 크므로 오류
	//	cout << "Rectangle initialization failed" << endl;

	//if (!rec.InitMember(pos1, pos2)) //pos1의 좌푯값이 pos2보다 작으므로 정상출력
	//	cout << "Rectangle initialization failed" << endl;
	//
	//rec.ShowRecInfo();

	//----------------------------------------------------

	//생성자 버전
	Rectangle rec(1, 1, 5, 5);
	rec.ShowRecInfo();



	//----------------------------------------------------
	////문제 4-1. 과일 판매 시뮬레이션에 '사과 구매 목적으로 0보다 작은 수 전달 불가' 조건 추가
	////안정성 높이기 위해 일부 함수 const 선언
	//FruitSeller seller;
	//seller.InitMember(1000, 20, 0);

	//FruitBuyer buyer;
	//buyer.InitMember(5000);
	//buyer.BuyApples(seller, -100); //과일 구매

	//cout << "FruitSeller state" << endl;
	//seller.ShowSalesResult();
	//cout << "FruitBuyer state" << endl;
	//buyer.ShowBuyResult();

	//생성자 버전
	////초기화 함수 쓸 필요 없이 생성자로 바로 초기화
	//FruitSeller seller(1000, 20, 0);

	//FruitBuyer buyer(5000);

	//buyer.BuyApples(seller, 2000); //과일 구매

	//cout << "FruitSeller state" << endl;
	//seller.ShowSalesResult();
	//cout << "FruitBuyer state" << endl;
	//buyer.ShowBuyResult();

	return 0;
}
