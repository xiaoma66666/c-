#include<stdio.h>
int main(){
    char c[][5]={{' ',' ','*',' ',' '},{' ','*',' ','*',' '},{'*',' ',' ',' ','*'},{' ','*',' ','*',' '},{' ',' ','*',' ',' '}};
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++){
            printf("%c",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}