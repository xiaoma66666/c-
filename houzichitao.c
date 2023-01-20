#include<stdio.h>
int zhaitao(int n);
int main(){
    int n=zhaitao(1);
    printf("第一天摘了%d个桃子\n",n);
    
   
}
int zhaitao(int n){
    int a;
    if(n==10)
    {
        return 1;
    }
    else
    {
        return (zhaitao(n+1)+1)*2;
    }

}