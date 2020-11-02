#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

/**
 * 屏幕上有 16x8的方格，按随机顺序将1~128的数字写到每个格子上
 * 需要记录这些格子，哪些写过数字，哪些没写数字
 */ 
int main(int argc, char const *argv[])
{
    int x, y; 
    wchar_t num[4];
    
    srand(time(NULL));
    
    initgraph(640, 480);
    
    // 画格子 16x8
    for (x = 0; x < 480; x += 30)
        for (y = 0; y < 240; y += 30)
            rectangle(x, y, x+28, y+28);
    
    // 定义二位数组
    bool cell[16][8] = { false }; 
    // 在每个格子上写数字
    for (int i = 0; i < 128; i++)
    {
        // 找到一个没有写数字的随机格子
        // 为 false 的 while condition将不满足，终止循环
        do {
            x = rand() % 16;
            y = rand() % 8;
        } while (cell[x][y] == true);
        // 标记该格子已用 
        cell[x][y] = true;
        // 在格子上写数字 
        swprintf_s(num, 4, L"%d", i);
        outtextxy(x*30+2, y*30+6, num);
    }
    
    _getch(); 
    closegraph();

    return 0;
}
