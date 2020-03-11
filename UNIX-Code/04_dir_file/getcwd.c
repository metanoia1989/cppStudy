#include "apue.h"

int main(int argc, char const *argv[])
{
    char *ptr;
    size_t size;
    if (argc != 2) 
        err_quit("usage: ./a.out <dirpath>");

    if (chdir(argv[1]) < 0)
        err_sys("chdir failed");

    ptr = path_alloc(&size); // 自定义函数
    if (getcwd(ptr, size) == NULL)
        err_sys("getcwd failed");
    printf("cwd = %s\n", ptr);

    return 0;
}
