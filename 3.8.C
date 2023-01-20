#include<stdio.h>
    int move(int *a, int n, int m)
{
    int t[100], i;
    for(i = 0; i < n; i++)
        t[i] = a [i];
    for(i = 0; i < m; i++)
        a[i] = t[n - m + i];
    for(i = m; i < n; i++)
        a[i] = t[i - m];
        return a[i];
}

int main(){
    int a[20], n, m, i;
    printf("整数个数:");
    scanf("%d", &n);
    printf(" m为:");
    scanf("%d", &m);
    for(i = 0; i < n; i++)
        scanf("%d", a+i);
    move(a, n, m);
    for(i = 0; i < n; i++)
        printf("%d\t", *(a+i));

}
