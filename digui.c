#include<stdio.h>
int main(){
    int age(int a);
    int i;
    printf("请输入第几位同学:\n");
    scanf("%d",&i);
    printf("%d\n",age(i));
    return 0;

}
int age(int a){
    int c;
    if(a==1){
        c=10;
    }
    else
    {
        c=age(a-1)+2;
    }
    return c;
    
}