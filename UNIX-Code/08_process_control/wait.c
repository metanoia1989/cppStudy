#include "apue.h"
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        exit(7);
    }

    if (wait(&status) != pid)
        err_sys("wait error");

    pr_exit(status);

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) { 
        abort();
    }

    if (wait(&status) != pid)
        err_sys("wait error");

    pr_exit(status);

    if ((pid = fork()) < 0 ) {
        err_sys("fork error");
    } else if (pid == 0) {
        status /= 0; // divide by 0 generates SIGFPE 
    }

    if (wait(&status) != pid)
        err_sys("wait error");

    pr_exit(status);

    return 0;
}