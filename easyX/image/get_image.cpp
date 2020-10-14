#include <graphics.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    initgraph(640, 480); 
    
    IMAGE img; // 定义 IMAGE 对象
    
    // 绘制内容
    circle(100, 100, 20);
    line(70, 100, 130, 100);
    line(100, 70, 100, 130);
    
    // 保存区域至 img 对象
    getimage(&img, 70, 70, 60, 60);
    
    putimage(200, 200, &img); // 指定坐标显示图像
    
    saveimage(_T("./screen.png"), &img);
    
    system("pause");
    closegraph();

    return 0;
}
