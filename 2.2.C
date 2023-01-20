#include <stdio.h>
 
int main()
{
	int i;
	int arr[50];
	printf("请输入一批成绩：\n");
	for( i = 0; i < 50; i++ )
	{
		scanf("%d",&arr[i]);
		if( arr[i] >= 80 )
		{
			printf("学号：%d 成绩：%d ",i+1,arr[i]);
		}
	}
	return 0;
}