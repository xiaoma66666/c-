//将任意输入的一个数插入一个有序数列中，使得该序列在插入数据后仍然有序。
#include<stdio.h>
int main(){
    int a[7]={1,6,8,25,33};
    int i,n;
    scanf("%d",&n);
    for(i=0;i<5;i++)
    {
        if(n>a[i]&&i==4){
            a[5]=n;
        }
        else if(n<=a[i])
        {
            for(int j=4;j>=i;j--)
            {
                a[j+1]=a[j];
            }
            a[i]=n;
            break;
        }
    }
    for(int i=0;i<7;i++)
    printf("%d\t",a[i]);
    return 0;
}