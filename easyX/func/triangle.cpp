#include <graphics.h>
#include <stdlib.h>

/**
 * 绘制三角形
 * @param  {int} x  x轴坐标
 * @param  {int} y  y轴坐标 
 * @param  {int} c  颜色
 */
void triangle(int x, int y, int c)
{
    setlinecolor(c); 
    // 画三角形的三条边
    line(x, y, x+50, y);
    line(x, y, x, y+50);
    line(x+50, y, x, y+50);
}

int main(int argc, char const *argv[])
{
    initgraph(640, 480);
    
    triangle(100, 100, RED);
    triangle(120, 160, BLUE);
    triangle(140, 220, GREEN);
    triangle(160, 120, BLUE);
    triangle(160, 160, GREEN);
    triangle(220, 140, GREEN);
    
    system("pause");
    
    closegraph();

    return 0;
}
