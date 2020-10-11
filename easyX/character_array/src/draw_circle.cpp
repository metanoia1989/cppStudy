#include "easyx.h"
#include <conio.h>


int main(int argc, char** argv)
{
    initgraph(640, 480); // 创建绘图窗口大小
    circle(200, 200, 100); // 画图，圆心200x200，半径100
    _getch();				// 按任意键继续
    closegraph();

    return 0;
}
