#include <graphics.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    initgraph(600, 400); 
    
    int curr;
    for (int y = 0; y <= 400; y++)
    {
        curr = y * 255 / 400;     
        setlinecolor(RGB(0, 0, curr));
        line(0, y, 600, y);
    }
    
    system("pause");
    closegraph();

    return 0;
}
