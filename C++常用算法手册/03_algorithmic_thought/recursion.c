#include <stdio.h>

// 递归求阶乘
long fact(int n); 

int main(int argc, char const *argv[])
{
    int i; // 声明变量
    printf("请输入要求阶乘的一个整数：");
    scanf("%d", &i); // 输入数据
    printf("%d的阶乘结果为：%ld\n", i, fact(i));

    return 0;
}

// 求阶乘函数
long fact(int n)
{
    if (n <= 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}
