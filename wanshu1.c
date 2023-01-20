#include <stdio.h>
int main(){
    int i,n,b,j;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        b=0;
        for(j=1;j<i;j++)
        {
            if(i%j==0)
            b+=j;
        }
        if(b==i)
        {
            printf("%d\n",i);
        }
    }
    
}