#include<stdio.h>
int main() {
    double q;
    int a=q/10;
    char g;
    scanf("%f",&q);
    switch (a)
    {
    case 10:
    case 9:g='a';break;
    case 8:g='b';break;
    case 7:g='c';break;
    case 6:g='d';break;
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
    case 0:g='e';
    
    
       
    }printf("%c\n",g);
    return 0;

}