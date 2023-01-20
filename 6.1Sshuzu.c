#include<stdio.h>
int main()
{
    int i,a[10];
    for ( i = 0; i <= 9; i++)//用int a[10]定义数组时最大的下标值为9,不存在数组a[10].
    {
        a[i]=i;
    }
    for ( i = 9; i >=0; i--)
    {
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}