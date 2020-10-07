#include <stdio.h>

long fact(int n);

int main(int argc, char const *argv[])
{
    int i;
    
    printf("请输入要求阶乘的一个整数：");
    scanf("%d", &i); // 输入数据
    printf("%d的阶乘结果为：%ld\n", i, fact(i));

    return 0;
}

// 求阶乘函数
long fact(int n)
{
    long result = 1;

    for (int i = 1; i <= n; i++)
        result *= i;

    return result;
}