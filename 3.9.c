#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[100],*p;
    p=a;
    for(int i=0;i<n;i++)
    {
        *(p+i)=i+1;
    }
    int j=0;
    int k=0;
    int m=0;
    while(m<n-1)
    {
        if(*(p+j)!=0)
        {
            k++;
        }
        if(k==3)
        {
            *(p+j)=0;
            m++;
            k=0;
        }
        j++;
        if(j==n)
            j=0;
    }
    for(int i=0;i<n;i++)
    {
        if(*(p+i)!=0)
            printf("剩下的是%d号",*(p+i));
    }

}