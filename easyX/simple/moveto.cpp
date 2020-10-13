#include <graphics.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    initgraph(100, 100);
    
    rectangle(0, 0, 10, 10); 
    moveto(10, 10);
    rectangle(0, 0, 10, 10); 
    
    system("pause");
    closegraph();

    return 0;
}
