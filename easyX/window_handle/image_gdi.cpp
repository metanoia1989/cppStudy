#include <graphics.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    initgraph(640, 480); 
    
    // 创建IMAGE对象，并获取其HDC句柄
    IMAGE img(300, 300);
    HDC hdc = GetImageHDC(&img);
    
    MoveToEx(hdc, 100, 100, NULL);
    LineTo(hdc, 200, 200);
    
    putimage(0, 0, &img);
    
    system("pause");
    
    closegraph();

    return 0;
}
