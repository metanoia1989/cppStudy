#include <graphics.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    initgraph(640, 480); 
    
    // 红蓝交错画线
    for (int y = 100; y < 200; y+=10) {
        if (y/10%2 == 1) { // 判断奇数行偶数行
            setcolor(RGB(255, 0, 0));
        } else {
            setcolor(RGB(0, 0, 255));
        }
        line(100, y, 300, y);
    }
    
    system("pause");
    closegraph();

    return 0;
}
