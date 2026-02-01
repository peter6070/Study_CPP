#include <iostream>
using namespace std;

//class First {
//public:
//	//가상 함수 선언
//	virtual void MyFunc() { cout << "FirstFunc" << endl; }
//};
//
//class Second :public First {
//public:
//	virtual void MyFunc() { cout << "SecondFunc" << endl; }
//};
//
//class Third : public Second {
//public:
//	virtual void MyFunc() { cout << "ThirdFunc" << endl; }
//};

//-------------------------------------------------

//Employee는 기초 클래스로서만 의미를 가질 뿐, 객체 생성을 목적으로 정의된 클래스가 아님
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
	//가상함수로 선언함으로써 함수 오버라이딩이 되더라도 포인터가 가리키는 객체를 기준으로 함수가 선언되도록 함
	virtual int GetPay() const = 0; //순수 가상함수(=0)
	
	virtual void ShowSalaryInfo() const = 0; //순수 가상함수
};

//정규직 직원
class PermanentWorker :public Employee {
	int salary; //매달 지불 급여액
public:
	PermanentWorker(const char* name, int money)
		: Employee(name), salary(money) {
	}
	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "Salary: " << GetPay() << endl << endl;
	}
};

//임시직(시급 x 일한 시간)
class TemporaryWorker : public Employee {
private:
	int workTime; //이 달에 일한 시간 합계
	int payPerHour; //시급
public:
	TemporaryWorker(const char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay) {
	}
	void AddWorkTime(int time) {
		workTime += time;
	}
	int GetPay() const {
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "Salary: " << GetPay() << endl << endl;
	}
};

//영업직
class SalesWorker : public PermanentWorker {
private:
	int salesResult; //월 판매실적
	double bonusRatio; //상여금 비율
public:
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {
	}
	void AddSalesResult(int value) {
		salesResult += value;
	}
	int GetPay() const {
		return PermanentWorker::GetPay() //PermanentWorker의 GetPay함수 호출
			+ (int)(salesResult * bonusRatio);
	}
	//PermanentWorker에도 같은 함수가 존재하지만 GetPay함수의 내용이 서로 다르기 때문에
	// 따로 분리하여 각각 선언해줘야 적절한 값이 출력됨
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "Salary: " << GetPay() << endl << endl;
	}
};

namespace RISK_LEVEL {
	enum {
		//단위: %
		RISK_A = 30,
		RISK_B = 20,
		RISK_C = 10
	};
};

//문제1. 영업직 위험수당 챙기기
class ForeignSalesWorker : public SalesWorker{
private:
	//double riskRatio;
	const int riskLevel;
public:
	ForeignSalesWorker(const char* name, int money, double ratio, int risk)
		: SalesWorker(name, money, ratio), riskLevel(risk) {	}
	
	int GetRiskPay() const {
		return (int)(SalesWorker::GetPay() * (riskLevel / 100.0));
	}
	int GetPay() const {
		return SalesWorker::GetPay() + GetRiskPay();
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "Salary: " << SalesWorker::GetPay() << endl;
		cout << "Risk Pay: " << GetRiskPay() << endl;
		cout << "Sum: " << GetPay()<< endl << endl;
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
	//Third* tptr = new Third();
	//Second* sptr = tptr;
	//First* fptr = sptr;

	//fptr->MyFunc(); //First 포인터 형이므로 First 클래스의 MyFunc 함수 실행(virtual 키워드 없을 때)
	//sptr->MyFunc();
	//tptr->MyFunc();

	//delete tptr;
	//--------------------------------------------------------

	EmployeeHandler handler;

	//Employee* emp = new Employee("Lee"); //순수 가상함수를 선언함으로써 추상클래스가 되었으므로 컴파일 오류 발생

	////정규직 등록
	//handler.AddEmployee(new PermanentWorker("KIM", 1000));
	//handler.AddEmployee(new PermanentWorker("LEE", 1500));

	////임시직 등록
	//TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	//alba->AddWorkTime(5);
	//handler.AddEmployee(alba);

	////영업직 등록
	//SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	//seller->AddSalesResult(7000);
	//handler.AddEmployee(seller);

	//---------------------------------------------
	//문제1. 영업직 위험수당 챙기기
	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1,RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	//이번 달 지불할 급여
	handler.ShowAllSalaryInfo();

	//이번 달 지불할 총 급여
	handler.ShowTotalSalary();


	return 0;
}