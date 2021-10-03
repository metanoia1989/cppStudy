#include <graphics.h>
#include <stdlib.h>
#ifdef __unix__
#define Sleep delay
#elif defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif


/**
 * 一个圆从左到右跳动
 */ 
int main(int argc, char const *argv[])
{
    initgraph(640, 480);
    
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
