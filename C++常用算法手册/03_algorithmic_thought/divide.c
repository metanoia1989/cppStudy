#include <stdio.h>

#define MAXNUM 30 // 最大数量

// 分治算法找假币
int FalseCoin(int coin[], int low, int high)
{
    int i, sum1, sum2, sum3;
    int re;

    sum1 = sum2 = sum3 = 0;
    if (low + 1 == high) {
        if (coin[low] < coin[high]) {
            re = low + 1;
            return re;
        } else {
            re = high + 1;
            return re;
        }
    }

    if ((high - low + 1)%2 == 0) { // 是偶数
        for (i = low; i <= low + (high - low) / 2; i++) 
            sum1 += coin[i]; // 前半段和
        for (i = low + (high - low)/2; i <= high; i++)
            sum2 += coin[i]; // 后半段和
        if (sum1 > sum2) {
            re = FalseCoin(coin, low + (high - low)/2 + 1, high);
            return re;
        } else if (sum1 < sum2) {
            re = FalseCoin(coin, low, low + (high - low) / 2);
            return re;
        } 
    } else {
        for (i = low; i <= low + (high - low) / 2 - 1; i++) 
            sum1 += coin[i]; // 前半段和
        for (i = low + (high - low)/2 + 1; i <= high; i++)
            sum2 += coin[i]; // 后半段和
        sum3 = coin[low + (high - low) / 2];
        if (sum1 > sum2) {
            re = FalseCoin(coin, low + (high - low)/2 + 1, high);
            return re;
        } else if (sum1 < sum2) {
            re = FalseCoin(coin, low, low + (high - low) / 2 - 1);
            return re;
        }
        if (sum1 + sum3 == sum2 + sum3) {
            re = low + (high - low) / 2 + 1;
            return re;
        }

    }
}

int main(int argc, char const *argv[])
{
    int coin[MAXNUM];
    int i, n;
    int weizhi;
    printf("分治算法求解假银币问题！\n");
    printf("请输入假银币总的个数：");
    scanf("%d", &n); // 银币总的个数
    printf("请输入银币的真假：");
    for (i = 0; i < n; i++)
        scanf("%d", &coin[i]); // 输入银币的真假
    weizhi = FalseCoin(coin, 0, n - 1); // 求解
    printf("在上述%d个银币中，第%d个银币是假的!\n", n, weizhi);

    return 0;
}
