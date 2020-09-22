#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 50 // 栈的最大长度

typedef struct
{
    char name[10];
    int age;
} DATA; // 栈结构数据元素类型

typedef struct stack
{
    DATA data[SIZE+1]; // 数据元素
    int top; // 栈顶
} StackType;

// 初始化栈结构
StackType* STInit()
{
    StackType *p;
    // 申请栈内存
    if ((p = (StackType *)malloc(sizeof(StackType)))) {
        p->top = 0; // 设置栈顶为0
        return p; // 返回指向栈的指针
    }
    printf("初始化栈失败\n");
    return NULL;
}

// 判断栈是否为空
int STIsEmpty(StackType *s)
{
    int t;
    t = (s->top == 0);
    return t;
}

// 判断栈是否已满
int STIsFull(StackType *s)
{
    int t;
    t = (s->top == SIZE);
    return t;
}

// 清空栈
void STClear(StackType *s)
{
    s->top = 0;
}

// 释放栈所占用的空间
void STFree(StackType *s)
{
    if (s)
        free(s);
}

// 入栈操作
int PushST(StackType *s, DATA data)
{
    if (s->top + 1 > SIZE) {
        printf("栈溢出！\n");
        return 0;
    }
    s->data[++s->top] = data; // 将元素入栈
    return 1;
}

// 出栈操作
DATA PopST(StackType *s)
{
    if (s->top == 0) {
        printf("栈为空!\n");
        exit(0);
    }
    return (s->data[s->top--]);
}

// 读取栈顶数据
DATA PeekST(StackType *s)
{
    if (s->top == 0) {
        printf("栈为空!\n");
        exit(0);
    }
    return (s->data[s->top]);
}

int main(int argc, char const *argv[])
{
    StackType *stack;
    DATA data, data1;

    stack = STInit(); // 初始化栈
    printf("入栈操作：\n");
    printf("输入姓名 年龄进行入栈操作：\n");
    while (1) {
        scanf("%s%d", data.name, &data.age);
        if (strcmp(data.name, "0") == 0) {
            break; // 若输入0，则退出
        }
        PushST(stack, data);
    }
    fflush(stdin);
    while (1) {
        printf("\n出栈操作：按任意键进行出栈操作：\n");
        getchar();
        data1 = PopST(stack);
        printf("出栈的数据是(%s,%d)\n", data1.name, data1.age);
    }

    STFree(stack); // 释放栈所占用的空间

    return 0;
}
