#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main(int argc, char const *argv[])
{
    int arr[N], x, n, i;
    int f = - 1;

    srand(time(NULL)); // 随机种子
    for (i = 0; i < N; i++) // 生成数组
        arr[i] = rand() / 1000;

    printf("输入要查找的整数：");
    scanf("%d", &x); // 输出要查找的数

    for (i = 0; i < N; i++) { // 顺序查找
        if (x == arr[i]) { // 找到数据
            f = i;
            break;
        }
    }

    printf("\n随机生成的数据序列：\n");
    for (i = 0; i < N; i++) 
        printf("%d ", arr[i]); 
    printf("\n\n");

    if (f < 0) {
        printf("没找到数据：%d\n", x);
    } else {
        printf("数据: %d 位于数组的第 %d 个元素处.\n", x, f + 1);
    }

    system("pause");

    return 0;
}
