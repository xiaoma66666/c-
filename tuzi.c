
#include <stdio.h>

double reciprocal (double number) {
    // 请在此处编写子函数代码
    double b;
    if(number==0){
        printf("没有倒数");
    return 0;
    }
    else{
        b=1/number;
        return b;
    }    
    
    
}

int main () {
    double number, number1 = 10;
    number = reciprocal(number1);
    printf("%f\n", number);
    return 0;
}