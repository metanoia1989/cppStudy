#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

/* 100个随机下落的点，每个点落到底部后，就回到顶部重新下落 */
/* 有种星空飞舞的感觉 */
int main(int argc, char const *argv[])
{
    srand(time(NULL)); 
    
    initgraph(640, 480);
    
    // 定义点的坐标数组
    int x[100], y[100];
    
    for (size_t i = 0; i < 100; i++)
    {
        x[i] = rand() % 640;
        y[i] = rand() % 640;
    }
    
    while (!_kbhit())
    {
        for (size_t i = 0; i < 100; i++)
        {
            // 擦掉前一个点
            putpixel(x[i], y[i], BLACK);
            // 计算新坐标
            y[i] += 3;
            if (y[i] >= 480) 
                y[i] = 0;
            // 绘制新点
            putpixel(x[i], y[i], WHITE);
        }
        Sleep(10); 
    }

    closegraph();

    return 0;
}
