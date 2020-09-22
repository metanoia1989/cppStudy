#include <stdio.h>
#include <stdlib.h>

void MatrixPlus(double A[], double B[], int m, int n, double C[])
{
    int j;
    for (int i = 0; i < m*n; i++)
        C[i] = A[i] + B[i]; // 对应项相加
}

int main(int argc, char const *argv[])
{
    double A[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
    }; // 矩阵A
    double B[3][3] = {
        {2.0, -2.0, 1.0},
        {1.0, 3.0, 9.0},
        {17.0, -3.0, 7.0},
    }; // 矩阵B
    double C[3][3]; // 结果矩阵C
    int m = 3, n = 3; // 行数、列数

    printf("矩阵A和B相加的结果为：\n");
    MatrixPlus(*A, *B, m, n, *C);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%10.6f", C[i][j]);
        printf("\n");
    }

    return 0;
}
