#include<stdio.h>//将输入的字符串s1复制到另一字符串s2中。
#include<string.h>
int main(){
        char s1[10];
        char s2[20];
        printf("输入的字符串s1是:");
        gets(s1);
        strcpy(s2,s1);
        printf("复制后的s2字符串s2是:");
       puts(s2);
}