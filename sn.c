#include<stdio.h>
#include<math.h>
/// @brief 
int main(){
int a=2,n,s,t,i;
scanf("%d%d",&a,&n);
s=t=0;
for ( i =1; i<=n; i++)
{t=t*10+1;
s=s+t;
}
s=s*a;
printf("s=%d\n",s);
}
