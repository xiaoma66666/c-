#include<stdio.h>
#include<math.h>
int main(){
    float money,year,rate,interst;
    scanf("%f%f%f",&money,&year,&rate);
    interst=money*pow(1+rate,year)-money;
    printf("interest=%.2f",interst);
    return 0;
}