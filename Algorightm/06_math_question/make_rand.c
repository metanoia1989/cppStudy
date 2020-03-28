#include <stdio.h>

double Rand01(double *r)
{
    double base, u, v, p, temp1, temp2, temp3;
    base = 256.0; // 基数
    u = 17.0;
    v = 139.0;

    temp1 = u*(*r) + v; // 计算总值
    temp2 = (int)(temp1/base); // 计算商
    temp3 = temp1 - temp2 * base; // 计算余数
    *r = temp3; // 更新随机数种子，为下一次使用
    p = *r / base; // 随机数

    return p;
}

int main(int argc, char const *argv[])
{
    int i;
    double r = 5.0;

    printf("产生10个[0, 1]之间的随机数：\n");
    for (int i = 0; i < 10; i++) // 循环调用
        printf("%10.5lf\n", Rand01(&r));
    printf("\n");

    printf("产生10个[10.0, 20.0]之间的随机浮点数：\n");
    for (int i = 0; i < 10; i++) // 循环调用
        printf("%10.5lf\n", Rand01(&r)*10.0+10.0);
    printf("\n");

    printf("产生10个[100, 200]之间的随机整数：\n");
    for (int i = 0; i < 10; i++) // 循环调用
        printf("%d\n",(int)(Rand01(&r)*100+100));
    printf("\n");

    return 0;
}
