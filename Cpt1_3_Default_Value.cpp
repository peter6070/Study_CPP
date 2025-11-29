#include <iostream>

//1-3 매개변수의 디폴트 값
//int Adder(int num1 = 1, int num2 =2){
//    return num1 + num2;
//}

//함수 선언
//int Adder(int num1 = 1, int num2 = 2);

//부분적 디폴트 값 설정
//int BoxVolume(int length, int width = 1, int height = 1);

int BoxVolume(int length, int width, int height) {
    return length * width * height;
}
int BoxVolume(int length, int width) {
    return length * width * 1;
}
int BoxVolume(int length) {
    return length * 1*1;
}

int main(void) {

    //std::cout << Adder() << std::endl; //매개변수 아무것도 없으므로 기본값으로 출력(1+2=3)
    //std::cout << Adder(5) << std::endl; //매개변수 하나이므로 num1=5(5+2=7)
    //std::cout << Adder(3, 5) << std::endl; //매개변수 두 개 이므로 num1=3,num2=5(3+5=8)

    /*std::cout <<"[3,3,3] : "<< BoxVolume(3, 3, 3) << std::endl;
    std::cout <<"[5,5,D] : "<< BoxVolume(5,5) << std::endl;
    std::cout <<"[5,D,D] : "<< BoxVolume(7) << std::endl;*/
    //std::cout <<"[D,D,D]"<< BoxVolume() << std::endl;
    //모든 매개변수에 디폴트 값이 지정된 것이 아니기 때문에, 인자를 전달하지 않는 형태의 함수 호출은 에러

    //문제1-1. 매개변수의 디폴트 값 지정 -> 함수 오버로딩
    std::cout << "[3,3,3] : " << BoxVolume(3, 3, 3) << std::endl;
    std::cout << "[5,5,D] : " << BoxVolume(5, 5) << std::endl;
    std::cout << "[5,D,D] : " << BoxVolume(7) << std::endl;


    return 0;
}

////함수 정의

//int Adder(int num1, int num2) {
//    return num1 + num2;
//}

//int BoxVolume(int length, int width, int height) {
//    return length * width * height;
//}