#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // 数组大小

// 选择法排序
void SelectionSort(int *a, int len)
{
    int i, j, k, h;
    int temp; // 交换临时变量

    for (i = 0; i < len - 1; i++) {
        k = i;
        for (j = i + 1; j < len; j++) {
            if (a[j] < a[k])
                k = j;
        }
        if (k != i) { // 交换 k 是最小数的索引
            temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        }
        printf("第%d步排序结果：", i); // 输出每步排序的结果
        for (h = 0; h < len; h++)
            printf("%d ", a[h]);
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int shuzu[SIZE];

    srand(time(NULL)); // 随机种子
    for (int i = 0; i < SIZE; i++)
        shuzu[i] = rand() / 1000 + 100; // 初始化数组

    printf("排序之前的数组为：\n"); // 输出排序前的数组
    for (int i = 0; i < SIZE; i++)
        printf("%d ", shuzu[i]);
    printf("\n");

    SelectionSort(shuzu, SIZE); // 排序操作

    printf("排序之后的数组为：\n"); // 输出排序后的数组
    for (int i = 0; i < SIZE; i++)
        printf("%d ", shuzu[i]);
    printf("\n");

    return 0;
}
