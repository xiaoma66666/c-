#define NUM_std 5
#define NUM_course 4
#include <stdio.h>
int main()
{ 	int i,j;
	float score[NUM_std+1][NUM_course+1]={{78,85,83, 65},{88,91,89,93},{72,65,54,75},{86,88,75,60},{69,60,50,72}};
	for(i=0;i<NUM_std;i++)
	{	for(j=0;j<NUM_course;j++)
		{	score[i][NUM_course]+=score[i][j];
			score[NUM_std][j]+=score[i][j];  }
		score[i][NUM_course]/=NUM_course;    }
	for(j=0;j<NUM_course;j++)
		score[NUM_std][j]/=NUM_std;
	printf("\n");
printf("学生编号  课程1   课程2   课程3   课程4  平均分\n");
for(i=0;i<NUM_std;i++)
{
      printf("学生%d\t",i+1);
      for(j=0;j<NUM_course+1;j++)
	printf("%6.1f\t",score[i][j]);
      printf("\n");
}
for(j=0;j<8*(NUM_course+2);j++)
      printf("-");
printf("\n课程平均");
for(j=0;j<NUM_course;j++)
      printf("%6.1f\t",score[NUM_std][j]);
printf("\n");
return 0; }
