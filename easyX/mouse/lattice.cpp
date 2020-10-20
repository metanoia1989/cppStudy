#include <graphics.h>

int main(int argc, char const *argv[])
{
    initgraph(820, 520);


    // 绘制格子
    setlinecolor(WHITE);    
    for (int x = 10; x < 800; x+=50)
    {
        for (int y = 10; y < 400; y+=50)
        {
            rectangle(x, y, x+50, y+50);
        }
    }
    
    // 绘制选色区
    COLORREF colors[8] = {
        WHITE, BLACK, YELLOW,
        BLUE, GREEN, CYAN, 
        RED, LIGHTRED, BROWN
    };
    for (int i=0; i<8; i++)
    {
        int x = i * 50;
        int y = 450;
        setfillcolor(colors[i]);
        fillrectangle(x, y, x+50, y+50); 
    }
    // 点击的时候设置什么颜色，以及点击格子绘制都需要进行计算才行，严重依赖绝对值的坐标。   

    system("pause");
    closegraph();
    return 0;
}
