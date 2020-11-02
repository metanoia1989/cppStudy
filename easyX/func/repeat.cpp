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
    line(x, y, x+10, y);
    line(x, y, x, y+10);
    line(x+10, y, x, y+10);
}

int main(int argc, char const *argv[])
{
    initgraph(640, 480); 
    
    for (int x = 0; x < 640; x += 10)
    {
        for (int y = 0; y < 480; y += 10)
            triangle(x, y, RGB(x*255/640, y*255/480, 0));
    }
    
    
    system("pause");
    closegraph();

    return 0;
}

