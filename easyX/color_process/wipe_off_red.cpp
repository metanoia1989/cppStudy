#include <graphics.h>
#include <stdlib.h>

/**
 * 去除图片的红色 利用位运算的与操作 color &= 0xffff00;
 * 生成底片效果 c = (0xff0000 - (c & 0xff0000)) | (0x00ff00 - (c & 0x00ff00)) | (0x0000ff - (c & 0x0000ff));     
 */ 
int main(int argc, char const *argv[])
{
    initgraph(640, 480);
    
    // 读取图片
    loadimage(NULL, _T("./image.jpg"));

    for (int x = 0; x < 640; x++)
    {
        for (int y = 0; y < 480; y++)
        {
            COLORREF c = getpixel(x, y);
            // 去掉红色
            // c &= 0xffff00; 
            // 底片效果
            c = (0xff0000 - (c & 0xff0000) | (0x00ff00 - (c & 0x00ff00)) | (0x0000ff - (c & 0x0000ff)));
            putpixel(x, y, c);
        }
    }

    system("pause"); 
    closegraph();

    return 0;
}
