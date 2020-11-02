#include <graphics.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <utility>

/**
 * 任意角度移动的球，碰到边界后任意角度反弹
 */ 
int main(int argc, char const *argv[])
{
    initgraph(600, 600);
    setwritemode(R2_XORPEN); // XOR绘图模式
    
    srand(time(NULL));

    setlinecolor(YELLOW); // 黄线
    setfillcolor(GREEN); // 绿色填充

    int x = 300, y = 300; // 初始坐标
    int degree =  rand() % 360; // 初始角度
    const int step = 10; // 每次移动的距离

    // 生成新的坐标
    auto generatePosition = [step, &degree](int x, int y) {
        // 没有超出任何边界，返回原角度的移动
        if (x > step && x < 600 - step && y > step && y < 600 - step) {
            x += step * cos(degree);
            y += step * sin(degree);
            return std::pair(x, y); 
        }
        // 超过边界则移动到边界内，并且生成新的角度
        int new_degree = rand() % 180;
        if (x < step) { // 左边界
            new_degree -= 90;
            new_degree = new_degree > 0 ? new_degree : 360 + new_degree;
            x = step;
        }
        if (x > 600 - step) { // 右边界
            new_degree += 90;
            x = 600 - step;
        }
        if (y < step) { // 上边界
            new_degree += 180;
            y = step;
        }
        if (y > 600 - step) { // 下边界
            y = 600 - step;
        }
        degree = new_degree;
        x += step * cos(new_degree);
        y += step * sin(new_degree);
        return std::pair(x, y); 
    };

    while (true)
    {
        fillcircle(x, y, step * 2); // 绘制
        Sleep(50);
        fillcircle(x, y, step * 2); // 取消
        
        auto position = generatePosition(x, y);
        x = position.first;
        y = position.second;
    }
    
    system("pause");
    closegraph();

    return 0;
}
