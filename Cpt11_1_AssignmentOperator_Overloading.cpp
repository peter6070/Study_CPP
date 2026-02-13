#include <iostream>
using namespace std;

//class First {
//private:
//	int num1, num2;
//public:
//	First(int n1=0, int n2=0):num1(n1), num2(n2){}
//	void ShowData() { cout << num1 << ", " << num2 << endl; }
//	//자동으로 삽입되어 작성 필요X
//	First& operator=(const First& ref) {
//		cout << "First& operator=()" << endl;
//		num1 = ref.num1;
//		num2 = ref.num2;
//		return *this;
//	}
//};

//class Second {
//private:
//	int num3, num4;
//public:
//	Second(int n3=0, int n4=0):num3(n3), num4(n4){}
//	void ShowData() { cout << num3 << ", " << num4 << endl; }
//
//	//호출 확인을 위한 디폴트 대입연산자
//	Second& operator=(const Second& ref) {
//		cout << "Second& operator=()" << endl;
//		num3 = ref.num3;
//		num4 = ref.num4;
//		return *this;
//	}
//};

//class Second :public First {
//private:
//	int num3, num4;
//public:
//	Second(int n1, int n2, int n3, int n4) 
//		: First(n1, n2), num3(n3), num4(n4) {}
//	void ShowData() { 
//		First::ShowData();
//		cout << num3 << ", " << num4 << endl; 
//	}
//
//	Second& operator=(const Second& ref) {
//		cout << "Second& operator=()" << endl;
//		First::operator=(ref); //기초 클래스 대입 연산자 호출
//		num3 = ref.num3;
//		num4 = ref.num4;
//		return *this;
//	}
//};
//---------------------------------------------------------

//class Person {
//	char* name;
//	int age;
//public:
//	Person(const char* myname, int myage) {
//		int len = strlen(myname) + 1;
//		name = new char[len];
//		strcpy_s(name, len, myname);
//		age = myage;
//	}
//	void ShowPersonInfo() const {
//		cout << "Name: " << name << endl;
//		cout << "Age: " << age << endl;
//	}
//	~Person() {
//		delete[] name;
//		cout << "Called Destructor" << endl;
//	}
//	//대입 연산자(깊은 복사를 하기 위함)
//	Person& operator=(const Person& ref) {
//		delete[] name; //메모리 누수를 막기 위한 메모리 해제 연산
//		int len = strlen(ref.name) + 1;
//		name = new char[len];
//		strcpy_s(name, len, ref.name);
//		age = ref.age;
//		return *this;
//	}
//};

//문제1. 클래스 간 깊은 복사(대입 연산자, 복사 생성자 정의)
//class Gun {
//private:
//	int bullet;
//public:
//	Gun(int bnum) : bullet(bnum) {}
//	void Shot() {
//		cout << "Bang!" << endl;
//		bullet--;
//	}
//};
//
//class Police {
//private:
//	int handcuffs;
//	Gun* pistol;
//public:
//	Police(int bnum, int bcuff) : handcuffs(bnum) {
//		if (bnum > 0)
//			pistol = new Gun(bnum);
//		else
//			pistol = NULL;
//	}
//	void PutHandcuff() {
//		cout << "SNAP!" << endl;
//		handcuffs--;
//	}
//	void Shot() {
//		if (pistol == NULL)
//			cout << "No Armo!" << endl;
//		else
//			pistol->Shot();
//	}
//	~Police() {
//		if (pistol != NULL)
//			delete pistol;
//	}
//	//대입 연산자
//	Police& operator=(const Police& ref) {
//		cout << "Police& operator=(const Police& ref)" << endl;
//		if(pistol!=NULL)
//			delete pistol;
//
//		if (ref.pistol != NULL)
//			pistol = new Gun(*(ref.pistol)); //ref.pistol이 가리키고 있는 주소 -> 복사되는 Gun 객체의 pistol 개수
//		else
//			pistol = NULL;
//
//		handcuffs = ref.handcuffs;
//		return *this;
//	}
//	//복사 생성자
//	Police(const Police& copy) : handcuffs(copy.handcuffs) {
//		cout << "Police(const Police& copy)" << endl;
//		if (copy.pistol != NULL)
//			pistol = new Gun(*(copy.pistol));
//		else
//			pistol = NULL;
//	}
//};
//---------------------------------------------------------

//문제2. Book 클래스 깊은복사
class Book {
private:
	char* title;
	char* isbn; //국제표준도서번호
	int price;
public:
	Book(const char* _title, const char* _isbn, int _price)
		: price(_price) {
		int len = strlen(_title) + 1;
		title = new char[len];
		strcpy_s(title, len, _title);

		len = strlen(_isbn) + 1;
		isbn = new char[len];
		strcpy_s(isbn, len, _isbn);
	}
	void ShowBookInfo() {
		cout << "Title: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "Price: " << price << endl;
	}
	~Book() {
		delete[] title;
		delete[] isbn;
	}
	//대입 연산자
	Book& operator=(const Book& ref) {
		delete title;
		delete isbn;

		int len = strlen(ref.title) + 1;
		title = new char[len];
		strcpy_s(title, len, ref.title);

		len = strlen(ref.isbn) + 1;
		isbn = new char[len];
		strcpy_s(isbn, len, ref.isbn);

		price = ref.price;
		return *this;
	}
	//복사 생성자
	Book(const Book& ref) :price(ref.price) {
		delete []title;
		delete []isbn;

		int len = strlen(ref.title) + 1;
		title = new char[len];
		strcpy_s(title, len, ref.title);

		len = strlen(ref.isbn) + 1;
		isbn = new char[len];
		strcpy_s(isbn, len, ref.isbn);
	}
};

class EBook : public Book {
private:
	char* DRMKey; //보안관련 키
public:
	EBook(const char* _title, const char* _isbn, int _price, const char* _DRMKey)
		: Book(_title, _isbn, _price) {
		int len = strlen(_DRMKey) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, _DRMKey);
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "DRMKey: " << DRMKey << endl;
	}
	~EBook() {
		delete[] DRMKey;
	}
	//대입 연산자
	EBook& operator=(const EBook& ref) {
		Book::operator=(ref);

		delete[] DRMKey;

		int len = strlen(ref.DRMKey) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, ref.DRMKey);

		return *this;
	}
	//복사 생성자
	EBook(const EBook& ref) : Book(ref){ //Book 에 기본 생성자가 없으므로 ref 객체를 매개변수로 Book 복사생성자 호출
		int len = strlen(ref.DRMKey) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, ref.DRMKey);
	}
};

int main(void) {
	//First fsrc(111, 222);
	//First fcpy;
	//Second ssrc(333, 444);
	//Second scpy;
	//fcpy = fsrc; //-> fcpy.operator=(fsrc);
	//scpy = ssrc;
	//fcpy.ShowData();
	//scpy.ShowData();

	//First fob1, fob2;
	//Second sob1, sob2;
	//fob1 = fob2 = fsrc; //대입 연산자는 오른쪽에서 왼쪽으로 진행됨
	//sob1 = sob2 = ssrc;

	//fob1.ShowData();
	//fob2.ShowData();
	//sob1.ShowData();
	//sob2.ShowData();
	//---------------------------------------------------------
	//Person man1("Lee", 29);
	//Person man2("Yoon", 22);
	//man2 = man1; //얕은 복사로 인해 소멸자가 한번만 실행됨(대입 연산자 정의 안했을 경우)

	//man1.ShowPersonInfo();
	//man2.ShowPersonInfo();
	//---------------------------------------------------------
	/*Second ssrc(111, 222, 333, 444);
	Second scpy(0, 0, 0, 0);
	scpy = ssrc;
	scpy.ShowData();*/
	//---------------------------------------------------------
	// 
	//문제1. 클래스 간 깊은 복사(대입 연산자, 복사 생성자 정의)
	//Police pol1(5, 2);
	//Police pol2 = pol1; //복사 생성자 호출
	//pol2.PutHandcuff();
	//pol2.Shot();

	//Police pol3(2, 4);
	//pol3 = pol1; //대입 연산자 호출
	//pol3.PutHandcuff();
	//pol3.Shot();
	//---------------------------------------------------------

	//문제2. Book 클래스 깊은복사
	//대입 연산자
	EBook ebook1("Good C++ ebook", "555-12345-890-1", 10000, "fdx9wi8ikw");
	EBook ebook2("null", "null", 0, "null");
	ebook2 = ebook1;
	ebook2.ShowEBookInfo();
	cout << endl;
	EBook ebook3 = ebook1;
	ebook3.ShowEBookInfo();

	return 0;
}