#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp;                                   //定义文件指针
    char ch,filename[10];                                                                                       
    printf("请输入所用的文件名:");
    scanf("%s",&filename);                      //输入文件名    
    fp=fopen(filename,"w");                     
    getchar();                                  //用来消化最后输入的回车符
    if(fp==NULL){
        printf("文件不存在");               //如果打开出错就输出文件不存在
       exit(0);                             //终止程序
    }
    printf("请输入一个准备存储到磁盘的字符串以'#'结束");
    ch=getchar();                           //接收从键盘输入的第一个字符
    while(ch!='#'){                             //当输入#时结束循环
        fputc(ch,fp);                       //向磁盘文件输出一个字符
        putchar(ch);                                //在屏幕上显示字符
        ch=getchar();                       //在接收从键盘输入的第一个字符
    }
    fclose(fp);                             //关闭文件
    putchar('\n');                              //向屏幕输出一个换行符
    return 0;           
}