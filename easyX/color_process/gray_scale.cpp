#include <graphics.h>
#include <stdlib.h>
#include <algorithm>
#include <random>

/**
 * 灰度算法 将彩色图片转换为灰色    
 */ 
int main(int argc, char const *argv[])
{
    initgraph(640, 480);
    
    // 读取图片
    loadimage(NULL, _T("./game.jpg"));
    
    // 随机数引擎初始化
    std::random_device device;
    std::mt19937 mt(device());
    std::uniform_int_distribution<int> dist(2, 256);

    for (int x = 0; x < 640; x++)
    {
        for (int y = 0; y < 480; y++)
        {
            COLORREF c = getpixel(x, y);
            
            // 三色值的平均数
            // BYTE gray = (GetRValue(c) + GetGValue(c) + GetBValue(c)) / 3;

            // 根据人眼对颜色的敏感度
            // BYTE gray = GetRValue(c) * 0.3 + GetGValue(c) * 0.59 + GetBValue(c) * 0.11;

            // 最大最值的平均数 
            // BYTE color[] = { GetRValue(c), GetGValue(c), GetBValue(c) };
            // BYTE gray = (*std::max_element(color, color + 3) + *std::min_element(color, color + 3)) / 2;
            
            // 取最大值 偏亮色的灰度图像
            // BYTE color[] = { GetRValue(c), GetGValue(c), GetBValue(c) };
            // BYTE gray = *std::max_element(color, color + 3);
           
            // 取最小值 偏暗色的灰度图像
            // BYTE color[] = { GetRValue(c), GetGValue(c), GetBValue(c) };
            // BYTE gray = *std::min_element(color, color + 3);
            
            // 单一颜色通道
            // BYTE gray = GetRValue(c); // 仅使用红色通道值生成灰度
            // BYTE gray = GetGValue(c); // 仅使用绿色通道值生成灰度
            // BYTE gray = GetBValue(c); // 仅使用蓝色通道值生成灰度
            
            // 自定义灰色阴影 Custom of gray shades
            int conversionFactor = 255 / (dist(mt) - 1);
            BYTE averageValue = (GetRValue(c) + GetGValue(c) + GetBValue(c)) / 3;
            BYTE gray = static_cast<int>(( averageValue / conversionFactor ) + 0.5) * conversionFactor;

            c = RGB(gray, gray, gray);
            putpixel(x, y, c);
        }
    }

    system("pause"); 
    closegraph();

    return 0;
}
