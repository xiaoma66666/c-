#include <stdio.h>
int main() {
	int y = 18, i = 0, j, a[8];
	do {
		a[i] = y % 2;
		i++;
		y = y / 2;
	} while (y >= 1);
	for (j = i - 1; j > 0; j--)
		printf("%d", a[j]);
		printf("\n");
		return 0;

}
