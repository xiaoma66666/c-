#include<stdio.h>
void fun1(int* a);
void fun2(int* a);
int main(void)
{
	int * a[10];

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}

	fun1(a);

	return 0;
}

void fun1(int* a)
{
	int i, j, max, min , n = 10 , t;

	max = min = a[0];

	for (i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}

		if (a[i] < min)
		{
			min = a[i];
		}

	}

	printf("max is %d , min is %d\n", max, min);


	for (i = 0; i < 10; i++)
	{
		if (a[i] == min)
		{
			t = a[i];
			a[i] = a[0];
			a[0] = t;
		}

		if (a[i] == max)
		{
			t = a[i];
			a[i] = a[n - 1];
			a[n - 1] = t;
		}
	}

	fun2(a);

}

void fun2(int* a)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
}