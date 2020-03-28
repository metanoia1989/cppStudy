#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15 // 数组大小

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

// 折半查找
int SearchFun(int arr[], int len, int x)
{
    int mid, low, high;

    low = 0;
    high = len - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == x) { // 查找到返回
            return mid;
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int shuzu[SIZE], x, n, i;

    srand(time(NULL)); // 随机种子
    for (int i = 0; i < SIZE; i++)
        shuzu[i] = rand() / 1000 + 100; // 初始化数组

    printf("折半查找算法演示！\n");
    printf("排序之前的数组为：\n"); // 输出排序前的数组
    for (int i = 0; i < SIZE; i++)
        printf("%d ", shuzu[i]);
    printf("\n\n");

    QuickSort(shuzu, 0, SIZE-1); // 排序操作
    printf("排序之后的数组为：\n"); // 输出排序后的数组
    for (int i = 0; i < SIZE; i++)
        printf("%d ", shuzu[i]);
    printf("\n\n");

    printf("输入要查找的数：");
    scanf("%d", &x); // 输入要查找的数

    n = SearchFun(shuzu, SIZE, x); // 查找
    if (n == -1) {
        printf("没找到数据：%d\n", x);
    } else {
        printf("数据：%d位于数组的第%d个元素处.\n", x, n + 1);
    }

    return 0;
}
