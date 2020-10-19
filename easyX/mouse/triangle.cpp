#include <graphics.h>
#include <stdlib.h>

/**
 * 使用 fillpoly 绘制一个填充三角形，用鼠标点旋三角形的三个顶点
 */ 
int main(int argc, char const *argv[])
{
    initgraph(640, 480);
    
    const int count = 3;
    POINT pts[count]; // 定义多边形坐标点
    const int ESC_KEY = 27;
    
    setwritemode(R2_XORPEN); 
    setfillcolor(YELLOW);

    int i = 0;
    MOUSEMSG m;
    while (true) {
        m = GetMouseMsg();
        switch (m.uMsg)
        {
        case WM_LBUTTONUP:
            if (i == 3) {
                i = i % 3; 
                fillpolygon(pts, 3); // 擦除
                for (auto &p : pts) 
                    putpixel(p.x, p.y, WHITE);
            }
            pts[i] = { m.x, m.y };
            putpixel(m.x, m.y, WHITE);
            if (i == 2) {
                fillpolygon(pts, 3);
            }
            i++;
            break;
        case WM_RBUTTONUP:
            return 0;
        default:
            break;
        }
    }
    
    closegraph();

    return 0;
}