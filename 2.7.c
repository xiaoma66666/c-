#include<stdio.h>
#include<string.h>
int main(){
    char str[20];
    printf("输入的字符串是:");
    gets(str);
    int i,word=0,num=0;
    while(str[i]!='\0')
        {
            if(str[i]==' ')
            {
                word=0;
            }
            else if(word==0)
            {
                word=1;num++;
            }
            i++;
        }
    printf("这个字符串共有单词%d个",num);
    return 0;
    
}