#include <iostream>
using namespace std;

//회사 급여 관리 시스템


//정규직 직원
class PermanentWorker {
	char name[20];
	int salary; //매달 지불 급여액
public:
	PermanentWorker(const char* name, int money) : salary(money) {
		strcpy_s(this->name, 20, name);
	}
	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const {
		cout << "name: " << name << endl;
		cout << "salary: " << GetPay() << endl << endl;
	}
};

//객체 저장 및 관리
//기능 처리를 실제로 담당하는 클래스: 컨트롤 클래스, 핸들러 클래스
class EmployeeHandler {
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {}
	//새 직원정보 등록
	void AddEmployee(PermanentWorker* emp) {
		empList[empNum++] = emp;
	}
	//모든 직원 이번 달 급여 출력
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	//이번 달 급여 총액 출력
	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		cout << "Total Salary: " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};


int main(void) {
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