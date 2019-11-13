#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i, j;
    int x = 5;
    int y = 10;

    int height = 20;    // 边界高度
    int velocity = 1;   // 记录速度

    while (1) {
        x = x + velocity;
        system("cls");  // 清屏
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

        // 小球达到上下边界时改变方向，改变速度的矢量方向
        if (x == height) {
            velocity = -velocity;
        } 
        if (x == 0) {
            velocity = -velocity;
        }
    }

    return 0;
}
