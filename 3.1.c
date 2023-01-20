#include<stdio.h>
int yue(int a,int b);
int bei(int a,int b);
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("最大公约数:%d\n最小公倍数:%d",yue(a,b),bei(a,b));
    
     return 0;
}



int yue(int a,int b){
    int t;
    while (t!=0)
    {
       t=a%b;
       a=b;
       b=t;
    }
    
    return a;
}
int bei(int a,int b){
    int i;
    i= yue(a,b); 
    return a*b/i;
}