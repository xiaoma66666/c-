#include<stdio.h>
#include<math.h>
int main(){
    float a,b;
    scanf("%f",&a);
    if (a>=1000||a<0)
    {printf("请输入小于1000的正数\n");
    scanf("%f",&a);
    b=sqrt(a);
    }
    else {
        b=sqrt(a);
    }
    printf("a=%4.0f,b=%4.0f\n",a,b);
    return 0;
    }
    