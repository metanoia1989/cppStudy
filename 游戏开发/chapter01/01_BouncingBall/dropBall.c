#include <stdio.h>
#include <stdlib.h>

// 小球下落

int main()
{
    int i, j;
    int x = 1;
    int y = 10;
    for (x = 1; x < 10; x++) {
        // 清屏
        system("cls");
        // 输出小球上面的空行
        for (i = 0; i < x; i++) {
            printf("\n");
        }
        // 输出小球左边的空格
        for (j = 0; j < y; j++) {
            printf(" ");
        }
        printf("o");
        printf("\n");

    }

    return 0;
}