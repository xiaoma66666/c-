#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define I 20
#define R 340
#include <string.h>
int main() {
    char answer[10];
    printf("陆雨\n你以后不能生我气了\n");
    printf("愿赌服输哦,\n真实你！\n输入\tok\n");
    scanf("%s", answer);
    char b[4] = "ok";
    if (strcmp(answer, b) == 0) {
        float y, x, z, f;
        for (y = 1.5f; y > -1.5f; y -= 0.1f) {
            for (x = -1.5f; x < 1.5f; x += 0.05f) {
                z = x * x + y * y - 1;
                f = z * z * z - x * x * y * y * y;
                putchar(f <= 0.0f ? "*********"[(int)(f * -8.0f)] : ' ');
            }
            putchar('\n');
        }
        long time;
        for (;;) {
            system("color a");
            for (time = 0; time < 99999999; time++);
            system("color b");
            for (time = 0; time < 99999999; time++);
            system("color c");
            for (time = 0; time < 99999999; time++);
            system("color d");
            for (time = 0; time < 99999999; time++);
            system("color e");
            for (time = 0; time < 99999999; time++);
            system("color f");
            for (time = 0; time < 99999999; time++);
            system("color 0");
            for (time = 0; time < 99999999; time++);
            system("color 1");
            for (time = 0; time < 99999999; time++);
            system("color 2");
            for (time = 0; time < 99999999; time++);
            system("color 3");
            for (time = 0; time < 99999999; time++);
            system("color 4");
            for (time = 0; time < 99999999; time++);
            system("color 5");
            for (time = 0; time < 99999999; time++);
            system("color 6");
            for (time = 0; time < 99999999; time++);
            system("color 7");
            for (time = 0; time < 99999999; time++);
            system("color 8");
            for (time = 0; time < 99999999; time++);
            system("color 9");
        }
        getchar();

    } else {
        printf("\n滚！\n");
    }
    return 0;
}
