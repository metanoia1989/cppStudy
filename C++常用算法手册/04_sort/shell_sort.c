#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // 数组大小

void ShellSort(int *arr, int len)
{
    int x = 0;
    for (int gap = len/2; gap >= 1; gap /= 2) { // 划组排序
        for (int i = gap; i < len; i++) {
            int temp = arr[i];
            int offset = i - gap;
            while (offset >= 0 && temp < arr[offset]) {
                arr[offset+gap] = arr[offset];
                offset -= gap;
            }
            arr[offset+gap] = temp;
        }
        x++;
        printf("gap=%d, 第%d步排序结果：", gap, x);
        for (int h = 0; h < len; h++)
            printf("%d ", arr[h]);
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

    ShellSort(shuzu, SIZE); // 排序操作

    printf("排序之后的数组为：\n"); // 输出排序后的数组
    for (int i = 0; i < SIZE; i++)
        printf("%d ", shuzu[i]);
    printf("\n");

    return 0;
}
