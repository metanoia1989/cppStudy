#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15

int SearchFun(int a[], int len, int x)
{
    int f = -1;

    for(int i = 0; i < len; i++) {
        if (x == a[i]) { // 查找到
            f = i; 
            break; // 退出
        }
    }
    return f;
}

int main(int argc, char const *argv[])
{
    int x, n;
    int shuzu[N];

    srand(time(NULL)); // 随机种子
    for (int i = 0; i < N; i++)
        shuzu[i] = rand() / 1000 + 100; // 产生数组
    
    printf("顺序查找算法演示！\n");
    printf("数据序列：\n");
    for (int i = 0; i < N; i++)
        printf("%d ", shuzu[i]); // 输出序列
    printf("\n\n");
    printf("输入要查找的数：");
    scanf("%d", &x); // 输入要查找的数

    n = SearchFun(shuzu, N, x); // 查找
    if (n == -1) {
        printf("没找到数据：%d\n", x);
    } else {
        printf("数据：%d位于数组的第%d个元素处.\n", x, n + 1);
    }

    return 0;
}
