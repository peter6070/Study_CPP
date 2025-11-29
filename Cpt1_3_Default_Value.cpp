//1-3 매개변수의 디폴트 값
#include <iostream>

int FuncOne(int num = 7){
    return num + 1;
}

 int main(void) {
     
     std::cout << FuncOne() << std::endl;


     return 0;
 }