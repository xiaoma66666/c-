#include<stdio.h>
int main(){
    int m,n;
    scanf("%d",&m);
    if (m>=0&&m<=100){
        for (m; m<=100; m++)
        {n=n+m;
        printf("%d\n",n);
        }
    }
    else printf("不满足\n");
    return 0;
}