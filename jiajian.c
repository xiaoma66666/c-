#include<stdio.h>
int main(){
    int i;
    double sum=0.0;
    for(i=1;i<=100;i++){
        if(i%2==1){
            sum=sum-1.0/i;
        }
        else{
            sum+=1.0/i;
        }

    }
    printf("%f",sum);
    return 0;
}