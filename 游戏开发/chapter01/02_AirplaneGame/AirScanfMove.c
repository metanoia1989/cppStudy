#include <stdio.h>
#include <stdlib.h>

// 利用 scanf 输入不同的字符，按 a s dw 键后改变坐标 x y 的值，从而控制飞机字符的上下左右移动

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
        printf("*");
        printf("\n");

        scanf("%c", &input);    // 根据用户的不同输入来移动
        if (input == 'a') {
            y--;
        } else if (input == 'd') {
            y++;
        } else if (input == 'w') {
            x--;
        } else if (input == 's') {
            x++;
        }
        
    }

    return 0;
}
