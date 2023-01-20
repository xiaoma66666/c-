#include<stdio.h>
int main()
{
    float score[6][5]={{78,85,83, 65},{88,91,89,93},{72,65,54,75},{86,88,75,60},{69,60,50,72}};
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            score[i][4]=score[i][4]+score[i][j];//第i个学生的总成绩
            score[5][j]=score[5][j]+score[i][j];//第j门课程的总成绩
        }
        score[i][4]/=4;//第i个学生的平均成绩
    }
    for(j=0;j<4;j++)
    {
        score[5][j]/=5;//第j门课的课程平均成绩
    }
    printf("学生编号  课程1   课程2   课程3   课程4  平均分\n");
    for(i=0;i<5;i++)
    {
        printf("学生%d\t",i+1);
        for ( j = 0; j <5; j++)
        {
           printf("%6.1f\t",score[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------"); 
	printf("\n课程平均 ");
    for(j = 0; j < 4; j++) 
	   printf("%6.1f\t", score[5][j]);
	printf("\n"); 
	
	return 0;
}