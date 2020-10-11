#include "graphics.h"
#include <time.h>
#include <conio.h>

/**
 * 字符阵列
 */ 
int main(int argc, char const *argv[])
{
    // // 设置随机函数种子   
    srand((unsigned) time(nullptr));
    // 初始化图形模式
    initgraph(640, 480);

    int x, y;
    char c;

    settextstyle(16, 8, _T("Courier")); // 设置字体

    // 设置颜色
    settextcolor(GREEN);
    setlinecolor(BLACK);

    for (int i = 0; i <= 479; i++) 
    {
        // 在随机位置显示三个随机字母
        for (int j = 0; j < 3; j++)
        {
            x = (rand() % 80) * 8;
            y = (rand() % 20) * 24;
            c = (rand() % 26) + 65;
            outtextxy(x, y, c);
        }
        // 画线擦掉一个像素行
        line(0, i, 639, i);

        Sleep(10);
        if (i >= 479) i = -1; // 循环处理
        if (_kbhit()) break; // 按任意键退出
    }
    // 关闭图形模式
    closegraph();

    return 0;
}
