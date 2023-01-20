#include <stdio.h>

int main () {
    // TODO 请在此处编写代码，完成题目要求
    int all_days=0;
    int year,month;
    scanf("%d %d",&year,&month);
    int year1=2000;
    for(;year1<year;year++){
        all_days+=(year1%400==0||(year1%4==0&&year1%100!=0))?366:365;
    }
    int m=1;
    for(;m<month;m++){
        if(m>12){
        printf("错误,月份不能大于12.");break;}
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
        all_days+=31;}
        if(m==4||m==6||m==9||m==11){
        all_days+=30;}
        if(m==2){
        all_days+=(year1%400==0||(year1%4==0&&year1%100!=0))?29:28;
    }}
        all_days+=1;
        int weekday=all_days%7;
        #include <stdio.h>

int main() {
    int all_days = 0;
    int year,month;
    scanf("%d %d",& year, & month);
    int _year = 2000;
    for (;_year<year;_year++) {
        all_days += (_year%400==0 || (_year%4==0 && _year%100!=0))? 366 : 365;
    }
    int _m = 1;
    for (;_m<month;_m++) {
        if (_m>12) {
            printf("错误：月份不能大于12");
            break;
        }
        if (_m==1 || _m==3 || _m==5 || _m==7 || _m==8 || _m==10 || _m==12) {
            all_days+=31;
        }
        if (_m==4 || _m==6 || _m==9 || _m==11) {
            all_days+=30;
        }
        if (_m==2) {
            all_days += (_year%400==0 || (_year%4==0 && _year%100!=0))? 29 : 28;
        }
    }
    all_days += 1;
    int weekday = all_days % 7;
    if (weekday==0) {
        printf("Friday");
    }
    if (weekday==1) {
        printf("Saturday");
    }
    if (weekday==2) {
        printf("Sunday");
    }
    if (weekday==3) {
        printf("Monday");
    }
    if (weekday==4) {
        printf("Tuesday");
    }
    if (weekday==5) {
        printf("Wednesday");
    }
    if (weekday==6) {
        printf("Thursday");
    }
    return 0;}}

   