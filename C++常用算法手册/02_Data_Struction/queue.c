#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define QUEUELEN 15

typedef struct
{
    char name[10];
    int age;
} DATA;

typedef struct 
{
    DATA data[QUEUELEN]; // 队列数组
    int head;   // 队头的序号
    int tail;   // 队尾的序号
} SQType;

// 初始化队列结构
SQType* SQTypeInit()
{
    SQType *q;
    if ((q=(SQType *)malloc(sizeof(SQType)))) { // 申请内存
        q->head = 0;    // 设置队头
        q->tail = 0;    // 设置队尾
        return q;
    }
    printf("申请内存失败！\n");
    return NULL;
}

// 判断空队列
int SQTypeIsEmpty(SQType *q)
{
    int temp;
    temp = q->head == q->tail;
    return temp;
}

// 判断满队列
int SQTypeIsFull(SQType *q)
{
    int temp;
    temp = q->tail == QUEUELEN;
    return temp;
}

// 清空队列
void SQTypeClear(SQType *q)
{
    q->head = 0; // 设置队头的序号
    q->tail = 0; // 设置队尾的序号
}

// 释放队列的内存空间
void SQTypeFree(SQType *q)
{
    if (q != NULL)
        free(q);
}

// 入队列
int InSQType(SQType *q, DATA data)
{
    if (q->tail == QUEUELEN) {
        printf("队列已满！操作失败！\n");
        return 0;
    }
    q->data[q->tail++] = data; // 将元素入队列
    return 1;
}

// 出队列
DATA* OutSQType(SQType *q)
{
    if (q->head == q->tail) {
        printf("\n队列已空！操作失败！\n");
        exit(0);
    }
    return &(q->data[q->head++]);
}

// 读取队列头的数据
DATA* PeekSQType(SQType *q)
{
    if (SQTypeIsEmpty(q)) {
        printf("\n空队列！\n");
        return NULL;
    }
    return &(q->data[q->head]);
}

// 计算队列中数据结点数量
int SQTypeLen(SQType *q)
{
    int temp;
    temp = q->tail - q->head;
    return temp;
}

int main(int argc, char const *argv[])
{
    SQType *stack;
    DATA data;
    DATA *data1;

    stack = SQTypeInit(); // 初始化队列
    printf("入队列操作：\n");
    printf("输入姓名 年龄进行入队列操作：\n");
    while (1) {
        scanf("%s%d", data.name, &data.age);
        if (strcmp(data.name, "0") == 0) 
            break;
        InSQType(stack, data);
    }

    while (1) {
        printf("出队列操作：按任意键进行出栈操作：\n");
        getchar();
        data1 = OutSQType(stack);
        printf("出队列的数据是（%s, %d）\n", data1->name, data1->age);
    }

    SQTypeFree(stack);

    return 0;
}
