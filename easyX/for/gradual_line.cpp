#include <graphics.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    initgraph(640, 480); 
    
    // 渐变颜色的线
    for (int y = 0; y < 256; y++) {
        setcolor(RGB(0, 0, y));
        line(100, y, 300, y);
    }
    
    system("pause");
    closegraph();

    return 0;
}
