#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXLEN 20 // 最大长度
typedef char DATA; // 定义元素类型
typedef struct CBT // 定义二叉树结点类型
{
    DATA data; // 元素数据
    struct CBT *left; // 左子树节点指针
    struct CBT *right; // 右子树节点指针
} CBTType;

CBTType* InitTree();
void AddTreeNode(CBTType *treeNode);
CBTType* TreeFindNode(CBTType *treeNode, DATA data);
CBTType *TreeLeftNode(CBTType *treeNode);
CBTType *TreeRightNode(CBTType *treeNode);
int TreeDepth(CBTType *treeNode);
void ClearTree(CBTType *treeNode);
void TreeNodeData(CBTType *p);
void LevelTree(CBTType *treeNode, void (*TreeNodeData)(CBTType *p));
void DLRTree(CBTType *treeNode, void (*TreeNodeData)(CBTType *p));
void LDRTree(CBTType *treeNode, void (*TreeNodeData)(CBTType *p));
void LRDTree(CBTType *treeNode, void (*TreeNodeData)(CBTType *p));

// 初始化二叉树的根
CBTType* InitTree()
{
    CBTType *node;
    if ((node = (CBTType *)malloc(sizeof(CBTType)))) { // 申请内存
        printf("请先输入一个根结点数据：\n");
        scanf("%s", &node->data);
        node->left = NULL;
        node->right = NULL;
        if (node != NULL) { // 如果二叉树根节点不为空
            return node;
        } else {
            return NULL;
        }
    }
    return NULL;
}

/**
 * 添加结点
 * 添加结点就是在二叉树中添加结点数据。添加结点时除了要输入结点数据外，
 * 还需要指定其父结点，以及添加的结点是作为左子树还是作为右子树。
 */ 
void AddTreeNode(CBTType *treeNode)
{
    CBTType *pnode, *parent;
    DATA data;
    char menusel;

    if((pnode = (CBTType *)malloc(sizeof(CBTType)))) { // 分配内存
        printf("输入二叉树结点数据：\n");
        fflush(stdin); // 清空输入缓冲区
        scanf("%s", &pnode->data);
        pnode->left = NULL;
        pnode->right = NULL;

        printf("输入该节点的父节点数据：");
        fflush(stdin); // 清空输入缓冲区
        scanf("%s", &data);
        parent = TreeFindNode(treeNode, data); // 查找指定数据的节点
        if (!parent) { // 如果未找到
            printf("未找到该父节点！\n");
            free(pnode);
            return;
        }
        printf("1. 添加该结点到左子树\n2. 添加该结点到右子树\n");
        do {
            menusel = getch(); // 输入选择项
            menusel -= '0';
            if (menusel == 1 || menusel == 2) {
                if (parent == NULL) {
                    printf("不存在父结点，请先设置父结点！\n");
                } else {
                    switch (menusel)
                    {
                    case 1: // 添加到左结点
                        if (parent->left) { // 左子树不为空
                            printf("左子树结点不为空！\n");
                        } else {
                            parent->left = pnode;
                        }
                        break;
                    case 2: // 添加到右结点
                        if (parent->right) { // 右子树不为空
                            printf("右子树结点不为空！\n");
                        } else {
                            parent->right = pnode;
                        }
                        break;
                    default:
                        printf("无效参数！\n");
                    }
                }

            }
        } while (menusel != 1 && menusel != 2);

    }
}

/**
 * 查找节点
 * 查找结点就是遍历二叉树中的每一个结点，逐个比较数据，
 * 当找到目标数据时将返回该数据所在结点的指针。
 */
CBTType* TreeFindNode(CBTType *treeNode, DATA data)
{
    CBTType *ptr;
    if (treeNode == NULL) {
        return NULL;
    }

    if (treeNode->data == data) {
        return treeNode;
    }

    // 分别向左右子树递归查找
    if ((ptr = TreeFindNode(treeNode->left, data))) {
        return ptr;
    } else if ((ptr = TreeFindNode(treeNode->right, data))) {
        return ptr;
    }

    return NULL;
}

/**
 * 获取左子树
 * 获取左子树就是返回当前结点的左子树结点的值
 */ 
CBTType *TreeLeftNode(CBTType *treeNode)
{
    if (treeNode) 
        return treeNode->left;

    return NULL;
}

/**
 * 获取右子树
 * 获取右子树就是返回当前结点的右子树结点的值
 */ 
CBTType *TreeRightNode(CBTType *treeNode)
{
    if (treeNode) 
        return treeNode->right;

    return NULL;
}

/**
 * 判断空树
 * 判断空树就是判断一个二叉树结构是否为空。
 */ 
int TreeIsEmpty(CBTType *treeNode)
{
    if (treeNode)
        return 0;

    return 1;
}

/**
 * 计算二叉树深度
 * 计算二叉树深度就是计算二叉树中结点的最大层数，
 * 这里往往需要采用递归算法来实现。
 */ 
int TreeDepth(CBTType *treeNode)
{
    int depleft, depright;

    if (treeNode == NULL)
        return 0;

    depleft = TreeDepth(treeNode->left); // 左子树深度 递归调用
    depright = TreeDepth(treeNode->right); // 右子树深度 递归调用
    if (depleft > depright) {
        return depleft + 1;
    } else {
        return depright + 1;
    }
}

/**
 * 清空二叉树
 * 清空二叉树就是将二叉树变成一个空树，这里也需要使用递归算法来实现。
 */ 
void ClearTree(CBTType *treeNode)
{
    if (treeNode) {
        ClearTree(treeNode->left); // 清空左子树
        ClearTree(treeNode->right); // 清空右子树
        free(treeNode); // 释放当前节点所占内存
        treeNode = NULL;
    }
}

/**
 * 显示结点数据
 * 显示结点数据就是显示当前结点的数据内容
 */ 
void TreeNodeData(CBTType *p)
{
    printf("%c", p->data);
}

/**
 * 按层遍历算法
 * 按层遍历算法是最直观的遍历算法。首先处理第 1 层即根结点，再处理第 1 根结点的左右子树，
 * 也即是第 2 层 … … 就这样循环处理，就可以逐层遍历。
 */ 
void LevelTree(CBTType *treeNode, void (*TreeNodeData)(CBTType *p))
{
    CBTType *p;
    CBTType *q[MAXLEN]; // 定义一个顺序栈
    int head = 0, tail = 0;

    if (treeNode) { // 如果队首指针不为空
        tail = (tail + 1) % MAXLEN; // 计算循环队列队尾序号
        q[tail] = treeNode; // 将二叉树根指针进队
    }

    while (head != tail) { // 队列不为空，进行循环
        head = (head + 1) % MAXLEN; // 计算循环队列的队首序号
        p = q[head]; // 获取队首元素
        TreeNodeData(p); // 处理队首元素
        if (p->left != NULL) { // 如果节点存在左子树
            tail = (tail + 1) % MAXLEN; // 计算循环队列的队尾序号
            q[tail] = p->left; // 将左子树指针进队
        }

        if (p->right != NULL) { // 如果结点存在右子树
            tail = (tail + 1) % MAXLEN; // 计算循环队列的队尾序号
            q[tail] = p->right; // 将右子树指针进队
        }
    }

}

/**
 * 先序遍历算法
 * 先序遍历算法就是先按中序遍历左子树，再访问根结点，鉍后按中序遍历右子树。
 * 程序中可以按照递归的思路来遍历整个二叉树。
 */
void DLRTree(CBTType *treeNode, void (*TreeNodeData)(CBTType *p))
{
    if (treeNode) {
        TreeNodeData(treeNode); // 显示结点的数据
        DLRTree(treeNode->left, TreeNodeData); 
        DLRTree(treeNode->right, TreeNodeData); 
    }
} 

/**
 * 中序遍历算法
 * 中序遍历算法就是先访问根结点，再按先序遍历左子树，最后按先序遍历右子树。
 * 程序中可以按照递归的思路來遍历整个二叉树。
 */ 
void LDRTree(CBTType *treeNode, void (*TreeNodeData)(CBTType *p))
{
    if (treeNode) {
        LDRTree(treeNode->left, TreeNodeData); 
        TreeNodeData(treeNode); // 显示结点的数据
        LDRTree(treeNode->right, TreeNodeData); 
    }
} 

/**
 * 后序遍历算法
 * 后序遍历算法就是先按后序遍历左子树，再按后序遍历右子树，鉍后访问根结点。
 * 程序中可以按照递归的思路来遍历整个二叉树。
 */ 
void LRDTree(CBTType *treeNode, void (*TreeNodeData)(CBTType *p))
{
    if (treeNode) {
        LRDTree(treeNode->left, TreeNodeData); 
        LRDTree(treeNode->right, TreeNodeData); 
        TreeNodeData(treeNode); // 显示结点的数据
    }
} 


// 二叉树操作函数
int main(int argc, char const *argv[])
{
    CBTType *root = NULL; // root为指向二叉树根结点的指针
    char menusel;
    void (*TreeNodeData1)(); // 指向函数的指针
    TreeNodeData1 = TreeNodeData; // 指向具体操作的函数

    // 设置根元素
    root = InitTree();

    // 添加结点
    do {
        printf("请选择菜单添加二叉树的结点\n");
        printf("0. 退出\t"); 
        printf("1. 添加二叉树的结点\n");
        menusel = getch();
        switch (menusel)
        {
        case '1': // 添加结点
            AddTreeNode(root);
            break;
        case '0':
            break; 
        default:
            break;
        }
    } while (menusel != '0');

    // 遍历
    do {
        printf("请选择菜单遍历二叉树，输入0表示退出：\n");
        printf("1. 先序遍历DLR\t");
        printf("2. 中序遍历LDR\t");
        printf("3. 后序遍历LRD\t");
        printf("4. 按层遍历\n");
        menusel = getch();
        switch (menusel)
        {
        case '0':
            break;
        case '1': // 先序遍历
            printf("\n先序遍历DLR的结果：");
            DLRTree(root, TreeNodeData1);
            printf("\n");
            break;
        case '2': // 中序遍历
            printf("\n中序遍历LDR的结果：");
            LDRTree(root, TreeNodeData1);
            printf("\n");
            break;
        case '3': // 后序遍历
            printf("\n后序遍历LRD的结果：");
            LRDTree(root, TreeNodeData1);
            printf("\n");
            break;
        case '4': // 按层遍历
            printf("\n按层遍历的结果：");
            LevelTree(root, TreeNodeData1);
            printf("\n");
            break;
        default:
            break;
        }
    } while (menusel != '0');

    printf("\n二叉树深度为：%d\n", TreeDepth(root));

    ClearTree(root); // 清空二叉树
    root = NULL;

    return 0;
}
