#include <graphics.h>
#include <cassert>
#include <tuple>

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
    COLORREF colors[9] = {
        WHITE, BLACK, YELLOW,
        BLUE, GREEN, CYAN, 
        RED, LIGHTRED, BROWN
    };
    for (int i=0; i<8; i++)
    {
        int x = i * 50 + 200;
        int y = 450;
        setfillcolor(colors[i]);
        fillrectangle(x, y, x+50, y+50); 
    }
    setfillcolor(BLACK); // 重置填充颜色为黑色
    
    // 绘制当前选择的颜色
    rectangle(10, 420, 90, 500);

    // 点击的时候设置什么颜色，以及点击格子绘制都需要进行计算才行，严重依赖绝对值的坐标。   
    // 是否是绘制格子的区域
    auto isDrawCellArea = [](int x, int y) {
        return x > 10 && x < 800 && y > 10 && y < 400;
    };
    // 是否是选色区
    auto isPeekColorArea = [](int x, int y) {
        return x > 200 && x < 600 && y > 450 && y < 500;
    };
    // 计算选取的颜色
    auto calculateColor = [colors, &isPeekColorArea](int x, int y) {
        assert(isPeekColorArea(x, y)); 
        int i = static_cast<int>((x - 200) / 50);
        return colors[i];
    };
    // 计算要绘制的格子左上角坐标
    auto calculatePosition = [colors, &isDrawCellArea](int x, int y) {
        assert(isDrawCellArea(x, y)); 
        int new_x = static_cast<int>((x - 10) / 50) * 50 + 10;
        int new_y = static_cast<int>((y - 10) / 50) * 50 + 10;
        return std::tuple(new_x, new_y);
    };
    // 鼠标点击事件
    MOUSEMSG m;
    while (true) {
        m = GetMouseMsg(); 
        switch (m.uMsg)
        {
        case WM_LBUTTONUP:
            // 用户点击选色区
            if (isPeekColorArea(m.x, m.y)) {
                COLORREF color = calculateColor(m.x, m.y); 
                setfillcolor(color);
                fillrectangle(10, 420, 90, 500);
            }
            // 用户点击绘制格子区域
            if (isDrawCellArea(m.x, m.y)) {
                auto [x, y] = calculatePosition(m.x, m.y);
                fillrectangle(x, y, x+50, y+50); 
            }
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
