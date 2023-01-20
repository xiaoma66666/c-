#include<stdio.h>//阶乘和计算
int main(){
    int i,n;
    float sum=0.0,b=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        b=b*i;
        sum=sum+b;
    }
    printf("%f",sum);
}