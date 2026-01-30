#include <iostream>
#include <cstring>
using namespace std;

//class Person {
//public:
//	void Sleep() {
//		cout << "Sleep" << endl;
//	}
//};
//
//class Student : public Person {
//public:
//	void Study() {
//		cout << "Study" << endl;
//	}
//};
//
//class PartTimeStudent : public Student {
//public:
//	void Work() {
//		cout << "Work" << endl;
//	}
//};

//-------------------------------------------------

class Employee {
private:
	char name[100];
public:
	Employee(const char* name) {
		strcpy_s(this->name, 100, name);
	}
	void ShowYourName() const {
		cout << "name: " << name << endl;
	}
};

//정규직 직원
class PermanentWorker :public Employee {
	int salary; //매달 지불 급여액
public:
	PermanentWorker(const char* name, int money) 
		: Employee(name), salary(money) {}
	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

//객체 저장 및 관리
//기능 처리를 실제로 담당하는 클래스: 컨트롤 클래스, 핸들러 클래스
class EmployeeHandler {
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {}
	//새 직원정보 등록
	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	//모든 직원 이번 달 급여 출력
	void ShowAllSalaryInfo() const {
		/*for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();*/
	}
	//이번 달 급여 총액 출력
	void ShowTotalSalary() const {
		int sum = 0;
		/*for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();*/
		cout << "Total Salary: " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void) {
	//Person* ptr1 = new Student(); //Person을 상속한 Student 객체 생성
	//Person* ptr2 = new PartTimeStudent(); //Person을 상속한 Student를 상속한 PartTimeStudent 객체 생성
	//Student* ptr3 = new PartTimeStudent(); //Student를 상속한 PartTimeStudent 객체 생성
	//ptr1->Sleep();
	//ptr2->Sleep();
	//ptr3->Study();
	//delete ptr1; delete ptr2; delete ptr3;

	//---------------------------------------------------------

	EmployeeHandler handler;

	//직원등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1000));
	handler.AddEmployee(new PermanentWorker("JUN", 1000));

	//이번 달 지불할 급여
	handler.ShowAllSalaryInfo();

	//이번 달 지불할 총 급여
	handler.ShowTotalSalary();

	return 0;
}