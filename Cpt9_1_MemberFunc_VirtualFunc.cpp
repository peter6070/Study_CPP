#include <iostream>
using namespace std;

//class Data {
//private:
//	int data;
//public:
//	Data(int num) :data(num) {}
//	void ShowData() { cout << "Data: " << data << endl; }
//	void Add(int num) { data += num; }
//};

//Data 클래스를 흉내 낸 영역
typedef struct Data {
	int data;
	//함수 포인터 변수가 구조체 멤버로 등장(함수 정의)
	void (*ShowData)(Data*);
	void (*Add)(Data*, int);

} Data;

//함수 선언
void ShowData(Data* THIS) { cout << "Data: " << THIS->data << endl; }
void Add(Data* THIS, int num) { THIS->data += num; }

int main(void) {
	/*Data obj(15);
	obj.Add(17);
	obj.ShowData();*/

	//구조체(객체) 생성
	Data obj1 = { 15,ShowData,Add };
	Data obj2 = { 7,ShowData,Add };

	obj1.Add(&obj1, 17);
	obj2.Add(&obj2, 9);
	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);

	return 0;
}