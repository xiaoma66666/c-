#include<stdio.h>
int main(){
    int a[10];
    int i,n=10,t,j;
    printf("请输入10十个数:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\n");
    for(j=0;j<9;j++){  
    for(i=0;i<9;i++)
    {
        if(a[i]>a[i+1])
            {
            t=a[i];
            a[i]=a[i+1];
            a[i+1]=t;
            }
    }
    }
        printf("交换后的数为:");
    for ( i = 0; i <10; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
    
}