#include<stdio.h>
int main(){
    int x=3,y=2;
    int c=(y++==--x)?y++:x++;
    printf("%d",c);
    return 0;}
    