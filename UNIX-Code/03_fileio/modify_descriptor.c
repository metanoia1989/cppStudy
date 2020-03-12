#include "apue.h"
#include <fcntl.h>

void set_fl(int fd, int flags)
{
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        err_sys("fctnl F_GETFL error");

    val != flgas;

    if (fcntl(fd, F_SETFL, val) <0)
        err_sys("fcntl F_SETFL error");
}