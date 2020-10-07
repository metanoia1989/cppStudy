#include <stdio.h>

#define MaxNum 20 // 图的最大顶点数
#define MaxValue 65535 // 最大值，可设置的最大整数

typedef struct
{
    char Vertex[MaxNum]; // 保存顶点信息（序号或字母）
    int GType; // 图的类型（0：无向图，1：有向图）
    int VertexNum; // 顶点的数量
    int EdgeNum; // 边的数量
    int EdgeWeight[MaxNum][MaxNum]; // 保存边的权
    int isTrav[MaxNum]; // 遍历标志
} GraphMatrix; // 定义邻接矩阵图结构

/**
 * 创建邻接矩阵图
 * 输入参数GM为一个指向图结构的指针。程序中，由用户输入顶点信息和边的信息。
 * 对于边来说，需要输入起始顶点、结朿顶点和权值，各项之间以空格分割。
 * 最后，判断是否为无向图，因为无向图还需将边的权值保存到对角位置。
 */ 
void CreateGraph(GraphMatrix *GM)
{
    int i, j, k;
    int weight; // 权
    char EstartV, EendV; // 边的起始顶点

    printf("输入图中各项顶点信息\n");
    for (i = 0; i < GM->VertexNum; i++) { // 输入顶点
        getchar();
        printf("第%d个顶点：", i + 1);
        scanf("%c", &(GM->Vertex[i])); // 保存到各项点数组元素中
    }

    printf("输入构成各边的顶点及权值：\n");
    for (k = 0; i < GM->EdgeNum; k++) { // 输入边的信息
        getchar();
        printf("第%d条边：", k + 1);
        scanf("%c%c%d", &EstartV, &EendV, &weight);
        for (i = 0; EstartV != GM->Vertex[i]; i++); // 在已有顶点中查找始点
        for (j = 0; EendV != GM->Vertex[j]; j++); // 在已有顶点中查找终点
        GM->EdgeWeight[i][j] = weight; // 对应位置保留权值，表示有一条边
        if (GM->GType == 0) // 若是无向图
            GM->EdgeWeight[j][i] = weight; // 在对角位置保存权值

    }
}

/**
 * 清空图
 * 清空图就是将一个图结构变成一个空图，这里只需将矩阵中各个元素设置为 M axValue 即可。
 */ 
void ClearGraph(GraphMatrix *GM)
{
    int i, j;
    for (i = 0; i < GM->VertexNum; i++) { // 清空矩阵
        for (j = 0; j < GM->VertexNum; j++)
            GM->EdgeWeight[i][j] = MaxValue; // 设置矩阵中各元素的值为MaxValue
    }
}

/**
 * 显示图
 * 显示图就是显示图的邻接矩阵，用户可以通过邻接矩阵方便地了解图的顶点和边等结构信息。
 */ 
void OutGraph(GraphMatrix *GM)
{
    int i, j;
    for (j = 0; j < GM->VertexNum; j++)
        printf("\t%c", GM->Vertex[i]); // 在第1行输出顶点信息
    printf("\n");
    for (i = 0; i < GM->VertexNum; i++) {
        printf("%c", GM->Vertex[i]);
        for (j = 0; j < GM->VertexNum; j++) {
            if (GM->EdgeWeight[i][j] == MaxValue) { // 若权值为最大值
                printf("\tZ");
            } else {
                printf("\t%d", GM->EdgeWeight[i][j]); // 输出边的权值
            }
        }
        printf("\n");
    }
}

/**
 * 从第N个结点开始，深度优先遍历图
 */ 
void DeepTraOne(GraphMatrix *GM, int n)
{
    int i;
    GM->isTrav[n] = 1; // 标记该顶点已处理过
    printf("->%c", GM->Vertex[n]); // 输出结点数据 

    // 添加处理结点的操作
    for (i = 0; i < GM->VertexNum; i++) {
        if (GM->EdgeWeight[n][i] != MaxValue && !GM->isTrav[n])
            DeepTraOne(GM, i); // 递归进行遍历
    }
}

/**
 * 深度优先遍历图
 */ 
void DeepTraGraph(GraphMatrix *GM)
{
    int i;
    for (i = 0; i < GM->VertexNum; i++) // 清除各顶点遍历标志
        GM->isTrav[i] = 0;
    printf("深度优先遍历结点：");
    for (i = 0; i < GM->VertexNum; i++) {
        if (!GM->isTrav[i]) // 若该点未遍历
            DeepTraOne(GM, i); // 调用函数遍历
    }
    printf("\n");
}

// 主测试函数
int main(int argc, char const *argv[])
{
    GraphMatrix GM; // 定义保存邻接表结构的图

    printf("输入生成图的类型：");
    scanf("%d", &GM.GType); // 图的种类

    printf("输入图的顶点数量：");
    scanf("%d", &GM.VertexNum); // 输入图顶点数

    printf("输入图的边数量：");
    scanf("%d", &GM.EdgeNum); // 输入图边数

    ClearGraph(&GM); // 清空图
    CreateGraph(&GM); // 生成邻接表结构的图

    printf("该图的邻接矩阵数据如下：\n"); 
    OutGraph(&GM); // 输出邻接矩阵
    DeepTraGraph(&GM); // 深度优先搜索遍历图

    return 0;
}
