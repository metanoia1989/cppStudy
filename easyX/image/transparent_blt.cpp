#include <graphics.h>
#include <stdlib.h>
// 使用TransparentBlt函数必须引入的库
#pragma comment(lib, "MSIMG32.LIB")

/**
 * 透明贴图函数
 * 
 * @param  {IMAGE*} dstimg 目标 IMAGE 对象指针，NULL 表示默认窗体
 * @param  {int} x 目标贴图位置的x坐标
 * @param  {int} y 目标贴图位置的y坐标
 * @param  {IMAGE*} srcimg 源 IMAGE 对象指针，NULL 表示默认窗体
 * @param  {UINT} transparentcolor 透明色，srcimg的该颜色不会复制到dstimg上，从而实现透明贴图
 */
void transparentimage(IMAGE *dstimg, int x, int y, IMAGE *srcimg, UINT transparentcolor)
{
    HDC dstDC = GetImageHDC(dstimg);
    HDC srcDC = GetImageHDC(srcimg);
    int w = srcimg->getwidth();
    int h = srcimg->getheight();
    
    // 使用 Windows GDI 函数实现透明位图
    TransparentBlt(dstDC, x, y, w, h, srcDC, 0, 0, w, h, transparentcolor);
}

/**
 * 透明贴图函数，通过操作缓冲区实现
 *
 * @param  {IMAGE*} dstimg 目标 IMAGE 对象指针，NULL 表示默认窗体
 * @param  {int} x 目标贴图位置的x坐标
 * @param  {int} y 目标贴图位置的y坐标
 * @param  {IMAGE*} srcimg 源 IMAGE 对象指针，NULL 表示默认窗体
 * @param  {UINT} transparentcolor 透明色，srcimg的该颜色不会复制到dstimg上，从而实现透明贴图
 */
void transparentimgae_buffer(IMAGE *dstimg, int x, int y,IMAGE *srcimg, UINT transparentcolor)
{
    DWORD *dst = GetImageBuffer(dstimg); 
    DWORD *src = GetImageBuffer(srcimg);
    int src_width = srcimg->getwidth();
    int src_height = srcimg->getheight();
    int dst_width = dstimg == NULL ? getwidth() : dstimg->getwidth(); 
    int dst_height = dstimg == NULL ? getheight() : dstimg->getheight(); 
    
    // 计算贴图实际长宽
    int iWidth = (x + src_width > dst_width) ? dst_width - x : src_width;
    int iHeight = (x + src_height > dst_height) ? dst_height - x : src_height;
    
    // 修正贴图起始位置
    dst += dst_width * y + x;
    
    // 修正透明色，显示缓冲区中的数据结构为 0xaarrggbb
    transparentcolor = 0xff000000 | BGR(transparentcolor);
    
    // 实现透明贴图
    for (int iY = 0; iY < iHeight; iY++) {
        for (int iX = 0; iX < iWidth; iX++) {
            if (src[iX] != transparentcolor) 
                dst[iX] = src[iX];
        }
        dst += dst_width;
        src += src_width;
    }
}

int main(int argc, char const *argv[])
{
    initgraph(600, 400); 
    
    IMAGE src;
    loadimage(&src, _T("./person.jpg"), 150, 100);
    
    // 画个简单背景
    setlinecolor(GREEN);
    for (int y = 0; y < 480; y += 3) {
        line(0, y, 639, y);
    }
    
    // 普通贴图
    putimage(0, 0, &src);
    // 透明贴图
    transparentimage(NULL, 200, 0, &src, 0xfcfcfc);

    transparentimgae_buffer(NULL, 0, 200, &src, 0xfcfcfc);

    system("pause"); 
    closegraph();

    return 0;
}
