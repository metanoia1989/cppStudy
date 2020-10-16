#include <graphics.h>
#include <stdlib.h>
#include <windows.h>


/**
 * 一条线从上往下移动
 */ 
int main(int argc, char const *argv[])
{
    initgraph(640, 480);
    
    for (int y = 0; y < 480; y++) 
    {
        setlinecolor(GREEN);
        line(0, y, 640, y);
        Sleep(10);
        setlinecolor(BLACK); // 绘制黑线，擦掉之前的绿线
        line(0, y, 640, y);
    }
    
    system("pause");
    closegraph();

    return 0;
}
