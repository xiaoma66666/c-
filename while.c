#include<stdio.h>
int main(){
    int m,n;
    scanf("%d",&m);
    if (m>=0&&m<=100){
    while (m<=100)
    {n=n+m;
    m++;
    }
    printf("%d",n);}
    else printf("不满足\n");
    return 0;
    
}