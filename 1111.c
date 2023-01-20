#include<stdio.h>
int main()
{
	
	int num;
	printf("请输入一个不大于5位的正整数: ");
	scanf("%d",&num);
	if (num<0 || num >99999){
		printf("输入的数据不符合规则!\n");
		return -1;
	} 
	if(num > 10000){
		printf("%d\t",num/10000);
	}	
	if(num > 1000){
		printf("%d\t",num % 10000 / 1000);
	}	
	if(num>100){
		printf("%d\t",num % 1000 / 100);
	}	
	if(num>10){
		printf("%d\t",num %100 / 10);
	}	
	printf("%d \n",num % 10);
	return 0;
}