#include <stdio.h>

int main () {
    int n,i,c,b;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        b=0;
        for(c=1;c<i;c++)
        {
            if(i%c==0)
            {
               b+=c; 
            }
        }
            if(b==i)
            {
                printf("%d\n",i);
            }   
    }
    return 0;
}