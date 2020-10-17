#include <graphics.h>
#include <stdio.h>
#include <conio.h>

/**
 * 如果有按键，就输出相关按键。否则，输出“.”。每隔 100 毫秒输出一次。按 ESC 退出。
 * ESC 的 ASCII 码为 27
 * 
 */ 
int main(int argc, char const *argv[])
{
    char c = 0; 
    while (c != 27) 
    {
        if (_kbhit()) {
            c = _getch();
        } else {
            c = '.';
        }
        printf("%c", c);
        Sleep(100);
    }

    return 0;
}
