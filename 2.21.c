#include<stdio.h>
int main() {
	int g;
	int n[50];
	printf("请输入学生成绩:");
	for(g=0;g<50;g++){
       scanf("%d",&n[g]);
		if (n[g]>= 80)
			printf("学号%d\t\t\t成绩%d",g+1, n[g]);
		else 
         printf("error");}
	return 0;
}