#include <graphics.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    initgraph(640, 480);
    
    // 画10条线，横5条、纵5条，间距为90
    // 画竖线
    for (int x = 95; x <= 640 - 95; x += 90) {
        line(x, 15, x, 15 + 450); 
    } 
    // 画横线
    for (int y = 15; y <= 480 - 15; y += 90) {
        line(95, y, 95 + 450, y); 
    } 

    _getch();
    closegraph();

    return 0;
}
