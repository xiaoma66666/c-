#include<stdio.h>
#include<math.h>
int main(){
    float d=300000,p=6000,r=0.01,m;
    m=(log10(p)-log10(p-d*r))/log10(1+r);
    printf("%f\n",m);
    return 0;
}