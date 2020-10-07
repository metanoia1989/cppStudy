#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// getch() 不需要回车就可以得到输入的控制字符
// kbhit() 在用户有键盘输入时返回1，否则返回0
// 发射激光 定义变量 isFire 记录飞机是否处于发射子弹的状态
// 添加靶子 变量 isKilled 存储是否被击中 为0显示靶子，为1隐藏靶子

int main(int argc, char const *argv[])
{
    int i, j;
    int x = 5;
    int y = 10;
    char input;
    int isFire = 0;

    int ny = 5; // 靶子，放在一行的 ny 列上
    int isKilled = 0;

    while (1) {
        system("cls");

        // 输出靶子
        if (!isKilled) {
            for (j = 0; j < ny; j++) {
                printf(" ");
            }
            printf("+\n");
        }

        if (isFire == 0) {
            // 输出飞机上面的空行
            for (i = 0; i < x; i++) {
                printf("\n");
            }
        } else {
            // 输出飞机上面的激光竖线
            for (i = 0; i < x; i++) {
                for (j = 0; j < y; j++) {
                    printf(" ");
                }
                printf("  |\n");
            }
            if (y + 2 == ny) {  // 激光位于飞机的正中间，距最左边两个坐标
                isKilled = 1;
            }
            isFire = 0;
        }


        // 输出复杂的飞机图案
        // 输出飞机左边的空格
        for (j = 0; j < y; j++) {
            printf(" ");
        }
        printf("  *\n");
        for (j = 0; j < y; j++) {
            printf(" ");
        }
        printf("***** \n");
        for (j = 0; j < y; j++) {
            printf(" ");
        }
        printf(" * * \n");


        if (kbhit()) {  // 判断是否有输入
            input = getch();
            switch (input)
            {
            case 'a':
                y--;
                break;
            case 'd':
                y++;
                break;
            case 'w':
                x--;
                break;
            case 's':
                x++;
                break;
            case ' ':
                isFire = 1;
                break;
            default:
                break;
            }
        }

        
    }

    return 0;
}
