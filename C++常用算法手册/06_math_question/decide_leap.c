/**
 * 判断闰年：四年一闰，百年不闰，四百年再闰
 * 闰年问题是历法上的一种折中，主要是弥补因人为制定的历法而造成的年度天数与地球实际公转周期的时间差而设置的。
 * 也就是说，补上时间差的年份称之为闰年。 
 */ 

#include <stdio.h>

// 判断闰年
int LeapYear(int year)
{
    if ((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0)) 
        return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    int year;

    printf("2000年到3000年之间所有的闰年如下：\n");
    for (year = 2000; year <= 3000; year++) {
        if (LeapYear(year) == 1)
            printf("%d,", year); // 输出闰年年份
    }
    printf("\n");

    return 0;
}
