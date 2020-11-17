#include <graphics.h>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <iostream>

/**
 * 亮度修改算法
 */ 
int main(int argc, char const *argv[])
{
    initgraph(640, 480);
    
    // 读取图片
    loadimage(NULL, _T("./game.jpg"));
    
    // 随机数引擎初始化
    std::random_device device;
    std::mt19937 mt(device());
    std::uniform_int_distribution<int> dist(1, 100);
    std::uniform_real_distribution<float> dist_float(0.1, 1.0);
    
    auto changeBrightness = [](COLORREF c, int brightness){
        auto truncate = [](int value){
            if (value < 0) value = 0;
            if (value > 255) value = 255;
            return value;
        };
        BYTE red =  truncate(GetRValue(c) + brightness);
        BYTE green =  truncate(GetGValue(c) + brightness);
        BYTE blue =  truncate(GetBValue(c) + brightness);
        return RGB(red, green, blue);
    };

    auto changeLightness = [](COLORREF c, float lightness){
        if (lightness < 0) lightness = 0.0;
        if (lightness > 1) lightness = 1.0;
        float *H, *S, *L;
        RGBtoHSL(c, H, S, L);
        return HSLtoRGB(*H, *S, lightness); 
    };


    for (int x = 0; x < 640; x++)
    {
        for (int y = 0; y < 480; y++)
        {
            COLORREF c = getpixel(x, y);
            // c = changeBrightness(c, dist(mt)); 
            c = changeLightness(c, dist_float(mt)); 
            putpixel(x, y, c);
        }
    }

    system("pause"); 
    closegraph();

    return 0;
}
