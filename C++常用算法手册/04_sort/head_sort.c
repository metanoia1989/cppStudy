#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// 堆排序
void HeapSort(int *a, int len)
{
    int i, j, h, k; 
    int t;

    for (i = len/2-1; i >= 0; i--) { // 将 a[0, n-1]建成大根堆
        while (2*i+1 < len) { // 第 i 个节点有右子树
            j = 2*i+1;
            if ((j+1) < len) {
                if (a[j] < a[j+1]) // 左子树小于右子树，则需要比较右子树
                    j++; // 序号增加1，指向右子树
            }
            if (a[i] < a[j]) { // 比较i与j为序号的数据
                t = a[i];
                a[i] = a[j]; 
                a[j] = t;
                i = j; // 堆被破坏，需要重新调整
            } else { // 比较左右子节点均大则堆未破坏，不再需要调整
                break; 
            }
        }
    }

    // 输出构成的堆
    printf("原数据构成的堆：");
    for (h = 0; h < len; h++)
        printf("%d ", a[h]); // 输出
    printf("\n");

    for (i = len - 1; i > 0; i--) {
        t = a[0]; // 与第i个记录交换
        a[0] = a[i];
        a[i] = t;
        k = 0;
        while (2*k+1 < i) { // 第i个结点有右子树
            j = 2*k+1;
            if (j+1 < i) {
                if (a[j] < a[j+1]) // 左子树小于右子树，则需要比较右子树
                    j++;
            }
            if (a[k] < a[j]) { // 比较i与j为需要的数据
                t = a[k];
                a[k] = a[j];
                a[j] = t;
                k = j; // 堆被破坏，需要重新调整
            } else { // 比较左右子节点均大则堆未被破坏，不再需要调整
                break;
            }
        }

        printf("第%d步排序结果：", len - i); // 输出每步排序的结果
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

    HeapSort(shuzu, SIZE); // 排序操作

    printf("排序之后的数组为：\n"); // 输出排序后的数组
    for (int i = 0; i < SIZE; i++)
        printf("%d ", shuzu[i]);
    printf("\n");

    return 0;
}
