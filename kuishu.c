#include <stdio.h>

int main () {
    // 请在此处完成你的程序
    int n,i,j,s=0;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
    
        for(j=1;j<i;j++)
        {
            if(i%j==0)
            {s=s+j;}
        }
        if(s<n){
                printf("%d\n",i);
    }
    }
    return 0;
}