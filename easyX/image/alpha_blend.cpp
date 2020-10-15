#include <graphics.h>
#include <stdlib.h>
#pragma comment(lib, "MSIMG32.LIB")

/**
 * 半透明贴图函数
 *
 * @param  {IMAGE*} dstimg 目标IMAGE对象指针，NULL表示默认窗体
 * @param  {int} x, y 目标贴图位置
 * @param  {IMAGE*} srcimg 源IMAGE对象指针，NULL表示默认窗体
 */
void transparentimage(IMAGE *dstimg, int x, int y, IMAGE *srcimg)
{
    HDC dstDC = GetImageHDC(dstimg);    
    HDC srcDC = GetImageHDC(srcimg);    
    int w = srcimg->getwidth();
    int h = srcimg->getheight();
    
    // 结构体的第三个成员表示额外的透明度，0表示全透明，255表示不透明
    BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
    // 使用 Windows GDI 函数实现半透明位图
    AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}

int main(int argc, char const *argv[])
{
    initgraph(600, 400); 
    
    IMAGE src;
    loadimage(&src, _T("./rook.png"), 150, 100);
    
    // 画个简单背景
    setlinecolor(GREEN);
    for (int y = 0; y < 480; y += 3) {
        line(0, y, 639, y);
    }
    
    // 普通贴图
    putimage(0, 0, &src);
    // 透明贴图
    transparentimage(NULL, 200, 0, &src);

    system("pause"); 
    closegraph();

    return 0;
}
