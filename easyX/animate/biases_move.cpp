#include <graphics.h>
#include <stdlib.h>
#include <windows.h>


/**
 * 绘制一个沿45度移动的球，碰到窗口边界后反弹。 
 */ 
int main(int argc, char const *argv[])
{
    initgraph(640, 480);
    
    int x = 0;
    int direction = true; // true为正向、false为反向
    while (true)
    {
        if (x > 480) {
            direction = false;
            x = 480;
        }
        if (x < 0) {
            direction = true;
            x = 0;
        }
        if (x <= 480 && x >= 0 ) {
            if (direction) {
                x += 10;
            } else {
                x -= 10;
            }
        } else {
            continue;
        }

        // 绘制黄线、绿色填充的圆
        setlinecolor(YELLOW);
        setfillcolor(GREEN);
        fillcircle(x, x, 30); 
        Sleep(50);
        // 绘制黑线、黑色填充的圆，抹掉之前的
        setlinecolor(BLACK);
        setfillcolor(BLACK);
        fillcircle(x, x, 30); 

    }
    
    for (int x = 100; x < 540; x+=20) 
    {
        // 绘制黄线、绿色填充的圆
        setlinecolor(YELLOW);
        setfillcolor(GREEN);
        fillcircle(x, 100, 20); 

        Sleep(500);

        // 绘制黑线、黑色填充的圆，抹掉之前的
        setlinecolor(BLACK);
        setfillcolor(BLACK);
        fillcircle(x, 100, 20); 
    }
    
    system("pause");
    closegraph();

    return 0;
}
