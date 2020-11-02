#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <utility>

/**
 * 
 * 1. 在二维平面上随机生成 3 个点 P[0]、P[1]、P[2]；
 * 2. 随机生成 1 个点 P；
 * 3. 绘制点 P；
 * 4. 随机生成 [0, 2] 内的整数 n；
 * 5. 令 P = P 与 P[n] 的中点；
 * 6. 重复执行步骤 (3)～(5) 三万次。
 *
 */ 
int main(int argc, char const *argv[])
{
    initgraph(640, 480);

    srand(time(NULL)); 

    auto randomPosition = [](){
        int x = rand() % 640;
        int y = rand() % 480;
        return std::pair(x, y);
    };

    // 随机生成三个点 p0、p1、p2
    std::pair<int,int> p_arr[] = {
        randomPosition(), 
        randomPosition(), 
        randomPosition()
    };

    // 随机生成一个点 p
    auto p = randomPosition(); 

    for (size_t i = 0; i < 50000; i++)
    {
        putpixel(p.first, p.second, YELLOW);
        int n = rand() % 3;
        p.first = (p.first + p_arr[n].first) / 2;
        p.second = (p.second + p_arr[n].second) / 2;
    }
    
    system("pause");
    closegraph();

    return 0;
}
