#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// getch() 不需要回车就可以得到输入的控制字符
// kbhit() 在用户有键盘输入时返回1，否则返回0

int main(int argc, char const *argv[])
{
    int i, j;
    int x = 5;
    int y = 10;
    char input;

    while (1) {
        system("cls");
        // 输出飞机上面的空行
        for (i = 0; i < x; i++) {
            printf("\n");
        }
        // 输出飞机左边的空格
        for (j = 0; j < y; j++) {
            printf(" ");
        }
        // 输出复杂的飞机图案
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
            default:
                break;
            }
        }

        
    }

    return 0;
}
