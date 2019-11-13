#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// getch() 不需要回车就可以得到输入的控制字符
// kbhit() 在用户有键盘输入时返回1，否则返回0
// 发射激光 定义变量 isFire 记录飞机是否处于发射子弹的状态

int main(int argc, char const *argv[])
{
    int i, j;
    int x = 5;
    int y = 10;
    char input;
    int isFire = 0;

    while (1) {
        system("cls");

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
