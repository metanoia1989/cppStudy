#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * 蒙卡罗概率算法计算π
 */
double MontePI(int n)
{
    double PI;
    double x, y;
    int i, sum;

    sum = 0;
    srand(time(NULL));
    for (i = 1; i < n; i++) {
        x = (double)rand() / RAND_MAX; // 产生0~1之间的一个随机数
        y = (double)rand() / RAND_MAX; // 产生0~1之间的一个随机数
        if ((x*x + y*y) <= 1) // 若在阴影区域
            sum++;
    }
    PI = 4.0 * sum / n; // 计算π
    return PI;
}

int main(int argc, char const *argv[])
{
    int n;
    double PI;

    printf("蒙特卡罗概率算法计算π：\n");
    printf("输入点的数量：");
    scanf("%d", &n); // 输入撒点个数
    PI = MontePI(n); // 计算PI
    printf("PI=%f\n", PI);

    return 0;
}
