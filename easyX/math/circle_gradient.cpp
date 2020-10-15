#include <graphics.h>
#include <stdlib.h>
#include <math.h>

constexpr double pi = 3.14159265358979323846;

int main(int argc, char const *argv[])
{
    initgraph(640, 480);
    
    int color;
    int x, y, radius = 200;
    for (double radian = 0; radian < pi * 2; radian += 0.001 )
    {
        x = static_cast<int>(radius * cos(radian) + 320 + 0.5);    
        y = static_cast<int>(radius * sin(radian) + 240 + 0.5);    
        color = static_cast<int>(radian * 255 / (2 * pi) + 0.5);    
        setlinecolor(RGB(color, 0, 0));
        line(320, 240, x, y);
    }
    
    system("pause");
    closegraph();

    return 0;
}
