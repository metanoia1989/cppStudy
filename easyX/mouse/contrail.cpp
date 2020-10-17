#include <graphics.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    initgraph(640, 480);     
    
    MOUSEMSG m; // 定义鼠标消息
    
    while (true)
    {
        // 获取一条鼠标消息    
        m = GetMouseMsg();
        
        switch (m.uMsg)
        {
        // 鼠标移动消息
        case WM_MOUSEMOVE: 
            putpixel(m.x, m.y, RED);
            break;
        // 点击左键的同时按下Ctrl键 
        case WM_LBUTTONDOWN: 
            if (m.mkCtrl) { // 画一个大方块
                rectangle(m.x-10, m.y-10, m.x+10, m.y+10);
            } else { // 画一个小方块
                rectangle(m.x-5, m.y-5, m.x+5, m.y+5);
            }
            break;
        // 按鼠标右键退出程序 
        case WM_RBUTTONUP:
            return 0;
        default:
            break;
        }
    }
    closegraph();

    return 0;
}
