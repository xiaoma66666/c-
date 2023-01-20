#include<stdio.h>
int main(){
    float h,w,t;
    scanf("%f%f",&h,&w);
    t=w/(h*h);
    if(t<18)
    printf("偏瘦\n");
    else if(t<=25)
    printf("正常\n");
    else if (t<27)
    printf("超重\n");
    else
    printf("肥胖\n");
    return 0;
}

