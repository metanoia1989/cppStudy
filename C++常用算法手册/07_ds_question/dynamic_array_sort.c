#include <string.h>
#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    char data;
    struct node *next;
} LNode, *LinkList;

LinkList createLinkList()
{
    char ch;
    LinkList list = NULL;

    scanf("%c", &ch);
    list = (LinkList)malloc(sizeof(LNode));
    list->data = ch;
    list->next = NULL;

    return list;
}

void insertList(LinkList *list, LinkList q, char e)
{
    LinkList p;
    p = (LinkList)malloc(sizeof(LNode));
    p->data = e;
    if (!*list) {
        *list = p;
        p->next = NULL;
    } else {
        p->next = q->next;
        q->next = p;
    }
}

// 动态数组排序
void dynamicSort(LinkList q)
{
    LNode *p = q;
    int k = 0;
    char t;

    while (p) {
        k++;
        p = p->next;
    }
    p = q;
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (p->data > p->next->data) {
                t = p->data;
                p->data = p->next->data;
                p->next->data = t;
            }
            p = p->next;
        }
        p = q;
    }
}

int main(int argc, char const *argv[])
{
    char ch;
    LinkList list, q;
    printf("动态数组排序！\n");
    printf("请输入一组字符，以0结束！\n");
    q = list = createLinkList(); // 创建一个链表结点

    scanf("%c", &ch); // 动态输入数据
    while (ch != '0') {
        insertList(&list, q, ch);
        q = q->next;
        scanf("%c", &ch);
    }
    dynamicSort(list); // 动态数组排序
    printf("\n");
    printf("对该数据排序之后，得到如下结果：\n");
    while (list) {
        printf("%c", list->data); // 输出排序后的数组内容
        list = list->next;
    }
    printf("\n");

    return 0;
}
