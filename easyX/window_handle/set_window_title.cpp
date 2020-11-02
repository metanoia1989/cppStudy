#include <graphics.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    initgraph(640, 480); 
    
    // 获取窗口句柄
    HWND hwnd = GetHWnd();
    // 设置窗口标题文字
    SetWindowText(hwnd, L"Hello World 哈喽沃尔德！");
    
    system("pause");
    closegraph();

    return 0;
}
