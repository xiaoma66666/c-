/*医务工作者通过广泛调查，按体重指数来划分一个人的肥胖程度。其中，体重指数t=w/(h*h)（w为体重，单位为kg；h为身高，单位为m）。
当t<18时，偏瘦；当18<=t<=25时，正常；当25<t<27时，超重；当t>=27时，肥胖；
1) 定义三个变量w、h、t，用w和h分别存放体重和身高。
2) 用t表示体重指数；3) 根据t的值做出判断。*/
#include<stdio.h>
int main(){
     float h,w,t;
     scanf("%f%f",&h,&w);
     t=w/(h*h);
     switch (t)
     {
        case 18:printf("偏瘦");break;
        case 25:printf("正常");break;
        case 27:printf("超重");break;
        default:printf("肥胖");break;
   
        
       
     }
}