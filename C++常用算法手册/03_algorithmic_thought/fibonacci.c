#include <stdio.h>

/**
 * 兔子产仔算法
 * 如果一对两个月大的兔子以后每一个月都可以生一对小兔子，而一对新生的兔子出生两个月后才可以生小兔子。
 * 也就是说，1月份出生，3月份才可产仔。那么假定一年内没有产生兔子死亡事件，那么1年后共有多少对兔子呢？
 */ 
int Fibonacci(int n)
{
    int t1, t2;
    if (n == 1 || n == 2) {
        return 1;
    } else {
        t1 = Fibonacci(n - 1); // 递归调用
        t2 = Fibonacci(n - 2);
        return t1 + t2;
    }
}

int main(int argc, char const *argv[])
{
    int n, num;
    
    printf("递推算法求解兔子产仔问题！\n");
    printf("请先输入时间：");
    scanf("%d", &n); // 时间
    num = Fibonacci(n); // 求解
    printf("经过%d月的时间，共能繁殖成%d对兔子！\n", n, num);

    return 0;
}
