#include <stdio.h>

// 静止的小球

int main()
{
    int i, j;
    int x = 5;
    int y = 10;
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

    return 0;
}