#include<stdio.h>
void main(){
   long int a,b;
    float x,y,z;
    a=32767;a=a+1;
    b=-32768;b=b-1;
    printf("%d%d",&a,&b);
    x=3.45;
    y=-7.689;
    z=x+y;
    a=x;
    b=y;
    printf("%f,%d,%d\n",z,a,b);
}