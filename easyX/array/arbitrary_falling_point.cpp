#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

/* 绘制一个从屏幕上边任意位置往下落的白色点 */
int main(int argc, char const *argv[])
{
    srand(time(NULL)); 
    
    initgraph(640, 480);
    
    int x = rand() % 640; // 点的x坐标
    int y = 0; // 点的y坐标
    
    while (!_kbhit()) 
    {
        // 擦掉前一个点
        putpixel(x, y, BLACK);
        // 计算新坐标
        y += 3;
        if (y >= 480) 
            break;
        // 绘制新点
        putpixel(x, y, WHITE);
        
        Sleep(100);
    }

    closegraph();
    return 0;
}
