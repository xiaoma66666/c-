#include<stdio.h>
#include<math.h>
int main(){
    float r1,r2,r3,r0,r5,p1,p2,p3,p4,p5,i;
    i=1000;
    r1=0.015;
    r2=0.021;
    r3=0.0275;
    r5=0.03;
    p1=i*((1+r5*5));
    p2=i*(1+2*r2)*(1+3*r3);
    p3=i*(1+3*r3)*(1+2*r2);
    p4=pow(1+r1,5)*i;
    p5=i*pow(1+r0/4,4*5);
    printf("p1=%f\n",p1);
    printf("p2=%f\n",p2);
    printf("p3=%f\n",p3);
    printf("p4=%f\n",p4);
    printf("p5=%f\n",p5);
    return 0;
}