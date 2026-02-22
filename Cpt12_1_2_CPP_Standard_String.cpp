#include <iostream>
#include <cstring>
using namespace std;

//string 클래스
class String {
private:
	int len;
	char* str;
public:
	String();
	String(const char* ref);
	String(const String& ref);
	~String();
	String& operator=(const String& ref);
	String& operator+=(const String& ref);
	bool operator==(const String& ref);
	String operator+(const String& ref);

	//<< 연산자 오버로딩
	friend ostream& operator<<(ostream& os, const String& ref);
	//>> 연산자 오버로딩
	friend istream& operator>>(istream& is, String& ref);
};
//생성자
String::String() {
	len = 0;
	str = NULL;
}
//생성자
String::String(const char* _str) { //깊은복사
	len = strlen(_str)+1;
	str = new char[len];
	strcpy_s(str, len, _str);
}
//복사 생성자
String::String(const String& ref) { //깊은복사
	len = ref.len;
	str = new char[len];
	strcpy_s(str, len, ref.str);
}
//소멸자
String::~String() {
	if(str!=NULL) //문자열이 비어있지 않으면(값이 있다면)
		delete[] str;
}

//대입 연산자
String& String::operator=(const String& ref) {
	if (str != NULL)
		delete[] str;
	len = ref.len;
	str = new char[len];
	strcpy_s(str, len, ref.str);
	return *this;
}
//+ 연산자 오버로딩
//참조값이 아닌 새로운 객체를 반환하기 때문에 반환형에 참조자가 붙지 않음
String String::operator+(const String& ref) {
	char* tempstr = new char[len+ref.len-1]; //두 문자열 뒤에는 null 문자가 포함되어있어 하나를 지우기 위해 -1
	strcpy_s(tempstr, len + ref.len - 1, str);
	strcat_s(tempstr, len + ref.len - 1, ref.str);

	String temp(tempstr); //객체 생성(두 문자열을 더한 임시 문자열 객체 넘겨줌)
	delete[] tempstr; // 임시 문자열 삭제
	return temp; //임시 객체 반환
}

//+= 연산자 오버로딩
String& String::operator+=(const String& ref) {
	//len += (ref.len - 1); //두 문자열의 길이를 합친 길이
	//char* tempstr = new char[len]; // 합쳐진 길이만큼 임시 문자열 객체 생성
	//strcpy_s(tempstr, len, str); //임시 문자열에 str 문자열을 복사
	//strcat_s(tempstr, len, ref.str); //임시 문자열과 ref.str 문자열 결합

	//if (str != NULL)
	//	delete[] str;
	//str = tempstr; //str에 임시 문자열 대입

	//+ 연산자를 이용해 간단하게 정의 가능(대신 덧셈 과정에서 객체가 추가로 생성됨)
	*this = *this + ref;
	return *this;
}

//== 연산자 오버로딩
bool String::operator==(const String& ref) {
	return strcmp(str, ref.str) ? false : true;
}

//<< 연산자 오버로딩
ostream& operator<<(ostream& os, const String& ref) {
	os << ref.str;
	return os;
}
//>> 연산자 오버로딩
istream& operator>>(istream& is, String& ref) {
	char str[100];
	is >> str;
	ref = String(str);
	return is;
}

int main(void) {
	String str1 = "I like";
	String str2 = "string class";
	String str3 = str1 + str2; //string 객체간 덧셈연산 가능(operator+ 연산자 오버로딩 되어있음)

	cout << str1 << endl; //string 클래스가 << 연산자에 대해서도 오버로딩됨
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2; //+= 연산의 결과로 두 문자열이 합쳐져 str1에 저장됨
	if (str1 == str3) //str1과 str2의 덧셈연산으로 생성된 str3는 위에서 +=연산을 진행한 str1과 동일
		cout << "Equal string" << endl;
	else
		cout << "Not Equal string" << endl;

	String str4;
	cout << "Enter string: ";
	cin >> str4; // >> 연산자 오버로딩
	cout << "Your string: " << str4 << endl;

	return 0;
}