#include <graphics.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    initgraph(640, 480); 
    
    IMAGE img; // 定义 IMAGE 对象
    loadimage(&img, _T("./guilty.jpg")); // 读取图片到对象中
    putimage(0, 0, &img); // 指定坐标显示图像
    
    system("pause");
    closegraph();

    return 0;
}
