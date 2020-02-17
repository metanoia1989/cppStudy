#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// 斜着弹跳的小球，添加 x y 两个方向的速度控制变量
// velocity_x 碰到上下边界后改变正负号
// velocity_y

int main(int argc, char const *argv[])
{
    int i, j;
    int x = 0;
    int y = 5;

    int velocity_x = 1;   // x 轴方向速度
    int velocity_y = 1;   // y 轴方向速度
    int left = 0;
    int right = 20;
    int top = 0;
    int bottom = 10;

    while (1) {
        x = x + velocity_x;
        y = y + velocity_y;
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
        Sleep(50);  // 等待50毫秒

        // 小球达到上下边界时改变方向，改变速度的矢量方向
        if (x == top || x == bottom) {
            velocity_x = -velocity_x;
        } 
        if (y == left || y == right) {
            velocity_y = -velocity_y;
        }
    }

    return 0;
}
