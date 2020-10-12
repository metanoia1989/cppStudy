#include <graphics.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    initgraph(800, 800);
    setlinecolor(0xffffff);    
    line(100, 100, 200, 100);
    setlinecolor(BLUE);    
    line(200, 100, 300, 100);
    setlinecolor(GREEN);    
    line(300, 100, 400, 100);
    setlinecolor(RED);    
    line(400, 100, 500, 100);
    
    Sleep(2000);
    setlinecolor(YELLOW);
    circle(400, 400, 150);
    
    // 彩色点的图缀
    srand(time(nullptr));
    int colors[] = {
        BLACK, DARKGRAY, 
        GREEN, LIGHTGREEN, 
        CYAN,
        RED, LIGHTRED, 
        MAGENTA, LIGHTMAGENTA, 
        BROWN, YELLOW,
        LIGHTGRAY
    };
    for (int i = 100; i < 700; i+=10) {
        for (int j = 100; j < 700; j+=10) {
            int rand_num = rand() % 12;
            putpixel(i, j, colors[rand_num - 1]); 
        }
    }
    
    system("pause");
    closegraph();

    return 0;
}
