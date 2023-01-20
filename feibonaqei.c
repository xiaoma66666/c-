#include<stdio.h>
long fibonacci(long n) {
    if(n == 1 || n == 2)    return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main(){
    long n=20,i=1;
    for ( i = n; i>=1; i--)
    {
       printf("%d\t",fibonacci(i));
       if (i%5==0)
       {
        printf("\n");
       }
       
    }
    
  
    return 0;}