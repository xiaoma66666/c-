#include<stdio.h>
int main(){
    long fbhs(int a);
    int a,i=1;
    for(i=1;i<=40;i++)
    {
        printf("%10d\t",fbhs(i));
        if(i%5==0)
        printf("\n");
    }

}




long fbhs(int a){
    if(a==1||a==2)
    return 1;
    else
    return fbhs(a-1)+fbhs(a-2);
}