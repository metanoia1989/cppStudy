#include <stdio.h>

/**
 * 穷举法算鸡兔同笼问题
 */ 
int qiongju(int head, int foot, int *chicken, int *rabbit)
{
    int i, j;
    for (i = 0; i <= head; i++) {
        j = head - i;
        if (i*2 + j*4 == foot) { // 判断，找到答案
            *chicken = i;
            *rabbit = j;
            return 1;
        }
    }
    return 0;
}

/**
 * 孙子算经：今有鸡兔同笼，上有三十五头，下有九十四足，问鸡兔各几何?
 */ 
int main(int argc, char const *argv[])
{
    int chicken, rabiit, head, foot;
    int re;
    
    printf("穷举法求解鸡兔同笼问题：\n");
    printf("输入头数：");
    scanf("%d", &head); // 输入头数
    printf("输入脚数：");
    scanf("%d", &foot); // 输入脚数

    re = qiongju(head, foot, &chicken, &rabiit);
    if (re) {
        printf("鸡有：%d只，兔子有：%d只。\n", chicken, rabiit);
    } else {
        printf("无法求解！\n");
    }

    return 0;
}
