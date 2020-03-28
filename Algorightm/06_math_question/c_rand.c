#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand((int)time(NULL)); // 随机种子
    printf("生成0~32767之间的随机数：\n");
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++)
            printf("%d\t", rand());
        printf("\n");
    }
    printf("\n生成0~100之间的随机数：\n");
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++)
            printf("%d\t", rand()%100); // 输出0~100之间的随机整数
        printf("\n");
    }

    system("pause");

    return 0;
}
