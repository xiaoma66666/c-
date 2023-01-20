#include<stdio.h>
float max=0,min=0;
int main(){
    float average(float array[],int n);
    float ave,score[10];
    int i;
    printf("请输入十个数字:");
    for ( i = 0; i < 10; i++)
    {
      scanf("%f",&score[i]);
    }
    ave=average(score,10);
    printf("max=%7.2f\nmin=%7.2f\nave=%7.2f",max,min,ave);

    
    
}
float average(float array[],int n)
{
    int i;
    float aver,sum=array[0];
    min=max=array[0];
    for(i=1;i<n;i++)
    {
        if (array[i]>max)
        {
           max=array[i];
        }
       else if (array[i]<min)
        {
            min=array[i];
        }
        sum+=array[i];
    }
    aver=sum/n;
    return aver;

}