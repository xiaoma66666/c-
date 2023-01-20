#include <stdio.h>

int main () {
float h,w,b;
    scanf("%f%f",&h,&w);
    b=(h-100)*0.9 ;   
    if(w<b*1.1&&w>b*0.9)
        printf("perfect body");
    else if(w>=b*1.1)
        printf("toofat");
    else if(w<=b*0.9)
        printf("tooskinny");
        
    
    return 0;
}