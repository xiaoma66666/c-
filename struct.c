#include<stdio.h>
int main(){
    //结构体类型
    struct Student
    {
       char name[10];
        int age;
        int care;
    };
    struct Student b={"MaChen",18,100};;
    printf("name:%s\nage:%d\ncare:%d",b.name,b.age,b.care);
}