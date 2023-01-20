//#include<stdio.h>
/*编程实现： 输入一个整数number（1 ≤ number ≤ 32），
计算序列1! + 2! + 3! + ··· + number!，并将计算结果输出。

//注：n!=1×2×3×…×(n-1)×n，n! 表示 n 的阶乘。
int main(){
    int i=1,n,sum=0,b=1;
    scanf("%d",&n);
    for(;i<=n;i++)
    {
        b=b*i;
        sum=sum+b;
    }
 printf("%d",sum);

}*/


//输入一个正整数number，计算序列1/1 - 1/2 + 1/3 - ··· +(-) 1/number，并将计算结果输出。


#include<stdio.h>
int main(){
    int i,n;
    float sum=0.0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(i%2!=0)
        {
            sum=sum+1.0/i;
        }
        else
        {
            sum=sum-1.0/i;
        }
    }
    printf("%f",sum);
}