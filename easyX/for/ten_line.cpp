#include <graphics.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    initgraph(640, 480); 
    
    // 10条直线
    for (int y = 100; y < 200; y+=10) {
        line(100, y, 300, y);
    }
    
    system("pause");
    closegraph();

    return 0;
}
