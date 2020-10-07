#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// 冒泡排序法
void BubbleSort(int *a, int len)
{
    int i, j, k, temp; 

    for (i = 0; i < len - 1; i++) { // 外层循环
        for (j = len - 1; j > i; j--)  { // 内层循环
            if (a[j-1] > a[j]) {
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
        printf("第%d步排序结果：", i); // 输出每步排序的结果
        for (k = 0; k < len; k++)
            printf("%d ", a[k]); 
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

    BubbleSort(shuzu, SIZE); // 排序操作

    printf("排序之后的数组为：\n"); // 输出排序后的数组
    for (int i = 0; i < SIZE; i++)
        printf("%d ", shuzu[i]);
    printf("\n");

    return 0;
}
