#include "apue.h"
#include <pwd.h>

static void my_alarm(int signo)
{
    struct passwd *rootptr;

    printf("in signal handler\n");
    if ((rootptr = getpwnam("root")) == NULL)
        err_sys("getpwname(root) error");
    alarm(1);
}

int main(int argc, char const *argv[])
{
    struct passwd *ptr; 

    signal(SIGALRM, my_alarm);
    alarm(1);
    while (1) {
        if ((ptr = getpwnam("sar")) == NULL)
            err_sys("getpwname error");
        if (strcmp(ptr->pw_name, "sar") != 0)
            printf("return value corrupted!, pw_name = %s\n", 
                ptr->pw_name);
    }

    return 0;
}
