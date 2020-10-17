#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    initgraph(640, 480); 
    
    int x = 320;
    int y = 240;
    
    // 画初始图形
    setlinecolor(YELLOW);
    setfillcolor(GREEN);
    fillcircle(x, y, 20);
    
    char c = 0;
    
    printf("输入ESC退出循环！");
    
    enum class DirectionX {
        Forward, // 正向
        None, // 停止
        Opposite // 反向
    };
    enum class DirectionY {
        Forward, // 正向
        None, // 停止
        Opposite // 反向
    };
    auto direction_x = DirectionX::None;
    auto direction_y = DirectionY::None;

    const int ESC_KEY = 27;

    while (true)
    {
        if (_kbhit()) {
            // 获取按键，阻塞
            c = _getch();    

            if (c == ESC_KEY) 
                break;
            
            switch (c)
            {
            case 'a': // 左方向
            case 75:
                direction_x = DirectionX::Opposite;
                direction_y = DirectionY::None;
                break;
            case 'd': // 右方向
            case 77:
                direction_x = DirectionX::Forward;
                direction_y = DirectionY::None;
                break;
            case 'w': // 上方向
            case 72:
                direction_x = DirectionX::None;
                direction_y = DirectionY::Opposite;
                break;
            case 's': // 下方向
            case 80:
                direction_x = DirectionX::None;
                direction_y = DirectionY::Forward;
                break;
            default:
                direction_x = DirectionX::None;
                direction_y = DirectionY::None;
                break;
            }
        }
        if (direction_x == DirectionX::None && direction_y == DirectionY::None) {
            continue;
        }
        
        // 擦掉上次显示的旧图形
        setlinecolor(BLACK); 
        setfillcolor(BLACK); 
        fillcircle(x, y, 20);
        
        // 边界检测 0 < x < 640, 0 < y < 480
        if (x > 620) direction_x = DirectionX::Opposite;
        if (x < 20) direction_x = DirectionX::Forward;
        if (y > 460) direction_y = DirectionY::Opposite;
        if (y < 20) direction_y = DirectionY::Forward;
    
        
        // 根据x、y的方向计算新的坐标
        if (direction_x == DirectionX::Opposite) x -= 2;
        if (direction_x == DirectionX::Forward) x += 2;
        if (direction_y == DirectionY::Opposite) y -= 2;
        if (direction_y == DirectionY::Forward) y += 2;

        // 绘制新的图形
        setlinecolor(YELLOW);
        setfillcolor(GREEN);
        fillcircle(x, y, 20);
        
        // 延时
        Sleep(10);
    }
    closegraph();

    return 0;
}
