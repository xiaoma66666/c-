#include <stdio.h>

int main () {
    // 请在此处完成你的程序
    int n;
    scanf("%d", &n);
    int sum = 0, count = 0;
    while (n != 0) {
        if (n > 0) {
        	sum += n;
        	count += 1;
        }
        scanf("%d", &n);
    }
    printf("sum: %d; count: %d\n", sum, count);
    return 0;
}