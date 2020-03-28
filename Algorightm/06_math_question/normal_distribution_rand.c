/**
 * 正态分布随机数
 */ 

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

// 正态分布的随机数
double RandZT(double u, double t, double *r)
{
    double total = 0.0;
    double result;
    for (int i = 0; i < 12; i++)
        total += Rand01(r); // 累加
    result = u+t*(total-6.0); // 随机数
    return result;
}

int main(int argc, char const *argv[])
{
    double r = 5.0, u = 2.0, t = 3.5;

    printf("产生10个正态分布的随机数：\n");
    for (int i = 0; i < 10; i++)
        printf("%10.5lf\n", RandZT(u, t, &r));

    return 0;
}
