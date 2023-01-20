#include<stdio.h>
#include<math.h>
int  main(){
    float r,h,c,s1,s2,v1,v2;
    float PI=3.1415926;
    printf("请输入r和h:");
    scanf("%f%f",&r,&h);
    c=2*PI*r;
    s1=PI*r*r;
    s2=4*PI*r*r;
    v1=(4/3)*PI*r*r*r;
    v2=s1*h;
    printf("圆的周长:%10.2f\n圆的面积:%10.2f\n圆球的表面积:%10.2f\n圆球体积%10.2f\n圆柱体积%10.2f\n",c,s1,s2,v1,v2);
    return 0;
}