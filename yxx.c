#include<stdio.h>
int main(){
    int x,y;
    scanf("%d",&x);
    y=x*x;
    printf("%d=%d*%d\n",y,x,x);
    printf("%d*%d=%d\n",x,x,y);
    return 0;
}