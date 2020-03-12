//****************************************
// 将标准输入 复制到标准输出，读行写行
//****************************************

#include "apue.h"

int main(int argc, char const *argv[])
{
    char buf[MAXLINE];

    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (fputs(buf, stdout) == EOF)
            err_sys("output error");
    }

    if (ferror(stdin))
        err_sys("input error");

    return 0;
}
