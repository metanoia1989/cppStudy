#include <graphics.h>
#include <stdlib.h>

/**
 * Windows GDI 画一条线
 */ 
int main(int argc, char const *argv[])
{
    initgraph(640, 480); 
    
    HDC hdc = GetImageHDC(); // 获取HDC句柄
    
    // 使用 Windows GDI 操作画一条线
    MoveToEx(hdc, 100, 100, NULL);
    LineTo(hdc, 200, 200);
    
    system("pause"); 
    closegraph();
    
    return 0;
}
