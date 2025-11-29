#include <iostream>

int FuncOne(int num = 7){
    return num + 1;
}

//1-3 매개변수의 디폴트 값
 int main(void) {
     
     FuncOne();

     return 0;
 }