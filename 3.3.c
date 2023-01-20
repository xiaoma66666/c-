#include<stdio.h>
void fun1();
void main(){
    fun1();
}
void fun1(){
    int i=1,sum=0;
    for(;i<=100;i++){
        sum+=i;
    }
    printf("%d",sum);
}