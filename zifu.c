#include<stdio.h>
/// @brief 
/// @return 
int main(){
    int c1,c2;
    printf("请输入两个字符:");
    c1=getchar();
    c2=getchar();
    printf("用putchar输出的结果为:");
    putchar(c1);
    putchar(c2);
    printf("\n");
    printf("用printf输出的结果为:");
    printf("%c%c\n",c1,c2);
    return 0;
    

}