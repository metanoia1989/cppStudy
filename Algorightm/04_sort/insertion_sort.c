#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10     // 数组大小

// 插入排序
void InsertionSort(int *a, int len)
{
    int perIndex, current;

    for (int i = 1; i < len; i++) {
        current = a[i];
        perIndex = i - 1;
        while (perIndex >= 0 && current < a[perIndex]) {
            a[perIndex+1] = a[perIndex];
            perIndex--;
        }
        a[perIndex+1] = current;

        printf("第%d步排序结果：", i);
        for (int h = 0; h < len; h++)
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

    InsertionSort(shuzu, SIZE); // 排序操作

    printf("排序之后的数组为：\n"); // 输出排序后的数组
    for (int i = 0; i < SIZE; i++)
        printf("%d ", shuzu[i]);
    printf("\n");

    return 0;
}
