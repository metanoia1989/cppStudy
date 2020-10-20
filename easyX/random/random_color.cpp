#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL)); 
    
    initgraph(640, 480);
    
    int x, y, c;
    while (!_kbhit())
    {
        x = rand() % 640; 
        y = rand() % 480; 
        c = RGB(rand()%256, rand()%256, rand()%256);
        putpixel(x, y, c);
    }

    closegraph();

    return 0;
}
