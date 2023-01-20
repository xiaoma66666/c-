#include<stdio.h>
int main(){
    float h,w,t;
    scanf("%f%f",&h,&w);
    t=w/(h*h);
     if(t<18)
    t=1;
    else if(t<=25)
   t=2;
    else if (t<27)
    t=3;
    else
   t=4;
    switch (t)
    {
    case 1:printf("偏瘦\n");break;
    case 2: printf("正常\n");break;
    case 3: printf("超重\n");break;
    default:printf("肥胖\n");break;
    
    } return 0;}