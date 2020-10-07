#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 18 // 数组大小

void QuickSort(int *arr, int left, int right)
{
    int f, t;
    int rtemp, ltemp;

    ltemp = left;
    rtemp = right;

    f = arr[(left + right) / 2]; // 分界值
    while (ltemp < rtemp) {
        while (arr[ltemp] < f)
            ++ltemp;
        while (arr[rtemp] > f)
            --rtemp;
        if (ltemp <= rtemp) {
            t = arr[ltemp];
            arr[ltemp] = arr[rtemp];
            arr[rtemp] = t;
            --rtemp;
            ++ltemp;
        }
    }

    if (ltemp == rtemp)
        ltemp++;

    if (left < rtemp)
        QuickSort(arr, left, ltemp - 1);

    if (ltemp < right)
        QuickSort(arr, rtemp + 1, right);
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

    QuickSort(shuzu, 0, SIZE-1); // 排序操作

    printf("排序之后的数组为：\n"); // 输出排序后的数组
    for (int i = 0; i < SIZE; i++)
        printf("%d ", shuzu[i]);
    printf("\n");

    return 0;
}
