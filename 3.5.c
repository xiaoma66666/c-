#include<stdio.h>
#include<math.h>

void fun1(int a);
int main(){
    void fun1(int a);
    int a;
    scanf("%d",&a);
    fun1(a);
    return 0;
}


void fun1(int a){
    int i,k;
    k=sqrt(a);
    for(i=2;i<=k;i++){
    if(a%i==0)
        break;}
    if (i<=k)
       printf("这不是一个素数\n");
    else
        printf("这是一个素数\n");
   
   
}