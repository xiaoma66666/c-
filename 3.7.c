#include<stdio.h>
int main(){
    int a=10;
    char c='Q';
    int * pointer_1, * pointer_2;
    pointer_1=&a;
    pointer_2=&c;
    printf("* pointer_1=%x,* pointer_2=%x\n",* pointer_1,* pointer_2);
}