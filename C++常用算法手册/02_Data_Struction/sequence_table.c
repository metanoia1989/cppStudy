#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAXLEN 100 // 定义顺序表的最大长度

typedef struct 
{
    char key[10]; // 结点的关键字
    char name[20];
    int age;
} DATA; // 定义结点类型

typedef struct // 定义顺序表结构
{
    DATA ListData[MAXLEN+1]; // 保存顺序表的结构数组
    int ListLen; // 顺序表已存结点的数量
} SLType;

// 初始化顺序表
void SLInit(SLType *SL)
{
    SL->ListLen = 0; // 初始化为空表
}

// 计算顺序表长度
int SLLength(SLType *SL)
{
    return SL->ListLen; // 返回顺序表的元素数量
}

// 插入节点
int SLInsert(SLType *SL, int n, DATA data)
{
    int i;
    if (SL->ListLen >= MAXLEN) { // 顺序表节点数量已超过最大数量
        printf("顺序表已满，不能插入节点\n");
        return 0; // 返回0 表示插入不成功
    }
    if (n < 1 || n > SL->ListLen - 1) { // 插入节点序号不正确
        printf("插入元素序号错误，不能插入元素！\n");
        return 0;
    }
    for (i = SL->ListLen; i >= n; i--) // 将顺序表中的数据向后移动
        SL->ListData[i+1] = SL->ListData[i];

    SL->ListData[n] = data; // 插入节点
    SL->ListLen++; // 顺序表节点数量增加1
    return 1;
}

// 追加节点，增加元素到顺序表尾部
int SLAdd(SLType *SL, DATA data)
{
    if (SL->ListLen >= MAXLEN) {
        printf("顺序表已满，不能插入节点\n");
        return 0; // 返回0 表示插入不成功
    }
    SL->ListData[++SL->ListLen] = data;
    return 1;
}

// 删除节点，删除顺序表中的数据元素
int SLDelete(SLType *SL, int n)
{
    int i;
    if (n < 1 || n > SL->ListLen + 1) {
        printf("删除结点序号错误，不能删除节点!\n");
        return 0;
    }
    for (i = n; i < SL->ListLen; i++) // 将顺序表中的数据向前移动
        SL->ListData[i] = SL->ListData[i+1];
    SL->ListLen--;
    return 1;
}

// 根据序号返回数据元素
DATA* SLFindByNum(SLType *SL, int n)
{
    if (n < 1 || n > SL->ListLen + 1) {
        printf("结点序号错误，不能返回结点！\n");
        return NULL;
    }
    return &(SL->ListData[n]);
}

// 按关键字查询节点
int SLFindByCont(SLType *SL, char *key)
{
    int i;
    for (i = 1; i <= SL->ListLen; i++) {
        // 如果找到所需节点，返回结点序号
        if (strcmp(SL->ListData[i].key, key) == 0)
            return i;
    }
    return 0; // 搜索整个表后仍没有找到
}

// 显示顺序表中的所有节点
int SLAll(SLType *SL)
{
    for (int i = 0; i <= SL->ListLen; i++)
        printf("(%s,%s,%d)\n", SL->ListData[i].key, SL->ListData[i].name, 
            SL->ListData[i].age);    
    return 0;
}

int main(int argc, char const *argv[])
{
    int i; 
    SLType SL; // 定义顺序表变量
    DATA data; // 定义结点保存数据类型变量
    DATA *pdata; // 定义结点保存指针变量
    char key[10]; // 保存关键字

    printf("顺序表操作演示！\n");
    SLInit(&SL);
    printf("初始化顺序表完成!\n");

    do { // 循环添加节点数据
        printf("输入添加的结点(学号 姓名 年龄): ");
        fflush(stdin); // 清空输入缓冲区
        scanf("%s%s%d", &data.key, &data.name, &data.age);
        if (data.age) { // 若年龄不为0
            if (!SLAdd(&SL, data)) // 若添加节点失败
                break;
        } else {
            break;
        }
    } while (1);
    printf("\n 顺序表中的节点顺序为：\n");
    SLAll(&SL);  // 显示所有节点数据

    fflush(stdin); // 清空输入缓冲区
    printf("\n 要取出结点的序号：");
    scanf("%d", &i); // 输入节点序号
    pdata = SLFindByNum(&SL, i);
    if (pdata)
        printf("第%d个节点为：(%s, %s, %d)\n", i, pdata->key, pdata->name, pdata->age);

    fflush(stdin); // 清空输入缓冲区
    printf("\n 要查找结点的关键字：");
    scanf("%s", key); // 输入关键字
    i = SLFindByCont(&SL, key); // 按关键字查找
    pdata = SLFindByNum(&SL, i); // 按序号查询，返回结点指针
    if (pdata)  // 若结点指针不为NULL
        printf("第%d个节点为：(%s, %s, %d)\n", i, pdata->key, pdata->name, pdata->age);
    getch();

    return 0;
}
