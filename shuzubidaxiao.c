#include<stdio.h>
int main(){
int a[10]={1,8,45,96,2,645,95,65,11,5},max;
int i;
max=a[0];

for(int i=0;i<10;i++)
{
    if(a[i]>max)
    {
        max=a[i];

    }
}
printf("%d",max);
return 0;
}