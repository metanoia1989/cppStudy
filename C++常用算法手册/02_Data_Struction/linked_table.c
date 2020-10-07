#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char key[10]; // 关键字
    char name[20];
    int age;
} Data; // 数据节点类型

typedef struct Node // 定义链表结构
{
    Data nodeData;
    struct Node *nextNode;
} CLType;

// 追加节点
CLType* CLAddEnd(CLType *head, Data nodeData)
{
    CLType *node, *htemp;
    if (!(node = (CLType*)malloc(sizeof(CLType)))) {
        printf("申请内存失败！\n");
        return NULL;
    } 
        
    node->nodeData = nodeData; // 保存数据
    node->nextNode = NULL; // 设置结点指针为空，即为表尾
    if (head == NULL) {
        head = node;
        return head;
    }

    htemp = head;
    // 查找链表的末尾
    while (htemp->nextNode != NULL) {
        htemp = htemp->nextNode;
    }
    htemp->nextNode = node;
    return head;
}

// 插入头节点
CLType* CLAddFirst(CLType *head, Data nodeData)
{
    CLType *node;
    if (!(node = (CLType *)malloc(sizeof(CLType)))) {
        printf("申请内存失败！\n");
        return NULL; // 分配内存鼠标
    }
    node->nodeData = nodeData; // 保存数据
    node->nextNode = head; // 指向头指针所指节点
    head = node; // 头指针指向新增节点
    return head;
}

// 查找节点，通过关键字
CLType* CLFindNode(CLType *head, char *key)
{
    CLType *htemp; 
    htemp = head; // 保存链表头指针
    while (htemp) { // 若结点有效，则进行查找
        if (strcmp(htemp->nodeData.key, key) == 0) 
            return htemp; 
        htemp = htemp->nextNode; // 处理下一结点
    }
    return NULL; // 返回空指针
}

// 插入结点，指定位置新增结点
CLType* CLInsertNode(CLType *head, char *findkey, Data nodeData)
{
    CLType *node, *nodetemp;
    if (!(node = (CLType *)malloc(sizeof(CLType)))) {
        printf("申请内存失败！\n");
        return 0;   // 分配内存失败
    }
    node->nodeData = nodeData; // 保存结点中的数据

    nodetemp = CLFindNode(head, findkey); 
    if (nodetemp) { // 若找到要插入的节点
        node->nextNode = nodetemp->nextNode; // 新插入结点指向关键结点的下一结点
        nodetemp->nextNode = node; // 设置关键结点指向新插入结点
    } else {
        printf("未找到正确的插入位置！\n");
        free(node);
    }
    return head;
}

// 删除结点
int CLDeleteNode(CLType *head, char *key)
{
    CLType *node, *htemp; // node 保存删除结点的前一结点
    htemp = head;
    node = head;
    while (htemp) {
        // 找到关键字，进行删除操作
        if(strcmp(htemp->nodeData.key, key) == 0) {
            node->nextNode = htemp->nextNode;
            free(htemp);
            return 1;
        } else {
            node = htemp; // 指向当前节点
            htemp = htemp->nextNode; // 指向下一结点
        }
    }
    return 0; // 未删除
}

// 计算链表长度，遍历整个链表
int CLLength(CLType *head)
{
    CLType *htemp;
    int Len = 0;
    htemp = head;
    while (htemp) { // 遍历整个链表
        Len++; // 累加结点数量
        htemp = htemp->nextNode; // 处理下一结点
    }
    return Len; // 返回节点数量
}

// 打印所有节点
void CLAllNode(CLType *head)
{
    CLType *htemp;
    Data nodeData;
    htemp = head;
    printf("当前链表共有%d个结点。链表所有数据如下:\n", CLLength(head));
    while (htemp) { // 遍历链表
        nodeData = htemp->nodeData; // 获取节点数据
        printf("结点(%s, %s, %d)\n", nodeData.key, nodeData.name,
            nodeData.age);
        htemp = htemp->nextNode; // 处理下一结点
    }
}

int main(int argc, char const *argv[])
{
    CLType *node, *head = NULL;
    Data nodeData;
    char key[10], findkey[10];

    /** 追加结点 */ 
    printf("链表测试。先输入链表中的数据，格式为：关键字 姓名 年龄\n");
    while (1) {
        fflush(stdin);
        scanf("%s", nodeData.key);
        if (strcmp(nodeData.key, "0") == 0)
            break; // 若输入0，则退出
        scanf("%s%d", nodeData.name, &nodeData.age);
        head = CLAddEnd(head, nodeData); // 在链表尾部添加结点
    }
    CLAllNode(head); // 显示所有结点

    /** 插入结点 */ 
    printf("\n 演示插入结点，输入插入位置的关键字：");
    scanf("%s", &findkey); // 输入插入位置关键字
    printf("输入插入结点的数据（关键字 姓名 年龄）：");
    scanf("%s%s%d", nodeData.key, nodeData.name, &nodeData.age);
    head = CLInsertNode(head, findkey, nodeData); // 调用插入函数
    CLAllNode(head);

    /** 删除结点 */ 
    printf("\n演示删除节点，输入要删除的关键字");
    fflush(stdin); // 清空输入缓冲区
    scanf("%s", key);
    CLDeleteNode(head, key);
    CLAllNode(head);

    /** 查找结点 */ 
    printf("\n 演示在链表中查找，输入查找关键字：");
    fflush(stdin); // 清空输入缓冲区
    scanf("%s", key);
    node = CLFindNode(head, key);
    if (node) {
        nodeData = node->nodeData;
        printf("关键字%s对应的结点为(%s,%s,%d)\n", key, nodeData.key, 
            nodeData.name, nodeData.age);
    } else {
        printf("在链表中未找到关键字为%s的结点！\n", key);
    }

    return 0;
}
