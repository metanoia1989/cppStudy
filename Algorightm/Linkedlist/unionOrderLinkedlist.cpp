#include <iostream>

// 合并两个有序链表 

/**
* definition for singly-inked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addNode(ListNode *li, int val)
{
    ListNode *elem = new ListNode(val);
    li->next = elem;
    li = elem;
    return li;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{

    //判断两个链表是否为空，为空就返回另一个表
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    ListNode *head = (ListNode*)malloc(sizeof(ListNode));//存放头节点
    ListNode *cur = head; 

    //其中一条表为空结束循环
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val <= l2->val) {
            cur = cur->next = l1; //保存指向的节点
            l1 = l1->next;//前往下一个节点
        }else {
            cur = cur->next = l2;
            l2 = l2->next;
        }
    }

    //结束循环，判断哪一个为空表
    if (l1 == nullptr) {
        cur->next = l2;
    }else if( l2 == nullptr){
        cur->next = l1;
    }

    return head->next;
}

void displayLinkedList(ListNode *list)
{
    ListNode *cur = list;
    std::cout << "开始输出链表：";
    while (cur != nullptr) {
        std::cout << cur->val << ", ";
        cur = cur->next;
    } 
    std::cout << std::endl;
}

int main(int argc, const char** argv) {
    ListNode *l1, *l2, *next1, *next2;
    l1 = next1 = new ListNode(1);
    l2 = next2 = new ListNode(11);
    for (size_t i = 2; i < 5; i++)
    {
        next1 = addNode(next1, i);
        next2 = addNode(next2, i + 10);
        std::cout << next1->val << "," << next2->val << std::endl;
    }
    
    displayLinkedList(l1);
    displayLinkedList(l2);
    ListNode *merge = mergeTwoLists(l1, l2);
    displayLinkedList(merge);
}