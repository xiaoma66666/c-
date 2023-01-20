#include<stdio.h>
int fun1(int n);
int main(){
    int n;
    int fun1(int n);
    int c;
    scanf("%d",&n);
    printf("%d",fun1(n));

}
int fun1(int n){
    int i,sum=0;
    for(i=1;i<=n;i++)
    {
        sum+=i;
    }
    return sum;
}