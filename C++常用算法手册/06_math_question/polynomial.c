/**
 * 多项式（ Polynomial) 是基础数学中常用到的概念，多项式就是若干个单项式的和构成的式子。
 * 多项式中每个单项式称为多项式的项，多项式项的最高次数称为多项式的次数，不含字母的项称为常数项。 
 */ 

#include <stdio.h>

double polynomial1D(double arr[], int len, double x)
{
    double result;
    result = arr[len - 1];
    for (int i = len - 2; i >= 0; i--) // 递推算法计算
        result = result * x + arr[i];
    return result;
}

int main(int argc, char const *argv[])
{
    static double a[7] = {-15.0, -7.0, 7.0, 2.0, -3.0, 7.0, 3.0};
    static double x[6] = {-2.0, -0.5, 1.0, 2.0, 3.7, 4.0};
    double result;

    printf("\n");
    for (int i = 0; i < 6; i++) { // 逐个计算结果
        result = polynomial1D(a, 7, x[i]);
        printf("x=%5.2lf时，p(x)=%13.7e\n", x[i], result);
    }
    return 0;
}
