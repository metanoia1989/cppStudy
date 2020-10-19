#include <graphics.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    initgraph(640, 480); 
    setlinestyle(PS_SOLID, 10); // 设置线宽为10
    setlinecolor(0x08abff); // 线颜色为黄色
    rectangle(100, 100, 200, 200); // 黄色矩形框背景
    
    setwritemode(R2_XORPEN); // 设置XOR绘图模式
    setlinecolor(0x2553f3); // 红色
    
    line(50, 20, 200, 300); 
    _getch();
    line(50, 20, 200, 300); 
    _getch();
    
    closegraph();

    return 0;
}
