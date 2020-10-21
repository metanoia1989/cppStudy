#include <graphics.h>
#include <stdlib.h>
#include <windows.h>

/**
 * 任意角度移动的球，碰到边界后任意角度反弹
 */ 
int main(int argc, char const *argv[])
{
    initgraph(600, 600);
    
    int x = 300;
    int y = 300;
    int degree = 0;
    const int step = 10;
    while (true)
    {
        degree = rand() % 360;
        x += step gg
    }
    
    system("pause");
    closegraph();

    return 0;
}
